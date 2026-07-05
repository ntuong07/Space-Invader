include("D:/Workspace/Projects/Space-Invader/build/Desktop_Qt_6_11_1_MinGW_64_bit_Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/Space-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase;qtmultimedia")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "D:/Workspace/Projects/Space-Invader/build/Desktop_Qt_6_11_1_MinGW_64_bit_Debug/Space.exe"
    GENERATE_QT_CONF
)
