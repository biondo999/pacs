# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /snap/clion/234/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /snap/clion/234/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mariano/CLionProjects/pacs/assignemnt2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mariano/CLionProjects/pacs/assignemnt2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/assignment2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/assignment2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/assignment2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/assignment2.dir/flags.make

CMakeFiles/assignment2.dir/main.cpp.o: CMakeFiles/assignment2.dir/flags.make
CMakeFiles/assignment2.dir/main.cpp.o: /home/mariano/CLionProjects/pacs/assignemnt2/main.cpp
CMakeFiles/assignment2.dir/main.cpp.o: CMakeFiles/assignment2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariano/CLionProjects/pacs/assignemnt2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/assignment2.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/assignment2.dir/main.cpp.o -MF CMakeFiles/assignment2.dir/main.cpp.o.d -o CMakeFiles/assignment2.dir/main.cpp.o -c /home/mariano/CLionProjects/pacs/assignemnt2/main.cpp

CMakeFiles/assignment2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mariano/CLionProjects/pacs/assignemnt2/main.cpp > CMakeFiles/assignment2.dir/main.cpp.i

CMakeFiles/assignment2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mariano/CLionProjects/pacs/assignemnt2/main.cpp -o CMakeFiles/assignment2.dir/main.cpp.s

CMakeFiles/assignment2.dir/SolverBase.cpp.o: CMakeFiles/assignment2.dir/flags.make
CMakeFiles/assignment2.dir/SolverBase.cpp.o: /home/mariano/CLionProjects/pacs/assignemnt2/SolverBase.cpp
CMakeFiles/assignment2.dir/SolverBase.cpp.o: CMakeFiles/assignment2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariano/CLionProjects/pacs/assignemnt2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/assignment2.dir/SolverBase.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/assignment2.dir/SolverBase.cpp.o -MF CMakeFiles/assignment2.dir/SolverBase.cpp.o.d -o CMakeFiles/assignment2.dir/SolverBase.cpp.o -c /home/mariano/CLionProjects/pacs/assignemnt2/SolverBase.cpp

CMakeFiles/assignment2.dir/SolverBase.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment2.dir/SolverBase.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mariano/CLionProjects/pacs/assignemnt2/SolverBase.cpp > CMakeFiles/assignment2.dir/SolverBase.cpp.i

CMakeFiles/assignment2.dir/SolverBase.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment2.dir/SolverBase.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mariano/CLionProjects/pacs/assignemnt2/SolverBase.cpp -o CMakeFiles/assignment2.dir/SolverBase.cpp.s

CMakeFiles/assignment2.dir/QuasiNewton.cpp.o: CMakeFiles/assignment2.dir/flags.make
CMakeFiles/assignment2.dir/QuasiNewton.cpp.o: /home/mariano/CLionProjects/pacs/assignemnt2/QuasiNewton.cpp
CMakeFiles/assignment2.dir/QuasiNewton.cpp.o: CMakeFiles/assignment2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariano/CLionProjects/pacs/assignemnt2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/assignment2.dir/QuasiNewton.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/assignment2.dir/QuasiNewton.cpp.o -MF CMakeFiles/assignment2.dir/QuasiNewton.cpp.o.d -o CMakeFiles/assignment2.dir/QuasiNewton.cpp.o -c /home/mariano/CLionProjects/pacs/assignemnt2/QuasiNewton.cpp

CMakeFiles/assignment2.dir/QuasiNewton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment2.dir/QuasiNewton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mariano/CLionProjects/pacs/assignemnt2/QuasiNewton.cpp > CMakeFiles/assignment2.dir/QuasiNewton.cpp.i

CMakeFiles/assignment2.dir/QuasiNewton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment2.dir/QuasiNewton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mariano/CLionProjects/pacs/assignemnt2/QuasiNewton.cpp -o CMakeFiles/assignment2.dir/QuasiNewton.cpp.s

