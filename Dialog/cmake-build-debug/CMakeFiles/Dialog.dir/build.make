# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Artem\Desktop\Api\Dialog

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Artem\Desktop\Api\Dialog\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Dialog.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Dialog.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Dialog.dir/flags.make

CMakeFiles/Dialog.dir/main.cpp.obj: CMakeFiles/Dialog.dir/flags.make
CMakeFiles/Dialog.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Artem\Desktop\Api\Dialog\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Dialog.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Dialog.dir\main.cpp.obj -c C:\Users\Artem\Desktop\Api\Dialog\main.cpp

CMakeFiles/Dialog.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dialog.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Artem\Desktop\Api\Dialog\main.cpp > CMakeFiles\Dialog.dir\main.cpp.i

CMakeFiles/Dialog.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dialog.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Artem\Desktop\Api\Dialog\main.cpp -o CMakeFiles\Dialog.dir\main.cpp.s

CMakeFiles/Dialog.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Dialog.dir/main.cpp.obj.requires

CMakeFiles/Dialog.dir/main.cpp.obj.provides: CMakeFiles/Dialog.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Dialog.dir\build.make CMakeFiles/Dialog.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Dialog.dir/main.cpp.obj.provides

CMakeFiles/Dialog.dir/main.cpp.obj.provides.build: CMakeFiles/Dialog.dir/main.cpp.obj


CMakeFiles/Dialog.dir/WObject.cpp.obj: CMakeFiles/Dialog.dir/flags.make
CMakeFiles/Dialog.dir/WObject.cpp.obj: ../WObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Artem\Desktop\Api\Dialog\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Dialog.dir/WObject.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Dialog.dir\WObject.cpp.obj -c C:\Users\Artem\Desktop\Api\Dialog\WObject.cpp

CMakeFiles/Dialog.dir/WObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dialog.dir/WObject.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Artem\Desktop\Api\Dialog\WObject.cpp > CMakeFiles\Dialog.dir\WObject.cpp.i

CMakeFiles/Dialog.dir/WObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dialog.dir/WObject.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Artem\Desktop\Api\Dialog\WObject.cpp -o CMakeFiles\Dialog.dir\WObject.cpp.s

CMakeFiles/Dialog.dir/WObject.cpp.obj.requires:

.PHONY : CMakeFiles/Dialog.dir/WObject.cpp.obj.requires

CMakeFiles/Dialog.dir/WObject.cpp.obj.provides: CMakeFiles/Dialog.dir/WObject.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Dialog.dir\build.make CMakeFiles/Dialog.dir/WObject.cpp.obj.provides.build
.PHONY : CMakeFiles/Dialog.dir/WObject.cpp.obj.provides

CMakeFiles/Dialog.dir/WObject.cpp.obj.provides.build: CMakeFiles/Dialog.dir/WObject.cpp.obj


# Object files for target Dialog
Dialog_OBJECTS = \
"CMakeFiles/Dialog.dir/main.cpp.obj" \
"CMakeFiles/Dialog.dir/WObject.cpp.obj"

# External object files for target Dialog
Dialog_EXTERNAL_OBJECTS =

Dialog.exe: CMakeFiles/Dialog.dir/main.cpp.obj
Dialog.exe: CMakeFiles/Dialog.dir/WObject.cpp.obj
Dialog.exe: CMakeFiles/Dialog.dir/build.make
Dialog.exe: CMakeFiles/Dialog.dir/linklibs.rsp
Dialog.exe: CMakeFiles/Dialog.dir/objects1.rsp
Dialog.exe: CMakeFiles/Dialog.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Artem\Desktop\Api\Dialog\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Dialog.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Dialog.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Dialog.dir/build: Dialog.exe

.PHONY : CMakeFiles/Dialog.dir/build

CMakeFiles/Dialog.dir/requires: CMakeFiles/Dialog.dir/main.cpp.obj.requires
CMakeFiles/Dialog.dir/requires: CMakeFiles/Dialog.dir/WObject.cpp.obj.requires

.PHONY : CMakeFiles/Dialog.dir/requires

CMakeFiles/Dialog.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Dialog.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Dialog.dir/clean

CMakeFiles/Dialog.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Artem\Desktop\Api\Dialog C:\Users\Artem\Desktop\Api\Dialog C:\Users\Artem\Desktop\Api\Dialog\cmake-build-debug C:\Users\Artem\Desktop\Api\Dialog\cmake-build-debug C:\Users\Artem\Desktop\Api\Dialog\cmake-build-debug\CMakeFiles\Dialog.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Dialog.dir/depend
