cmake_minimum_required (VERSION 3.10)

execute_process(COMMAND which g++
                OUTPUT_VARIABLE CXX_LOC)

find_package( Boost REQUIRED )

project( Logger )
set( CMAKE_CXX_STANDARD 17 )

set( CMAKE_GENERATOR ${CXX_LOC})

set( LOGGER_FILES LoggerGlobal.cxx Logger.cxx )

add_library( ${PROJECT_NAME} ${LOGGER_FILES} )
target_link_libraries( ${PROJECT_NAME} ${Boost_LIBRARIES} )
target_include_directories( ${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIRS} )
