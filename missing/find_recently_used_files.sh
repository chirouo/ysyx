#!/bin/bash
find . -type f -exec stat --format="%X %n" {} \; | sort -n | tail -n 10

