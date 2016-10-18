# Project #-----------------------------------------------------------------------------------------
project ( tp2 )

cmake_minimum_required ( VERSION 2.8.9 )

find_package ( Threads )
include      ( gtest.cmake )

# C++ Warning Level #-------------------------------------------------------------------------------
if ( CMAKE_COMPILER_IS_GNUCXX )
 set ( CMAKE_CXX_FLAGS "-Wall -pedantic ${CMAKE_CXX_FLAGS}" )
endif()

# C++11 #-------------------------------------------------------------------------------------------
include ( CheckCXXCompilerFlag )

check_cxx_compiler_flag ( "-std=gnu++11" COMPILER_SUPPORTS_CPP11 )
check_cxx_compiler_flag ( "-std=gnu++0x" COMPILER_SUPPORTS_CPP0X )

if ( COMPILER_SUPPORTS_CPP11 )
 set ( CMAKE_CXX_FLAGS "-std=gnu++11 ${CMAKE_CXX_FLAGS}" )
elseif( COMPILER_SUPPORTS_CPP0X )
 set ( CMAKE_CXX_FLAGS "-std=gnu++0x ${CMAKE_CXX_FLAGS}" )
else ()
 message ( STATUS "Compiler ${CMAKE_CXX_COMPILER} has no C++11 support." )
endif ()

message ( STATUS "Compiler flags: ${CMAKE_CXX_FLAGS}" )

# Sources #-----------------------------------------------------------------------------------------
set ( ZZ3_HEADERS
      src/point.h
      src/cartesien.h
      src/polaire.h
      src/nuage.h
      src/cosinus.h
      src/sinus.h
      src/exponentielle.h
      src/factorielle.h
      src/puissance.h
    )

set ( ZZ3_SOURCES
      src/cartesien.cpp
      src/point.cpp
      src/polaire.cpp
      #src/nuage.cxx
    )

set ( ZZ3_HEADERS_TEST
    )

set ( ZZ3_SOURCES_TEST
    )

include_directories ( src/ )

# Executables #-------------------------------------------------------------------------------------
add_executable ( ${CMAKE_PROJECT_NAME}_metaprog
                 src/main_metaprog.cpp
                 ${ZZ3_HEADERS}
                 ${ZZ3_SOURCES}
               )

add_executable ( ${CMAKE_PROJECT_NAME}_test
                 test/${CMAKE_PROJECT_NAME}_test.hpp
                 test/${CMAKE_PROJECT_NAME}_test.cpp
                 ${ZZ3_HEADERS}
                 ${ZZ3_SOURCES}
                 ${ZZ3_HEADERS_TEST}
                 ${ZZ3_SOURCES_TEST}
               )

# Build #-------------------------------------------------------------------------------------------
set_target_properties ( ${CMAKE_PROJECT_NAME}_metaprog PROPERTIES LINKER_LANGUAGE C )
target_link_libraries ( ${CMAKE_PROJECT_NAME}_metaprog ${CMAKE_THREAD_LIBS_INIT} )

set_target_properties ( ${CMAKE_PROJECT_NAME}_test PROPERTIES LINKER_LANGUAGE C )
target_link_libraries ( ${CMAKE_PROJECT_NAME}_test ${CMAKE_THREAD_LIBS_INIT} )
add_dependencies      ( ${CMAKE_PROJECT_NAME}_test googletest )
target_link_libraries ( ${CMAKE_PROJECT_NAME}_test gtest pthread )
