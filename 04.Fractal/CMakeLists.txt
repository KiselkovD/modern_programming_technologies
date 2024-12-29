cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Установка стандартов компиляции
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Опции сборки
set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG")
set(CMAKE_C_FLAGS_DEBUG "-g -DDEBUG")

# Добавление исходных файлов
set(SOURCES main.c image.c fractal.c)

# Создание исполняемых файлов
add_executable(release ${SOURCES})
add_executable(debug ${SOURCES})
add_executable(debug_test test_main.c ${SOURCES})

# Установка свойств целей
set_target_properties(release PROPERTIES COMPILE_FLAGS "${CMAKE_C_FLAGS_RELEASE}")
set_target_properties(debug PROPERTIES COMPILE_FLAGS "${CMAKE_C_FLAGS_DEBUG}")
set_target_properties(debug_test PROPERTIES COMPILE_FLAGS "${CMAKE_C_FLAGS_DEBUG}")

# Удаление временных файлов при очистке
include(GNUInstallDirs)

add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} -E remove *.o *.hdrdep.bak
    COMMENT "Cleaning object files and dependency files"
)

add_custom_target(cleanall DEPENDS clean_all
    COMMAND ${CMAKE_COMMAND} -E remove release debug debug_test
    COMMAND ${CMAKE_COMMAND} -E echo > makefile.hdrdep
    COMMENT "Cleaning all build artifacts"
)

add_custom_target(mrproper DEPENDS cleanall)
