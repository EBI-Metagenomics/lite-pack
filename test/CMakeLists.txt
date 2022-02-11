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
  target_link_libraries(${name} PRIVATE LITE_PACK::lite_pack)
  target_compile_features(${name} PRIVATE c_std_11)
  target_compile_options(${name} PRIVATE ${WARNING_FLAGS})
  add_test(NAME ${name} COMMAND ${name})
  target_compile_definitions(${name} PUBLIC "TMPDIR=\"${TMPDIR}\"")
  target_compile_definitions(${name} PUBLIC "ASSETS=\"${ASSETS}\"")
endfunction()

lp_add_test(integer)
lp_add_test(float)
lp_add_test(string)
lp_add_test(first_byte)
lp_add_test(bool)
lp_add_test(map)
lp_add_test(array)
lp_add_test(ext)
lp_add_test(examples)
lp_add_test(integer_stress)
lp_add_test(ext_example)
