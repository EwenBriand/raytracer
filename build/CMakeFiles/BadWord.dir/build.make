# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gxby/Epitech/delivery/project/semestre4/OOP/B-OOP-400-BAR-4-1-raytracer-thomas.laprie

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gxby/Epitech/delivery/project/semestre4/OOP/B-OOP-400-BAR-4-1-raytracer-thomas.laprie/build

# Include any dependencies generated for this target.
include CMakeFiles/BadWord.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BadWord.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BadWord.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BadWord.dir/flags.make

CMakeFiles/BadWord.dir/badWords/badWord.cpp.o: CMakeFiles/BadWord.dir/flags.make
CMakeFiles/BadWord.dir/badWords/badWord.cpp.o: /home/gxby/Epitech/delivery/project/semestre4/OOP/B-OOP-400-BAR-4-1-raytracer-thomas.laprie/badWords/badWord.cpp
CMakeFiles/BadWord.dir/badWords/badWord.cpp.o: CMakeFiles/BadWord.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gxby/Epitech/delivery/project/semestre4/OOP/B-OOP-400-BAR-4-1-raytracer-thomas.laprie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BadWord.dir/badWords/badWord.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BadWord.dir/badWords/badWord.cpp.o -MF CMakeFiles/BadWord.dir/badWords/badWord.cpp.o.d -o CMakeFiles/BadWord.dir/badWords/badWord.cpp.o -c /home/gxby/Epitech/delivery/project/semestre4/OOP/B-OOP-400-BAR-4-1-raytracer-thomas.laprie/badWords/badWord.cpp

CMakeFiles/BadWord.dir/badWords/badWord.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BadWord.dir/badWords/badWord.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gxby/Epitech/delivery/project/semestre4/OOP/B-OOP-400-BAR-4-1-raytracer-thomas.laprie/badWords/badWord.cpp > CMakeFiles/BadWord.dir/badWords/badWord.cpp.i

CMakeFiles/BadWord.dir/badWords/badWord.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BadWord.dir/badWords/badWord.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gxby/Epitech/delivery/project/semestre4/OOP/B-OOP-400-BAR-4-1-raytracer-thomas.laprie/badWords/badWord.cpp -o CMakeFiles/BadWord.dir/badWords/badWord.cpp.s

CMakeFiles/BadWord.dir/badWords/entryPoint.cpp.o: CMakeFiles/BadWord.dir/flags.make
CMakeFiles/BadWord.dir/badWords/entryPoint.cpp.o: /home/gxby/Epitech/delivery/project/semestre4/OOP/B-OOP-400-BAR-4-1-raytracer-thomas.laprie/badWords/entryPoint.cpp
CMakeFiles/BadWord.dir/badWords/entryPoint.cpp.o: CMakeFiles/BadWord.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gxby/Epitech/delivery/project/semestre4/OOP/B-OOP-400-BAR-4-1-raytracer-thomas.laprie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BadWord.dir/badWords/entryPoint.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BadWord.dir/badWords/entryPoint.cpp.o -MF CMakeFiles/BadWord.dir/badWords/entryPoint.cpp.o.d -o CMakeFiles/BadWord.dir/badWords/entryPoint.cpp.o -c /home/gxby/Epitech/delivery/project/semestre4/OOP/B-OOP-400-BAR-4-1-raytracer-thomas.laprie/badWords/entryPoint.cpp

CMakeFiles/BadWord.dir/badWords/entryPoint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BadWord.dir/badWords/entryPoint.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gxby/Epitech/delivery/project/semestre4/OOP/B-OOP-400-BAR-4-1-raytracer-thomas.laprie/badWords/entryPoint.cpp > CMakeFiles/BadWord.dir/badWords/entryPoint.cpp.i

CMakeFiles/BadWord.dir/badWords/entryPoint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BadWord.dir/badWords/entryPoint.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gxby/Epitech/delivery/project/semestre4/OOP/B-OOP-400-BAR-4-1-raytracer-thomas.laprie/badWords/entryPoint.cpp -o CMakeFiles/BadWord.dir/badWords/entryPoint.cpp.s

# Object files for target BadWord
BadWord_OBJECTS = \
"CMakeFiles/BadWord.dir/badWords/badWord.cpp.o" \
"CMakeFiles/BadWord.dir/badWords/entryPoint.cpp.o"

# External object files for target BadWord
BadWord_EXTERNAL_OBJECTS =

libBadWord.so: CMakeFiles/BadWord.dir/badWords/badWord.cpp.o
libBadWord.so: CMakeFiles/BadWord.dir/badWords/entryPoint.cpp.o
libBadWord.so: CMakeFiles/BadWord.dir/build.make
libBadWord.so: CMakeFiles/BadWord.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gxby/Epitech/delivery/project/semestre4/OOP/B-OOP-400-BAR-4-1-raytracer-thomas.laprie/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library libBadWord.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BadWord.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BadWord.dir/build: libBadWord.so
.PHONY : CMakeFiles/BadWord.dir/build

CMakeFiles/BadWord.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BadWord.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BadWord.dir/clean

CMakeFiles/BadWord.dir/depend:
	cd /home/gxby/Epitech/delivery/project/semestre4/OOP/B-OOP-400-BAR-4-1-raytracer-thomas.laprie/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gxby/Epitech/delivery/project/semestre4/OOP/B-OOP-400-BAR-4-1-raytracer-thomas.laprie /home/gxby/Epitech/delivery/project/semestre4/OOP/B-OOP-400-BAR-4-1-raytracer-thomas.laprie /home/gxby/Epitech/delivery/project/semestre4/OOP/B-OOP-400-BAR-4-1-raytracer-thomas.laprie/build /home/gxby/Epitech/delivery/project/semestre4/OOP/B-OOP-400-BAR-4-1-raytracer-thomas.laprie/build /home/gxby/Epitech/delivery/project/semestre4/OOP/B-OOP-400-BAR-4-1-raytracer-thomas.laprie/build/CMakeFiles/BadWord.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BadWord.dir/depend

