add_library(queue queue.cpp queue.hpp)
target_include_directories(queue PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS queue)
