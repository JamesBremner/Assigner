#source file search paths
VPATH = ./src 

	# compiler include search paths
INCS = -I./include \
	-I../raven-set \


LIBS = \
	-lgdiplus -lgdi32 -lcomdlg32 -lstdc++fs \


static_link_flags = -static-libstdc++ -static-libgcc -static -lComctl32

# folders
ODIR = ./.vscode/obj

OPT = -g
CCflags = -std=c++17 $(OPT) -D_mingw_

# sources
OBJ_starter = \
	$(ODIR)/main.o \
	$(ODIR)/input.o \
	$(ODIR)/cAgent.o \
	$(ODIR)/cTask.o \
	$(ODIR)/cSlot.o \
	$(ODIR)/cAssign.o \
	$(ODIR)/unitTest.o \

#includes
OBJ_includes = \
	cTask.h \
	cAgent.h \
	cAssign.h \
	cSlot.h \

### COMPILE

$(ODIR)/%.o: %.cpp  $(OBJ_includes)
	g++ $<  \
	-c -o $@  $(INCS) $(CCflags)

a2t: $(OBJ_starter)
	g++ $(OPT) \
	-o bin/Agents2Tasks.exe $^  \
	$(static_link_flags) $(LIBS)

.PHONY: clean
clean:
	del /q .vscode\\obj\\*.o

