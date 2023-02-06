cmake_minimum_required(VERSION 3.16)

# Configurate project
project(vtk_opencv_cmake_boilerplate LANGUAGES CXX)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
	set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

# Configurate CXX
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Configurate Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Libraries
find_package(VTK REQUIRED)
find_package(OPENCV REQUIRED)
message("OPENCV_LIBRARIES=========================" ${OpenCV_LIBRARIES})
find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

# Extract files
file(GLOB_RECURSE SRCS src/*.cpp)

# Make binary
add_executable(
	${CMAKE_PROJECT_NAME}
	${SRCS}
	main.cpp
)

# Linking
target_link_libraries(
	${CMAKE_PROJECT_NAME}
	PUBLIC
	Qt5::Core
	Qt5::Widgets
	${VTK_LIBRARIES}
	${OpenCV_LIBRARIES}
)

#	${OPENCV_LIBRARIES}

target_include_directories(
	${CMAKE_PROJECT_NAME}
	PRIVATE
	${CMAKE_SOURCE_DIR}/src
)
