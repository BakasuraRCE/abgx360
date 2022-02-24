cmake_minimum_required(VERSION 3.21)
project(abgx360gui)

set(CMAKE_CXX_STANDARD 23)

include_directories(abgx360gui/src)

# Set GTK3 for wxWidgets
set(wxWidgets_CONFIG_OPTIONS --toolkit=gtk3)
# Find wxWidgets
# Note that for MinGW users the order of libs is important!
find_package(wxWidgets REQUIRED net gl core base adv)
include(${wxWidgets_USE_FILE})

# Add executable
add_executable(abgx360gui
        abgx360gui/src/abgx360gui.cpp
        abgx360gui/src/abgx360gui.h
        abgx360gui/src/abgx360guiApp.cpp
        abgx360gui/src/abgx360guiApp.h)

# Link wxWidgets deps
# and for each of your dependent executable/library targets:
target_link_libraries(abgx360gui ${wxWidgets_LIBRARIES})
