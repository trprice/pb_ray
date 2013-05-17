This is the build directory. To build pb_ray on Linux, do the following:

1. In this directory, run `cmake ..`
2. In this directory, run `make`

To build using LLVM's static analysis tool, scan-build, do the following:

1. In this directory, run `../scan_build_configure ..`
2. In this directory, run `../scan_build_make`
