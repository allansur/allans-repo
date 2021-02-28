/* 
Names: Allan Sur, Jason Songvilay
RedIDs: 821444631, 821071661
Edoras IDs: cssc3455, cssc3454
Course: CS530-03-Spring2021
Assignment 2: Part II
23 February, 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

extern "C" void * progress_monitor(void *parameter)  //We needed this to use pthreads as it's a C function 

class WordCount
{
public:
    void *progress_monitor(void *);
    long wordcount(string filename);
    int main(int argc, char **argv);
};