file(GLOB_RECURSE SRC_FILES "*.cpp")

add_executable(MyGameProject ${SRC_FILES})

target_include_directories(MyGameProject PRIVATE ${CMAKE_SOURCE_DIR}/include)
