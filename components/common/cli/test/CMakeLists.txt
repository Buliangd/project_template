# 检查测试框架路径是否传入
## TODO 改成库形式或目标形式传入，减少编译时间
set(TEST_FRAMEWORK_DIR "/home/buliangd/work/code/dev/test/cmake/Modern2/tools/googletest")

message(STATUS "test_framework_dir: ${TEST_FRAMEWORK_DIR}")
if(NOT IS_DIRECTORY ${TEST_FRAMEWORK_DIR})
    message(FATAL_ERROR "can not find test_framework(gtest)")
endif()

# 添加测试框架
if (NOT DEFINED GTEST_INCLUDED)
    message(STATUS "include googletest")
    add_subdirectory(${TEST_FRAMEWORK_DIR} ${CMAKE_BINARY_DIR}/testwork)
    set(GTEST_INCLUDED ON CACHE BOOL "chain include gtest flag" FORCE)
endif()

# 生成测试程序

set(TEST_EXEC "test_${PROJECT_NAME}")
message(STATUS "test_exec: ${TEST_EXEC}")
message(STATUS "PROJECT_NAME: ${PROJECT_NAME}")

aux_source_directory(../src DIR_PRODUCT_SRCS)
aux_source_directory(. DIR_TEST_SRCS)
add_executable(${TEST_EXEC}
        ${DIR_PRODUCT_SRCS}
        ${DIR_TEST_SRCS}
)
target_link_libraries(
        ${TEST_EXEC}
        gtest gmock gtest_main cjson
)
target_include_directories(
        ${TEST_EXEC}
        PRIVATE ../src
        PUBLIC ../include
)

# ctest识别测试用例
enable_testing()
include(${CMAKE_ROOT}/Modules/GoogleTest.cmake)
gtest_discover_tests(${TEST_EXEC})
