function(custom_add_component target type)
    if (NOT IS_DIRECTORY ${CUSTOM_COMPONENTS_DIR})
        message(FATAL_ERROR "can not find components directory or is not directory: ${CUSTOM_COMPONENTS_DIR}")
    endif()

    if (NOT DEFINED ${target}_INCLUDED)
        add_subdirectory(${CUSTOM_COMPONENTS_DIR}/${type}/${target} ${CMAKE_BINARY_DIR}/depend/${target})
        set(${target}_INCLUDED ON CACHE BOOL "component ${target} include guard flag" FORCE)
    endif()
endfunction()

