# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yanik/qtProjects/seededImgSeg2/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yanik/qtProjects/seededImgSeg2/build

# Include any dependencies generated for this target.
include common/CMakeFiles/common.dir/depend.make

# Include the progress variables for this target.
include common/CMakeFiles/common.dir/progress.make

# Include the compile flags for this target's objects.
include common/CMakeFiles/common.dir/flags.make

common/CMakeFiles/common.dir/moc_mainwindow.cpp.o: common/CMakeFiles/common.dir/flags.make
common/CMakeFiles/common.dir/moc_mainwindow.cpp.o: /home/yanik/qtProjects/seededImgSeg2/src/common/moc_mainwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yanik/qtProjects/seededImgSeg2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object common/CMakeFiles/common.dir/moc_mainwindow.cpp.o"
	cd /home/yanik/qtProjects/seededImgSeg2/build/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/common.dir/moc_mainwindow.cpp.o -c /home/yanik/qtProjects/seededImgSeg2/src/common/moc_mainwindow.cpp

common/CMakeFiles/common.dir/moc_mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/moc_mainwindow.cpp.i"
	cd /home/yanik/qtProjects/seededImgSeg2/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yanik/qtProjects/seededImgSeg2/src/common/moc_mainwindow.cpp > CMakeFiles/common.dir/moc_mainwindow.cpp.i

common/CMakeFiles/common.dir/moc_mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/moc_mainwindow.cpp.s"
	cd /home/yanik/qtProjects/seededImgSeg2/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yanik/qtProjects/seededImgSeg2/src/common/moc_mainwindow.cpp -o CMakeFiles/common.dir/moc_mainwindow.cpp.s

common/CMakeFiles/common.dir/moc_mainwindow.cpp.o.requires:

.PHONY : common/CMakeFiles/common.dir/moc_mainwindow.cpp.o.requires

common/CMakeFiles/common.dir/moc_mainwindow.cpp.o.provides: common/CMakeFiles/common.dir/moc_mainwindow.cpp.o.requires
	$(MAKE) -f common/CMakeFiles/common.dir/build.make common/CMakeFiles/common.dir/moc_mainwindow.cpp.o.provides.build
.PHONY : common/CMakeFiles/common.dir/moc_mainwindow.cpp.o.provides

common/CMakeFiles/common.dir/moc_mainwindow.cpp.o.provides.build: common/CMakeFiles/common.dir/moc_mainwindow.cpp.o


common/CMakeFiles/common.dir/engine.cpp.o: common/CMakeFiles/common.dir/flags.make
common/CMakeFiles/common.dir/engine.cpp.o: /home/yanik/qtProjects/seededImgSeg2/src/common/engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yanik/qtProjects/seededImgSeg2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object common/CMakeFiles/common.dir/engine.cpp.o"
	cd /home/yanik/qtProjects/seededImgSeg2/build/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/common.dir/engine.cpp.o -c /home/yanik/qtProjects/seededImgSeg2/src/common/engine.cpp

common/CMakeFiles/common.dir/engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/engine.cpp.i"
	cd /home/yanik/qtProjects/seededImgSeg2/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yanik/qtProjects/seededImgSeg2/src/common/engine.cpp > CMakeFiles/common.dir/engine.cpp.i

common/CMakeFiles/common.dir/engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/engine.cpp.s"
	cd /home/yanik/qtProjects/seededImgSeg2/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yanik/qtProjects/seededImgSeg2/src/common/engine.cpp -o CMakeFiles/common.dir/engine.cpp.s

common/CMakeFiles/common.dir/engine.cpp.o.requires:

.PHONY : common/CMakeFiles/common.dir/engine.cpp.o.requires

common/CMakeFiles/common.dir/engine.cpp.o.provides: common/CMakeFiles/common.dir/engine.cpp.o.requires
	$(MAKE) -f common/CMakeFiles/common.dir/build.make common/CMakeFiles/common.dir/engine.cpp.o.provides.build
.PHONY : common/CMakeFiles/common.dir/engine.cpp.o.provides

common/CMakeFiles/common.dir/engine.cpp.o.provides.build: common/CMakeFiles/common.dir/engine.cpp.o


