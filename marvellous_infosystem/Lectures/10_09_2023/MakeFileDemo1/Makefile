exeName = myexe
mainFileName = Demo.c

#make -s

#all:Perform all operation on the code
all: info build run clean
#info:Project Description
info:
	echo "*************"
	echo "MakeFile Demo"
	echo "*************"
#build:compile the code
build:
	gcc $(mainFileName) -o $(exeName)
	echo "build completed"
#run:execute the code
run:
	echo "Output:"
	./$(exeName)
#clean:delete exe file
clean:
	rm $(exeName)
	echo "clean up completed"
