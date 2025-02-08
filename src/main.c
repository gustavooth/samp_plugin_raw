#include <defines.h>
#include <amx/plugin.h>
#include <invoke/invoke.h>
#include <stdio.h>

extern void *pAMXFunctions;
extern PFN_logprintf logprintf;

cell PLUGINAPI wellcome(AMX* amx, cell* params){
  i32 player_id = params[1];

  char name[25] = {0};
  invoke(amx, &GetPlayerName, player_id, name, 25);

  char message[50] = {0};
  sprintf(message, "%s entrou no servidor.", name);

  invoke(amx, &SendClientMessageToAll, -1, message);
  return true;
}

PLUGINAPI unsigned int Supports(){
  return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGINAPI b8 Load(void **ppData){
  pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];

  logprintf = (PFN_logprintf) ppData[PLUGIN_DATA_LOGPRINTF];

  logprintf(" * myplugin was loaded.");
  return true;
}

PLUGINAPI void Unload(){
  logprintf(" * myplugin was unloaded.");
}

AMX_NATIVE_INFO PluginNatives[] = {
  {"wellcome", wellcome},
  {0, 0}
};

PLUGINAPI i32 AmxLoad(AMX *amx){
  amx_Register(amx, PluginNatives, -1);

  // --------- Check amx natives
  AMX_HEADER* hdr = (AMX_HEADER*)amx->base;

  AMX_FUNCSTUBNT* natives = (AMX_FUNCSTUBNT*)(hdr->natives + ((u32)(amx->base)));
  AMX_FUNCSTUBNT* libraries = (AMX_FUNCSTUBNT* )(hdr->libraries + ((u32)(amx->base)));

  for (AMX_FUNCSTUBNT *n = natives; n < libraries; n++) {
    char *name = (char*)(n->nameofs + ((u32)(hdr)));
    if (n->address == 0) {
      logprintf("Error: Function not registered: '%s'", name);
    }else{
      logprintf("Function registered: '%s'", name);
    }
  }

  return AMX_ERR_NONE;
}

PLUGINAPI i32 AmxUnload(AMX *amx){
  return AMX_ERR_NONE;
}
