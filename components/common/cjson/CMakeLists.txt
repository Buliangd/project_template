cmake_minimum_required(VERSION 3.11...3.21)

project(cjson
            VERSION 0.0.1
            DESCRIPTION "common components: cjson")

# 导入用户变量默认配置
set(CUSTOM_DEFINE_FILE "/home/buliangd/work/code/dev/test/cmake/Modern2/rules/custom_define.cmake"
                    CACHE FILEPATH "default custom define file")
include(${CUSTOM_DEFINE_FILE})
default_custom_define()

# 导入函数
include(${CUSTOM_UTIL_FUNCTION_FILE})

# 使能ctest测试框架
enable_testing()


############      Product Code Build      ############
# 动态库
add_library(${PROJECT_NAME} SHARED)
target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include> #同一构建环境下或者export导出时有效
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src
)

# 静态库
add_library(${PROJECT_NAME}_a STATIC)
target_include_directories(${PROJECT_NAME}_a
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src
)

aux_source_directory(./src DIR_SRCS)
set_target_properties(${PROJECT_NAME} ${PROJECT_NAME}_a
    PROPERTIES 
        SOURCES ${DIR_SRCS}
)

# 输出生成物（库文件+头文件）
if(${CUSTOM_OUTPUT_RESULTS})
    set_target_properties(${PROJECT_NAME} ${PROJECT_NAME}_a
        PROPERTIES
            ARCHIVE_OUTPUT_DIRECTORY "${CUSTOM_STATIC_LIB_DIR}"
            LIBRARY_OUTPUT_DIRECTORY "${CUSTOM_SHARED_LIB_DIR}"
            RUNTIME_OUTPUT_DIRECTORY "${CUSTOM_SHARED_LIB_DIR}"
    )
    file(COPY ${PROJECT_SOURCE_DIR}/include/ DESTINATION ${CUSTOM_INCLUDE_DIR}/${PROJECT_NAME})
endif()

############      Test Code Build      ############
if((CUSTOM_FORCE_ALL_TESTING) 
    OR ((BUILD_TESTING) 
        AND (${PROJECT_NAME} IN_LIST CUSTOM_TEST_COMPONENTS_LIST)))
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/test)
endif()