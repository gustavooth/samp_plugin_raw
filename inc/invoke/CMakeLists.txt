include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_SOURCE_DIR}/inc/
)

add_library(invoke STATIC
  invoke.c
)