# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ashleyc./Desktop/w7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ashleyc./Desktop/w7/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/w7.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/w7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/w7.dir/flags.make

CMakeFiles/w7.dir/w7_p2.cpp.o: CMakeFiles/w7.dir/flags.make
CMakeFiles/w7.dir/w7_p2.cpp.o: ../w7_p2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ashleyc./Desktop/w7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/w7.dir/w7_p2.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/w7.dir/w7_p2.cpp.o -c /Users/ashleyc./Desktop/w7/w7_p2.cpp

CMakeFiles/w7.dir/w7_p2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/w7.dir/w7_p2.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ashleyc./Desktop/w7/w7_p2.cpp > CMakeFiles/w7.dir/w7_p2.cpp.i

CMakeFiles/w7.dir/w7_p2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/w7.dir/w7_p2.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ashleyc./Desktop/w7/w7_p2.cpp -o CMakeFiles/w7.dir/w7_p2.cpp.s

CMakeFiles/w7.dir/SongCollection.cpp.o: CMakeFiles/w7.dir/flags.make
CMakeFiles/w7.dir/SongCollection.cpp.o: ../SongCollection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ashleyc./Desktop/w7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/w7.dir/SongCollection.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/w7.dir/SongCollection.cpp.o -c /Users/ashleyc./Desktop/w7/SongCollection.cpp

CMakeFiles/w7.dir/SongCollection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/w7.dir/SongCollection.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ashleyc./Desktop/w7/SongCollection.cpp > CMakeFiles/w7.dir/SongCollection.cpp.i

CMakeFiles/w7.dir/SongCollection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/w7.dir/SongCollection.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ashleyc./Desktop/w7/SongCollection.cpp -o CMakeFiles/w7.dir/SongCollection.cpp.s

# Object files for target w7
w7_OBJECTS = \
"CMakeFiles/w7.dir/w7_p2.cpp.o" \
"CMakeFiles/w7.dir/SongCollection.cpp.o"

# External object files for target w7
w7_EXTERNAL_OBJECTS =

w7: CMakeFiles/w7.dir/w7_p2.cpp.o
w7: CMakeFiles/w7.dir/SongCollection.cpp.o
w7: CMakeFiles/w7.dir/build.make
w7: CMakeFiles/w7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ashleyc./Desktop/w7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable w7"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/w7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/w7.dir/build: w7

.PHONY : CMakeFiles/w7.dir/build

CMakeFiles/w7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/w7.dir/cmake_clean.cmake
.PHONY : CMakeFiles/w7.dir/clean

CMakeFiles/w7.dir/depend:
	cd /Users/ashleyc./Desktop/w7/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ashleyc./Desktop/w7 /Users/ashleyc./Desktop/w7 /Users/ashleyc./Desktop/w7/cmake-build-debug /Users/ashleyc./Desktop/w7/cmake-build-debug /Users/ashleyc./Desktop/w7/cmake-build-debug/CMakeFiles/w7.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/w7.dir/depend

