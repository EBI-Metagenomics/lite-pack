cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

project(
  lite_pack
  VERSION 0.3.2
  LANGUAGES C)

set(LIP_MAIN_PROJECT OFF)
if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
  set(LIP_MAIN_PROJECT ON)
endif()

if(LIP_MAIN_PROJECT)
  set(LIP_BUILD_TESTS_DEFAULT ON)
else()
  set(LIP_BUILD_TESTS_DEFAULT OFF)
endif()

option(LIP_BUILD_TESTS "Build the unit tests" ${LIP_BUILD_TESTS_DEFAULT})
message(STATUS "LIP_MAIN_PROJECT: " ${LIP_MAIN_PROJECT})
message(STATUS "LIP_BUILD_TESTS: " ${LIP_BUILD_TESTS})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_EXTENSIONS OFF)

include(cmake/compiler-options.cmake)
include(cmake/sanitizers.cmake)

set(THREAD_SAFE_LEVELS 0 1)
set(THREAD_SAFE_LEVEL
    "1"
    CACHE STRING "Thread-safe level: 0 for none; 1 otherwise.")
if(${THREAD_SAFE_LEVEL} IN_LIST THREAD_SAFE_LEVELS)
  message(STATUS "Thread-safe level - ${THREAD_SAFE_LEVEL}")
else()
  message(FATAL_ERROR "Thread-safe levels are either 0 or 1.")
endif()

option(ENABLE_1DARRAY_EXTENSION "Enable 1darray extension (defaults to TRUE)"
       TRUE)
if(${ENABLE_1DARRAY_EXTENSION})
  set(ENABLE_1DARRAY_EXTENSION 1)
  message(STATUS "Enabled 1darray extension")
else()
  set(ENABLE_1DARRAY_EXTENSION 0)
  message(STATUS "Disabled 1darray extension")
endif()

set(FILE_SOURCES
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
    src/unpack_str.c)

if(${ENABLE_1DARRAY_EXTENSION})
  list(
    APPEND
    FILE_SOURCES
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
endif()

add_library(lite_pack ${FILE_SOURCES})
add_library(LITE_PACK::lite_pack ALIAS lite_pack)

set(CONFIG_FILE ${CMAKE_CURRENT_BINARY_DIR}/lite_pack/config.h)
configure_file(${PROJECT_SOURCE_DIR}/include/lite_pack/config.h.in
               ${CONFIG_FILE})

set(EXPORT_FILE ${CMAKE_CURRENT_BINARY_DIR}/lite_pack/export.h)
include(GenerateExportHeader)
generate_export_header(
  lite_pack
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
  set_target_properties(lite_pack PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()

target_compile_features(lite_pack PRIVATE c_std_11)
target_compile_options(lite_pack PRIVATE ${WARNING_FLAGS})

target_include_directories(
  lite_pack
  PUBLIC $<INSTALL_INTERFACE:include>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
  PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)

install(TARGETS lite_pack EXPORT lite_pack-targets)

install(DIRECTORY include/lite_pack/ DESTINATION include/lite_pack)

install(
  EXPORT lite_pack-targets
  FILE lite_pack-targets.cmake
  NAMESPACE LITE_PACK::
  DESTINATION lib/cmake/lite_pack)

include(CMakePackageConfigHelpers)

set(CMAKE_CONFIG_FILE ${CMAKE_CURRENT_BINARY_DIR}/lite_pack-config.cmake)
configure_package_config_file(lite_pack-config.cmake.in ${CMAKE_CONFIG_FILE}
                              INSTALL_DESTINATION lib/cmake/lite_pack)

set(CMAKE_VERSION_FILE
    ${CMAKE_CURRENT_BINARY_DIR}/lite_pack-config-version.cmake)
write_basic_package_version_file(${CMAKE_VERSION_FILE}
                                 COMPATIBILITY SameMajorVersion)

install(FILES ${CMAKE_VERSION_FILE} ${CMAKE_CONFIG_FILE}
        DESTINATION lib/cmake/lite_pack)
install(FILES ${EXPORT_FILE} ${CONFIG_FILE} DESTINATION include/lite_pack)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/README.md
              ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE
        DESTINATION share/docs/lite_pack)

if(LIP_BUILD_TESTS)
  enable_testing()
  add_subdirectory(test)
endif()

set(CPACK_PACKAGE_NAME lite_pack)
set(CPACK_PACKAGE_VENDOR "Danilo Horta")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY
    "C library implementing the amazing MessagePack serialisation format")
set(CPACK_PACKAGE_CONTACT "Danilo Horta")
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE)
set(CPACK_RESOURCE_FILE_README ${CMAKE_CURRENT_SOURCE_DIR}/README.md)
set(CPACK_OUTPUT_FILE_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/package)
set(CPACK_VERBATIM_VARIABLES YES)
set(CPACK_PACKAGE_RELOCATABLE YES)
set(CPACK_MONOLITHIC_INSTALL YES)
include(CPack)
