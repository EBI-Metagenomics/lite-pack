cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(
  lite_pack
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

add_library(
  ${PROJECT_NAME}
  src/1darray/pack_float.c
  src/1darray/pack_int.c
  src/1darray/pack_int_inplace.c
  src/1darray/unpack_float.c
  src/1darray/unpack_int.c
  src/1darray/unpack_int_inplace.c
  src/1darray/write.c
  src/1darray/write_int.c
  src/1darray/write_int_inplace.c
  src/1darray/write_float.c
  src/1darray/read.c
  src/1darray/read_int.c
  src/1darray/read_float.c
  src/io/file/write_array.c
  src/io/file/write_bool.c
  src/io/file/write_ext.c
  src/io/file/write_float.c
  src/io/file/write_int.c
  src/io/file/write_map.c
  src/io/file/write_str.c
  src/io/file/read_array.c
  src/io/file/read_bool.c
  src/io/file/read_ext.c
  src/io/file/read_float.c
  src/io/file/read_int.c
  src/io/file/read_map.c
  src/io/file/read_str.c
  src/first_byte.c
  src/format.c
  src/pack_array.c
  src/pack_ext.c
  src/pack_int.c
  src/pack_map.c
  src/pack_str.c
  src/unpack_array.c
  src/unpack_bool.c
  src/unpack_ext.c
  src/unpack_float.c
  src/unpack_int.c
  src/unpack_map.c
  src/unpack_str.c)
add_library(LITE_PACK::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set(EXPORT_FILE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}/export.h)
include(GenerateExportHeader)
generate_export_header(
  ${PROJECT_NAME}
  BASE_NAME
  LIP
  INCLUDE_GUARD_NAME
  LITE_PACK_EXPORT_H
  EXPORT_MACRO_NAME
  LIP_API
  EXPORT_FILE_NAME
  ${EXPORT_FILE})

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
         $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}-targets)

install(DIRECTORY src/${PROJECT_NAME}/ DESTINATION include/${PROJECT_NAME})

install(
  EXPORT ${PROJECT_NAME}-targets
  FILE ${PROJECT_NAME}-targets.cmake
  NAMESPACE LITE_PACK::
  DESTINATION lib/cmake/${PROJECT_NAME})

include(CMakePackageConfigHelpers)

set(CONFIG_FILE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake)
configure_package_config_file(${PROJECT_NAME}-config.cmake.in ${CONFIG_FILE}
                              INSTALL_DESTINATION lib/cmake/${PROJECT_NAME})

set(VERSION_FILE
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake)
write_basic_package_version_file(${VERSION_FILE} COMPATIBILITY SameMajorVersion)

install(FILES ${CONFIG_FILE} ${VERSION_FILE}
        DESTINATION lib/cmake/${PROJECT_NAME})

install(FILES ${EXPORT_FILE} DESTINATION include/${PROJECT_NAME})

enable_testing()
add_subdirectory(test)
