cmake_minimum_required(VERSION 3.11...3.21)

project(app 
            VERSION 1.0
            DESCRIPTION "top business entry")

# 依赖模块
if(NOT DEFINED CJSON_DEPEND_DIR)
    set(CJSON_DEPEND_DIR "/home/buliangd/work/code/dev/test/cmake/Modern2/components/common/cjson")
    add_subdirectory(${CJSON_DEPEND_DIR} ${CJSON_DEPEND_DIR}/build)
endif()
if(NOT DEFINED CLI_DEPEND_DIR)
    set(CLI_DEPEND_DIR "/home/buliangd/work/code/dev/test/cmake/Modern2/components/common/cli")
    add_subdirectory(${CLI_DEPEND_DIR} ${CLI_DEPEND_DIR}/build)
endif()
if(NOT DEFINED UPG_DEPEND_DIR)
    set(UPG_DEPEND_DIR "/home/buliangd/work/code/dev/test/cmake/Modern2/components/module/upg")
    add_subdirectory(${UPG_DEPEND_DIR} ${UPG_DEPEND_DIR}/build)
endif()
if(NOT DEFINED WORK_DEPEND_DIR)
    set(WORK_DEPEND_DIR "/home/buliangd/work/code/dev/test/cmake/Modern2/components/business/work")
    add_subdirectory(${WORK_DEPEND_DIR} ${WORK_DEPEND_DIR}/build)
endif()
if(NOT DEFINED MOVE_DEPEND_DIR)
    set(MOVE_DEPEND_DIR "/home/buliangd/work/code/dev/test/cmake/Modern2/components/business/move")
    add_subdirectory(${MOVE_DEPEND_DIR} ${MOVE_DEPEND_DIR}/build)
endif()

############      Product Code Build      ############
# 可执行程序
add_executable(${PROJECT_NAME})
target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include> #同一构建环境下或者export导出时有效
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src
)
target_link_libraries(${PROJECT_NAME} cjson cli upg work move)
aux_source_directory(./src DIR_SRCS)
set_target_properties(${PROJECT_NAME}
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