TORM = file_parser.o driver.o driver

CC = g++
CCFLAGS = -g -O3 -Wall -Wno-deprecated -Wpointer-arith -Wcast-qual -Wwrite-strings

driver: driver.o file_parser.o
        ${CC} ${CCFLAGS} -o driver driver.o file_parser.o 
    
driver.o:       driver.cpp 
        ${CC} ${CCFLAGS} -c driver.cpp
    
file_parser.o:  file_parser.cc file_parser.h file_parse_exception.h
        ${CC} ${CCFLAGS} -c file_parser.cc  
clean:
        rm -f ${TORM}
