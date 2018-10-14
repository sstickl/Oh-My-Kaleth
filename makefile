#OBJS specifies which files to compile as part of the project
OBJS = main.cpp src/error.cpp src/graphicscontroller.cpp src/image.cpp

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = omk.exe

#This is the target that compiles our executable
all : $(OBJS)
	g++ $(OBJS) -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o bin/$(OBJ_NAME)