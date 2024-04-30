objects = main.o TestControl.o SpaceW.o PartFactory.o Part.o Date.o Rocket.o View.o

a4: $(objects)
	g++ -o a4 $(objects)

main.o: main.cc Date.h 
	g++ -c main.cc 

TestControl.o: TestControl.h TestControl.cc
	g++ -c TestControl.cc
	
View.o: View.cc View.h
	g++ -c View.cc
	
SpaceW.o: SpaceW.cc SpaceW.h
	g++ -c SpaceW.cc
	
Rocket.o: Rocket.cc Rocket.h
	g++ -c Rocket.cc

Date.o: Date.cc Date.h 
	g++ -c Date.cc

PartFactory.o: PartFactory.cc PartFactory.h
	g++ -c PartFactory.cc

Part.o: Part.cc Part.h
	g++ -c Part.cc
	

clean:
	rm -f a4 *.o *.gch

