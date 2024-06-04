#!/bin/bash

###########
# Simple diff to verify all the footprints
# are up to date from previous project
###########

for file in ./eda/g0dzilla_vs/lib_fp/0_local.pretty/*; do
     echo "INFO - Checking $file"
     diff $file ../cowboys_vs_dinosaurs/eda/cowboys_vs_dinos/lib_fp/0_local.pretty/
done
