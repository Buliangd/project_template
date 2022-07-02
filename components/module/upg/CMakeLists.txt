cmake_minimum_required(VERSION 3.11...3.21)

project(upg 
            VERSION 1.0
            DESCRIPTION "module components: upg")

# 依赖模块
if(NOT DEFINED CJSON_DEPEND_DIR)
    set(CJSON_DEPEND_DIR "/home/buliangd/work/code/dev/test/cmake/Modern2/components/common/cjson")
    add_subdirectory(${CJSON_DEPEND_DIR} ${CJSON_DEPEND_DIR}/build)
endif()
if(NOT DEFINED CLI_DEPEND_DIR)
    set(CLI_DEPEND_DIR "/home/buliangd/work/code/dev/test/cmake/Modern2/components/common/cli")
    add_subdirectory(${CLI_DEPEND_DIR} ${CLI_DEPEND_DIR}/build)
endif()

############      Product Code Build      ############
# 动态库
add_library(${PROJECT_NAME} SHARED)
target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include> #同一构建环境下或者export导出时有效
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src
)
target_link_libraries(${PROJECT_NAME} cjson cli)

# 静态库
add_library(${PROJECT_NAME}_a STATIC)
target_include_directories(${PROJECT_NAME}_a
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src
)
target_link_libraries(${PROJECT_NAME}_a cjson_a cli_a)

aux_source_directory(./src DIR_SRCS)
set_target_properties(${PROJECT_NAME} ${PROJECT_NAME}_a
    PROPERTIES 
        SOURCES ${DIR_SRCS}
)

# 输出生成物
if(DEFINED LIB_OUTPUT_DIR)
    message(STATUS "set lib output dir: ${LIB_OUTPUT_DIR}")
    set_target_properties(${PROJECT_NAME} ${PROJECT_NAME}_a
            PROPERTIES
            ARCHIVE_OUTPUT_DIRECTORY "${LIB_OUTPUT_DIR}"
            LIBRARY_OUTPUT_DIRECTORY "${LIB_OUTPUT_DIR}"
            RUNTIME_OUTPUT_DIRECTORY "${LIB_OUTPUT_DIR}"
            )
endif()

# 输出对外头文件
if(DEFINED INC_OUTPUT_DIR)
    message(STATUS "set inc output dir: ${INC_OUTPUT_DIR}")
    # 暂时通过手动拷贝的方式 将对外头文件拷贝到指定目录下
    file(COPY ${PROJECT_SOURCE_DIR}/include/ DESTINATION ${INC_OUTPUT_DIR}/${PROJECT_NAME})
endif()

############      Test Code Build      ############
if(BUILD_TESTING)
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/test)
endif()