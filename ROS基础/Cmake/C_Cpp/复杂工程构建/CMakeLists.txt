# 复杂工程的CMake编译链模板

# 1、指定构建项目，所需最低的CMake 版本
cmake_minimum_required(VERSION 3.0)


# 2、命名工程 Blackhole
project(Blackhole)

# 3、第三方库
# imgui 为 第三方库名称，REQUIRED 表示 必须找到
# 需要确保pc系统中已经安装好了第三方库，一般支持CMake构建
find_package(imgui REQUIRED) //查找imgui库

# 4、调用 file GLOB 命令，通过通配符 匹配所有的C++源文件
# 将匹配到的文件保存在变量 SRC_FILES 中
file(GLOB SRC_FILES
  "${PROJECT_SOURCE_DIR}/src/*.h"
  "${PROJECT_SOURCE_DIR}/src/*.cpp"
  "${PROJECT_SOURCE_DIR}/src/*.c"
  "${PROJECT_SOURCE_DIR}/src/*.cc"
)


#构建可执行文件，指定源文件列表
#第一个参数是工程文件的 name 这里的CMAKE_PROJECT_NAME 是一个宏指向Blackhole
#第二个参数是匹配的源文件列表
add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES})



#  5、添加库文件（链接库）
#  如果忘记链接库，error：unresolved external symbol_*  未定义的符号
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE imgui::imgui) #链接imgui库


# 6、打开C++17标准支持，target_compile_features()
target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17)

# 7、添加自定义命令，将assets目录下的所有文件复制到构建目录
add_custom_command(
  TARGET ${CMAKE_PROJECT_NAME}
  POST_BUILD   #构建完成后执行
  # 利用CMake命令，复制assets目录下的所有文件到构建目录
  COMMAND ${CMAKE_COMMAND} -E copy_directory
          "${PROJECT_SOURCE_DIR}/assets"
          "$<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/assets"
)
