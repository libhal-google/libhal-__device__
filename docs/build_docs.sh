#!/bin/bash

# Get the repo name so it can be replaced in the doxygen template configuration
# file.
REPO_NAME=$(basename $(git rev-parse --show-toplevel))

# Replace "RESERVED_REPO_NAME" with the repo name
sed "s/RESERVED_REPO_NAME/$REPO_NAME/g" doxygen_template.conf > doxygen.conf

# Build documenation
doxygen doxygen.conf 2> doxygen.stderr

# Check if the doxygen stderr file is empty, if so, return success code 0
if [ ! -s doxygen.stderr ]; then
  exit 0
fi

# Otherwise print out the stderr messages and return failure code 1
cat doxygen.stderr
exit 1