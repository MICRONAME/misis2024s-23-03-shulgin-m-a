add_executable(complex_test complex_test.cpp)
target_link_libraries(complex_test complex)

add_executable(rational_test rational_test.cpp)
target_link_libraries(rational_test rational)

add_executable(dynarr_test dynarr_test.cpp)
target_link_libraries(dynarr_test dynarr)

add_executable(stackarr_test stackarr_test.cpp)
target_link_libraries(stackarr_test stackarr)
target_link_libraries(stackarr_test complex)

add_executable(stacklst_test stacklst_test.cpp)
target_link_libraries(stacklst_test stacklst)
target_link_libraries(stacklst_test complex)

add_executable(queue_test queue_test.cpp)
target_link_libraries(queue_test queue)
target_link_libraries(queue_test complex)