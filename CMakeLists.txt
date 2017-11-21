cmake_minimum_required(VERSION 3.9)
project(TLSMessageParsing)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(STRING_ENCODING_TYPE "NONE" CACHE STRING "Set the way strings have to be encoded (ICONV|NONE|...)")
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/runtime/cpp/kaitai_struct_cpp_stl_runtime)
target_include_directories(kaitai_struct_cpp_stl_runtime INTERFACE ${CMAKE_CURRENT_LIST_DIR}/runtime/cpp/kaitai_struct_cpp_stl_runtime)

file(GLOB_RECURSE messageParsingCore_SRC
    ${CMAKE_CURRENT_LIST_DIR}/src/cpp/*.h
    ${CMAKE_CURRENT_LIST_DIR}/src/cpp/*.hpp
    ${CMAKE_CURRENT_LIST_DIR}/src/cpp/*.cpp
)

add_library(MessageParsingCore STATIC ${messageParsingCore_SRC})
target_link_libraries(MessageParsingCore kaitai_struct_cpp_stl_runtime)
target_include_directories(MessageParsingCore PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src/cpp)

file(GLOB_RECURSE messageParsingCore_test_SRC
    ${CMAKE_CURRENT_LIST_DIR}/test/cpp/*.h
    ${CMAKE_CURRENT_LIST_DIR}/test/cpp/*.hpp
    ${CMAKE_CURRENT_LIST_DIR}/test/cpp/*.cpp
)

add_executable(MessageParsingCoreTest ${messageParsingCore_test_SRC})
target_link_libraries(MessageParsingCoreTest MessageParsingCore)