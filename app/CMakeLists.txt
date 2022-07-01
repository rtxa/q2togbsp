add_executable(q2togbsp "src/q2togbsp.cpp")

target_compile_features(q2togbsp PUBLIC cxx_std_17)

target_link_libraries(q2togbsp 
    fmt::fmt
    argparse::argparse
    common
)
