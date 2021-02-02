cmake_minimum_required(VERSION 3.5)

project(DatasetLabelConvert LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ==== Files  ==== #
aux_source_directory(. SRC_LIST)
include_directories(.)
file(GLOB HEADER_FILES "*.h")
aux_source_directory(src SRC_LIST)
include_directories(src)
file(GLOB HEADER_FILES "src/*.h")
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SRC_LIST})
find_package(OpenCV REQUIRED )
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} -lboost_system -lboost_filesystem -lboost_thread)
