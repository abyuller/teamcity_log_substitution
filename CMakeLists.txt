# CMakeList.txt: проект CMake для tclog_sed; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 2.8.12)

project(tclog_sed CXX)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (tclog_sed "tclog_sed.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
