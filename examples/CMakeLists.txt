add_hpx_executable(example 
	SOURCES example.cpp
	DEPENDENCIES ${HYPERTABLE_LIBRARY} ${HYPERTABLE_INSTALL_DIR}/lib/libHyperThrift.a)
