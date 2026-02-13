cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME Cattle_ingredients_base) 			 # задать значение PROJECT_NAME	
# set(CMAKE_INSTALL_PREFIX ".." CACHE PATH "Installation directory")	 
project("${PROJECT_NAME}")           # установить имя проекта

set(CMAKE_CXX_STANDARD 20)			 # устанавливаем 17 стандарт языка

# Сказать программе, что должен быть исполняемый файл
add_library("${PROJECT_NAME}" STATIC Cattle_ingredients_base.cpp Cattle_ingredients_base.hpp Potion.cpp Potion.hpp)

target_include_directories("${PROJECT_NAME}" PUBLIC "./")
