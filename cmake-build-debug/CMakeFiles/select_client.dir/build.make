# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/dingyingsi/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.7319.62/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/dingyingsi/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.7319.62/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dingyingsi/linux_c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dingyingsi/linux_c/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/select_client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/select_client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/select_client.dir/flags.make

CMakeFiles/select_client.dir/tcp/select/client.c.o: CMakeFiles/select_client.dir/flags.make
CMakeFiles/select_client.dir/tcp/select/client.c.o: ../tcp/select/client.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dingyingsi/linux_c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/select_client.dir/tcp/select/client.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/select_client.dir/tcp/select/client.c.o   -c /home/dingyingsi/linux_c/tcp/select/client.c

CMakeFiles/select_client.dir/tcp/select/client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/select_client.dir/tcp/select/client.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dingyingsi/linux_c/tcp/select/client.c > CMakeFiles/select_client.dir/tcp/select/client.c.i

CMakeFiles/select_client.dir/tcp/select/client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/select_client.dir/tcp/select/client.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dingyingsi/linux_c/tcp/select/client.c -o CMakeFiles/select_client.dir/tcp/select/client.c.s

# Object files for target select_client
select_client_OBJECTS = \
"CMakeFiles/select_client.dir/tcp/select/client.c.o"

# External object files for target select_client
select_client_EXTERNAL_OBJECTS =

select_client: CMakeFiles/select_client.dir/tcp/select/client.c.o
select_client: CMakeFiles/select_client.dir/build.make
select_client: CMakeFiles/select_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dingyingsi/linux_c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable select_client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/select_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/select_client.dir/build: select_client

.PHONY : CMakeFiles/select_client.dir/build

CMakeFiles/select_client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/select_client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/select_client.dir/clean

CMakeFiles/select_client.dir/depend:
	cd /home/dingyingsi/linux_c/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dingyingsi/linux_c /home/dingyingsi/linux_c /home/dingyingsi/linux_c/cmake-build-debug /home/dingyingsi/linux_c/cmake-build-debug /home/dingyingsi/linux_c/cmake-build-debug/CMakeFiles/select_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/select_client.dir/depend

