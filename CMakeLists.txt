cmake_minimum_required(VERSION 3.20)

project(Pokedex)

add_executable(${PROJECT_NAME} source/main.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES
   CXX_STANDARD 20
   CXX_STANDARD_REQUIRED TRUE)

target_compile_options(${PROJECT_NAME} PRIVATE
   $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic -Werror>
   $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>)

include(FetchContent)

fetchcontent_declare(FroncuJSON
   GIT_REPOSITORY https://github.com/Froncu/FroncuJSON
   GIT_TAG main)
fetchcontent_makeavailable(FroncuJSON)
target_link_libraries(${PROJECT_NAME} PRIVATE FroncuJSON)

add_custom_command(
   TARGET ${PROJECT_NAME} POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
   ${CMAKE_SOURCE_DIR}/content
   $<TARGET_FILE_DIR:${PROJECT_NAME}>/content)