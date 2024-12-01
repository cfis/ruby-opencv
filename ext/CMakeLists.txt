cmake_minimum_required (VERSION 3.26)

project("ruby_opencv")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library (${CMAKE_PROJECT_NAME} SHARED)
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES PREFIX "")
#set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES SUFFIX ".so")

if (MINGW)
  target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "C:/msys64/ucrt64/include/opencv4")
  target_link_directories(${CMAKE_PROJECT_NAME} PUBLIC "C:/msys64/ucrt64/lib")
  target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC -ftemplate-backtrace-limit=0)
  target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC -Wa,-mbig-obj)
  # https://github.com/doxygen/doxygen/issues/9269#issuecomment-1094975328
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O1")

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  set(VCPKG_VERBOSE, true)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
  add_compile_definitions(-D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE)
  add_compile_definitions(CVAPI_EXPORTS)
  target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC /bigobj /utf-8)

  # The default of /EHsc crashes Ruby when calling longjmp with optimizations on (/O2)
  string(REGEX REPLACE "/EHsc" "/EHs" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${CMAKE_PROJECT_NAME})
  set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY VS_DEBUGGER_COMMAND $<$<CONFIG:DEBUG>:\$(ProjectDir))

  set(OpenCV_ROOT "${VCPKG_INSTALLED_DIR}/x64-windows/share/opencv4")

#  target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "C:/Source/vcpkg/installed/x64-windows/include")
#  target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.41.34120/include")
#  target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "C:/Program Files (x86)/Windows Kits/10/include/10.0.22621.0/ucrt")
#  target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/Llvm/lib/clang/17/include")
#  target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.6/include")
#  target_link_directories(${CMAKE_PROJECT_NAME} PUBLIC "C:/Source/vcpkg/installed/x64-windows/debug/lib")

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC -ftemplate-backtrace-limit=0)

endif ()

set(CMAKE_MESSAGE_LOG_LEVEL DEBUG)
message(DEBUG ${CMAKE_CURRENT_SOURCE_DIR})

#find_package(FFMPEG REQUIRED)
#target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${FFMPEG_INCLUDE_DIRS})
#target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE ${FFMPEG_LIBRARY_DIRS})
#target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${FFMPEG_LIBRARIES})

# Ruby
#find_package(Ruby REQUIRED)
include("../../rice/FindRuby.cmake")
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${Ruby_INCLUDE_DIR} ${Ruby_CONFIG_INCLUDE_DIR})
target_link_libraries(${CMAKE_PROJECT_NAME} ${Ruby_LIBRARY})

# OpenCv
find_package(OpenCV CONFIG REQUIRED)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${CMAKE_PROJECT_NAME} ${OpenCV_LIBS})

# Rice headers
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ".")

# Add subdirectories
add_subdirectory ("opencv2")

# Sources
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "ruby_opencv.def"
    "ruby_opencv-rb.cpp"
  )
