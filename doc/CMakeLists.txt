
set(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/hpxflow.doxygen)
set(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/doxygen.conf)

configure_file(${doxyfile_in} ${doxyfile} @ONLY)

add_custom_target(documentation
	COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	)

