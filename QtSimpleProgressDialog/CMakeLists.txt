
project( subA VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets LinguistTools)


add_definitions( -DQTSIMPLEPROGRESSDIALOG_LIBRARY )

# 如果想生成动态库，使用下面的语句
add_library(QtSimpleProgressDialog SHARED
#    qtcustomprogressdialog.cpp
 qtcustomprogressdialog.cpp
 qtcustomprogressdialog.h
qtsimpleprogressdialog.cpp
qtsimpleprogressdialog.h
qtsimpleprogressdialog_global.h
)
target_include_directories(QtSimpleProgressDialog PRIVATE  ${CMAKE_SOURCE_DIR}/QtSimpleProgressDialog/include)
set_target_properties(QtSimpleProgressDialog PROPERTIES PUBLIC_HEADER ${CMAKE_SOURCE_DIR}/QtSimpleProgressDialog/QtSimpleProgressDialog.h)

target_link_libraries(QtSimpleProgressDialog PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(QtSimpleProgressDialog PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)




#//---MyMath---------------------------------------------
# 写入库的版本信息

write_basic_package_version_file(
    QtSimpleProgressDialogConfigVersion.cmake
    VERSION ${PACKAGE_VERSION}
    COMPATIBILITY AnyNewerVersion
)

# 将库文件，可执行文件，头文件安装到指定目录
install(TARGETS QtSimpleProgressDialog
    EXPORT QtSimpleProgressDialogTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    PUBLIC_HEADER DESTINATION include
)

# 将库的相关信息输出为MyMathConfig.cmake，供find_package查找
install(EXPORT QtSimpleProgressDialogTargets
    FILE QtSimpleProgressDialogTargets.cmake
    NAMESPACE QtSimpleProgressDialog::
    DESTINATION lib/cmake/QtSimpleProgressDialog
)

configure_file( QtSimpleProgressDialogConfig.cmake.in
    QtSimpleProgressDialog/QtSimpleProgressDialogConfig.cmake @ONLY)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/QtSimpleProgressDialog/QtSimpleProgressDialogConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/QtSimpleProgressDialogConfigVersion.cmake"
    DESTINATION lib/cmake/QtSimpleProgressDialog
)


message( "{QtSimpleProgressDialog_INCLUDE_DIRS} = ${QtSimpleProgressDialog_INCLUDE_DIRS}"  )
message( "{INTERFACE_INCLUDE_DIRECTORIES} = ${INTERFACE_INCLUDE_DIRECTORIES}"  )

