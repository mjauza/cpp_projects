# CMakeList.txt : CMake project for MC_example, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("MC_example")

# Add source to this project's executable.
add_executable (MC_example "MC_example.cpp" "MC_example.h" "sim_func.cpp" "sim_func.h" "pricing_fun.cpp" "pricing_fun.h" "intergral_fun.cpp" "integral_fun.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MC_example PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
include("C:/vcpkg/vcpkg/scripts/buildsystems/vcpkg.cmake")
find_package(xtensor REQUIRED)
target_link_libraries(MC_example PUBLIC xtensor)

install (TARGETS MC_example DESTINATION "MC_example/bin")