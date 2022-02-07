set(TMPDIR ${CMAKE_CURRENT_BINARY_DIR}/tmp)
set(ASSETS ${CMAKE_CURRENT_BINARY_DIR}/assets)

file(MAKE_DIRECTORY ${TMPDIR})
file(MAKE_DIRECTORY ${ASSETS})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/assets/u32.txt ${ASSETS}/u32.txt
               COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/assets/i32.txt ${ASSETS}/i32.txt
               COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/assets/u64.txt ${ASSETS}/u64.txt
               COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/assets/i64.txt ${ASSETS}/i64.txt
               COPYONLY)

function(lp_add_test name)
  add_executable(${name} ${name}.c helper.c)
  target_link_libraries(${name} PRIVATE LITEPACK::litepack)
  target_compile_features(${name} PRIVATE c_std_11)
  target_compile_options(${name} PRIVATE ${WARNING_FLAGS})
  add_test(NAME ${name} COMMAND ${name})
  target_compile_definitions(${name} PUBLIC "TMPDIR=\"${TMPDIR}\"")
  target_compile_definitions(${name} PUBLIC "ASSETS=\"${ASSETS}\"")
endfunction()

lp_add_test(integer)
lp_add_test(float)
lp_add_test(string)
lp_add_test(bool)
lp_add_test(map)
lp_add_test(examples)

lp_add_test(pack_int)
add_custom_command(
  TARGET pack_int
  POST_BUILD
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/pack_int.py "${ASSETS}/u32.txt"
          "${TMPDIR}/u32_py.mp")
add_custom_command(
  TARGET pack_int
  POST_BUILD
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/pack_int.py "${ASSETS}/i32.txt"
          "${TMPDIR}/i32_py.mp")
add_custom_command(
  TARGET pack_int
  POST_BUILD
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/pack_int.py "${ASSETS}/u64.txt"
          "${TMPDIR}/u64_py.mp")
add_custom_command(
  TARGET pack_int
  POST_BUILD
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/pack_int.py "${ASSETS}/i64.txt"
          "${TMPDIR}/i64_py.mp")
