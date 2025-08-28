find_package(SDL3 REQUIRED)
add_executable(SDL3-Game "main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
	set_property(TARGET SDL3-Game PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(SDL3-Game PRIVATE SDL3::SDL3)