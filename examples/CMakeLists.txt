if(HPX_ROOT)
    #set(HPX_DIR "${HPX_ROOT}/lib/cmake/HPX")
    include_directories(${HPX_ROOT})
endif()

include_directories(${HYPERTABLE_INCLUDE_DIRS})

add_hpx_executable(example SOURCES example.cpp DEPENDENCIES ${HYPERTABLE_INCLUDE_DIR} ${HYPERTABLE_CONFIG_FILE} ${HYPERTABLE_INSTALL_DIR} ${HYPER_LIB_PATHS})
