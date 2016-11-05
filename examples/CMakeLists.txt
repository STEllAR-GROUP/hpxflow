add_hpx_executable(example SOURCES example.cpp COMPONENT_DEPENDENCIES libhpxflow)

#add_hpx_executable(example SOURCES example.cpp DEPENDENCIES ${HYPERTABLE_INCLUDE_DIR} ${HYPERTABLE_CONFIG_FILE} ${HYPERTABLE_INSTALL_DIR} ${HYPER_LIB_PATHS})
