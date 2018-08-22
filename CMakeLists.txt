 cmake_minimum_required(VERSION 3.0)
 project(learningOpenCV)
 
 
 set(CMAKE_AUTOMOC ON)
 set(CMAKE_CURRENT_INCLUDE ON)
 
 
 find_package(OpenCV REQUIRED)
 find_package(Qt5Widgets REQUIRED)
 find_package(Qt5Core REQUIRED)
 find_package(Qt5Gui REQUIRED)
 
 set(QT_LIBS Qt5::Widgets Qt5::Core Qt5::Gui)
 
 
 file(GLOB SRC src/*.cc)
 file(GLOB HDR src/*.h)
 
 
 
 add_executable(learningOpenCV ${SRC} ${HDR})
 
 
 target_link_libraries(learningOpenCV ${Qt_LIBS})
 target_link_libraries(learningOpenCV ${OpenCV_LIBS})