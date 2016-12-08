add_hpx_executable(example SOURCES example.cpp
    COMPONENT_DEPENDENCIES  hpxflow
    DEPENDENCIES ${MYSQL_LIBRARIES})
