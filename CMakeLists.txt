#############################
#     NEATRACER-DEV     
#############################

cmake_minimum_required(VERSION 3.8)
# Global properties
set_property(GLOBAL PROPERTY USE_FOLDERS ON) # Visual studio doesn't use folders properly without this
set(CMAKE_CXX_STANDARD 17)

# Create project
SET(PROJECT_NAME "neatracer-dev")
Project(${PROJECT_NAME})

# Include mmgcmake
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/mmecmake")
include(helpers)


#------------ VARIABLE AND OPTIONS SETUP ---------------
# Shared libraries
set(MME_TESTS ON CACHE BOOL "Enable MME tests")

# Third parties
SET(CATCH_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/thirdparties/catch/include")
SET(YAML_CPP_BUILD_CONTRIB OFF CACHE BOOL false)
SET(YAML_CPP_BUILD_TESTS OFF CACHE BOOL false)
SET(YAML_CPP_BUILD_TOOLS OFF CACHE BOOL false)


#------------ SUBDIRECTORIES ---------------
# Adding shared libraries
add_subdirectory(shared/mmecpp)
add_subdirectory(shared/sfmlutils)
add_subdirectory(shared/mme)

# Thirdparties
add_subdirectory(thirdparties/yamlcpp)

# Gameplay libs
add_subdirectory(code/core)

# Executable
add_subdirectory(code/client)

# Game editor
# TODO This needs wxwidgets, which sucks if we want to automate builds
# add_subdirectory(code/editor)