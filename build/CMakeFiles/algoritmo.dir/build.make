# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement\build

# Include any dependencies generated for this target.
include CMakeFiles/algoritmo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/algoritmo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/algoritmo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/algoritmo.dir/flags.make

CMakeFiles/algoritmo.dir/main.cpp.obj: CMakeFiles/algoritmo.dir/flags.make
CMakeFiles/algoritmo.dir/main.cpp.obj: CMakeFiles/algoritmo.dir/includes_CXX.rsp
CMakeFiles/algoritmo.dir/main.cpp.obj: C:/Users/jptac/OneDrive/Escritorio/universidad/Geometria/proyecto/FractalMidPointDisplacement/main.cpp
CMakeFiles/algoritmo.dir/main.cpp.obj: CMakeFiles/algoritmo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/algoritmo.dir/main.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/algoritmo.dir/main.cpp.obj -MF CMakeFiles\algoritmo.dir\main.cpp.obj.d -o CMakeFiles\algoritmo.dir\main.cpp.obj -c C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement\main.cpp

CMakeFiles/algoritmo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/algoritmo.dir/main.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement\main.cpp > CMakeFiles\algoritmo.dir\main.cpp.i

CMakeFiles/algoritmo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/algoritmo.dir/main.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement\main.cpp -o CMakeFiles\algoritmo.dir\main.cpp.s

# Object files for target algoritmo
algoritmo_OBJECTS = \
"CMakeFiles/algoritmo.dir/main.cpp.obj"

# External object files for target algoritmo
algoritmo_EXTERNAL_OBJECTS =

algoritmo.exe: CMakeFiles/algoritmo.dir/main.cpp.obj
algoritmo.exe: CMakeFiles/algoritmo.dir/build.make
algoritmo.exe: src/libmidPointDisplacement2D.a
algoritmo.exe: src/libAux_funcs.a
algoritmo.exe: CMakeFiles/algoritmo.dir/linkLibs.rsp
algoritmo.exe: CMakeFiles/algoritmo.dir/objects1.rsp
algoritmo.exe: CMakeFiles/algoritmo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable algoritmo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\algoritmo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/algoritmo.dir/build: algoritmo.exe
.PHONY : CMakeFiles/algoritmo.dir/build

CMakeFiles/algoritmo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\algoritmo.dir\cmake_clean.cmake
.PHONY : CMakeFiles/algoritmo.dir/clean

CMakeFiles/algoritmo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement\build C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement\build C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement\build\CMakeFiles\algoritmo.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/algoritmo.dir/depend
