add_library(stackarrt stackarrt.hpp stackarrt.cpp)

target_include_directories(stackarrt PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS stackarrt)
