
project(dde-wloutput-daemon)

set(TARGET_NAME dde-wloutput-daemon)
FILE(GLOB SC_FILES "*.cpp" "*.h")

add_executable(${TARGET_NAME} ${SC_FILES})

find_package(KF5Wayland REQUIRED)
# Find the library
find_package(PkgConfig REQUIRED)
find_package(Qt5 COMPONENTS
    Core
    DBus
REQUIRED)

target_link_libraries(${TARGET_NAME}  Qt5::Core Qt5::DBus)
target_link_libraries(${TARGET_NAME} KF5::WaylandClient KF5::WaylandServer)
