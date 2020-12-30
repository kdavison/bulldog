cmake_minimum_required(VERSION 3.19)

project(bulldog)

## SETUP
SET (CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/artifacts")
SET (CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
SET (CMAKE_USER_MAKE_RULES_OVERRIDE "${PROJECT_SOURCE_DIR}/ClangOverrides.txt")
SET (CMAKE_TOOLCHAIN_PREFIX "llvm-")

## MODULES
include(ExternalProject)

## DEPENDENCIES
add_subdirectory(${PROJECT_SOURCE_DIR}/dependencies)

link_directories(${CMAKE_INSTALL_PREFIX}/lib)
include_directories(
  ${CMAKE_INSTALL_PREFIX}/include
  ${PROJECT_SOURCE_DIR}/include
)
## SERVER
set(
  SERVER_SOURCES
  source/server.cc
)
set(
  SERVER_LIBRARIES
  steam_api
)
add_executable(
  BulldogServer
  ${SERVER_SOURCES}
)
target_link_libraries(
  BulldogServer
  ${SERVER_LIBRARIES}
)

## CLIENT
set(
  CLIENT_SOURCES
  source/client.cc
)
set(
  CLIENT_LIBRARIES
  steam_api
)
add_executable(
  BulldogClient
  ${CLIENT_SOURCES}
)
target_link_libraries(
  BulldogClient
  ${CLIENT_LIBRARIES}
)

## INSTALL
install(
  TARGETS BulldogClient BulldogServer
  RUNTIME
  DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
)
