#!/bin/bash -eu


exec docker run \
  --rm \
  -it \
  -u $(id -u):$(id -g) \
  -v $(pwd):/workdir \
  -v /etc/passwd:/etc/passwd:ro \
  -w /workdir \
  toolkit.local/cpp-builder:latest
