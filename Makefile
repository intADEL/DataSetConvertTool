# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert/CMakeFiles /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named DatasetLabelConvert

# Build rule for target.
DatasetLabelConvert: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 DatasetLabelConvert
.PHONY : DatasetLabelConvert

# fast build rule for target.
DatasetLabelConvert/fast:
	$(MAKE) -f CMakeFiles/DatasetLabelConvert.dir/build.make CMakeFiles/DatasetLabelConvert.dir/build
.PHONY : DatasetLabelConvert/fast

csvreader.o: csvreader.cpp.o

.PHONY : csvreader.o

# target to build an object file
csvreader.cpp.o:
	$(MAKE) -f CMakeFiles/DatasetLabelConvert.dir/build.make CMakeFiles/DatasetLabelConvert.dir/csvreader.cpp.o
.PHONY : csvreader.cpp.o

csvreader.i: csvreader.cpp.i

.PHONY : csvreader.i

# target to preprocess a source file
csvreader.cpp.i:
	$(MAKE) -f CMakeFiles/DatasetLabelConvert.dir/build.make CMakeFiles/DatasetLabelConvert.dir/csvreader.cpp.i
.PHONY : csvreader.cpp.i

csvreader.s: csvreader.cpp.s

.PHONY : csvreader.s

# target to generate assembly for a file
csvreader.cpp.s:
	$(MAKE) -f CMakeFiles/DatasetLabelConvert.dir/build.make CMakeFiles/DatasetLabelConvert.dir/csvreader.cpp.s
.PHONY : csvreader.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/DatasetLabelConvert.dir/build.make CMakeFiles/DatasetLabelConvert.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/DatasetLabelConvert.dir/build.make CMakeFiles/DatasetLabelConvert.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/DatasetLabelConvert.dir/build.make CMakeFiles/DatasetLabelConvert.dir/main.cpp.s
.PHONY : main.cpp.s

toyoloconvert.o: toyoloconvert.cpp.o

.PHONY : toyoloconvert.o

# target to build an object file
toyoloconvert.cpp.o:
	$(MAKE) -f CMakeFiles/DatasetLabelConvert.dir/build.make CMakeFiles/DatasetLabelConvert.dir/toyoloconvert.cpp.o
.PHONY : toyoloconvert.cpp.o

toyoloconvert.i: toyoloconvert.cpp.i

.PHONY : toyoloconvert.i

# target to preprocess a source file
toyoloconvert.cpp.i:
	$(MAKE) -f CMakeFiles/DatasetLabelConvert.dir/build.make CMakeFiles/DatasetLabelConvert.dir/toyoloconvert.cpp.i
.PHONY : toyoloconvert.cpp.i

toyoloconvert.s: toyoloconvert.cpp.s

.PHONY : toyoloconvert.s

# target to generate assembly for a file
toyoloconvert.cpp.s:
	$(MAKE) -f CMakeFiles/DatasetLabelConvert.dir/build.make CMakeFiles/DatasetLabelConvert.dir/toyoloconvert.cpp.s
.PHONY : toyoloconvert.cpp.s

trainvalspilit.o: trainvalspilit.cpp.o

.PHONY : trainvalspilit.o

# target to build an object file
trainvalspilit.cpp.o:
	$(MAKE) -f CMakeFiles/DatasetLabelConvert.dir/build.make CMakeFiles/DatasetLabelConvert.dir/trainvalspilit.cpp.o
.PHONY : trainvalspilit.cpp.o

trainvalspilit.i: trainvalspilit.cpp.i

.PHONY : trainvalspilit.i

# target to preprocess a source file
trainvalspilit.cpp.i:
	$(MAKE) -f CMakeFiles/DatasetLabelConvert.dir/build.make CMakeFiles/DatasetLabelConvert.dir/trainvalspilit.cpp.i
.PHONY : trainvalspilit.cpp.i

trainvalspilit.s: trainvalspilit.cpp.s

.PHONY : trainvalspilit.s

# target to generate assembly for a file
trainvalspilit.cpp.s:
	$(MAKE) -f CMakeFiles/DatasetLabelConvert.dir/build.make CMakeFiles/DatasetLabelConvert.dir/trainvalspilit.cpp.s
.PHONY : trainvalspilit.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... DatasetLabelConvert"
	@echo "... edit_cache"
	@echo "... csvreader.o"
	@echo "... csvreader.i"
	@echo "... csvreader.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... toyoloconvert.o"
	@echo "... toyoloconvert.i"
	@echo "... toyoloconvert.s"
	@echo "... trainvalspilit.o"
	@echo "... trainvalspilit.i"
	@echo "... trainvalspilit.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

