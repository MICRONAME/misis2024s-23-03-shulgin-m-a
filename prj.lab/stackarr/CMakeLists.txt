add_library(stackarr stackarr.cpp stackarr.hpp)
target_link_libraries(stackarr complex)
target_include_directories(stackarr PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS stackarr)
