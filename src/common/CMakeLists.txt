add_library(common OBJECT CRawImage.cpp)

target_compile_options(common PRIVATE -fPIC)
