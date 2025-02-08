/*  THIS FILE WAS MODIFIED BY
 *  github.com/gustavooth
 *
 *  This file contains the PawnFunction command, which simply said
 *  provides functionality to invoke on a specific pawn command, using
 *  a ScriptCommand-like syntax. The pawn functions _have_ to be used
 *  in the filterscript/gamemode using the LVP Core.
 *
 *  Author: Peter Beverloo
 *          peter@dmx-network.com
 *
 *  The structure of the code is ScriptCommand-like, therefore some
 *  credits to spookie as well.
 */

#include <amx/plugin.h>
#include <defines.h>
#include "invoke.h"

#include <stdarg.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

extern PFN_logprintf logprintf;

#define MAX_REFERENCE_VARS 6

// A type-definition for the AMX-function type;
typedef int (*amx_Function_t)(AMX *amx, cell* params);

// This function invokes the SA-MP server and directly calls the
// requested function, specified by the PAWN_FUNCTION parameter.
int invoke(AMX* amx, const PAWN_FUNCTION* command, ...)
{
	const char* params = command->Params;

	va_list v_arguments;
	va_start( v_arguments, command );

	if (!amx) return 0;

 	// contains output variable ?
	b8 out_var = false;
	i32 out_cnt = 0;
	cell* out_addrs [ MAX_REFERENCE_VARS ];

	// Get the function-index for this specific command;
	i32 func_index;
	i32 result = amx_FindNative( amx, command->Function, &func_index );
	if (result != AMX_ERR_NONE || func_index == 2147483647){
		return result;
	}

	// Proceed with locating the memory address for this function;
	AMX_HEADER* hdr= (AMX_HEADER*) amx->base;
	unsigned int dwCallAddr = (unsigned int)( ( AMX_FUNCSTUB* )
		( (char*)(hdr) + (hdr)->natives + hdr->defsize * func_index) )->address;

	if( dwCallAddr == 0 )
		return AMX_ERR_NOTFOUND; // Could not locate the function's address.

	// Initialize the Arguments array, in which we save all required
	// values (which are also needed by the invoked-function).
	cell* args = (cell*)malloc(sizeof(cell) * (command->ParamCnt + 1));
	args[0] = command->ParamCnt * sizeof(cell);

	for (i32 i = 0; i < command->ParamCnt; i++){
		i32 ai = i + 1;

		if (params[i] == 'i'){
			args[ai] = va_arg(v_arguments, i32);
		}else if (params[i] == 'f'){
			f32 f_var = va_arg(v_arguments, f64);
			args[ai] = amx_ftoc(f_var);
		}else if (params[i] == 's'){
			char* str = va_arg(v_arguments, char*);
			i32 size = strlen(str) + 1;
			cell* tmp;
			amx_Allot(amx, size, &args[ai], &tmp);
			amx_SetString(tmp, str, false, false, size);
		}else if (params[i] == 'v'){
			cell* tmp;
			amx_Allot(amx, 1, &args[ai], &tmp);
			va_arg(v_arguments, cell*); // Just need to pop the arg.
			out_var = true;
			out_addrs[out_cnt++] = tmp;
		}else if (params[i] == 'p'){
			cell* tmp;
			amx_Allot(amx, 1, &args[ai], &tmp);

			// Whenever a string is an output, the next parameter is the length of the array 
			// reserved to store that string. 
			// I don't want the str now, just the length.
			va_arg(v_arguments, char*); // Just need to pop the arg.
			i++;
			
			out_var = true;
			out_addrs[out_cnt++] = tmp;
		}
	}

	va_end(v_arguments);

	// Next off, we need to define the prototype for the function
	// we'll be using. Internally, so it works on Linux too.
	amx_Function_t pFunction = (amx_Function_t)dwCallAddr;
	result = pFunction( amx, args );
	free(args);

	if (out_var){
		va_start(v_arguments, command);
		out_cnt = 0;

		for (i32 i = 0; i < command->ParamCnt; i++){
			i32 ai = i + 1;
			if (params[i] == 'i'){
				va_arg(v_arguments, i32);
			}else if (params[i] == 'f'){
				va_arg(v_arguments, f64);
			}else if (params[i] == 's'){
				va_arg(v_arguments, char*);
			} else if (params[i] == 'v'){
				cell* ref = va_arg(v_arguments, cell*);
				cell* tmp = out_addrs[out_cnt++];
				*ref = *tmp;
				amx_Release(amx, args[ai]);
			} else if (params[i] == 'p'){
				char* str = va_arg(v_arguments, char*);
				i++;
				i32 size = va_arg(v_arguments, i32);
				amx_GetString(str, out_addrs[out_cnt++], false, size);
				amx_Release(amx, args[ai]);
			}
		}
		va_end(v_arguments);
	}

	// Now just return the value.
	return result;
}
