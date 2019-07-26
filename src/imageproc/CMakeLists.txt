#add_library(imageproc OBJECT CNecklace.cpp sysmat.cpp CNecklace.cpp CTransformation.cpp CCircleDetect.cpp)
add_library(imageproc OBJECT CNecklace.cpp)

target_compile_options(imageproc PRIVATE -fPIC)
