#!/usr/bin/env bash

CONTEST_PATTERN='^[0-9]+$'
PROBLEM_PATTERN='^[A-Z][0-9]*$'

if (($# != 2)); then
  echo "Usage: $0 <contest> <problem>" >&2
  exit 1
fi

contest=$1
if ! [[ "$contest" =~ $CONTEST_PATTERN ]]; then
  echo "Error: wrong contest format" >&2
  exit 1
fi

problem=$2
if ! [[ "$problem" =~ $PROBLEM_PATTERN ]]; then
  echo "Error: wrong problem format" >&2
  exit 1
fi

mkdir -p "contests/$contest"
mv -i main.cpp "contests/$contest/$problem.cpp"
git restore main.cpp input.txt
