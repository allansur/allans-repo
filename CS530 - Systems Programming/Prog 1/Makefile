##################################
#XBD Makefile for CS530 Project #1 
#Allan Sur
##################################
xbd: hexdump.o
	g++ hexdump.o -o xbd

hexdump.o: hexdump.cpp
	g++ -c hexdump.cpp

clean:
	rm *.o xbd