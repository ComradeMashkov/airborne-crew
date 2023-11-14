cmake_minimum_required(VERSION 3.11)

project(DispatchWindow CXX)
set(CMAKE_CXX_STANDARD 17)

set(LIBS_DIR CACHE STRING "All neccessary libraries directory")

if(NOT LIBS_DIR)
    message(FATAL_ERROR "Please, specify libraries directory via -DLIBS_DIR=<dir>")
endif()
message(STATUS "Libraries dir is ${LIBS_DIR}, change via -DLIBS_DIR=<dir>")

if (CMAKE_SYSTEM_NAME MATCHES "^MINGW")
    set(SYSTEM_LIBS -lstdc++)
else()
    set(SYSTEM_LIBS)
endif()

find_package(Boost 1.82.0 REQUIRED COMPONENTS log_setup log)

add_executable(main main.cpp event_handler.h event_handler.cpp gui/menu.h gui/menu.cpp gui/coords.h gui/coords.cpp gui/canvas.h gui/canvas.cpp gui/fps.h gui/fps.cpp objects/plane.h objects/plane.cpp ../utils/log_handler.h ../utils/log_handler.cpp)

target_include_directories(main PUBLIC "${LIBS_DIR}/LIBSFML/include")
target_include_directories(main PUBLIC "${LIBS_DIR}/LIBTGUI/include")

target_link_libraries(main "${LIBS_DIR}/LIBSFML/lib/libsfml-graphics.dylib" ${SYSTEM_LIBS})
target_link_libraries(main "${LIBS_DIR}/LIBSFML/lib/libsfml-window.dylib" ${SYSTEM_LIBS})
target_link_libraries(main "${LIBS_DIR}/LIBSFML/lib/libsfml-system.dylib" ${SYSTEM_LIBS})
target_link_libraries(main "${LIBS_DIR}/LIBTGUI/lib/libtgui.dylib" ${SYSTEM_LIBS})
target_link_libraries(main ${Boost_LIBRARIES})