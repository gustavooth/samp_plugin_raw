#include <defines.h>
#include <amx/plugin.h>
#include <invoke/invoke.h>
#include <stdio.h>

typedef void (*PFN_logprintf)(const char* format, ...);
PFN_logprintf logprintf;

extern void *pAMXFunctions;

cell AMX_NATIVE_CALL wellcome(AMX* amx, cell* params){
  i32 player_id = params[1];

  char name[25] = {0};
  invoke(amx, &GetPlayerName, player_id, name, 25);

  char message[50] = {0};
  sprintf(message, "%s entrou no servidor.", name);

  invoke(amx, &SendClientMessageToAll, -1, message);
  return true;
}

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports(){
  return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT b8 PLUGIN_CALL Load(void **ppData){
  pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];

  logprintf = (PFN_logprintf) ppData[PLUGIN_DATA_LOGPRINTF];

  logprintf(" * myplugin was loaded.");
  return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload(){
  logprintf(" * myplugin was unloaded.");
}

AMX_NATIVE_INFO PluginNatives[] = {
  {"wellcome", wellcome},
  {0, 0}
};

PLUGIN_EXPORT i32 PLUGIN_CALL AmxLoad(AMX *amx){
  amx_Register(amx, PluginNatives, -1);

  // --------- Check amx natives
  AMX_HEADER* hdr = (AMX_HEADER*)amx->base;

  AMX_FUNCSTUBNT* natives = (AMX_FUNCSTUBNT*)(hdr->natives + ((u32)(amx->base)));
  AMX_FUNCSTUBNT* libraries = (AMX_FUNCSTUBNT* )(hdr->libraries + ((u32)(amx->base)));

  for (AMX_FUNCSTUBNT *n = natives; n < libraries; n++) {
    if (n->address == 0) {
      char *name = (char*)(n->nameofs + ((u32)(hdr)));
      logprintf("   Error: Function not registered: '%s'", name);
    }
  }

  return AMX_ERR_NONE;
}

PLUGIN_EXPORT i32 PLUGIN_CALL AmxUnload(AMX *amx){
  return AMX_ERR_NONE;
}
