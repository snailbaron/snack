load("@rules_cc//cc:cc_library.bzl", "cc_library")

cc_library(
    name = "snack",
    srcs = [
        "error.hpp",
        "stream.cpp",
        "stream.hpp",
        "token.cpp",
        "token.hpp",
    ],
    hdrs = ["snack.hpp"],
    strip_include_prefix = "/src/snack",
    visibility = ["//visibility:public"],
)
