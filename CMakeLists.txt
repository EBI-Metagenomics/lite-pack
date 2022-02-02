cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(
  litepack
  VERSION 0.0.1
  LANGUAGES C)

# Generate compile_commands.json file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(${PROJECT_NAME} src/lite_pack.c src/format.c)
add_library(LITEPACK::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PRIVATE c_std_11)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC $<INSTALL_INTERFACE:include>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

enable_testing()
add_subdirectory(test)
