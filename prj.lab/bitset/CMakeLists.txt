add_library(bitset bitset.cpp bitset.hpp)
#add_executable(complex_test ../prj_test/complex_test.cpp)
target_include_directories(bitset PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS bitset)
