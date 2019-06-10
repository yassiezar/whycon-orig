add_library(imageproc OBJECT CNecklace.cpp sysmat.cpp CNecklace.cpp CTransformation.cpp CCircleDetect.cpp)

target_compile_options(imageproc PRIVATE -fPIC)

target_include_directories(imageproc PRIVATE ${PROJECT_SOURCE_DIR}/include/)
