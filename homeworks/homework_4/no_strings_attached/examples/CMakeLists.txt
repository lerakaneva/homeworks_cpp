add_executable(split_strings split_strings.cpp)
add_executable(trim_strings trim_strings.cpp)
target_link_libraries(split_strings PRIVATE string_split string_trim cxx_setup)
target_link_libraries(trim_strings PRIVATE string_split string_trim cxx_setup)