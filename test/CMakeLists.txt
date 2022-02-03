function(lp_add_test name)
  add_executable(${name} ${name}.c lorem.c)
  target_link_libraries(${name} PRIVATE LITEPACK::litepack)
  target_compile_features(${name} PRIVATE c_std_11)
  add_test(NAME ${name} COMMAND ${name})
endfunction()

lp_add_test(msgpack)
