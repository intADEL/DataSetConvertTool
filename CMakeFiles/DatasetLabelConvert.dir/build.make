# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert

# Include any dependencies generated for this target.
include CMakeFiles/DatasetLabelConvert.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DatasetLabelConvert.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DatasetLabelConvert.dir/flags.make

CMakeFiles/DatasetLabelConvert.dir/csvreader.cpp.o: CMakeFiles/DatasetLabelConvert.dir/flags.make
CMakeFiles/DatasetLabelConvert.dir/csvreader.cpp.o: csvreader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DatasetLabelConvert.dir/csvreader.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DatasetLabelConvert.dir/csvreader.cpp.o -c /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert/csvreader.cpp

CMakeFiles/DatasetLabelConvert.dir/csvreader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DatasetLabelConvert.dir/csvreader.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert/csvreader.cpp > CMakeFiles/DatasetLabelConvert.dir/csvreader.cpp.i

CMakeFiles/DatasetLabelConvert.dir/csvreader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DatasetLabelConvert.dir/csvreader.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert/csvreader.cpp -o CMakeFiles/DatasetLabelConvert.dir/csvreader.cpp.s

CMakeFiles/DatasetLabelConvert.dir/csvreader.cpp.o.requires:

.PHONY : CMakeFiles/DatasetLabelConvert.dir/csvreader.cpp.o.requires

CMakeFiles/DatasetLabelConvert.dir/csvreader.cpp.o.provides: CMakeFiles/DatasetLabelConvert.dir/csvreader.cpp.o.requires
	$(MAKE) -f CMakeFiles/DatasetLabelConvert.dir/build.make CMakeFiles/DatasetLabelConvert.dir/csvreader.cpp.o.provides.build
.PHONY : CMakeFiles/DatasetLabelConvert.dir/csvreader.cpp.o.provides

CMakeFiles/DatasetLabelConvert.dir/csvreader.cpp.o.provides.build: CMakeFiles/DatasetLabelConvert.dir/csvreader.cpp.o


CMakeFiles/DatasetLabelConvert.dir/main.cpp.o: CMakeFiles/DatasetLabelConvert.dir/flags.make
CMakeFiles/DatasetLabelConvert.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DatasetLabelConvert.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DatasetLabelConvert.dir/main.cpp.o -c /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert/main.cpp

CMakeFiles/DatasetLabelConvert.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DatasetLabelConvert.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert/main.cpp > CMakeFiles/DatasetLabelConvert.dir/main.cpp.i

CMakeFiles/DatasetLabelConvert.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DatasetLabelConvert.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert/main.cpp -o CMakeFiles/DatasetLabelConvert.dir/main.cpp.s

CMakeFiles/DatasetLabelConvert.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/DatasetLabelConvert.dir/main.cpp.o.requires

CMakeFiles/DatasetLabelConvert.dir/main.cpp.o.provides: CMakeFiles/DatasetLabelConvert.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/DatasetLabelConvert.dir/build.make CMakeFiles/DatasetLabelConvert.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/DatasetLabelConvert.dir/main.cpp.o.provides

CMakeFiles/DatasetLabelConvert.dir/main.cpp.o.provides.build: CMakeFiles/DatasetLabelConvert.dir/main.cpp.o


CMakeFiles/DatasetLabelConvert.dir/toyoloconvert.cpp.o: CMakeFiles/DatasetLabelConvert.dir/flags.make
CMakeFiles/DatasetLabelConvert.dir/toyoloconvert.cpp.o: toyoloconvert.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DatasetLabelConvert.dir/toyoloconvert.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DatasetLabelConvert.dir/toyoloconvert.cpp.o -c /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert/toyoloconvert.cpp

CMakeFiles/DatasetLabelConvert.dir/toyoloconvert.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DatasetLabelConvert.dir/toyoloconvert.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert/toyoloconvert.cpp > CMakeFiles/DatasetLabelConvert.dir/toyoloconvert.cpp.i

CMakeFiles/DatasetLabelConvert.dir/toyoloconvert.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DatasetLabelConvert.dir/toyoloconvert.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert/toyoloconvert.cpp -o CMakeFiles/DatasetLabelConvert.dir/toyoloconvert.cpp.s

CMakeFiles/DatasetLabelConvert.dir/toyoloconvert.cpp.o.requires:

.PHONY : CMakeFiles/DatasetLabelConvert.dir/toyoloconvert.cpp.o.requires

CMakeFiles/DatasetLabelConvert.dir/toyoloconvert.cpp.o.provides: CMakeFiles/DatasetLabelConvert.dir/toyoloconvert.cpp.o.requires
	$(MAKE) -f CMakeFiles/DatasetLabelConvert.dir/build.make CMakeFiles/DatasetLabelConvert.dir/toyoloconvert.cpp.o.provides.build
.PHONY : CMakeFiles/DatasetLabelConvert.dir/toyoloconvert.cpp.o.provides

CMakeFiles/DatasetLabelConvert.dir/toyoloconvert.cpp.o.provides.build: CMakeFiles/DatasetLabelConvert.dir/toyoloconvert.cpp.o


