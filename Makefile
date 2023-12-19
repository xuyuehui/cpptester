CC = g++
CLANG = clang++
CFLAGS = -g -std=c++11 -std=c++0x -Wall -Wextra
OBJCFLAGS := -framework Cocoa

SOURCEDIR  	:= .
INCLUDEDIR 	:= .
BUILDDIR 	:= build
DEMODIR 	= demos
DEMOSRC 	:= $(wildcard $(addprefix $(DEMODIR)/, *.cpp))
DEMOOBJS 	:= $(addprefix $(BUILDDIR)/$(DEMODIR)/, $(notdir $(DEMOSRC:.cpp=.o)))
SOURCES  	:= $(wildcard $(addprefix $(SOURCEDIR)/, *.cpp))
OBJECTS 	:= $(addprefix $(BUILDDIR)/, $(notdir $(SOURCES:.cpp=.o))) $(DEMOOBJS)
TARGET 		:= cpptester

HEADERS 	:= $(wildcard $(addprefix $(INCLUDEDIR)/, *.h))

INCLUDES 		:= -I$(INCLUDEDIR)
DEMOINCLUDES 	:= -I$(DEMODIR) $(INCLUDES)

MD := mkdir -p

ifeq ($(OS), Windows_NT)
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S), Linux)
		CFLAGS += -D LINUX
	endif

	ifeq ($(UNAME_S), Darwin)
		CFLAGS += -D OSX
	endif
endif

macos: macos_prepare macos_compile

macos_prepare: 
	@$(MD) $(BUILDDIR)
	@$(MD) $(BUILDDIR)/$(DEMODIR)

macos_compile: $(OBJECTS)
	@$(CC) -o $(TARGET) $(OBJCFLAGS) $(CFLAGS) $(OBJECTS)

$(TARGET) : $(OBJECTS)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

$(BUILDDIR)/%.o : $(SOURCEDIR)/%.cpp $(HEADERS)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(BUILDDIR)/$(DEMODIR)/%.o : $(DEMODIR)/%.cpp $(HEADERS)
	@$(CC) $(CFLAGS) $(DEMOINCLUDES) -o $@ -c $<

