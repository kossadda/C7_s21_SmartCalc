cmake_minimum_required(VERSION 3.5)

project(s21_smartcalc VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    ./s21_frontend/main.cpp
    ./s21_frontend/s21_smartcalc.cpp
    ./s21_frontend/s21_deposit.cpp
    ./s21_frontend/s21_credit.cpp
    ./s21_frontend/qcustomplot.cpp
    ./s21_frontend/my_widget.cpp
    ./s21_frontend/graphics.cpp
    ./s21_frontend/s21_credit_table.cpp
    ./s21_backend/s21_calculator/s21_calculator.c
    ./s21_backend/s21_calculator/s21_checks.c
    ./s21_backend/s21_calculator/s21_comparison.c
    ./s21_backend/s21_calculator/s21_math_operations.c
    ./s21_backend/s21_calculator/s21_notation.c
    ./s21_backend/s21_calculator/s21_unar_operation.c
    ./s21_backend/s21_credit/s21_credit.c
    ./s21_backend/s21_credit/s21_calc_payments.c
    ./s21_backend/s21_credit/s21_redemption.c
    ./s21_backend/s21_credit/s21_supporting.c
    ./s21_backend/s21_deposit/s21_deposit.c
    ./s21_backend/s21_deposit/s21_calc_deposits.c
    ./s21_backend/s21_common/s21_common.c
    ./s21_backend/s21_common/s21_calendar.c
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(s21_smartcalc
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(s21_smartcalc
        ${PROJECT_SOURCES}
    )
endif()

target_include_directories(s21_smartcalc PRIVATE
    ./s21_frontend
    ./s21_backend
)

target_link_libraries(s21_smartcalc PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

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

include(GNUInstallDirs)
install(TARGETS s21_smartcalc
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(s21_smartcalc)
endif()
