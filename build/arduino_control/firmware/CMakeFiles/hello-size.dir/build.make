# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/samlyu/testbench_ws/src/arduino_control/firmware

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/samlyu/testbench_ws/build/arduino_control/firmware

# Utility rule file for hello-size.

# Include the progress variables for this target.
include CMakeFiles/hello-size.dir/progress.make

CMakeFiles/hello-size: /home/samlyu/testbench_ws/devel/share/arduino_control/hello.elf
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/samlyu/testbench_ws/build/arduino_control/firmware/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Calculating hello image size"
	/usr/bin/cmake -DFIRMWARE_IMAGE=/home/samlyu/testbench_ws/devel/share/arduino_control/hello.elf -DMCU=atmega328p -DEEPROM_IMAGE=/home/samlyu/testbench_ws/devel/share/arduino_control/hello.eep -P /home/samlyu/testbench_ws/build/arduino_control/firmware/CMakeFiles/FirmwareSize.cmake

hello-size: CMakeFiles/hello-size
hello-size: CMakeFiles/hello-size.dir/build.make

.PHONY : hello-size

# Rule to build all files generated by this target.
CMakeFiles/hello-size.dir/build: hello-size

.PHONY : CMakeFiles/hello-size.dir/build

CMakeFiles/hello-size.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hello-size.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hello-size.dir/clean

CMakeFiles/hello-size.dir/depend:
	cd /home/samlyu/testbench_ws/build/arduino_control/firmware && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/samlyu/testbench_ws/src/arduino_control/firmware /home/samlyu/testbench_ws/src/arduino_control/firmware /home/samlyu/testbench_ws/build/arduino_control/firmware /home/samlyu/testbench_ws/build/arduino_control/firmware /home/samlyu/testbench_ws/build/arduino_control/firmware/CMakeFiles/hello-size.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hello-size.dir/depend

