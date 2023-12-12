cmake_minimum_required(VERSION 3.11)

project(DispatchWindow CXX)
set(CMAKE_CXX_STANDARD 17)

set(BOOST_DIR CACHE STRING "Boost root directory, e.g. path to your boost_1_83_0/ directory")
set(LIBS_DIR "${CMAKE_SOURCE_DIR}/../libs")
message(STATUS "Libraries directory is ${LIBS_DIR}")

if (NOT BOOST_DIR AND CMAKE_SYSTEM_NAME MATCHES "Windows")
    message(FATAL_ERROR "Please, specify Boost root directory via -DBOOST_DIR=<dir>")
endif()

if (CMAKE_SYSTEM_NAME MATCHES "Windows")
    message(STATUS "Boost root directory is ${BOOST_DIR}, change via -DBOOST_DIR=<dir>")

    set(Boost_INCLUDE_DIR ${BOOST_DIR})
    set(Boost_LOG_LIBRARY ${BOOST_DIR}/stage/lib)
    set(Boost_LOG_SETUP_LIBRARY ${BOOST_DIR}/stage/lib)
    set(Boost_FILESYSTEM_LIBRARY ${BOOST_DIR}/stage/lib)
    set(Boost_THREAD_LIBRARY ${BOOST_DIR}/stage/lib)
    set(Boost_REGEX_LIBRARY ${BOOST_DIR}/stage/lib)
    set(Boost_CHRONO_LIBRARY ${BOOST_DIR}/stage/lib)
    set(Boost_ATOMIC_LIBRARY ${BOOST_DIR}/stage/lib)
endif()

set(MENU gui/menu.h gui/menu.cpp)
set(LABELS gui/label_base.h gui/text_label.h gui/text_label.cpp gui/coords.h gui/coords.cpp gui/fps.h gui/fps.cpp gui/stamp.h gui/stamp.cpp)
set(CANVAS gui/canvas.h gui/canvas.cpp)
set(SEPARATOR gui/separator.h gui/separator.cpp)
set(GUI ${MENU} ${LABELS} ${CANVAS} ${SEPARATOR})

set(EVENT_HANDLER event_handler.h event_handler.cpp)

set(OBJECTS objects/plane.h objects/plane.cpp)

set(UTILS ../utils/log_handler.h)

set(CONST global_parameters.h)

find_package(Boost 1.83.0 REQUIRED COMPONENTS log_setup log)

add_executable(main main.cpp ${GUI} ${EVENT_HANDLER} ${OBJECTS} ${UTILS} ${CONST})

if (CMAKE_SYSTEM_NAME MATCHES "Windows")
    target_include_directories(main PUBLIC "${LIBS_DIR}/LIBSFML/win64/include")
    target_include_directories(main PUBLIC "${LIBS_DIR}/LIBTGUI/win64/include")
    target_include_directories(main PUBLIC ${Boost_INCLUDE_DIR})

    target_link_libraries(main "${LIBS_DIR}/LIBSFML/win64/lib/libsfml-graphics.a")
    target_link_libraries(main "${LIBS_DIR}/LIBSFML/win64/lib/libsfml-window.a")
    target_link_libraries(main "${LIBS_DIR}/LIBSFML/win64/lib/libsfml-system.a")
    target_link_libraries(main "${LIBS_DIR}/LIBTGUI/win64/lib/libtgui.a")
    target_link_libraries(main "${Boost_LOG_LIBRARY}/libboost_log-mgw13-mt-x64-1_83.a")
    target_link_libraries(main "${Boost_LOG_SETUP_LIBRARY}/libboost_log_setup-mgw13-mt-x64-1_83.a")
    target_link_libraries(main "${Boost_FILESYSTEM_LIBRARY}/libboost_filesystem-mgw13-mt-x64-1_83.a")
    target_link_libraries(main "${Boost_THREAD_LIBRARY}/libboost_thread-mgw13-mt-x64-1_83.a")
    target_link_libraries(main "${Boost_REGEX_LIBRARY}/libboost_regex-mgw13-mt-x64-1_83.a")
    target_link_libraries(main "${Boost_CHRONO_LIBRARY}/libboost_chrono-mgw13-mt-x64-1_83.a")
    target_link_libraries(main "${Boost_ATOMIC_LIBRARY}/libboost_atomic-mgw13-mt-x64-1_83.a")

    set(SFML_DLL_PATH "${LIBS_DIR}/LIBSFML/win64/bin")
    set(TGUI_DLL_PATH "${LIBS_DIR}/LIBTGUI/win64/bin")

    add_custom_command(TARGET main POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory "${SFML_DLL_PATH}" $<TARGET_FILE_DIR:main>)
    add_custom_command(TARGET main POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory "${TGUI_DLL_PATH}" $<TARGET_FILE_DIR:main>)

else()
    target_include_directories(main PUBLIC "${LIBS_DIR}/LIBSFML/osx/include")
    target_include_directories(main PUBLIC "${LIBS_DIR}/LIBTGUI/osx/include")

    target_link_libraries(main "${LIBS_DIR}/LIBSFML/osx/lib/libsfml-graphics.dylib")
    target_link_libraries(main "${LIBS_DIR}/LIBSFML/osx/lib/libsfml-window.dylib")
    target_link_libraries(main "${LIBS_DIR}/LIBSFML/osx/lib/libsfml-system.dylib")
    target_link_libraries(main "${LIBS_DIR}/LIBTGUI/osx/lib/libtgui.dylib")
    target_link_libraries(main ${Boost_LIBRARIES})
endif()

