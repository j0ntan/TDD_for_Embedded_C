add_library(RuntimeErrorStub STATIC RuntimeErrorStub.c)
target_include_directories(RuntimeErrorStub PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
