# CMakeList.txt: 最上層的 CMake 專案檔，執行全域設定
# 並在這裡包含子專案。
#
cmake_minimum_required (VERSION 3.8)

project ("abs")

# 加入子專案。
add_subdirectory ("abs")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY D:/docker/vs/abs/build/)
