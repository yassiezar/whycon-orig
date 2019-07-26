add_library(common OBJECT CRawImage.cpp)

target_compile_options(common PRIVATE -fPIC)

target_include_directories(common PUBLIC ${PROJECT_SOURCE_DIR}/include/whycon/)