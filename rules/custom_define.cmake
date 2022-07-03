macro(default_custom_define)
    set(CUSTOM_COMPONENTS_DIR "/home/buliangd/work/code/dev/test/cmake/Modern2/components" 
                                CACHE PATH "custom define: indicate components directory")

    set(CUSTOM_UTIL_FUNCTION_FILE "/home/buliangd/work/code/dev/test/cmake/Modern2/rules/functions.cmake"
                                CACHE FILEPATH "custom define: indicate util function cmake file")

    set(CUSTOM_OUTPUT_RESULTS OFF CACHE BOOL "custom define: indicate enable/disable output result(lib + header)")
    set(CUSTOM_SHARED_LIB_DIR "/home/buliangd/work/code/dev/test/cmake/Modern2/output/lib"
                                CACHE PATH "custom define: indicate components share libraries output directory")
    set(CUSTOM_STATIC_LIB_DIR "/home/buliangd/work/code/dev/test/cmake/Modern2/output/lib"
                                CACHE PATH "custom define: indicate components static libraries output directory")
    set(CUSTOM_INCLUDE_DIR "/home/buliangd/work/code/dev/test/cmake/Modern2/output/include"
                                CACHE PATH "custom define: indicate components header files output directory")

    set(CUSTOM_GTEST_SOURCE_DIR "/home/buliangd/work/code/dev/test/cmake/Modern2/tools/googletest"
                                CACHE PATH "custom define: indicate googleest source directory")
    set(CUSTOM_FORCE_ALL_TESTING OFF CACHE BOOL "custom define: indicate enable/disable force test")
    # list使用，遍历待测试组件
    set(CUSTOM_TEST_COMPONENTS_LIST "cjson;cli;fifo" 
                                CACHE STRING "custom define: indicate components waitting test (when BUILD_TESTING=ON valid)")
endmacro()