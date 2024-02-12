add_library(stacklst stacklst.cpp stacklst.hpp)
target_include_directories(stacklst PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS stacklst)
