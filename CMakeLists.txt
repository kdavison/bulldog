cmake_minimum_required(VERSION 3.28)

project(bulldog CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/artifacts)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/artifacts)
set(CMAKE_PDB_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/artifacts)

include(FetchContent)

# ---------------------------------
# SDL3 Dependency
# ---------------------------------
set(SDL_TEST OFF CACHE BOOL "Disable SDL test suite" FORCE)
set(SDL_SHARED ON CACHE BOOL "Build SDL shared library" FORCE)
set(SDL_STATIC OFF CACHE BOOL "Build SDL static library" FORCE)

FetchContent_Declare(
  SDL3
  SOURCE_DIR ./dependencies/SDL
)


# ---------------------------------
# GLM Dependency via FetchContent
# ---------------------------------
set(GLM_BUILD_TESTS OFF CACHE BOOL "Disable GLM tests" FORCE)

FetchContent_Declare(
    glm
    SOURCE_DIR ./dependencies/glm
)

# ---------------------------------
# entt Dependency via FetchContent
# ---------------------------------
FetchContent_Declare(
  entt
  SOURCE_DIR ./dependencies/entt
)

FetchContent_MakeAvailable(SDL3 glm entt)