common/CMakeFiles/common.dir/moc_imglabel.cpp.o: common/CMakeFiles/common.dir/flags.make
common/CMakeFiles/common.dir/moc_imglabel.cpp.o: /home/yanik/qtProjects/seededImgSeg2/src/common/moc_imglabel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yanik/qtProjects/seededImgSeg2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object common/CMakeFiles/common.dir/moc_imglabel.cpp.o"
	cd /home/yanik/qtProjects/seededImgSeg2/build/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/common.dir/moc_imglabel.cpp.o -c /home/yanik/qtProjects/seededImgSeg2/src/common/moc_imglabel.cpp

common/CMakeFiles/common.dir/moc_imglabel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/moc_imglabel.cpp.i"
	cd /home/yanik/qtProjects/seededImgSeg2/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yanik/qtProjects/seededImgSeg2/src/common/moc_imglabel.cpp > CMakeFiles/common.dir/moc_imglabel.cpp.i

common/CMakeFiles/common.dir/moc_imglabel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/moc_imglabel.cpp.s"
	cd /home/yanik/qtProjects/seededImgSeg2/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yanik/qtProjects/seededImgSeg2/src/common/moc_imglabel.cpp -o CMakeFiles/common.dir/moc_imglabel.cpp.s

common/CMakeFiles/common.dir/moc_imglabel.cpp.o.requires:

.PHONY : common/CMakeFiles/common.dir/moc_imglabel.cpp.o.requires

common/CMakeFiles/common.dir/moc_imglabel.cpp.o.provides: common/CMakeFiles/common.dir/moc_imglabel.cpp.o.requires
	$(MAKE) -f common/CMakeFiles/common.dir/build.make common/CMakeFiles/common.dir/moc_imglabel.cpp.o.provides.build
.PHONY : common/CMakeFiles/common.dir/moc_imglabel.cpp.o.provides

common/CMakeFiles/common.dir/moc_imglabel.cpp.o.provides.build: common/CMakeFiles/common.dir/moc_imglabel.cpp.o


common/CMakeFiles/common.dir/mainwindow.cpp.o: common/CMakeFiles/common.dir/flags.make
common/CMakeFiles/common.dir/mainwindow.cpp.o: /home/yanik/qtProjects/seededImgSeg2/src/common/mainwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yanik/qtProjects/seededImgSeg2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object common/CMakeFiles/common.dir/mainwindow.cpp.o"
	cd /home/yanik/qtProjects/seededImgSeg2/build/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/common.dir/mainwindow.cpp.o -c /home/yanik/qtProjects/seededImgSeg2/src/common/mainwindow.cpp

common/CMakeFiles/common.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/mainwindow.cpp.i"
	cd /home/yanik/qtProjects/seededImgSeg2/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yanik/qtProjects/seededImgSeg2/src/common/mainwindow.cpp > CMakeFiles/common.dir/mainwindow.cpp.i

common/CMakeFiles/common.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/mainwindow.cpp.s"
	cd /home/yanik/qtProjects/seededImgSeg2/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yanik/qtProjects/seededImgSeg2/src/common/mainwindow.cpp -o CMakeFiles/common.dir/mainwindow.cpp.s

common/CMakeFiles/common.dir/mainwindow.cpp.o.requires:

.PHONY : common/CMakeFiles/common.dir/mainwindow.cpp.o.requires

common/CMakeFiles/common.dir/mainwindow.cpp.o.provides: common/CMakeFiles/common.dir/mainwindow.cpp.o.requires
	$(MAKE) -f common/CMakeFiles/common.dir/build.make common/CMakeFiles/common.dir/mainwindow.cpp.o.provides.build
.PHONY : common/CMakeFiles/common.dir/mainwindow.cpp.o.provides

common/CMakeFiles/common.dir/mainwindow.cpp.o.provides.build: common/CMakeFiles/common.dir/mainwindow.cpp.o


common/CMakeFiles/common.dir/imglabel.cpp.o: common/CMakeFiles/common.dir/flags.make
common/CMakeFiles/common.dir/imglabel.cpp.o: /home/yanik/qtProjects/seededImgSeg2/src/common/imglabel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yanik/qtProjects/seededImgSeg2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object common/CMakeFiles/common.dir/imglabel.cpp.o"
	cd /home/yanik/qtProjects/seededImgSeg2/build/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/common.dir/imglabel.cpp.o -c /home/yanik/qtProjects/seededImgSeg2/src/common/imglabel.cpp

