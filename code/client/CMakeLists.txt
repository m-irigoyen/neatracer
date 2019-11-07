#------------------------------------------#
#           NeatRacer Client
#------------------------------------------#

SET(EXE_NAME "neatracer_client")

# Find SFML
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

# Executable
FILE(GLOB_RECURSE GAME_SRC ${CMAKE_CURRENT_SOURCE_DIR}/sources/*.cpp)
FILE(GLOB_RECURSE GAME_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/sources/*.hpp)
FILE(GLOB_RECURSE GAME_SHADERS ${CMAKE_CURRENT_SOURCE_DIR}/shaders/*.hpp)

add_executable(${EXE_NAME} ${GAME_SRC} ${GAME_HEADERS} ${GAME_SHADERS})
target_link_libraries(${EXE_NAME}
	# Third parties
	"yaml-cpp"
	"sfml-system"
	"sfml-window"
	"sfml-graphics"
	"sfml-audio"
	# Shared libraries
	"mme"
	"mmecpp"
	"sfmlutils"
	# Game libraries
	"core"
	)
	
target_compile_definitions(${EXE_NAME} PRIVATE MMECPP_USE_SFML)

set_target_properties(${EXE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
set_target_properties(${EXE_NAME} PROPERTIES FOLDER NeatRacer)

# Resource management
setupResources(${EXE_NAME} ${CMAKE_SOURCE_DIR}/resources resources)

if (MSVC)
    setupVisualStudioWorkingDirectory(${EXE_NAME})
endif()