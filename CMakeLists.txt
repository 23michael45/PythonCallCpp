cmake_minimum_required(VERSION 2.8)
project( PythonCallCpp )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") # 添加c++11标准支持

SET(CMAKE_C_COMPILER "/usr/bin/gcc") # 默认c编译器
SET(CMAKE_CXX_COMPILER "/usr/bin/g++") # 默认c++编译器
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
set(CMAKE_Cxx_FLAGS "${CMAKE_Cxx_FLAGS} -fPIC")

SET(OUTPUTNAME "pym")
SET(PYTHONDEV_DIR "/home/michael/DevelopProj/PythonDev/Python-3.6.7/")
SET(PYBIND11_DIR "/home/michael/DevelopProj/pybind11/pybind11/")
SET(OPENCV_DIR "/home/michael/DevelopProj/OpenCV3.4.0/opencv-3.4.0/") #opencv dir
SET(SYS_DIR "/usr/include/x86_64-linux-gnu/sys/")
find_package( OpenCV 3.4.0 REQUIRED )
find_package(Threads REQUIRED)


#add_definitions(-DUSE_DLL)
#add_definitions(-DDEBUG) # 相当于代码中 #define DEBUG
SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin") # 可执行文件输出目录


INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/include")
INCLUDE_DIRECTORIES("/usr/local/include")

INCLUDE_DIRECTORIES("/usr/local/include/python3.6m")
INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}include")

#INCLUDE_DIRECTORIES("${SYS_DIR}")
#INCLUDE_DIRECTORIES("${PYTHONDEV_DIR}Include"
#"${PYTHONDEV_DIR}PC")
#INCLUDE_DIRECTORIES("${PYBIND11_DIR}include")

#add_subdirectory("${PROJECT_SOURCE_DIR}/src")
#add_executable( main
#              ./src/main.cpp 
#              ./src/utils.cpp
#              )
add_library(${OUTPUTNAME} SHARED
      ./src/utils.cpp)
set_target_properties(${OUTPUTNAME} PROPERTIES PREFIX "")

# .SO file extension on Linux/Mac OS
set_target_properties(${OUTPUTNAME} PROPERTIES SUFFIX ".so")


link_directories("/usr/local/ibs")
message(STATUS "Opencv Libs : ${OpenCV_LIBS}")
target_link_libraries(${OUTPUTNAME} ${OpenCV_LIBS})
target_link_libraries(${OUTPUTNAME} "python3.6m")

target_link_libraries(${OUTPUTNAME} ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(${OUTPUTNAME} ${CMAKE_DL_LIBS})
target_link_libraries(${OUTPUTNAME} util)
#link_libraries("${Opencv_LIBS}")
#target_link_libraries(${ProjectName} "${OpenCV_LIBS}")
#target_link_libraries( ${ProjectName} opencv_core
#              opencv_imgcodecs
#              opencv_imgproc )
#target_link_libraries( ${ProjectName} opencv_imgcodecs )

