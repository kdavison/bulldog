cmake_minimum_required(VERSION 3.19)

project(bulldog)

## SETUP
SET (CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/artifacts")
SET (CMAKE_USER_MAKE_RULES_OVERRIDE "${PROJECT_SOURCE_DIR}/ClangOverrides.txt")
SET (CMAKE_TOOLCHAIN_PREFIX "llvm-")

## MODULES
include(ExternalProject)

## DEPENDENCIES
add_subdirectory(${PROJECT_SOURCE_DIR}/dependencies)

## SERVER

## CLIENT
