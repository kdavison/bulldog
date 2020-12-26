cmake_minimum_required(VERSION 3.19)

project(bulldog)

include_directories(
  ${PROJECT_SOURCE_DIR}/artifacts/include
  ${PROJECT_SOURCE_DIR}/include
)
link_directories(
  ${PROJECT_SOURCE_DIR}/artifacts/lib
)

## CLIENT
SET (
  CLIENT_SOURCES
  client.cc
)
SET (
  CLIENT_LIBRARIES
  pthread
)
add_executable(
  Client
  "${CLIENT_SOURCES}"
)
target_link_libraries(
  Client
  "${CLIENT_LIBRARIES}"
)

## SERVER
set (
  SERVER_SOURCES
  server.cc
)
SET (
  SERVER_LIBRARIES
  pthread
)
add_executable(
  Server
  ${SERVER_SOURCES}
)
target_link_libraries(
  Server
  "${SERVER_LIBRARIES}"
)
