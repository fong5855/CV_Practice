# CMakeList.txt: abs 的 CMake 專案，包含來源並在此定義
# 此處為專案專屬邏輯。
#
cmake_minimum_required (VERSION 2.8)

# 將來源新增到此專案的可執行檔。
file(GLOB_RECURSE srcs ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
# add_executable (abs ${srcs})

# TODO: 新增測試，並視需要安裝目標。
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
add_library(ABSLIB SHARED ${srcs})