
include_directories( ${CMAKE_SOURCE_DIR}/../QtSimpleProgressDialog
 ../QtSimpleProgressDialog )

# 生成可执行文件
add_executable(mymathapp
    mainwindow.ui mainwindow.cpp  mainwindow.h
    Demo.pro
    main.cpp
)

target_link_directories(mymathapp PRIVATE ${CMAKE_BINARY_DIR})
#target_link_libraries(mymathapp mymath)
target_include_directories(mymathapp PRIVATE ${CMAKE_SOURCE_DIR}/../QtSimpleProgressDialog)

target_link_libraries(mymathapp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets  QtSimpleProgressDialog )

set_target_properties(mymathapp PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# 将库文件，可执行文件，头文件安装到指定目录
install(TARGETS      mymathapp
    #    EXPORT MyMathTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    PUBLIC_HEADER DESTINATION include
)

