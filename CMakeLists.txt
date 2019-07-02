cmake_minimum_required(VERSION 2.8)
project(myCaPCamera)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set("OpenCV_DIR" "/home/zhaosl/local_install/opencv3.3.1/share/OpenCV/")
set("OpenCV_DIR" "/usr/local/share/OpenCV/")
#set("OpenCV_DIR" "/home/tianws/project/yuyong/opencv/share/OpenCV/")
find_package( OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})
MESSAGE("OpenCV vesion: ${OpenCV_VERSION}")

set(PROJECT_ROOT ".")
include_directories(${PROJECT_ROOT}/include)
set(MODULE_SRC_ROOT ${PROJECT_ROOT}/src/)

file(GLOB src_cap_files ${MODULE_SRC_ROOT}/capImage.cpp)
add_executable(myCapCamera ${src_cap_files})
target_link_libraries(myCapCamera ${OpenCV_LIBS} )

file(GLOB src_capWithStamp_files ${MODULE_SRC_ROOT}/capImageWithStamp.cpp)
add_executable(myCapCameraWithStamp ${src_capWithStamp_files})
target_link_libraries(myCapCameraWithStamp ${OpenCV_LIBS} )

file(GLOB src_png_files ${MODULE_SRC_ROOT}/readVideoToPng.cpp)
add_executable(myreadVideoToPng ${src_png_files})
target_link_libraries(myreadVideoToPng ${OpenCV_LIBS} )

file(GLOB src_timer_files ${MODULE_SRC_ROOT}/timer.cpp)
add_executable(myTimer ${src_timer_files})
target_link_libraries(myTimer ${OpenCV_LIBS} )

file(GLOB src_capImage640_480_files ${MODULE_SRC_ROOT}/capImage640_480.cpp)
add_executable(myCapImage640_480 ${src_capImage640_480_files})
target_link_libraries(myCapImage640_480 ${OpenCV_LIBS} )


file(GLOB src_cap_files ${MODULE_SRC_ROOT}/capImage2.cpp)
add_executable(myCapCamera2 ${src_cap_files})
target_link_libraries(myCapCamera2 ${OpenCV_LIBS} )

file(GLOB src_png_files ${MODULE_SRC_ROOT}/readVideoToPng2.cpp)
add_executable(myreadVideoToPng2 ${src_png_files})
target_link_libraries(myreadVideoToPng2 ${OpenCV_LIBS} )
