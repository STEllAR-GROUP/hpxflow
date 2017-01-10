add_hpx_executable(example_mapreduce SOURCES mapreduce.cpp
    COMPONENT_DEPENDENCIES  hpxflow
    DEPENDENCIES ${MYSQL_LIBRARY})
