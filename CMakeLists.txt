cmake_minimum_required(VERSION 3.16)

# Determine if insight in built at a subproject (using add_subdirectory)
# or if it is the master project.
set(MASTER_PROJECT FALSE)
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
  set(MASTER_PROJECT TRUE)
endif()

# Set the default CMAKE_BUILD_TYPE to Release.
# This should be done before the project command since the latter can set
# CMAKE_BUILD_TYPE itself (it does so for nmake).
if (MASTER_PROJECT AND NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE_STRING
    "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel."
  )
endif()

project(insight
        DESCRIPTION "Provides facilities for extracting information from Microsoft and Linux executables and shared libraries."
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS        NO)

option(INSIGHT_TEST "Generate the test target." ${MASTER_PROJECT})

# Make symbols hidden by default.
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
# Make inlined functions hidden by default.
set(CMAKE_CXX_VISIBILITY_INLINES HIDDEN TRUE)

add_subdirectory(dependencies)

add_subdirectory(src)

if (${INSIGHT_TEST})
  enable_testing()
  add_subdirectory(test)
endif()