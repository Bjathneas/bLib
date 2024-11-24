#!/bin/bash

# Enter root dir
cd $(dirname "0")

# Format changes
cppship fmt -f

# Build the project
cppship build
