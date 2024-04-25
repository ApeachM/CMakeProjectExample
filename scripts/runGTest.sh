#!/usr/bin/env bash
##########################################################
# Set the working directory path as the file path
cd "$(dirname "$0")"
bash runCMake.sh
##########################################################

../out/bin/my_function_tests
../out/bin/my_class_tests

../out/bin/my_function_tests --gtest_filter=AddTest.*
../out/bin/my_function_tests --gtest_filter=SubtractTest.*
