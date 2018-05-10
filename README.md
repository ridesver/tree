[![Build Status](https://travis-ci.org/ridesver/tree.svg?branch=master)](https://travis-ci.org/ridesver/tree)

```
cmake -H. -B_builds -DBUILD_TESTS=ON
cmake --build _builds
cmake --build _builds --target test -- ARGS=--verbose
```
