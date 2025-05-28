# Sets the minimum CMake version
cmake_minimum_required(VERSION 3.22.1)

# vars
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(PROJECT_NAME c2bsh)

project(${PROJECT_NAME})

option(C2BSH_ANDROID "Build for Android platform" ON)

set(COMMON_SOURCE_FILES
    src/cb_log.c
    src/cb_converter.c
    src/cb_file_util.c
    src/cb_string.c
    src/cb_formatter.c)

set(COMMON_HEADER_FILES
    include/cb_log.h
    include/cb_converter.h
    include/cb_file_util.h
    include/cb_string.h
    include/cb_formatter.h
    include/cb_bool.h)

if (C2BSH_ANDROID)
  list(APPEND SOURCE_FILES src/android/android_main.c)
  list(APPEND HEADER_FILES
      include/android/android_log.h
      include/android/android_main.h)
else()
  list(APPEND SOURCE_FILES
      src/cb_main.c)
endif()

list(APPEND SOURCE_FILES ${COMMON_SOURCE_FILES})
list(APPEND HEADER_FILES ${COMMON_HEADER_FILES})

add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
add_link_options(-fsanitize=address)

# configure program
if (C2BSH_ANDROID)
  add_library(${PROJECT_NAME}
      SHARED
      ${SOURCE_FILES}
      ${HEADER_FILES})
else()
  add_executable(${PROJECT_NAME}
      ${SOURCE_FILES}
      ${HEADER_FILES})
endif()

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

if (C2BSH_ANDROID)
  target_compile_definitions(${PROJECT_NAME}
      PUBLIC
      C2BSH_ANDROID)
endif()

if (C2BSH_ANDROID)
  find_library(log-lib
      log)

  target_link_libraries(${PROJECT_NAME}
      ${log-lib})
endif()