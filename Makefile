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
CFLAGS ?= -w -std=c++11 -O3

INCLUDES = 

LFLAGS = 

LIBS = 

SRCS = ./main.cc

MAIN = ./app.out

#*# ************************************************************************ #*#

OBJS = $(SRCS:.cc=.o)

.PHONY: depend clean

all:	$(MAIN)
		@echo  $(MAIN) has been compiled

$(MAIN): $(OBJS) 
		$(CXX) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.cc.o:
		$(CXX) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
		$(RM) ./*.o ./*~ $(MAIN)

depend: $(SRCS)
		makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE - make depend needs it