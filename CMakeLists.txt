cmake_minimum_required(VERSION 3.20.2 FATAL_ERROR)
project(
  lip
  VERSION 0.5.4
  LANGUAGES C)
set(PROJECT_DESCRIPTION "C library for MessagePack serialisation format.")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)

include(cmake/sanitizers.cmake)
include(cmake/warnings.cmake)

option(LIP_THREAD_SAFE "Enable thread safety." ON)

add_library(
  lip
  src/endian.c
  src/file/file.c
  src/file/read_array.c
  src/file/read_bool.c
  src/file/read_cstr.c
  src/file/read_ext.c
  src/file/read_float.c
  src/file/read_int.c
  src/file/read_map.c
  src/file/read_object.c
  src/file/read_str.c
  src/file/write_array.c
  src/file/write_bool.c
  src/file/write_cstr.c
  src/file/write_ext.c
  src/file/write_float.c
  src/file/write_int.c
  src/file/write_map.c
  src/file/write_object.c
  src/file/write_str.c
  src/first_byte.c
  src/format.c
  src/load_bool.c
  src/load_ext.c
  src/load_float.c
  src/load_int.c
  src/load_number.c
  src/object.c
  src/pack_array.c
  src/pack_bool.c
  src/pack_ext.c
  src/pack_float.c
  src/pack_int.c
  src/pack_map.c
  src/pack_object.c
  src/pack_str.c
  src/stdio_unlocked.c
  src/store_bool.c
  src/store_ext.c
  src/store_float.c
  src/store_int.c
  src/store_map.c
  src/store_number.c
  src/store_str.c
  src/unpack_array.c
  src/unpack_bool.c
  src/unpack_ext.c
  src/unpack_float.c
  src/unpack_int.c
  src/unpack_map.c
  src/unpack_object.c
  src/unpack_str.c
  src/1darray/file/read.c
  src/1darray/file/read_float.c
  src/1darray/file/read_int.c
  src/1darray/file/write.c
  src/1darray/file/write_float.c
  src/1darray/file/write_int.c
  src/1darray/file/write_int_data.c
  src/1darray/file/write_int_data_in.c
  src/1darray/pack_float.c
  src/1darray/pack_int.c
  src/1darray/pack_int_in.c
  src/1darray/unpack_float.c
  src/1darray/unpack_int.c
  src/1darray/unpack_int_in.c)
add_library(LIP::lip ALIAS lip)

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(lip PUBLIC -DLIP_STATIC_DEFINE)
endif()

target_include_directories(
  lip
  PUBLIC $<INSTALL_INTERFACE:include>
         $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
         $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
  PRIVATE ${PROJECT_SOURCE_DIR}/src)

set_target_properties(lip PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(lip PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})
target_compile_options(lip PRIVATE ${WARNING_FLAGS})

if(CMAKE_BUILD_TYPE STREQUAL "Release")
  include(CheckIPOSupported)
  check_ipo_supported()
  set_target_properties(lip PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()

install(
  TARGETS lip
  EXPORT lip-targets
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)
install(DIRECTORY include/lip/ DESTINATION include/lip)

export(
  TARGETS lip
  NAMESPACE LIP::
  FILE lip-targets.cmake)
install(
  EXPORT lip-targets
  NAMESPACE LIP::
  DESTINATION lib/cmake/lip)

install(FILES ${PROJECT_SOURCE_DIR}/README.md ${PROJECT_SOURCE_DIR}/LICENSE
        DESTINATION share/docs/lip)

include(CMakePackageConfigHelpers)

set(project_config ${PROJECT_BINARY_DIR}/lip-config.cmake)
set(version_config ${PROJECT_BINARY_DIR}/lip-config-version.cmake)

configure_package_config_file(lip-config.cmake.in ${project_config}
                              INSTALL_DESTINATION lib/cmake/lip)

write_basic_package_version_file(${version_config}
                                 COMPATIBILITY SameMajorVersion)

install(FILES ${project_config} ${version_config}
        DESTINATION lib/cmake/lip)

if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
  enable_testing()
  add_subdirectory(test)
endif()
