include_directories(${PROJECT_SOURCE_DIR}/)
include_directories("../common")

include_directories(${external_includes})
#include_directories( ${OpenCV_INCLUDE_DIRS} )

# Create test executables
set(app_programs
	main)

foreach(app ${app_programs})
    add_executable(${app} ${app}.cpp ${common_HEADERS_MOC})
    target_link_libraries(${app}
                          common
                          ${external_libs}
							Qt4::QtGui
							#Qt4::QtBus
							${QT_LIBRARIES}
							${OpenCV_LIBS}
							)
	#target_link_libraries(seededImgSeg ${QT_LIBRARIES})
#Qt4::QtWidgets
endforeach()


