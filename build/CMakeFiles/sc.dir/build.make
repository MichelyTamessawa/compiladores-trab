# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/hudson/Desktop/Compiladores/compiladores-trab

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hudson/Desktop/Compiladores/compiladores-trab/build

# Include any dependencies generated for this target.
include CMakeFiles/sc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sc.dir/flags.make

parser.cc: ../parser.yy
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/hudson/Desktop/Compiladores/compiladores-trab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BISON][Parser] Building parser with bison 3.7.6"
	cd /home/hudson/Desktop/Compiladores/compiladores-trab && /usr/bin/bison -d -o /home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc parser.yy

parser.hh: parser.cc
	@$(CMAKE_COMMAND) -E touch_nocreate parser.hh

scanner.cc: ../scanner.ll
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/hudson/Desktop/Compiladores/compiladores-trab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "[FLEX][Scanner] Building scanner with flex 2.6.4"
	cd /home/hudson/Desktop/Compiladores/compiladores-trab && /usr/bin/flex -o/home/hudson/Desktop/Compiladores/compiladores-trab/build/scanner.cc scanner.ll

CMakeFiles/sc.dir/arvore.cc.o: CMakeFiles/sc.dir/flags.make
CMakeFiles/sc.dir/arvore.cc.o: ../arvore.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hudson/Desktop/Compiladores/compiladores-trab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sc.dir/arvore.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sc.dir/arvore.cc.o -c /home/hudson/Desktop/Compiladores/compiladores-trab/arvore.cc

CMakeFiles/sc.dir/arvore.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sc.dir/arvore.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hudson/Desktop/Compiladores/compiladores-trab/arvore.cc > CMakeFiles/sc.dir/arvore.cc.i

CMakeFiles/sc.dir/arvore.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sc.dir/arvore.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hudson/Desktop/Compiladores/compiladores-trab/arvore.cc -o CMakeFiles/sc.dir/arvore.cc.s

CMakeFiles/sc.dir/biblioteca.cc.o: CMakeFiles/sc.dir/flags.make
CMakeFiles/sc.dir/biblioteca.cc.o: ../biblioteca.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hudson/Desktop/Compiladores/compiladores-trab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sc.dir/biblioteca.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sc.dir/biblioteca.cc.o -c /home/hudson/Desktop/Compiladores/compiladores-trab/biblioteca.cc

CMakeFiles/sc.dir/biblioteca.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sc.dir/biblioteca.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hudson/Desktop/Compiladores/compiladores-trab/biblioteca.cc > CMakeFiles/sc.dir/biblioteca.cc.i

CMakeFiles/sc.dir/biblioteca.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sc.dir/biblioteca.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hudson/Desktop/Compiladores/compiladores-trab/biblioteca.cc -o CMakeFiles/sc.dir/biblioteca.cc.s

CMakeFiles/sc.dir/codeobject.cc.o: CMakeFiles/sc.dir/flags.make
CMakeFiles/sc.dir/codeobject.cc.o: ../codeobject.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hudson/Desktop/Compiladores/compiladores-trab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sc.dir/codeobject.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sc.dir/codeobject.cc.o -c /home/hudson/Desktop/Compiladores/compiladores-trab/codeobject.cc

CMakeFiles/sc.dir/codeobject.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sc.dir/codeobject.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hudson/Desktop/Compiladores/compiladores-trab/codeobject.cc > CMakeFiles/sc.dir/codeobject.cc.i

CMakeFiles/sc.dir/codeobject.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sc.dir/codeobject.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hudson/Desktop/Compiladores/compiladores-trab/codeobject.cc -o CMakeFiles/sc.dir/codeobject.cc.s

CMakeFiles/sc.dir/driver.cc.o: CMakeFiles/sc.dir/flags.make
CMakeFiles/sc.dir/driver.cc.o: ../driver.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hudson/Desktop/Compiladores/compiladores-trab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/sc.dir/driver.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sc.dir/driver.cc.o -c /home/hudson/Desktop/Compiladores/compiladores-trab/driver.cc

CMakeFiles/sc.dir/driver.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sc.dir/driver.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hudson/Desktop/Compiladores/compiladores-trab/driver.cc > CMakeFiles/sc.dir/driver.cc.i

CMakeFiles/sc.dir/driver.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sc.dir/driver.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hudson/Desktop/Compiladores/compiladores-trab/driver.cc -o CMakeFiles/sc.dir/driver.cc.s

CMakeFiles/sc.dir/lib_externa.cc.o: CMakeFiles/sc.dir/flags.make
CMakeFiles/sc.dir/lib_externa.cc.o: ../lib_externa.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hudson/Desktop/Compiladores/compiladores-trab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/sc.dir/lib_externa.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sc.dir/lib_externa.cc.o -c /home/hudson/Desktop/Compiladores/compiladores-trab/lib_externa.cc

CMakeFiles/sc.dir/lib_externa.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sc.dir/lib_externa.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hudson/Desktop/Compiladores/compiladores-trab/lib_externa.cc > CMakeFiles/sc.dir/lib_externa.cc.i

CMakeFiles/sc.dir/lib_externa.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sc.dir/lib_externa.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hudson/Desktop/Compiladores/compiladores-trab/lib_externa.cc -o CMakeFiles/sc.dir/lib_externa.cc.s

CMakeFiles/sc.dir/main.cc.o: CMakeFiles/sc.dir/flags.make
CMakeFiles/sc.dir/main.cc.o: ../main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hudson/Desktop/Compiladores/compiladores-trab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/sc.dir/main.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sc.dir/main.cc.o -c /home/hudson/Desktop/Compiladores/compiladores-trab/main.cc

CMakeFiles/sc.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sc.dir/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hudson/Desktop/Compiladores/compiladores-trab/main.cc > CMakeFiles/sc.dir/main.cc.i

CMakeFiles/sc.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sc.dir/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hudson/Desktop/Compiladores/compiladores-trab/main.cc -o CMakeFiles/sc.dir/main.cc.s

CMakeFiles/sc.dir/semantic.cc.o: CMakeFiles/sc.dir/flags.make
CMakeFiles/sc.dir/semantic.cc.o: ../semantic.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hudson/Desktop/Compiladores/compiladores-trab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/sc.dir/semantic.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sc.dir/semantic.cc.o -c /home/hudson/Desktop/Compiladores/compiladores-trab/semantic.cc

CMakeFiles/sc.dir/semantic.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sc.dir/semantic.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hudson/Desktop/Compiladores/compiladores-trab/semantic.cc > CMakeFiles/sc.dir/semantic.cc.i

CMakeFiles/sc.dir/semantic.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sc.dir/semantic.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hudson/Desktop/Compiladores/compiladores-trab/semantic.cc -o CMakeFiles/sc.dir/semantic.cc.s

CMakeFiles/sc.dir/symbol.cc.o: CMakeFiles/sc.dir/flags.make
CMakeFiles/sc.dir/symbol.cc.o: ../symbol.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hudson/Desktop/Compiladores/compiladores-trab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/sc.dir/symbol.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sc.dir/symbol.cc.o -c /home/hudson/Desktop/Compiladores/compiladores-trab/symbol.cc

CMakeFiles/sc.dir/symbol.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sc.dir/symbol.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hudson/Desktop/Compiladores/compiladores-trab/symbol.cc > CMakeFiles/sc.dir/symbol.cc.i

CMakeFiles/sc.dir/symbol.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sc.dir/symbol.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hudson/Desktop/Compiladores/compiladores-trab/symbol.cc -o CMakeFiles/sc.dir/symbol.cc.s

CMakeFiles/sc.dir/table.cc.o: CMakeFiles/sc.dir/flags.make
CMakeFiles/sc.dir/table.cc.o: ../table.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hudson/Desktop/Compiladores/compiladores-trab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/sc.dir/table.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sc.dir/table.cc.o -c /home/hudson/Desktop/Compiladores/compiladores-trab/table.cc

CMakeFiles/sc.dir/table.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sc.dir/table.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hudson/Desktop/Compiladores/compiladores-trab/table.cc > CMakeFiles/sc.dir/table.cc.i

CMakeFiles/sc.dir/table.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sc.dir/table.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hudson/Desktop/Compiladores/compiladores-trab/table.cc -o CMakeFiles/sc.dir/table.cc.s

