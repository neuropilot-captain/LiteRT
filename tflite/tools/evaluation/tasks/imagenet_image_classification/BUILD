load("//tflite:build_def.bzl", "tflite_copts")
load("//tflite/tools/evaluation/tasks:build_def.bzl", "task_linkopts")

package(
    # copybara:uncomment default_applicable_licenses = ["@org_tensorflow//tensorflow:license"],
    default_visibility = [
        "//visibility:public",
    ],
    licenses = ["notice"],
)

cc_library(
    name = "run_eval_lib",
    srcs = ["run_eval.cc"],
    copts = tflite_copts(),
    linkopts = task_linkopts(),
    deps = [
        "//tflite/core/c:common",
        "//tflite/tools:command_line_flags",
        "//tflite/tools:logging",
        "//tflite/tools/evaluation:evaluation_delegate_provider",
        "//tflite/tools/evaluation:evaluation_stage",
        "//tflite/tools/evaluation:utils",
        "//tflite/tools/evaluation/proto:evaluation_config_cc_proto",
        "//tflite/tools/evaluation/proto:evaluation_stages_cc_proto",
        "//tflite/tools/evaluation/stages:image_classification_stage",
        "//tflite/tools/evaluation/tasks:task_executor",
        "@com_google_absl//absl/types:optional",
    ],
    alwayslink = 1,
)

cc_binary(
    name = "run_eval",
    copts = tflite_copts(),
    linkopts = task_linkopts(),
    deps = [
        ":run_eval_lib",
        "//tflite/tools/evaluation/tasks:task_executor_main",
    ],
)
