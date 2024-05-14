cmake_minimum_required(VERSION 3.15)

project(misis2024s VERSION 1.7.3 LANGUAGES CXX) #

set(CMAKE_CXX_STANDART 11)
set(CMAKE_GENERATOR Ninja)

set(ADD_CODEFORCES 0 CACHE BOOL "Add CodeForces directory to the build")
set(BUILD_PET_PROJECT 0 CACHE BOOL "Configure only the pet project")

if (BUILD_PET_PROJECT)
	message("Building only the pet project ")
	add_subdirectory(prj.cw)
else ()
	if (ADD_CODEFORCES)
		add_subdirectory(prj.codeforces)
	endif ()
	add_subdirectory(prj.lab)
	add_subdirectory(prj.test)
endif ()