CMakeFiles/assignment2.dir/Bisection.cpp.o: CMakeFiles/assignment2.dir/flags.make
CMakeFiles/assignment2.dir/Bisection.cpp.o: /home/mariano/CLionProjects/pacs/assignemnt2/Bisection.cpp
CMakeFiles/assignment2.dir/Bisection.cpp.o: CMakeFiles/assignment2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariano/CLionProjects/pacs/assignemnt2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/assignment2.dir/Bisection.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/assignment2.dir/Bisection.cpp.o -MF CMakeFiles/assignment2.dir/Bisection.cpp.o.d -o CMakeFiles/assignment2.dir/Bisection.cpp.o -c /home/mariano/CLionProjects/pacs/assignemnt2/Bisection.cpp

CMakeFiles/assignment2.dir/Bisection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment2.dir/Bisection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mariano/CLionProjects/pacs/assignemnt2/Bisection.cpp > CMakeFiles/assignment2.dir/Bisection.cpp.i

CMakeFiles/assignment2.dir/Bisection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment2.dir/Bisection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mariano/CLionProjects/pacs/assignemnt2/Bisection.cpp -o CMakeFiles/assignment2.dir/Bisection.cpp.s

CMakeFiles/assignment2.dir/Secant.cpp.o: CMakeFiles/assignment2.dir/flags.make
CMakeFiles/assignment2.dir/Secant.cpp.o: /home/mariano/CLionProjects/pacs/assignemnt2/Secant.cpp
CMakeFiles/assignment2.dir/Secant.cpp.o: CMakeFiles/assignment2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mariano/CLionProjects/pacs/assignemnt2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/assignment2.dir/Secant.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/assignment2.dir/Secant.cpp.o -MF CMakeFiles/assignment2.dir/Secant.cpp.o.d -o CMakeFiles/assignment2.dir/Secant.cpp.o -c /home/mariano/CLionProjects/pacs/assignemnt2/Secant.cpp

CMakeFiles/assignment2.dir/Secant.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/assignment2.dir/Secant.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mariano/CLionProjects/pacs/assignemnt2/Secant.cpp > CMakeFiles/assignment2.dir/Secant.cpp.i

CMakeFiles/assignment2.dir/Secant.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/assignment2.dir/Secant.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mariano/CLionProjects/pacs/assignemnt2/Secant.cpp -o CMakeFiles/assignment2.dir/Secant.cpp.s

# Object files for target assignment2
assignment2_OBJECTS = \
"CMakeFiles/assignment2.dir/main.cpp.o" \
"CMakeFiles/assignment2.dir/SolverBase.cpp.o" \
"CMakeFiles/assignment2.dir/QuasiNewton.cpp.o" \
"CMakeFiles/assignment2.dir/Bisection.cpp.o" \
"CMakeFiles/assignment2.dir/Secant.cpp.o"

# External object files for target assignment2
assignment2_EXTERNAL_OBJECTS =

assignment2: CMakeFiles/assignment2.dir/main.cpp.o
assignment2: CMakeFiles/assignment2.dir/SolverBase.cpp.o
assignment2: CMakeFiles/assignment2.dir/QuasiNewton.cpp.o
assignment2: CMakeFiles/assignment2.dir/Bisection.cpp.o
assignment2: CMakeFiles/assignment2.dir/Secant.cpp.o
assignment2: CMakeFiles/assignment2.dir/build.make
assignment2: CMakeFiles/assignment2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mariano/CLionProjects/pacs/assignemnt2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable assignment2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/assignment2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/assignment2.dir/build: assignment2
.PHONY : CMakeFiles/assignment2.dir/build

CMakeFiles/assignment2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/assignment2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/assignment2.dir/clean

CMakeFiles/assignment2.dir/depend:
	cd /home/mariano/CLionProjects/pacs/assignemnt2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mariano/CLionProjects/pacs/assignemnt2 /home/mariano/CLionProjects/pacs/assignemnt2 /home/mariano/CLionProjects/pacs/assignemnt2/cmake-build-debug /home/mariano/CLionProjects/pacs/assignemnt2/cmake-build-debug /home/mariano/CLionProjects/pacs/assignemnt2/cmake-build-debug/CMakeFiles/assignment2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/assignment2.dir/depend