common/CMakeFiles/common.dir/imglabel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/imglabel.cpp.i"
	cd /home/yanik/qtProjects/seededImgSeg2/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yanik/qtProjects/seededImgSeg2/src/common/imglabel.cpp > CMakeFiles/common.dir/imglabel.cpp.i

common/CMakeFiles/common.dir/imglabel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/imglabel.cpp.s"
	cd /home/yanik/qtProjects/seededImgSeg2/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yanik/qtProjects/seededImgSeg2/src/common/imglabel.cpp -o CMakeFiles/common.dir/imglabel.cpp.s

common/CMakeFiles/common.dir/imglabel.cpp.o.requires:

.PHONY : common/CMakeFiles/common.dir/imglabel.cpp.o.requires

common/CMakeFiles/common.dir/imglabel.cpp.o.provides: common/CMakeFiles/common.dir/imglabel.cpp.o.requires
	$(MAKE) -f common/CMakeFiles/common.dir/build.make common/CMakeFiles/common.dir/imglabel.cpp.o.provides.build
.PHONY : common/CMakeFiles/common.dir/imglabel.cpp.o.provides

common/CMakeFiles/common.dir/imglabel.cpp.o.provides.build: common/CMakeFiles/common.dir/imglabel.cpp.o


common/CMakeFiles/common.dir/utilities.cpp.o: common/CMakeFiles/common.dir/flags.make
common/CMakeFiles/common.dir/utilities.cpp.o: /home/yanik/qtProjects/seededImgSeg2/src/common/utilities.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yanik/qtProjects/seededImgSeg2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object common/CMakeFiles/common.dir/utilities.cpp.o"
	cd /home/yanik/qtProjects/seededImgSeg2/build/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/common.dir/utilities.cpp.o -c /home/yanik/qtProjects/seededImgSeg2/src/common/utilities.cpp

common/CMakeFiles/common.dir/utilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/utilities.cpp.i"
	cd /home/yanik/qtProjects/seededImgSeg2/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yanik/qtProjects/seededImgSeg2/src/common/utilities.cpp > CMakeFiles/common.dir/utilities.cpp.i

common/CMakeFiles/common.dir/utilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/utilities.cpp.s"
	cd /home/yanik/qtProjects/seededImgSeg2/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yanik/qtProjects/seededImgSeg2/src/common/utilities.cpp -o CMakeFiles/common.dir/utilities.cpp.s

common/CMakeFiles/common.dir/utilities.cpp.o.requires:

.PHONY : common/CMakeFiles/common.dir/utilities.cpp.o.requires

common/CMakeFiles/common.dir/utilities.cpp.o.provides: common/CMakeFiles/common.dir/utilities.cpp.o.requires
	$(MAKE) -f common/CMakeFiles/common.dir/build.make common/CMakeFiles/common.dir/utilities.cpp.o.provides.build
.PHONY : common/CMakeFiles/common.dir/utilities.cpp.o.provides

common/CMakeFiles/common.dir/utilities.cpp.o.provides.build: common/CMakeFiles/common.dir/utilities.cpp.o


common/CMakeFiles/common.dir/common_automoc.cpp.o: common/CMakeFiles/common.dir/flags.make
common/CMakeFiles/common.dir/common_automoc.cpp.o: /home/yanik/qtProjects/seededImgSeg2/src/common/common_automoc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yanik/qtProjects/seededImgSeg2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object common/CMakeFiles/common.dir/common_automoc.cpp.o"
	cd /home/yanik/qtProjects/seededImgSeg2/build/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/common.dir/common_automoc.cpp.o -c /home/yanik/qtProjects/seededImgSeg2/src/common/common_automoc.cpp

common/CMakeFiles/common.dir/common_automoc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/common_automoc.cpp.i"
	cd /home/yanik/qtProjects/seededImgSeg2/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yanik/qtProjects/seededImgSeg2/src/common/common_automoc.cpp > CMakeFiles/common.dir/common_automoc.cpp.i

common/CMakeFiles/common.dir/common_automoc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/common_automoc.cpp.s"
	cd /home/yanik/qtProjects/seededImgSeg2/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yanik/qtProjects/seededImgSeg2/src/common/common_automoc.cpp -o CMakeFiles/common.dir/common_automoc.cpp.s

