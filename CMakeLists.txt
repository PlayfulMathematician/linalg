cmake_minimum_required(VERSION 3.15)
project(LinAlg VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(LinAlg INTERFACE)

target_include_directories(LinAlg
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_features(LinAlg INTERFACE cxx_std_20)
add_executable(test test.cpp)
target_link_libraries(test PRIVATE LinAlg)
include(CMakePackageConfigHelpers)

install(
  DIRECTORY include/
  DESTINATION include
)

install(
  TARGETS LinAlg
  EXPORT LinAlgTargets
)

install(
  EXPORT LinAlgTargets
  FILE LinAlgConfig.cmake
  NAMESPACE LinAlg::
  DESTINATION lib/cmake/LinAlg
)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/LinAlgConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY AnyNewerVersion
)

install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/LinAlgConfigVersion.cmake"
  DESTINATION lib/cmake/LinAlg
)

