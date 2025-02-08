/*  THIS FILE WAS MODIFIED BY
 *  github.com/gustavooth
 * 
 *  Pawn Abstract Machine (for the Pawn language)
 *
 *  Copyright (c) ITB CompuPhase, 1997-2005
 *
 *  This software is provided "as-is", without any express or implied warranty.
 *  In no event will the authors be held liable for any damages arising from
 *  the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute it
 *  freely, subject to the following restrictions:
 *
 *  1.  The origin of this software must not be misrepresented; you must not
 *      claim that you wrote the original software. If you use this software in
 *      a product, an acknowledgment in the product documentation would be
 *      appreciated but is not required.
 *  2.  Altered source versions must be plainly marked as such, and must not be
 *      misrepresented as being the original software.
 *  3.  This notice may not be removed or altered from any source distribution.
 *
 */

#pragma once
#include <defines.h>
#include <stdlib.h>

#ifdef  __cplusplus
extern  "C" {
#endif

#define CUR_FILE_VERSION  8     /* current file version; also the current AMX version */
#define MIN_FILE_VERSION  6     /* lowest supported file format version for the current AMX version */
#define MIN_AMX_VERSION   8     /* minimum AMX version needed to support the current file format */

#define PAWN_CELL_SIZE 32     /* by default, use 32-bit cells */
typedef u32 ucell;
typedef i32 cell;

struct tagAMX;
typedef cell (*AMX_NATIVE)(struct tagAMX* amx, cell* params);
typedef int (*AMX_CALLBACK)(struct tagAMX* amx, cell index, cell* result, cell* params);
typedef int (*AMX_DEBUG)(struct tagAMX* amx);

typedef struct tagAMX_NATIVE_INFO {
  const char* name  PACKED;
  AMX_NATIVE func   PACKED;
} PACKED AMX_NATIVE_INFO;

#define AMX_USERNUM     4
#define sEXPMAX         19      /* maximum name length for file version <= 6 */
#define sNAMEMAX        31      /* maximum name length of symbol name */

typedef struct tagAMX_FUNCSTUB {
  ucell address         PACKED;
  char name[sEXPMAX+1]  PACKED;
} PACKED AMX_FUNCSTUB;

typedef struct tagFUNCSTUBNT {
  ucell address         PACKED;
  u32 nameofs      PACKED;
} PACKED AMX_FUNCSTUBNT;

/* The AMX structure is the internal structure for many functions. Not all
 * fields are valid at all times; many fields are cached in local variables.
 */
typedef struct tagAMX {
  unsigned char* base PACKED; /* points to the AMX  header plus the code, optionally also the data */
  unsigned char* data PACKED; /* points to separate data+stack+heap, may be NULL */
  AMX_CALLBACK callback PACKED;
  AMX_DEBUG debug       PACKED; /* debug callback */
  /* for external functions a few registers must be accessible from the outside */
  cell cip              PACKED; /* instruction pointer: relative to base + amxhdr->cod */
  cell frm              PACKED; /* stack frame base: relative to base + amxhdr->dat */
  cell hea              PACKED; /* top of the heap: relative to base + amxhdr->dat */
  cell hlw              PACKED; /* bottom of the heap: relative to base + amxhdr->dat */
  cell stk              PACKED; /* stack pointer: relative to base + amxhdr->dat */
  cell stp              PACKED; /* top of the stack: relative to base + amxhdr->dat */
  int flags             PACKED; /* current status, see amx_Flags() */
  /* user data */
  long usertags[AMX_USERNUM] PACKED;
  void* userdata[AMX_USERNUM] PACKED;
  /* native functions can raise an error */
  int error             PACKED;
  /* passing parameters requires a "count" field */
  int paramcount;
  /* the sleep opcode needs to store the full AMX status */
  cell pri              PACKED;
  cell alt              PACKED;
  cell reset_stk        PACKED;
  cell reset_hea        PACKED;
  cell sysreq_d         PACKED; /* relocated address/value for the SYSREQ.D opcode */
} PACKED AMX;

/* The AMX_HEADER structure is both the memory format as the file format. The
 * structure is used internaly.
 */
typedef struct tagAMX_HEADER {
  i32 size          PACKED; /* size of the "file" */
  u16 magic        PACKED; /* signature */
  char    file_version  PACKED; /* file format version */
  char    amx_version   PACKED; /* required version of the AMX */
  i16 flags         PACKED;
  i16 defsize       PACKED; /* size of a definition record */
  i32 cod           PACKED; /* initial value of COD - code block */
  i32 dat           PACKED; /* initial value of DAT - data block */
  i32 hea           PACKED; /* initial value of HEA - start of the heap */
  i32 stp           PACKED; /* initial value of STP - stack top */
  i32 cip           PACKED; /* initial value of CIP - the instruction pointer */
  i32 publics       PACKED; /* offset to the "public functions" table */
  i32 natives       PACKED; /* offset to the "native functions" table */
  i32 libraries     PACKED; /* offset to the table of libraries */
  i32 pubvars       PACKED; /* the "public variables" table */
  i32 tags          PACKED; /* the "public tagnames" table */
  i32 nametable     PACKED; /* name table */
} PACKED AMX_HEADER;

#define AMX_MAGIC 0xf1e0

enum {
  AMX_ERR_NONE,
  /* reserve the first 15 error codes for exit codes of the abstract machine */
  AMX_ERR_EXIT,         /* forced exit */
  AMX_ERR_ASSERT,       /* assertion failed */
  AMX_ERR_STACKERR,     /* stack/heap collision */
  AMX_ERR_BOUNDS,       /* index out of bounds */
  AMX_ERR_MEMACCESS,    /* invalid memory access */
  AMX_ERR_INVINSTR,     /* invalid instruction */
  AMX_ERR_STACKLOW,     /* stack underflow */
  AMX_ERR_HEAPLOW,      /* heap underflow */
  AMX_ERR_CALLBACK,     /* no callback, or invalid callback */
  AMX_ERR_NATIVE,       /* native function failed */
  AMX_ERR_DIVIDE,       /* divide by zero */
  AMX_ERR_SLEEP,        /* go into sleepmode - code can be restarted */
  AMX_ERR_INVSTATE,     /* invalid state for this access */

  AMX_ERR_MEMORY = 16,  /* out of memory */
  AMX_ERR_FORMAT,       /* invalid file format */
  AMX_ERR_VERSION,      /* file is for a newer version of the AMX */
  AMX_ERR_NOTFOUND,     /* function not found */
  AMX_ERR_INDEX,        /* invalid index parameter (bad entry point) */
  AMX_ERR_DEBUG,        /* debugger cannot run */
  AMX_ERR_INIT,         /* AMX not initialized (or doubly initialized) */
  AMX_ERR_USERDATA,     /* unable to set user data field (table full) */
  AMX_ERR_INIT_JIT,     /* cannot initialize the JIT */
  AMX_ERR_PARAMS,       /* parameter error */
  AMX_ERR_DOMAIN,       /* domain error, expression result does not fit in range */
  AMX_ERR_GENERAL,      /* general error (unknown or unspecific error) */
};

/*      AMX_FLAG_CHAR16   0x01     no longer used */
#define AMX_FLAG_DEBUG    0x02  /* symbolic info. available */
#define AMX_FLAG_COMPACT  0x04  /* compact encoding */
#define AMX_FLAG_BYTEOPC  0x08  /* opcode is a byte (not a cell) */
#define AMX_FLAG_NOCHECKS 0x10  /* no array bounds checking; no STMT opcode */
#define AMX_FLAG_NTVREG 0x1000  /* all native functions are registered */
#define AMX_FLAG_JITC   0x2000  /* abstract machine is JIT compiled */
#define AMX_FLAG_BROWSE 0x4000  /* busy browsing */
#define AMX_FLAG_RELOC  0x8000  /* jump/call addresses relocated */

#define AMX_EXEC_MAIN   -1      /* start at program entry point */
#define AMX_EXEC_CONT   -2      /* continue from last address */

/* for native functions that use floating point parameters, the following
 * two macros are convenient for casting a "cell" into a "float" type _without_
 * changing the bit pattern
 */
#define amx_ftoc(f)   ( * ((cell*)&f) )   /* float to cell */
#define amx_ctof(c)   ( * ((float*)&c) )

u16* PLUGINAPI amx_Align16(u16 *v);
u32* PLUGINAPI amx_Align32(u32 *v);

int PLUGINAPI amx_Allot(AMX *amx, int cells, cell *amx_addr, cell **phys_addr);
int PLUGINAPI amx_Callback(AMX *amx, cell index, cell *result, cell *params);
int PLUGINAPI amx_Cleanup(AMX *amx);
int PLUGINAPI amx_Clone(AMX *amxClone, AMX *amxSource, void *data);
int PLUGINAPI amx_Exec(AMX* amx, cell* retval, int index);
int PLUGINAPI amx_FindNative(AMX *amx, const char *name, int *index);
int PLUGINAPI amx_FindPublic(AMX *amx, const char *funcname, int *index);
int PLUGINAPI amx_FindPubVar(AMX *amx, const char *varname, cell *amx_addr);
int PLUGINAPI amx_FindTagId(AMX *amx, cell tag_id, char *tagname);
int PLUGINAPI amx_Flags(AMX *amx,u16 *flags);
int PLUGINAPI amx_GetAddr(AMX *amx,cell amx_addr,cell **phys_addr);
int PLUGINAPI amx_GetNative(AMX *amx, int index, char *funcname);
int PLUGINAPI amx_GetPublic(AMX *amx, int index, char *funcname);
int PLUGINAPI amx_GetPubVar(AMX *amx, int index, char *varname, cell *amx_addr);
int PLUGINAPI amx_GetString(char *dest,const cell *source, int use_wchar, size_t size);
int PLUGINAPI amx_GetTag(AMX *amx, int index, char *tagname, cell *tag_id);
int PLUGINAPI amx_GetUserData(AMX *amx, long tag, void **ptr);
int PLUGINAPI amx_Init(AMX *amx, void *program);
int PLUGINAPI amx_InitJIT(AMX *amx, void *reloc_table, void *native_code);
int PLUGINAPI amx_MemInfo(AMX *amx, long *codesize, long *datasize, long *stackheap);
int PLUGINAPI amx_NameLength(AMX *amx, int *length);
AMX_NATIVE_INFO * PLUGINAPI amx_NativeInfo(const char *name, AMX_NATIVE func);
int PLUGINAPI amx_NumNatives(AMX *amx, int *number);
int PLUGINAPI amx_NumPublics(AMX *amx, int *number);
int PLUGINAPI amx_NumPubVars(AMX *amx, int *number);
int PLUGINAPI amx_NumTags(AMX *amx, int *number);
int PLUGINAPI amx_Push(AMX *amx, cell value);
int PLUGINAPI amx_PushArray(AMX *amx, cell *amx_addr, cell **phys_addr, const cell array[], int numcells);
int PLUGINAPI amx_PushString(AMX *amx, cell *amx_addr, cell **phys_addr, const char *string, int pack, int use_wchar);
int PLUGINAPI amx_RaiseError(AMX *amx, int error);
int PLUGINAPI amx_Register(AMX *amx, const AMX_NATIVE_INFO *nativelist, int number);
int PLUGINAPI amx_Release(AMX *amx, cell amx_addr);
int PLUGINAPI amx_SetCallback(AMX *amx, AMX_CALLBACK callback);
int PLUGINAPI amx_SetDebugHook(AMX *amx, AMX_DEBUG debug);
int PLUGINAPI amx_SetString(cell *dest, const char *source, int pack, int use_wchar, size_t size);
int PLUGINAPI amx_SetUserData(AMX *amx, long tag, void *ptr);
int PLUGINAPI amx_StrLen(const cell *cstring, int *length);
int PLUGINAPI amx_UTF8Check(const char *string, int *length);
int PLUGINAPI amx_UTF8Get(const char *string, const char **endptr, cell *value);
int PLUGINAPI amx_UTF8Len(const cell *cstr, int *length);
int PLUGINAPI amx_UTF8Put(char *string, char **endptr, int maxchars, cell value);

#define amx_RegisterFunc(amx, name, func) \
  amx_Register((amx), amx_NativeInfo((name),(func)), 1);

UNPACKED

#ifdef  __cplusplus
}
#endif
