cmake_minimum_required( VERSION 3.20 )

set( CPPLOGGER cpplogger )

project( Logger VERSION 1.0.0 LANGUAGES CXX )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED True )
option( BUILD_CPPLOGGER_TESTS "Build CPPLogger Unit Tests" OFF )

file( GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cxx )

add_library( ${CPPLOGGER} ${SRC_FILES} )
target_link_libraries( ${CPPLOGGER} PUBLIC ${Boost_LIBRARIES} )
target_include_directories( ${CPPLOGGER} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include )

install(
    TARGETS ${CPPLOGGER}
    LIBRARY
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cpplogger
)

install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/cpplogger
    DESTINATION include
    PATTERN "*.hxx"
)

# Expose headers for CPPLogger library to other targets
target_include_directories( ${CPPLOGGER} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

if( CODE_COVERAGE )
    set( BUILD_CPPLOGGER_TESTS ON )
    message( STATUS "Including Code Coverage" )
    set( COVERAGE_COMPILER_FLAGS "-g -fprofile-arcs -ftest-coverage" )
    set( CMAKE_CXX_FLAGS "-Wall -Wextra ${COVERAGE_COMPILER_FLAGS} ${CMAKE_CXX_FLAGS}" )
endif( CODE_COVERAGE )

if( BUILD_CPPLOGGER_TESTS )
    add_subdirectory( tests )
endif()
