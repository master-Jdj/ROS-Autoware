Cmake是一种编译器，可以自动生成编译文件，并自动编译。

-自身不带编译工具，需要安装编译工具，如g++、clang、VS、C++_Compiler
-CMake-->CMakeList.txt-->Makefile-->编译-->可执行文件

# Cmake编译流程
## 单文件 Cmake编译流程：
{
1.创建CMakeLists.txt文件
```bash
#配置项目
$ cmake -S . -B build
```
2.使用cmake命令生成Makefile文件
3.使用make命令编译生成可执行文件
```bash
#构建项目
$ cmake --build build
```
4.运行可执行文件

---删除生成的文件
}
## 复杂工程 Cmake编译流程：
{
```bash
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

```
}
## 第三方库的安装，应用需要先安装
一般来说，安装较为复杂，不同平台下安装方式不同，可参考CMake官方文档。

- windows平台安装方式：下载源文件，用命令 `$cmake -S . -B build ` 构建,指定Cmake库的路径，如：`$cmake -S . -B build -DCMAKE_PREFIX_PATH=/path/to/library `  
- linux平台：可以使用apt（包管理）安装第三方库，也可以使用vcpkg包管理器安装第三方库

**推荐 vcpkg** 是一个C++包管理器，可以自动下载第三方库，并自动编译。

### vcpkg安装第三方库
- vscode插件：在CMake配置中添加vcpkg路径即可

- 调用 vcpkg 再使用命令 `$ vcpkg install <库名>` 构建

- 命令行构建,只需指定vcpkg工具链文件路径，如：`$ cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake `
