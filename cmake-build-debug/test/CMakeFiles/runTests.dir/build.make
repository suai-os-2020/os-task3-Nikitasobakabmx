# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\cmake-build-debug

# Include any dependencies generated for this target.
include test\CMakeFiles\runTests.dir\depend.make

# Include the progress variables for this target.
include test\CMakeFiles\runTests.dir\progress.make

# Include the compile flags for this target's objects.
include test\CMakeFiles\runTests.dir\flags.make

test\CMakeFiles\runTests.dir\__\lab3.cpp.obj: test\CMakeFiles\runTests.dir\flags.make
test\CMakeFiles\runTests.dir\__\lab3.cpp.obj: ..\lab3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/runTests.dir/__/lab3.cpp.obj"
	cd C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\cmake-build-debug\test
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\runTests.dir\__\lab3.cpp.obj /FdCMakeFiles\runTests.dir\ /FS -c C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\lab3.cpp
<<
	cd C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\cmake-build-debug

test\CMakeFiles\runTests.dir\__\lab3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/__/lab3.cpp.i"
	cd C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\cmake-build-debug\test
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe > CMakeFiles\runTests.dir\__\lab3.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\lab3.cpp
<<
	cd C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\cmake-build-debug

test\CMakeFiles\runTests.dir\__\lab3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/__/lab3.cpp.s"
	cd C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\cmake-build-debug\test
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\runTests.dir\__\lab3.cpp.s /c C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\lab3.cpp
<<
	cd C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\cmake-build-debug

test\CMakeFiles\runTests.dir\tests.cpp.obj: test\CMakeFiles\runTests.dir\flags.make
test\CMakeFiles\runTests.dir\tests.cpp.obj: ..\test\tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/runTests.dir/tests.cpp.obj"
	cd C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\cmake-build-debug\test
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\runTests.dir\tests.cpp.obj /FdCMakeFiles\runTests.dir\ /FS -c C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\test\tests.cpp
<<
	cd C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\cmake-build-debug

test\CMakeFiles\runTests.dir\tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/tests.cpp.i"
	cd C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\cmake-build-debug\test
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe > CMakeFiles\runTests.dir\tests.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\test\tests.cpp
<<
	cd C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\cmake-build-debug

test\CMakeFiles\runTests.dir\tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/tests.cpp.s"
	cd C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\cmake-build-debug\test
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\runTests.dir\tests.cpp.s /c C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\test\tests.cpp
<<
	cd C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\cmake-build-debug

# Object files for target runTests
runTests_OBJECTS = \
"CMakeFiles\runTests.dir\__\lab3.cpp.obj" \
"CMakeFiles\runTests.dir\tests.cpp.obj"

# External object files for target runTests
runTests_EXTERNAL_OBJECTS =

test\runTests.exe: test\CMakeFiles\runTests.dir\__\lab3.cpp.obj
test\runTests.exe: test\CMakeFiles\runTests.dir\tests.cpp.obj
test\runTests.exe: test\CMakeFiles\runTests.dir\build.make
test\runTests.exe: test\gtest\gtestd.lib
test\runTests.exe: test\gtest\gtest_maind.lib
test\runTests.exe: test\gtest\gtestd.lib
test\runTests.exe: test\CMakeFiles\runTests.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable runTests.exe"
	cd C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\cmake-build-debug\test
	"C:\Program Files\JetBrains\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\runTests.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1425~1.286\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\runTests.dir\objects1.rsp @<<
 /out:runTests.exe /implib:runTests.lib /pdb:C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\cmake-build-debug\test\runTests.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  gtest\gtestd.lib gtest\gtest_maind.lib gtest\gtestd.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<
	cd C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\cmake-build-debug

# Rule to build all files generated by this target.
test\CMakeFiles\runTests.dir\build: test\runTests.exe

.PHONY : test\CMakeFiles\runTests.dir\build

test\CMakeFiles\runTests.dir\clean:
	cd C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\cmake-build-debug\test
	$(CMAKE_COMMAND) -P CMakeFiles\runTests.dir\cmake_clean.cmake
	cd C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\cmake-build-debug
.PHONY : test\CMakeFiles\runTests.dir\clean

test\CMakeFiles\runTests.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\test C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\cmake-build-debug C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\cmake-build-debug\test C:\Users\Nikittossii\Documents\HiSuite\os-task3-Nikitasobakabmx\cmake-build-debug\test\CMakeFiles\runTests.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test\CMakeFiles\runTests.dir\depend

