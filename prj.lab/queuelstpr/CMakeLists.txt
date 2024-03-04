add_library(queuelstpr queuelstpr.cpp queuelstpr.hpp)
target_include_directories(queuelstpr PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS queuelstpr)
