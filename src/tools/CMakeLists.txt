set (
	DPRECTOOL_SOURCES
	dprectool.cpp
	stats.cpp
	../client/canvas/aclfilter.cpp
	)

add_executable( dprectool ${DPRECTOOL_SOURCES} )
target_link_libraries( dprectool ${DPSHAREDLIB} Qt5::Core)

set (
	DPCMDTOOL_SOURCES
	drawpile-cmd.cpp
	renderer.cpp
	)

include_directories("../client")
add_executable( drawpile-cmd ${DPCMDTOOL_SOURCES} )
target_link_libraries( drawpile-cmd ${DPSHAREDLIB} ${DPCLIENTLIB} Qt5::Core)

if ( UNIX AND NOT APPLE )
	install ( TARGETS dprectool DESTINATION ${INSTALL_TARGETS_DEFAULT_ARGS} )
	install ( TARGETS drawpile-cmd DESTINATION ${INSTALL_TARGETS_DEFAULT_ARGS} )
endif ()

