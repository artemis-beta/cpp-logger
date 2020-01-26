cmake_minimum_required (VERSION 3.10)

execute_process(COMMAND which g++
                OUTPUT_VARIABLE CXX_LOC)

set( BOOST $ENV{BOOSTINCLUDE} )
project( Logger )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -c")
set( CMAKE_CXX_STANDARD 17 )

set( CMAKE_GENERATOR ${CXX_LOC})

set( LOGGER_FILES LoggerGlobal.cxx Logger.cxx )

add_executable( ${PROJECT_NAME} ${LOGGER_FILES} )
target_link_libraries(${PROJECT_NAME} ${LIBS} )
target_include_directories( ${PROJECT_NAME} PUBLIC ${BOOST} )
