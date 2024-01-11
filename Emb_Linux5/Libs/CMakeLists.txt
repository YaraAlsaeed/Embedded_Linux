add_library(operations STATIC add.c divide.c modulus.c multiply.c subtract.c)
target_include_directories(operations INTERFACE ${CMAKE_CURRENT_DIRECTORY}/../Includes)
