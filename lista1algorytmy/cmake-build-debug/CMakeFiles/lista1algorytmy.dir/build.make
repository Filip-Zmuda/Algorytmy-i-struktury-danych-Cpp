# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.3.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.3.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\filip\Documents\pulpit\CLionProjects\lista1algorytmy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\filip\Documents\pulpit\CLionProjects\lista1algorytmy\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lista1algorytmy.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lista1algorytmy.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lista1algorytmy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lista1algorytmy.dir/flags.make

CMakeFiles/lista1algorytmy.dir/main.cpp.obj: CMakeFiles/lista1algorytmy.dir/flags.make
CMakeFiles/lista1algorytmy.dir/main.cpp.obj: C:/Users/filip/Documents/pulpit/CLionProjects/lista1algorytmy/main.cpp
CMakeFiles/lista1algorytmy.dir/main.cpp.obj: CMakeFiles/lista1algorytmy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\filip\Documents\pulpit\CLionProjects\lista1algorytmy\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lista1algorytmy.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lista1algorytmy.dir/main.cpp.obj -MF CMakeFiles\lista1algorytmy.dir\main.cpp.obj.d -o CMakeFiles\lista1algorytmy.dir\main.cpp.obj -c C:\Users\filip\Documents\pulpit\CLionProjects\lista1algorytmy\main.cpp

CMakeFiles/lista1algorytmy.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/lista1algorytmy.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\filip\Documents\pulpit\CLionProjects\lista1algorytmy\main.cpp > CMakeFiles\lista1algorytmy.dir\main.cpp.i

CMakeFiles/lista1algorytmy.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/lista1algorytmy.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\filip\Documents\pulpit\CLionProjects\lista1algorytmy\main.cpp -o CMakeFiles\lista1algorytmy.dir\main.cpp.s

# Object files for target lista1algorytmy
lista1algorytmy_OBJECTS = \
"CMakeFiles/lista1algorytmy.dir/main.cpp.obj"

# External object files for target lista1algorytmy
lista1algorytmy_EXTERNAL_OBJECTS =

lista1algorytmy.exe: CMakeFiles/lista1algorytmy.dir/main.cpp.obj
lista1algorytmy.exe: CMakeFiles/lista1algorytmy.dir/build.make
lista1algorytmy.exe: CMakeFiles/lista1algorytmy.dir/linkLibs.rsp
lista1algorytmy.exe: CMakeFiles/lista1algorytmy.dir/objects1.rsp
lista1algorytmy.exe: CMakeFiles/lista1algorytmy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\filip\Documents\pulpit\CLionProjects\lista1algorytmy\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lista1algorytmy.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lista1algorytmy.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lista1algorytmy.dir/build: lista1algorytmy.exe
.PHONY : CMakeFiles/lista1algorytmy.dir/build

CMakeFiles/lista1algorytmy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lista1algorytmy.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lista1algorytmy.dir/clean

CMakeFiles/lista1algorytmy.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\filip\Documents\pulpit\CLionProjects\lista1algorytmy C:\Users\filip\Documents\pulpit\CLionProjects\lista1algorytmy C:\Users\filip\Documents\pulpit\CLionProjects\lista1algorytmy\cmake-build-debug C:\Users\filip\Documents\pulpit\CLionProjects\lista1algorytmy\cmake-build-debug C:\Users\filip\Documents\pulpit\CLionProjects\lista1algorytmy\cmake-build-debug\CMakeFiles\lista1algorytmy.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/lista1algorytmy.dir/depend