common/CMakeFiles/common.dir/common_automoc.cpp.o.requires:

.PHONY : common/CMakeFiles/common.dir/common_automoc.cpp.o.requires

common/CMakeFiles/common.dir/common_automoc.cpp.o.provides: common/CMakeFiles/common.dir/common_automoc.cpp.o.requires
	$(MAKE) -f common/CMakeFiles/common.dir/build.make common/CMakeFiles/common.dir/common_automoc.cpp.o.provides.build
.PHONY : common/CMakeFiles/common.dir/common_automoc.cpp.o.provides

common/CMakeFiles/common.dir/common_automoc.cpp.o.provides.build: common/CMakeFiles/common.dir/common_automoc.cpp.o


# Object files for target common
common_OBJECTS = \
"CMakeFiles/common.dir/moc_mainwindow.cpp.o" \
"CMakeFiles/common.dir/engine.cpp.o" \
"CMakeFiles/common.dir/moc_imglabel.cpp.o" \
"CMakeFiles/common.dir/mainwindow.cpp.o" \
"CMakeFiles/common.dir/imglabel.cpp.o" \
"CMakeFiles/common.dir/utilities.cpp.o" \
"CMakeFiles/common.dir/common_automoc.cpp.o"

# External object files for target common
common_EXTERNAL_OBJECTS =

common/libcommon.a: common/CMakeFiles/common.dir/moc_mainwindow.cpp.o
common/libcommon.a: common/CMakeFiles/common.dir/engine.cpp.o
common/libcommon.a: common/CMakeFiles/common.dir/moc_imglabel.cpp.o
common/libcommon.a: common/CMakeFiles/common.dir/mainwindow.cpp.o
common/libcommon.a: common/CMakeFiles/common.dir/imglabel.cpp.o
common/libcommon.a: common/CMakeFiles/common.dir/utilities.cpp.o
common/libcommon.a: common/CMakeFiles/common.dir/common_automoc.cpp.o
common/libcommon.a: common/CMakeFiles/common.dir/build.make
common/libcommon.a: common/CMakeFiles/common.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yanik/qtProjects/seededImgSeg2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library libcommon.a"
	cd /home/yanik/qtProjects/seededImgSeg2/build/common && $(CMAKE_COMMAND) -P CMakeFiles/common.dir/cmake_clean_target.cmake
	cd /home/yanik/qtProjects/seededImgSeg2/build/common && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/common.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
common/CMakeFiles/common.dir/build: common/libcommon.a

.PHONY : common/CMakeFiles/common.dir/build

common/CMakeFiles/common.dir/requires: common/CMakeFiles/common.dir/moc_mainwindow.cpp.o.requires
common/CMakeFiles/common.dir/requires: common/CMakeFiles/common.dir/engine.cpp.o.requires
common/CMakeFiles/common.dir/requires: common/CMakeFiles/common.dir/moc_imglabel.cpp.o.requires
common/CMakeFiles/common.dir/requires: common/CMakeFiles/common.dir/mainwindow.cpp.o.requires
common/CMakeFiles/common.dir/requires: common/CMakeFiles/common.dir/imglabel.cpp.o.requires
common/CMakeFiles/common.dir/requires: common/CMakeFiles/common.dir/utilities.cpp.o.requires
common/CMakeFiles/common.dir/requires: common/CMakeFiles/common.dir/common_automoc.cpp.o.requires

.PHONY : common/CMakeFiles/common.dir/requires

common/CMakeFiles/common.dir/clean:
	cd /home/yanik/qtProjects/seededImgSeg2/build/common && $(CMAKE_COMMAND) -P CMakeFiles/common.dir/cmake_clean.cmake
.PHONY : common/CMakeFiles/common.dir/clean

common/CMakeFiles/common.dir/depend:
	cd /home/yanik/qtProjects/seededImgSeg2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yanik/qtProjects/seededImgSeg2/src /home/yanik/qtProjects/seededImgSeg2/src/common /home/yanik/qtProjects/seededImgSeg2/build /home/yanik/qtProjects/seededImgSeg2/build/common /home/yanik/qtProjects/seededImgSeg2/build/common/CMakeFiles/common.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : common/CMakeFiles/common.dir/depend
