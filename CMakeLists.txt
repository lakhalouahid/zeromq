#*rs,*.cpp,*.h,*.c specify the minimum version of cmake
cmake_minimum_required(VERSION 3.0)


# specify the project name
project(zeromq)

# specifiy the project version
set(PROJECT_VERSION 0.1.0)

# CXX standard version
set(CMAKE_CXX_STANDARD 14)

# Build type
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)


# # CUDNN_LIBRARY_PATH
# set(CUDNN_LIBRARY_PATH /home/ublacker/projects/ex9/perception/cudnn-linux-x86_64/lib)
# set(CMAKE_PREFIX_PATH /usr/local/cuda /home/ublacker/projects/ex9/perception/libtorch /home/ublacker/projects/ex9/perception/torchvision)
set(CMAKE_PREFIX_PATH /home/ublacker/.local)

# # install pack
# set(CMAKE_INSTALL_PREFIX /home/ublacker/projects/ex9/perception/ex9/ODAT)


# find_package(CUDA REQUIRED)
# find_package(Torch REQUIRED)
# find_package(ATen REQUIRED)
# find_package(TorchVision REQUIRED)
# find_package(spdlog REQUIRED)


include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(/home/ublacker/.local/include)
link_directories(/home/ublacker/.local/lib)

# # eigen
# include_directories(/usr/include/eigen3)

# # CUDA
# include_directories(/usr/local/cuda/include)
# link_directories(/usr/local/cuda/lib64)

# # CUDNN
# include_directories(/home/ublacker/projects/ex9/perception/cudnn-linux-x86_64/include)
# link_directories(/home/ublacker/projects/ex9/perception/cudnn-linux-x86_64/lib)

# # TensorRT
# include_directories(/home/ublacker/projects/ex9/perception/TensorRT/include)
# link_directories(/home/ublacker/projects/ex9/perception/TensorRT/lib)

# # ATen
# include_directories(/home/ublacker/projects/ex9/perception/libtorch/include)
# link_directories(/home/ublacker/projects/ex9/perception/libtorch/lib)

# # TorchVision
# include_directories(/home/ublacker/projects/ex9/perception/torchvision/include)
# link_directories(/home/ublacker/projects/ex9/perception/torchvision/lib)

# # OpenCV
# include_directories(/home/ublacker/projects/ex9/perception/opencv/include/opencv4)
# link_directories(/home/ublacker/projects/ex9/perception/opencv/lib)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS} -D_MWAITXINTRIN_H_INCLUDED -Wall -Wfatal-errors -Ofast")

add_executable(server server.cpp)
target_link_libraries(server zmq)

add_executable(client client.cpp)
target_link_libraries(client zmq)
