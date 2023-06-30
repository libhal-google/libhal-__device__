# Copyright 2023 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.15)

project(libhal-__device__ VERSION 0.0.1 LANGUAGES CXX)

find_package(libhal REQUIRED CONFIG)
find_package(libhal-util REQUIRED CONFIG)

add_library(libhal-__device__ src/__device__.cpp)

target_include_directories(libhal-__device__ PUBLIC include)
target_compile_features(libhal-__device__ PRIVATE cxx_std_20)
target_compile_options(libhal-__device__ PRIVATE -Wall -Wextra)
target_link_libraries(libhal-__device__ PRIVATE
  libhal::libhal
  libhal::util
)

if(NOT BUILD_TESTING STREQUAL OFF)
  add_subdirectory(tests)
endif()

install(TARGETS libhal-__device__)