CMakeFiles/sc.dir/scanner.cc.o: CMakeFiles/sc.dir/flags.make
CMakeFiles/sc.dir/scanner.cc.o: scanner.cc
CMakeFiles/sc.dir/scanner.cc.o: parser.hh
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hudson/Desktop/Compiladores/compiladores-trab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/sc.dir/scanner.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sc.dir/scanner.cc.o -c /home/hudson/Desktop/Compiladores/compiladores-trab/build/scanner.cc

CMakeFiles/sc.dir/scanner.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sc.dir/scanner.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hudson/Desktop/Compiladores/compiladores-trab/build/scanner.cc > CMakeFiles/sc.dir/scanner.cc.i

CMakeFiles/sc.dir/scanner.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sc.dir/scanner.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hudson/Desktop/Compiladores/compiladores-trab/build/scanner.cc -o CMakeFiles/sc.dir/scanner.cc.s

CMakeFiles/sc.dir/parser.cc.o: CMakeFiles/sc.dir/flags.make
CMakeFiles/sc.dir/parser.cc.o: parser.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hudson/Desktop/Compiladores/compiladores-trab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/sc.dir/parser.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sc.dir/parser.cc.o -c /home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc

CMakeFiles/sc.dir/parser.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sc.dir/parser.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc > CMakeFiles/sc.dir/parser.cc.i

CMakeFiles/sc.dir/parser.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sc.dir/parser.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hudson/Desktop/Compiladores/compiladores-trab/build/parser.cc -o CMakeFiles/sc.dir/parser.cc.s

# Object files for target sc
sc_OBJECTS = \
"CMakeFiles/sc.dir/arvore.cc.o" \
"CMakeFiles/sc.dir/biblioteca.cc.o" \
"CMakeFiles/sc.dir/codeobject.cc.o" \
"CMakeFiles/sc.dir/driver.cc.o" \
"CMakeFiles/sc.dir/lib_externa.cc.o" \
"CMakeFiles/sc.dir/main.cc.o" \
"CMakeFiles/sc.dir/semantic.cc.o" \
"CMakeFiles/sc.dir/symbol.cc.o" \
"CMakeFiles/sc.dir/table.cc.o" \
"CMakeFiles/sc.dir/scanner.cc.o" \
"CMakeFiles/sc.dir/parser.cc.o"

# External object files for target sc
sc_EXTERNAL_OBJECTS =

../sc: CMakeFiles/sc.dir/arvore.cc.o
../sc: CMakeFiles/sc.dir/biblioteca.cc.o
../sc: CMakeFiles/sc.dir/codeobject.cc.o
../sc: CMakeFiles/sc.dir/driver.cc.o
../sc: CMakeFiles/sc.dir/lib_externa.cc.o
../sc: CMakeFiles/sc.dir/main.cc.o
../sc: CMakeFiles/sc.dir/semantic.cc.o
../sc: CMakeFiles/sc.dir/symbol.cc.o
../sc: CMakeFiles/sc.dir/table.cc.o
../sc: CMakeFiles/sc.dir/scanner.cc.o
../sc: CMakeFiles/sc.dir/parser.cc.o
../sc: CMakeFiles/sc.dir/build.make
../sc: CMakeFiles/sc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hudson/Desktop/Compiladores/compiladores-trab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX executable ../sc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sc.dir/build: ../sc

.PHONY : CMakeFiles/sc.dir/build

CMakeFiles/sc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sc.dir/clean

CMakeFiles/sc.dir/depend: parser.cc
CMakeFiles/sc.dir/depend: parser.hh
CMakeFiles/sc.dir/depend: scanner.cc
	cd /home/hudson/Desktop/Compiladores/compiladores-trab/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hudson/Desktop/Compiladores/compiladores-trab /home/hudson/Desktop/Compiladores/compiladores-trab /home/hudson/Desktop/Compiladores/compiladores-trab/build /home/hudson/Desktop/Compiladores/compiladores-trab/build /home/hudson/Desktop/Compiladores/compiladores-trab/build/CMakeFiles/sc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sc.dir/depend

