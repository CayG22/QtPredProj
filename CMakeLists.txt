cmake_minimum_required(VERSION 3.16)

project(TestHeroPage VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        HeroPage.cpp
        HeroPage.h
        HeroPage.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(TestHeroPage
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        murdock.h murdock.cpp
        herolistpage.h herolistpage.cpp herolistpage.ui
        FunctionalClasses.h
        FunctionalClasses.h
        HeroPage.h HeroPage.cpp HeroPage.ui
        hero.h hero.cpp
        ability.h ability.cpp
        crest.h crest.cpp
        Resources.qrc
        crestlistpage.h crestlistpage.cpp crestlistpage.ui
        item.h item.cpp
        itemlistpage.h itemlistpage.cpp itemlistpage.ui
        crestpage.h crestpage.cpp crestpage.ui
        active.h active.cpp



    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET TestHeroPage APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(TestHeroPage SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(TestHeroPage
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(TestHeroPage PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.TestHeroPage)
endif()
set_target_properties(TestHeroPage PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS TestHeroPage
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(TestHeroPage)
endif()
