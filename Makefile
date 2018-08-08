#
# 'make depend' uses makedepend to automatically generate dependencies 
#			   (dependencies are added to end of Makefile)
# 'make'		build executable file './app.out'
# 'make clean'  removes all .o and executable files
#

#*# ************************************************************************ #*#

ifeq ($(origin CXX), default)
CXX = g++
endif
CXXFLAGS ?= -w -std=c++11 -O3

INCLUDES = 

LFLAGS = 

LIBS = 

SRCS = ./main.cc

HDR = ./ai.hh

MAIN = ./app.out

DESTDIR ?= /usr/local/include

#*# ************************************************************************ #*#

OBJS = $(SRCS:.cc=.o)

INSTLIB = $(INSTALL_DIR)/$(HDR)

.PHONY: depend clean

all: $(MAIN)
		@echo  $(MAIN) has been compiled
		
$(INSTLIB): 
		cp -vf $(HDR) $(DESTDIR)

$(MAIN): $(OBJS)
		$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.cc.o:
		$(CXX) $(CXXFLAGS) $(INCLUDES) -c $<  -o $@

clean:
		$(RM) ./*.o ./*~ $(MAIN)
		
install: $(INSTLIB)

depend: $(SRCS)
		makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE - make depend needs it