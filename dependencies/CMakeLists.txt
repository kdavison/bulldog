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
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/protobuf
  UPDATE_COMMAND ""
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/protobuf/autogen.sh && ${CMAKE_CURRENT_SOURCE_DIR}/protobuf/configure --prefix=${CMAKE_INSTALL_PREFIX}
  BUILD_IN_SOURCE TRUE
  INSTALL_COMMAND $(MAKE) install
)

## libgcrypt
ExternalProject_Add(
  libgcrypt
  PREFIX libgcrypt
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libgcrypt
  UPDATE_COMMAND ""
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/libgcrypt/autogen.sh && ${CMAKE_CURRENT_SOURCE_DIR}/libgcrypt/configure --enable-static --disable-doc --prefix=${CMAKE_INSTALL_PREFIX} --includedir=${CMAKE_INSTALL_PREFIX}/include/gcrypt
  BUILD_IN_SOURCE TRUE
  INSTALL_COMMAND $(MAKE) install
)

## steamworks
ExternalProject_Add(
  steamworks
  PREFIX steamworks
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/steamworks
  DOWNLOAD_COMMAND wget --no-cache https://partner.steamgames.com/downloads/steamworks_sdk_150.zip
  URL https://partner.steamgames.com/downloads/steamworks_sdk_150.zip
  URL_HASH SHA256=5402cb9f93907d3235fd7388e83ef78788e3cad0b19e4687b8b956643495149c
  UPDATE_COMMAND ""
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  INSTALL_COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_INSTALL_PREFIX}/include/steamworks
)

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/steamworks/public/steam/
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include/steamworks
  FILES_MATCHING PATTERN "*.h"
)

## ENTT
add_subdirectory(entt)
