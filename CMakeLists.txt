cmake_minimum_required(VERSION 3.28)
project(oop-a10-MihaiCiorascu)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.7.1/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(oop-a10-MihaiCiorascu main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        WatchList.h
        WatchList.cpp
        FileWatchList.h
        FileWatchList.cpp

        CSVWatchList.h
        CSVWatchList.cpp

        HTMLWatchList.h
        HTMLWatchList.cpp

        Exceptions.h
        Exceptions.cpp

        Movie.h
        Movie.cpp

        MovieValidator.h
        MovieValidator.cpp

        Repository.h
        Repository.cpp

        FileRepository.h
        FileRepository.cpp

        Service.h
        Service.cpp

        UI.h
        UI.cpp

        Utils.h
        Utils.cpp

        AdminWidget.h
        AdminWidget.cpp

        UserWidget.h
        UserWidget.cpp

        movies.txt

        qcustomplot.cpp
        qcustomplot.h

        testMovie.cpp
        testMovie.h

        testRepository.cpp
        testRepository.h

        testService.cpp
        testService.h
        MovieWatchListModel.h
        Command.h)
target_link_libraries(oop-a10-MihaiCiorascu
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
