
#Set this to @ to keep the makefile quiet
SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = PoemGenerator
TARGET_LIB = \
	lib/lib$(COMPONENT_NAME).a

SERVER_TARGET = \
	$(COMPONENT_NAME)_server

$(SERVER_TARGET):

TEST_TARGET = \
	$(COMPONENT_NAME)_tests
test: $(TEST_TARGET)

#--- Inputs ----#
PROJECT_HOME_DIR = .
CPPUTEST_HOME = ./CppUTest
CPP_PLATFORM = Gcc

#CFLAGS are set to override malloc and free to get memory leak detection in C programs
$(TEST_TARGET):CFLAGS = -Dmalloc=cpputest_malloc -Dfree=cpputest_free
$(TEST_TARGET):GCOVFLAGS = -fprofile-arcs -ftest-coverage
CPPFLAGS += -I$(CPPUTEST_HOME)/include
CXXFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorNewMacros.h
CFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorMallocMacros.h

LD_LIBRARIES = -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt
#SRC_DIRS is a list of source directories that make up the target library
#If test files are in these directories, their IMPORT_TEST_GROUPs need
#to be included in main to force them to be linked in.  By convention
#put them into an AllTests.h file in each directory
SRC_DIRS = \
	src/

#TEST_SRC_DIRS is a list of directories including 
# - A test main (AllTests.cpp by conventin)
# - OBJ files in these directories are included in the TEST_TARGET
# - Consequently - AllTests.h containing the IMPORT_TEST_GROUPS is not needed
# - 
TEST_SRC_DIRS = \
	tests \


#includes for all compiles	
INCLUDES =\
  -I.\
  -I$(CPPUTEST_HOME)/include/

#Flags to pass to ld
LDFLAGS +=

$(SERVER_TARGET): CFLAGS +=
$(SERVER_TARGET): GCOVFLAGS +=

include ComponentMakefile
