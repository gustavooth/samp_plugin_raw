include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(amx STATIC
  amxplugin.c
)