cmake_minimum_required(VERSION 3.1)
project(mycalculator	VERSION		1.0
			DESCRIPTION	"calculator"
			LANGUAGES	C)
			
add_executable(${PROJECT_NAME} main.c)
target_include_directories(${PROJECT_NAME} INTERFACE ./Includes)
add_subdirectory(./Libs)
target_link_libraries(${PROJECT_NAME} PRIVATE operations)
			
