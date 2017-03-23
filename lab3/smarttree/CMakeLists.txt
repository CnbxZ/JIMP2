project(smarttree)

set(CMAKE_CXX_STANDARD 14)

set(HEDEAR_FILES SmartTree.h)
set(SOURCE_FILES SmartTree.cpp)

add_library(libsmarttree STATIC ${SOURCE_FILES})
target_include_directories(libsmarttree PUBLIC .)

