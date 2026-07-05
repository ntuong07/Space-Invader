cmake_minimum_required(VERSION 3.19)
project(Space LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Multimedia)

qt_standard_project_setup()

qt_add_executable(Space
    MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    gui.cpp
    gui.h
    draw.cpp
    draw.h
    player.cpp
    player.h
    bullet.cpp
    bullet.h
    enemy.cpp
    enemy.h
    collision.cpp
    collision.h
    file.cpp
    file.h
    sound.cpp
    sound.h
    utils.cpp
    utils.h
)

target_link_libraries(Space
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Multimedia
)

install(TARGETS Space
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Space
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})