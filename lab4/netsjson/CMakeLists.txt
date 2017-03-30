project(simplejson)

set(HEDEAR_FILES SimpleJson.h)
set(SOURCE_FILES SimpleJson.cpp Simple.cpp Simple.h)

add_library(libsimplejson STATIC ${SOURCE_FILES} Simple.cpp Simple.h)
target_include_directories(libsimplejson PUBLIC .)

add_executable(simplejson ${SOURCE_FILES} main.cpp Simple.cpp Simple.h)

target_link_libraries(simplejson libsimplejson)
