cmake_minimum_required(VERSION 3.5)

project(s21_smartcalc VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(S21_SMARTCALC_LIB ${CMAKE_CURRENT_SOURCE_DIR}/s21_smartcalc.a)

set(PROJECT_SOURCES
    ./gui_modules/cpp_modules/main.cpp
    ./gui_modules/cpp_modules/s21_smartcalc.cpp
    ./gui_modules/cpp_modules/s21_deposit.cpp
    ./gui_modules/cpp_modules/s21_credit.cpp
    ./gui_modules/cpp_modules/qcustomplot.cpp
    ./gui_modules/cpp_modules/my_widget.cpp
    ./gui_modules/cpp_modules/graphics.cpp
    ./gui_modules/cpp_modules/s21_credit_table.cpp
    ./resources/resource.qrc
)

set(PROJECT_HEADERS
    ./gui_modules/include/s21_smartcalc.h
    ./gui_modules/include/s21_deposit.h
    ./gui_modules/include/s21_credit.h
    ./gui_modules/include/qcustomplot.h
    ./gui_modules/include/my_widget.h
    ./gui_modules/include/graphics.h
    ./gui_modules/include/s21_credit_table.h
)

# Путь к файлам интерфейсов пользователя
set(CMAKE_AUTOUIC_SEARCH_PATHS
    ${CMAKE_CURRENT_SOURCE_DIR}/gui_modules/ui_modules
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(s21_smartcalc
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
    )
else()
    add_executable(s21_smartcalc
        ${PROJECT_SOURCES}
        ${PROJECT_HEADERS}
    )
endif()

# Добавляем директории с заголовочными файлами для сборки
target_include_directories(s21_smartcalc PRIVATE
    ./gui_modules/include
    ./modules
)

# Целевая ссылка на библиотеки Qt и вашу пользовательскую библиотеку
target_link_libraries(s21_smartcalc PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${S21_SMARTCALC_LIB})

# Устанавливаем свойства цели (для MACOSX_BUNDLE, WIN32_EXECUTABLE и т.д.)
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.s21_smartcalc)
endif()

set_target_properties(s21_smartcalc PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Устанавливаем путь установки
include(GNUInstallDirs)
install(TARGETS s21_smartcalc
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Завершаем сборку для Qt 6
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(s21_smartcalc)
endif()
