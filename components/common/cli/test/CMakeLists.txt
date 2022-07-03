# 检查测试框架路径是否传入
if(NOT IS_DIRECTORY ${CUSTOM_GTEST_SOURCE_DIR})
    message(FATAL_ERROR "can not find gtest source dir or is not directory: ${CUSTOM_GTEST_SOURCE_DIR}")
endif()

# 添加测试框架
# find_package(GTest)
if (NOT DEFINED GTEST_INCLUDED)
    message(STATUS "include googletest")
    add_subdirectory(${CUSTOM_GTEST_SOURCE_DIR} ${CUSTOM_GTEST_SOURCE_DIR}/build/testwork)
    set(GTEST_INCLUDED ON CACHE BOOL "chain include gtest flag" FORCE)
endif()

# 生成测试程序
set(TEST_EXEC "test_${PROJECT_NAME}")
aux_source_directory(../src DIR_PRODUCT_SRCS)
aux_source_directory(. DIR_TEST_SRCS)
add_executable(${TEST_EXEC}
        ${DIR_PRODUCT_SRCS}
        ${DIR_TEST_SRCS}
)
target_link_libraries(
        ${TEST_EXEC}
        gtest gtest_main ${${PROJECT_NAME}_DEPEND_COMPONENTS}
)
target_include_directories(
        ${TEST_EXEC}
        PRIVATE ../src
        PUBLIC ../include
)

# 注册测试程序至ctest中
include(${CMAKE_ROOT}/Modules/GoogleTest.cmake)
gtest_discover_tests(${TEST_EXEC})
