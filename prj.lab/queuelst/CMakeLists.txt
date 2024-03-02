add_library(queuelst queuelst.cpp queuelst.hpp)
target_link_libraries(queuelst complex)
target_include_directories(queuelst PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS queuelst)
