cmake_minimum_required(VERSION 3.19)

project(root)

## SETUP
SET (CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/artifacts")
SET (CMAKE_USER_MAKE_RULES_OVERRIDE "${PROJECT_SOURCE_DIR}/ClangOverrides.txt")
SET (CMAKE_TOOLCHAIN_PREFIX "llvm-")

## DEPENDENCIES
add_subdirectory(${PROJECT_SOURCE_DIR}/dependencies/glfw)
add_subdirectory(${PROJECT_SOURCE_DIR}/dependencies/enet)

## PROJECTS
add_subdirectory(${PROJECT_SOURCE_DIR}/source)
