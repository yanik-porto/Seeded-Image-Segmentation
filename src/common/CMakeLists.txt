file(GLOB_RECURSE common_sources *.cpp *.cc)
file(GLOB_RECURSE common_headers *.h *.hpp)

include_directories(${external_includes})

add_library(common STATIC
        ${common_sources}
        ${common_headers}
		${common_headers_moc} 
		${common_form_headers}
)

target_link_libraries(common
					${external_libs}
					${QT_LIBRARIES}
)

#SET(seededImgSeg_SOURCES main.cpp mainwindow.cpp engine.cpp imglabel.cpp utilities.cpp)
#SET(seededImgSeg_HEADERS mainwindow.h engine.h imglabel.h utilities.h)
SET(common_FORMS
    mainwindow.ui
)					#changer pour common_FORMS




QT4_WRAP_CPP(common_HEADERS_MOC ${common_HEADERS})
#QT4_WRAP_UI(seededImgSeg_UIS_H ${seededImgSeg_UIS})


#ADD_LIBRARY(seededImgSeg_CONFIG ${seededImgSeg_HEADERS_MOC} ${seededImgSeg_FORMS_HEADERS})

#add_executable(seededImgSeg
#                 ${seededImgSeg_SRCS}
#                 ${seededImgSeg_UIS_H}
#                 )
