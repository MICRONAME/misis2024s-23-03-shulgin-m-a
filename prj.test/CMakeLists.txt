add_executable(complex_test complex_test.cpp)
target_link_libraries(complex_test complex)

add_executable(rational_test rational_test.cpp)
target_link_libraries(rational_test rational)

add_executable(dynarr_test dynarr_test.cpp)
target_link_libraries(dynarr_test dynarr)

add_executable(stackarr_test stackarr_test.cpp)
target_link_libraries(stackarr_test stackarr)

add_executable(stacklst_test stacklst_test.cpp)
target_link_libraries(stacklst_test stacklst)

add_executable(queue_test queue_test.cpp)
target_link_libraries(queue_test queuelst)

add_executable(queuearr_test queuearr_test.cpp)
target_link_libraries(queuearr_test queuearr)

add_executable(queuelstpr_test queuelstpr_test.cpp)
target_link_libraries(queuelstpr_test queuelstpr)

add_executable(queuelstprt_test queuelstprt_test.cpp)
target_link_libraries(queuelstprt_test queuelstprt)

add_executable(bitset_test bitset_test.cpp)
target_link_libraries(bitset_test bitset)