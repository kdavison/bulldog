## GLFW
set (GLFW_BUILD_EXAMPLES OFF CACHE BOOL "disable examples")
set (GLFW_BUILD_TESTS OFF CACHE BOOL "disable tests")
set (GLFW_BUILD_DOCS OFF CACHE BOOL "disable docs")
##TODO: Vulkan
add_subdirectory(glfw)

## ENET
add_subdirectory(enet)

## BOOST
ExternalProject_Add(
  boost
  PREFIX boost
  SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/boost"
  GIT_REPOSITORY "git@github.com:boostorg/boost.git"
  GIT_TAG "boost-1.75.0"
  GIT_SUBMODULES_RECURSE TRUE
  GIT_SHALLOW TRUE
  UPDATE_COMMAND ""
  CONFIGURE_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/boost/bootstrap.sh --with-toolset=clang --prefix=${CMAKE_INSTALL_PREFIX} --with-libraries=program_options,filesystem,log
  BUILD_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/boost/b2
  BUILD_IN_SOURCE TRUE
  BUILD_ALWAYS FALSE
  INSTALL_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/boost/b2 install
)

## PROTOBUF
ExternalProject_Add(
  protobuf
  PREFIX protobuf
  GIT_REPOSITORY "git@github.com:protocolbuffers/protobuf.git"
  GIT_TAG "v3.14.0"
  GIT_SUBMODULES_RECURSE TRUE
  GIT_SHALLOW TRUE
  UPDATE_COMMAND ""
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/protobuf/autogen.sh && ${CMAKE_CURRENT_SOURCE_DIR}/protobuf/configure --prefix=${CMAKE_INSTALL_PREFIX}
  BUILD_IN_SOURCE TRUE
  INSTALL_COMMAND make -j12 install
)
