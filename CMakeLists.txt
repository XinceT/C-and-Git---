# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)
# 项目信息
project (Multisum1)

include_directories(/usr/include)

find_package(Threads)
LINK_DIRECTORIES( ${PROJECT_SOURCE_DIR}/lib )
INCLUDE_DIRECTORIES(  ${PROJECT_SOURCE_DIR}/include )
# 指定生成目标
add_executable(multisim 源.c)

target_link_libraries(multisim ${CMAKE_THREAD_LIBS_INIT})