# The cmake version - preferably = `cmake --version`
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

# The name of our program
PROJECT(helloworld VERSION 0.1)

# Set some variables for later use or
# include inside the binaries
SET(AUTHOR "Gilles Trenson")

# Add an optional "Goodbye"
OPTION(USE_GOODBYE "Say goodbye" ON)

# Configure a header that will be used
# to insert the version number indide our
# program and possibly other vars as well
CONFIGURE_FILE(hello.h.in hello.h)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# If option goodbye is set
IF(USE_GOODBYE)
    # Add a library in a subfolder
    ADD_SUBDIRECTORY(goodbye)
    # Append the name of the library to a list
    list(APPEND EXTRA_LIBS goodbye)
    # Append the location of the header files of the library
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/goodbye")
ENDIF()

# Add out executable - using variables to 
# refer to our ${PROJECT_NAME}
ADD_EXECUTABLE(${PROJECT_NAME} hello.cpp)

# Add the location src files
TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC
    ${EXTRA_LIBS}
)

# The configure file will be read in the 
# binary tree, that's why we need to add the
# directory for Linker - should only be 
# available to the current target!
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC
    "${PROJECT_BINARY_DIR}"
    ${EXTRA_INCLUDES}
)

# Find packages, see available find
# modules using `cmake --help-module-list`
# and `cmake --help-module <MODULE>` to see
# which variables will be exposed