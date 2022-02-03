cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(
  litepack
  VERSION 0.0.1
  LANGUAGES C)

# Generate compile_commands.json file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_C_COMPILER_ID STREQUAL "MSVC")
  # /wd5105:
  # https://docs.microsoft.com/en-us/cpp/error-messages/compiler-warnings/c5105?view=msvc-160
  set(WARNING_FLAGS /W3 /wd5105)
else()
  set(WARNING_FLAGS
      -Wall
      -Wextra
      -Wstrict-prototypes
      -Wshadow
      -Wconversion
      -Wmissing-prototypes
      -Wno-unused-parameter
      -Wsign-conversion
      -Wno-unused-function
      -Wmissing-field-initializers)

  if(NOT CMAKE_C_COMPILER_ID STREQUAL "GNU")
    list(
      APPEND
      WARNING_FLAGS
      -Wno-gnu-designator
      -Wno-empty-translation-unit
      -Wno-gnu-statement-expression
      -Wno-nullability-extension
      -Wconditional-uninitialized
      -Wgnu-empty-initializer)
  endif()
endif()

include("cmake/sanitizers.cmake")

add_library(${PROJECT_NAME} src/format.c src/unpack.c src/load.c)
add_library(LITEPACK::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

if(CMAKE_BUILD_TYPE STREQUAL "Release")
  include(CheckIPOSupported)
  check_ipo_supported()
  set_target_properties(${PROJECT_NAME} PROPERTIES INTERPROCEDURAL_OPTIMIZATION
                                                   TRUE)
endif()

target_compile_features(${PROJECT_NAME} PRIVATE c_std_11)
target_compile_options(${PROJECT_NAME} PRIVATE ${WARNING_FLAGS})

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC $<INSTALL_INTERFACE:include>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

enable_testing()
add_subdirectory(test)
