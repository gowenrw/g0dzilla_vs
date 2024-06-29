#!/bin/bash
echo "CLEANING UP LOCAL BUILD DIRECTORIES"
echo "##########"

echo "rm -rf ./_build/*"
rm -rf ./_build/*

# Put back the file ./_build/README.md which is detroyed during compile
echo -e "# directory placeholder" > ./_build/README.md

echo "rm -rf ./_data/package*"
rm -rf ./_data/package*

echo "rm -rf ./_data/lib*"
rm -rf ./_data/lib*

echo "rm -rf ./_data/inv*"
rm -rf ./_data/inv*

echo "rm -rf ./_data/tm*"
rm -rf ./_data/tm*

echo "rm -rf ./_staging/package*"
rm -rf ./_staging/package*

echo "rm -rf ./_staging/lib*"
rm -rf ./_staging/lib*

echo "rm -rf ./libraries/Adafruit*"
rm -rf ./libraries/Adafruit*

echo "rm -rf ./libraries/Async*"
rm -rf ./libraries/Async*

echo "rm -rf ./libraries/ESP*"
rm -rf ./libraries/ESP*

echo "##########"
echo "CLEANUP DONE - READY TO RUN ./cli-setup.sh"
