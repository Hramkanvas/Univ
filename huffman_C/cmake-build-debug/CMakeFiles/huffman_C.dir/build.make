# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\kastu\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\181.4668.70\bin\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\kastu\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\181.4668.70\bin\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\kastu\Desktop\cs\Algorithms\Problem_sets\huffman_C

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\kastu\Desktop\cs\Algorithms\Problem_sets\huffman_C\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/huffman_C.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/huffman_C.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/huffman_C.dir/flags.make

CMakeFiles/huffman_C.dir/main.cpp.obj: CMakeFiles/huffman_C.dir/flags.make
CMakeFiles/huffman_C.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kastu\Desktop\cs\Algorithms\Problem_sets\huffman_C\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/huffman_C.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\huffman_C.dir\main.cpp.obj -c C:\Users\kastu\Desktop\cs\Algorithms\Problem_sets\huffman_C\main.cpp

CMakeFiles/huffman_C.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/huffman_C.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kastu\Desktop\cs\Algorithms\Problem_sets\huffman_C\main.cpp > CMakeFiles\huffman_C.dir\main.cpp.i

CMakeFiles/huffman_C.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/huffman_C.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kastu\Desktop\cs\Algorithms\Problem_sets\huffman_C\main.cpp -o CMakeFiles\huffman_C.dir\main.cpp.s

CMakeFiles/huffman_C.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/huffman_C.dir/main.cpp.obj.requires

CMakeFiles/huffman_C.dir/main.cpp.obj.provides: CMakeFiles/huffman_C.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\huffman_C.dir\build.make CMakeFiles/huffman_C.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/huffman_C.dir/main.cpp.obj.provides

CMakeFiles/huffman_C.dir/main.cpp.obj.provides.build: CMakeFiles/huffman_C.dir/main.cpp.obj


# Object files for target huffman_C
huffman_C_OBJECTS = \
"CMakeFiles/huffman_C.dir/main.cpp.obj"

# External object files for target huffman_C
huffman_C_EXTERNAL_OBJECTS =

huffman_C.exe: CMakeFiles/huffman_C.dir/main.cpp.obj
huffman_C.exe: CMakeFiles/huffman_C.dir/build.make
huffman_C.exe: CMakeFiles/huffman_C.dir/linklibs.rsp
huffman_C.exe: CMakeFiles/huffman_C.dir/objects1.rsp
huffman_C.exe: CMakeFiles/huffman_C.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\kastu\Desktop\cs\Algorithms\Problem_sets\huffman_C\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable huffman_C.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\huffman_C.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/huffman_C.dir/build: huffman_C.exe

.PHONY : CMakeFiles/huffman_C.dir/build

CMakeFiles/huffman_C.dir/requires: CMakeFiles/huffman_C.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/huffman_C.dir/requires

CMakeFiles/huffman_C.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\huffman_C.dir\cmake_clean.cmake
.PHONY : CMakeFiles/huffman_C.dir/clean

CMakeFiles/huffman_C.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\kastu\Desktop\cs\Algorithms\Problem_sets\huffman_C C:\Users\kastu\Desktop\cs\Algorithms\Problem_sets\huffman_C C:\Users\kastu\Desktop\cs\Algorithms\Problem_sets\huffman_C\cmake-build-debug C:\Users\kastu\Desktop\cs\Algorithms\Problem_sets\huffman_C\cmake-build-debug C:\Users\kastu\Desktop\cs\Algorithms\Problem_sets\huffman_C\cmake-build-debug\CMakeFiles\huffman_C.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/huffman_C.dir/depend
