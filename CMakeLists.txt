cmake_minimum_required(VERSION 3.10)
project(VulnerableCppProject)

set(CMAKE_CXX_STANDARD 11)

# Add path hints for package discovery
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "/usr/lib/x86_64-linux-gnu/")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "/usr/lib/x86_64-linux-gnu/cmake/")

find_package(LibXml2 REQUIRED)
find_package(SQLite3 REQUIRED)
find_package(EXPAT REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(CURL REQUIRED)
find_package(ZLIB REQUIRED)

add_executable(vulnerable_cpp main.cpp)
target_link_libraries(vulnerable_cpp 
    OpenSSL::SSL 
    CURL::libcurl 
    ZLIB::ZLIB 
    LibXml2::LibXml2 
    SQLite::SQLite3 
    EXPAT::EXPAT
)