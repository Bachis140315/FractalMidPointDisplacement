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
include src/CMakeFiles/Aux_funcs.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/Aux_funcs.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Aux_funcs.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/Aux_funcs.dir/flags.make

src/CMakeFiles/Aux_funcs.dir/Aux_funcs.cpp.obj: src/CMakeFiles/Aux_funcs.dir/flags.make
src/CMakeFiles/Aux_funcs.dir/Aux_funcs.cpp.obj: src/CMakeFiles/Aux_funcs.dir/includes_CXX.rsp
src/CMakeFiles/Aux_funcs.dir/Aux_funcs.cpp.obj: C:/Users/jptac/OneDrive/Escritorio/universidad/Geometria/proyecto/FractalMidPointDisplacement/src/Aux_funcs.cpp
src/CMakeFiles/Aux_funcs.dir/Aux_funcs.cpp.obj: src/CMakeFiles/Aux_funcs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/Aux_funcs.dir/Aux_funcs.cpp.obj"
	cd /d C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement\build\src && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/Aux_funcs.dir/Aux_funcs.cpp.obj -MF CMakeFiles\Aux_funcs.dir\Aux_funcs.cpp.obj.d -o CMakeFiles\Aux_funcs.dir\Aux_funcs.cpp.obj -c C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement\src\Aux_funcs.cpp

src/CMakeFiles/Aux_funcs.dir/Aux_funcs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Aux_funcs.dir/Aux_funcs.cpp.i"
	cd /d C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement\build\src && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement\src\Aux_funcs.cpp > CMakeFiles\Aux_funcs.dir\Aux_funcs.cpp.i

src/CMakeFiles/Aux_funcs.dir/Aux_funcs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Aux_funcs.dir/Aux_funcs.cpp.s"
	cd /d C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement\build\src && C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement\src\Aux_funcs.cpp -o CMakeFiles\Aux_funcs.dir\Aux_funcs.cpp.s

# Object files for target Aux_funcs
Aux_funcs_OBJECTS = \
"CMakeFiles/Aux_funcs.dir/Aux_funcs.cpp.obj"

# External object files for target Aux_funcs
Aux_funcs_EXTERNAL_OBJECTS =

src/libAux_funcs.a: src/CMakeFiles/Aux_funcs.dir/Aux_funcs.cpp.obj
src/libAux_funcs.a: src/CMakeFiles/Aux_funcs.dir/build.make
src/libAux_funcs.a: src/CMakeFiles/Aux_funcs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libAux_funcs.a"
	cd /d C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement\build\src && $(CMAKE_COMMAND) -P CMakeFiles\Aux_funcs.dir\cmake_clean_target.cmake
	cd /d C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement\build\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Aux_funcs.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/Aux_funcs.dir/build: src/libAux_funcs.a
.PHONY : src/CMakeFiles/Aux_funcs.dir/build

src/CMakeFiles/Aux_funcs.dir/clean:
	cd /d C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement\build\src && $(CMAKE_COMMAND) -P CMakeFiles\Aux_funcs.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/Aux_funcs.dir/clean

src/CMakeFiles/Aux_funcs.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement\src C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement\build C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement\build\src C:\Users\jptac\OneDrive\Escritorio\universidad\Geometria\proyecto\FractalMidPointDisplacement\build\src\CMakeFiles\Aux_funcs.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/Aux_funcs.dir/depend
