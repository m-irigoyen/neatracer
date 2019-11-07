#------------------------------------------#
#           NeatRacer Core                  #
#------------------------------------------#

cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 17)

#---------- CREATING LIBRARY -------------
SET(MMGTMPL_CORE_LIB_NAME "core")

#headers
FILE(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)
# source files
FILE(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/sources/*.cpp)

# Create library target
add_library(${MMGTMPL_CORE_LIB_NAME} ${SOURCES} ${HEADERS})

# Setting include files in target
target_include_directories(${MMGTMPL_CORE_LIB_NAME}
    PUBLIC
        #$<INSTALL_INTERFACE:include>	# No install interface, adcore is built statically
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/sources
)
target_compile_definitions(${MMGTMPL_CORE_LIB_NAME} PUBLIC MMECPP_USE_SFML)

target_link_libraries(${MMGTMPL_CORE_LIB_NAME}
	# Third parties
	"yaml-cpp"
	# Shared libraries
	"mme"
	"mmecpp"
	"sfmlutils")
	
set_target_properties(${MMGTMPL_CORE_LIB_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
set_target_properties(${MMGTMPL_CORE_LIB_NAME} PROPERTIES FOLDER NeatRacer)

# Source grouping
SET(F_H "Headers")
SET(F_S "Sources")
SET(SOURCE_GROUP_DELIMITER "/")
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/include PREFIX ${F_H} FILES ${HEADERS})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/sources PREFIX ${F_S} FILES ${SOURCES})

