cmake_minimum_required(VERSION 3.15)
project(LinAlg VERSION 1.0.0 LANGUAGES CXX)

# ===========================
# Clangd / Neovim integration
# ===========================
# Generate compile_commands.json so clangd knows include paths
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ===========================
# Header-only library setup
# ===========================
add_library(LinAlg INTERFACE)

# Expose include directories to dependents
target_include_directories(LinAlg
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_features(LinAlg INTERFACE cxx_std_20)

# ===========================
# Example executable
# ===========================
add_executable(test test.cpp)
target_link_libraries(test PRIVATE LinAlg)

# ===========================
# Installation
# ===========================
include(CMakePackageConfigHelpers)

# Install headers
install(
  DIRECTORY include/
  DESTINATION include
)

# Install the header-only target
install(
  TARGETS LinAlg
  EXPORT LinAlgTargets
)

# Create and install the CMake package config
install(
  EXPORT LinAlgTargets
  FILE LinAlgConfig.cmake
  NAMESPACE LinAlg::
  DESTINATION lib/cmake/LinAlg
)

# Create a version file (for find_package compatibility)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/LinAlgConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY AnyNewerVersion
)

install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/LinAlgConfigVersion.cmake"
  DESTINATION lib/cmake/LinAlg
)

# ===========================
# Optional summary output
# ===========================
message(STATUS "LinAlg header-only library configured!")
message(STATUS "To install:   sudo cmake --install build")
message(STATUS "To include:   #include <LinAlg.hpp>")

