# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = "F:\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "F:\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\CLionProjects\generatorhasel

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\CLionProjects\generatorhasel\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/generatorhasel.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/generatorhasel.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/generatorhasel.dir/flags.make

CMakeFiles/generatorhasel.dir/main.c.obj: CMakeFiles/generatorhasel.dir/flags.make
CMakeFiles/generatorhasel.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\CLionProjects\generatorhasel\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/generatorhasel.dir/main.c.obj"
	D:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\generatorhasel.dir\main.c.obj -c F:\CLionProjects\generatorhasel\main.c

CMakeFiles/generatorhasel.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/generatorhasel.dir/main.c.i"
	D:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\CLionProjects\generatorhasel\main.c > CMakeFiles\generatorhasel.dir\main.c.i

CMakeFiles/generatorhasel.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/generatorhasel.dir/main.c.s"
	D:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\CLionProjects\generatorhasel\main.c -o CMakeFiles\generatorhasel.dir\main.c.s

# Object files for target generatorhasel
generatorhasel_OBJECTS = \
"CMakeFiles/generatorhasel.dir/main.c.obj"

# External object files for target generatorhasel
generatorhasel_EXTERNAL_OBJECTS =

generatorhasel.exe: CMakeFiles/generatorhasel.dir/main.c.obj
generatorhasel.exe: CMakeFiles/generatorhasel.dir/build.make
generatorhasel.exe: CMakeFiles/generatorhasel.dir/linklibs.rsp
generatorhasel.exe: CMakeFiles/generatorhasel.dir/objects1.rsp
generatorhasel.exe: CMakeFiles/generatorhasel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\CLionProjects\generatorhasel\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable generatorhasel.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\generatorhasel.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/generatorhasel.dir/build: generatorhasel.exe

.PHONY : CMakeFiles/generatorhasel.dir/build

CMakeFiles/generatorhasel.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\generatorhasel.dir\cmake_clean.cmake
.PHONY : CMakeFiles/generatorhasel.dir/clean

CMakeFiles/generatorhasel.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\CLionProjects\generatorhasel F:\CLionProjects\generatorhasel F:\CLionProjects\generatorhasel\cmake-build-debug F:\CLionProjects\generatorhasel\cmake-build-debug F:\CLionProjects\generatorhasel\cmake-build-debug\CMakeFiles\generatorhasel.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/generatorhasel.dir/depend

