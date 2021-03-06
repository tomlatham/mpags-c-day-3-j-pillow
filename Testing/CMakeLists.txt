# - Build sub-script for the MPAGSCipher libarary unit tests

# Most basic test
add_executable(testHello testHello.cpp)
add_test(NAME test-hello COMMAND testHello)

# Create Interface Library for Catch
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_LIST_DIR})

# First Catch-based test
add_executable(testCatch testCatch.cpp)
target_include_directories(testCatch PRIVATE ${CMAKE_CURRENT_LIST_DIR})
add_test(NAME test-catch COMMAND testCatch)

# Test TransformChar
add_executable(testTransformChar testTransformChar.cpp)
target_include_directories(testTransformChar PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(testTransformChar MPAGSCipher)
add_test(NAME test-transformchar COMMAND testTransformChar)

# Test CaesarCipher
add_executable(testCaesarCipher testCaesarCipher.cpp)
target_include_directories(testCaesarCipher PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(testCaesarCipher MPAGSCipher)
add_test(NAME test-caesarcipher COMMAND testCaesarCipher)

# Test ProcessCommandLine
add_executable(testProcessCommandLine testProcessCommandLine.cpp)
target_include_directories(testProcessCommandLine PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(testProcessCommandLine MPAGSCipher)
add_test(NAME test-processcommandline COMMAND testProcessCommandLine)