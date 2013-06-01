pb_ray
======

Welcome to the pb_ray project! This will be a ray tracer that is initially
based on the first edition of the book "Physically Based Rendering: From Theory to 
Implementation". There is a second edition of the book, but SafariBooksOnline
only has the first edition. An Amazon link to the second edition of the book is
[here](http://www.amazon.com/Physically-Based-Rendering-Implementation-ebook/dp/B005SNM0Z2/ref=sr_1_fkmr1_3).
<br>
<br>
Goals
-----
I have several goals for this project:

- Implement the ray tracer as described by the book.
- Write unit tests along the way using the googletest framework.
- Use the googlemock framework for mock objects.
- Use CMake to make the ray tracer buildable on Windows (Visual Studio 2010) and *nix variants (including Mac OSX).

<br>
Building The Source:
--------------------
To build pb_ray on Linux, do the following:<br>

1. In the build directory, run `cmake ..`
2. In the build directory, run `make`

To build using LLVM's static analysis tool, scan-build, do the following:<br>

1. In the build directory, run `../scan_build_configure ..`
2. In the build directory, run `../scan_build_make`

<b>Note:</b> the first build will (and consecutive builds may) take a while because googletest and googlemock are downloaded via svn during the build process.
