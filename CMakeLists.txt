cmake_minimum_required(VERSION 3.30)

project(bulldog CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# ---------------------------------
# SDL3 Dependency
# ---------------------------------
FetchContent_Declare(
  SDL3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG        release-3.2.18
  GIT_SHALLOW    TRUE
)


# ---------------------------------
# GLM Dependency via FetchContent
# ---------------------------------
set(GLM_BUILD_TESTS OFF CACHE BOOL "Disable GLM tests" FORCE)

FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG        1.0.1
    GIT_SHALLOW    TRUE
)

FetchContent_MakeAvailable(SDL3 glm)