CMakeFiles/DatasetLabelConvert.dir/trainvalspilit.cpp.o: CMakeFiles/DatasetLabelConvert.dir/flags.make
CMakeFiles/DatasetLabelConvert.dir/trainvalspilit.cpp.o: trainvalspilit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DatasetLabelConvert.dir/trainvalspilit.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DatasetLabelConvert.dir/trainvalspilit.cpp.o -c /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert/trainvalspilit.cpp

CMakeFiles/DatasetLabelConvert.dir/trainvalspilit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DatasetLabelConvert.dir/trainvalspilit.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert/trainvalspilit.cpp > CMakeFiles/DatasetLabelConvert.dir/trainvalspilit.cpp.i

CMakeFiles/DatasetLabelConvert.dir/trainvalspilit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DatasetLabelConvert.dir/trainvalspilit.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert/trainvalspilit.cpp -o CMakeFiles/DatasetLabelConvert.dir/trainvalspilit.cpp.s

CMakeFiles/DatasetLabelConvert.dir/trainvalspilit.cpp.o.requires:

.PHONY : CMakeFiles/DatasetLabelConvert.dir/trainvalspilit.cpp.o.requires

CMakeFiles/DatasetLabelConvert.dir/trainvalspilit.cpp.o.provides: CMakeFiles/DatasetLabelConvert.dir/trainvalspilit.cpp.o.requires
	$(MAKE) -f CMakeFiles/DatasetLabelConvert.dir/build.make CMakeFiles/DatasetLabelConvert.dir/trainvalspilit.cpp.o.provides.build
.PHONY : CMakeFiles/DatasetLabelConvert.dir/trainvalspilit.cpp.o.provides

CMakeFiles/DatasetLabelConvert.dir/trainvalspilit.cpp.o.provides.build: CMakeFiles/DatasetLabelConvert.dir/trainvalspilit.cpp.o


# Object files for target DatasetLabelConvert
DatasetLabelConvert_OBJECTS = \
"CMakeFiles/DatasetLabelConvert.dir/csvreader.cpp.o" \
"CMakeFiles/DatasetLabelConvert.dir/main.cpp.o" \
"CMakeFiles/DatasetLabelConvert.dir/toyoloconvert.cpp.o" \
"CMakeFiles/DatasetLabelConvert.dir/trainvalspilit.cpp.o"

# External object files for target DatasetLabelConvert
DatasetLabelConvert_EXTERNAL_OBJECTS =

DatasetLabelConvert: CMakeFiles/DatasetLabelConvert.dir/csvreader.cpp.o
DatasetLabelConvert: CMakeFiles/DatasetLabelConvert.dir/main.cpp.o
DatasetLabelConvert: CMakeFiles/DatasetLabelConvert.dir/toyoloconvert.cpp.o
DatasetLabelConvert: CMakeFiles/DatasetLabelConvert.dir/trainvalspilit.cpp.o
DatasetLabelConvert: CMakeFiles/DatasetLabelConvert.dir/build.make
DatasetLabelConvert: /usr/local/lib/libopencv_gapi.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_stitching.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_aruco.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_bgsegm.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_bioinspired.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_ccalib.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_dnn_objdetect.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_dnn_superres.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_dpm.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_face.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_freetype.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_fuzzy.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_hdf.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_hfs.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_img_hash.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_intensity_transform.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_line_descriptor.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_quality.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_rapid.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_reg.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_rgbd.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_saliency.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_sfm.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_stereo.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_structured_light.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_superres.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_surface_matching.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_tracking.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_videostab.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_xfeatures2d.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_xobjdetect.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_xphoto.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_highgui.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_shape.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_datasets.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_plot.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_text.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_dnn.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_ml.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_phase_unwrapping.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_optflow.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_ximgproc.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_video.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_videoio.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_imgcodecs.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_objdetect.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_calib3d.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_features2d.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_flann.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_photo.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_imgproc.so.4.2.0
DatasetLabelConvert: /usr/local/lib/libopencv_core.so.4.2.0
DatasetLabelConvert: CMakeFiles/DatasetLabelConvert.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable DatasetLabelConvert"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DatasetLabelConvert.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DatasetLabelConvert.dir/build: DatasetLabelConvert

.PHONY : CMakeFiles/DatasetLabelConvert.dir/build

CMakeFiles/DatasetLabelConvert.dir/requires: CMakeFiles/DatasetLabelConvert.dir/csvreader.cpp.o.requires
CMakeFiles/DatasetLabelConvert.dir/requires: CMakeFiles/DatasetLabelConvert.dir/main.cpp.o.requires
CMakeFiles/DatasetLabelConvert.dir/requires: CMakeFiles/DatasetLabelConvert.dir/toyoloconvert.cpp.o.requires
CMakeFiles/DatasetLabelConvert.dir/requires: CMakeFiles/DatasetLabelConvert.dir/trainvalspilit.cpp.o.requires

.PHONY : CMakeFiles/DatasetLabelConvert.dir/requires

CMakeFiles/DatasetLabelConvert.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DatasetLabelConvert.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DatasetLabelConvert.dir/clean

CMakeFiles/DatasetLabelConvert.dir/depend:
	cd /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert /home/adel/Projects/Cpp/ConvertDataSetLabel/DatasetLabelConvert/CMakeFiles/DatasetLabelConvert.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DatasetLabelConvert.dir/depend

