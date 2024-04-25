#!/usr/bin/env bash
##########################################################
# Set the working directory path as the file path
cd "$(dirname "$0")"
bash runCMake.sh
##########################################################

cd ../build
ctest -T Test
