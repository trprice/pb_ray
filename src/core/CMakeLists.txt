# Find the *.cpp files and add them to the executable.
FILE (GLOB CPPSources *.cpp)
add_library (core ${CPPSources})

# Add the install targets
#       These are relative to CMAKE_INSTALL_PREFIX
install (TARGETS core DESTINATION lib)

# Do the header files reallly need to be installed somewhere?
#install (FILES include/Geometry.h DESTINATION include)
