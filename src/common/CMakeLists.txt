add_library(common OBJECT cmath.cpp CPoint.cpp CPosition.cpp CRawImage.cpp)

target_compile_options(common PRIVATE -fPIC)

target_include_directories(common PUBLIC ${PROJECT_SOURCE_DIR}/include/)
