#makefile

CC=g++

all: EyeDetection.exe

EyeDetection.exe: Circle.h CircleDetection.h DetectEdges.h FileIO.h Filters.h Image.h ValidateArguments.h VotingData.h Circle.cpp CircleDetection.cpp DetectEdges.cpp EyeDetection.cpp FileIO.cpp Filters.cpp Image.cpp ValidateArguments.cpp VotingData.cpp 
	$(CC) -o EyeDetection.exe Circle.h CircleDetection.h DetectEdges.h FileIO.h Filters.h Image.h ValidateArguments.h VotingData.h Circle.cpp CircleDetection.cpp DetectEdges.cpp EyeDetection.cpp FileIO.cpp Filters.cpp Image.cpp ValidateArguments.cpp VotingData.cpp 
