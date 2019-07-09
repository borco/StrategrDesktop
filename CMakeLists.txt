cmake_minimum_required(VERSION 3.14)
project(Strategr)

set(CMAKE_CXX_STANDARD 17)

find_package(catch2 REQUIRED)
find_package(Qt5 COMPONENTS Widgets Test REQUIRED)

include_directories(.)
include_directories(models)
include_directories(ui)
include_directories(utility)

set(MODELS
        models/activity.cpp
        models/activity.h
        models/strategy.cpp
        models/strategy.h
        models/activityinvalidpropertyexception.cpp
        models/activityinvalidpropertyexception.h
        models/activitylist.cpp
        models/activitylist.h
        models/privatelist.hpp
        models/notifiableonchange.h
        models/timeslot.cpp
        models/timeslot.h
        models/timeslotsstate.cpp
        models/timeslotsstate.h
        models/activitysessionslist.cpp
        models/activitysessionslist.h
        models/streamablelist.h
        models/activitysessionscalculator.cpp
        models/activitysessionscalculator.h
        models/strategyhistory.cpp
        models/strategyhistory.h)

set(MODELS_TESTS
        models/tests/activity_tests.cpp
        models/tests/strategy_activities_test.cpp
        models/tests/strategy_settings_test.cpp
        models/tests/strategy_timeslots_test.cpp
        models/tests/strategy_activities_slots_interaction_test.cpp
        models/tests/strategy_history_test.cpp)

set(UI
        ui/mainwindow.cpp
        ui/mainwindow.h
        ui/windowgeometrymanager.cpp
        ui/windowgeometrymanager.h
        ui/applicationmenu.cpp
        ui/applicationmenu.h ui/mainscene.cpp ui/mainscene.cpp ui/mainscene.h)

set(UTILITY
        utility/jsonserializer.cpp
        utility/jsonserializer.h
        utility/filesystemiomanager.cpp
        utility/filesystemiomanager.h
        utility/applicationsettings.h
        #        utility/notifier.cpp
        #        utility/notifier.h
        #        utility/notifierbackend.h
        )

set(UI_TESTS
        ui/tests/main_window_test.cpp utility/testutils.h)

qt5_add_resources(RESOURCES
        resources/icons.qrc
        resources/fonts.qrc)

if (APPLE)
    set(CMAKE_EXE_LINKER_FLAGS "-framework Foundation -w")
    set(PLATFORM_FILES
            utility/notifierbackend.mm)

    list(APPEND RESOURCES deployment/Strategr.icns)
endif ()

add_executable(models_tests
        tests_main.cpp
        ${MODELS}
        ${MODELS_TESTS})

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)

add_executable(Strategr
        main.cpp
        ${PLATFORM_FILES}
        ${MODELS}
        ${UI}
        ${UTILITY}
        ${RESOURCES})

add_executable(ui_tests
        qt_tests_main.cpp
        ${PLATFORM_FILES}
        ${MODELS}
        ${UI}
        ${UTILITY}
        ${UI_TESTS}
        ${RESOURCES})

target_link_libraries(models_tests Catch2::Catch2)
target_link_libraries(ui_tests
        Catch2::Catch2
        Qt5::Widgets
        Qt5::Test)

target_link_libraries(Strategr Qt5::Widgets)


# Set a custom plist file for the app bundle
set_target_properties(Strategr PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_BUNDLE_INFO_PLIST "${CMAKE_SOURCE_DIR}/deployment/Info.plist"
        RESOURCE deployment/Strategr.icns)