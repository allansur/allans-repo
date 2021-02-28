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


typedef struct { //Defined our structure for our progress bar
    long *CurrentStatus;
    long InitialValue;
    long TerminationValue;
} PROGRESS_STATUS;

void* progress_monitor(void* parameter) {
    PROGRESS_STATUS *prog_stat = (PROGRESS_STATUS *) parameter;
    int count = 0; // printed characters
    int holder = 0; // hold 50 characters to be printed
   
   // While there are < 50 characters in the progress bar
    while(count < 50) { 
        // amount of characters = int (double (*CurrentStatus - InitialValue) / TerminationValue * 50)
        // int ((40 current val - 0 initial val / termination value) * 50 characters)
        // Had to cast to doubles as longs do NOT hold decimal places (Learned the hard way)
         holder = (int)((double)((*prog_stat->CurrentStatus)-(prog_stat->InitialValue)) / (prog_stat->TerminationValue)*50);
         while(count < holder) {
             if(count % 10 == 0) { 
               cout << "+" << flush; // + for every 10,20,30,40th character
             } else if(count == 49){
               cout << "+" << flush; // + when count reaches the 2nd to last character
             } else { 
               cout << "-" << flush; // - for everything else
             }
            count++;
        }
    }
    pthread_exit(0); //Exit the thread
    return NULL; //For a void method we don't have to return anything so we returned NULL
}

long wordcount(string filename) { //Input filename to parse the file
    // initialize count, index, and struct to hold amount of bytes
    int wordCount = 0;
    long index = 0;
    struct stat stats; //Defined our stats structure

    // open file, print error if file not found
    char const* charFileName = filename.c_str(); 
    ifstream myfile(charFileName);
    if(!myfile.is_open()) {
         cout << "Couldnt open" << charFileName << ", file not found" << endl;
         exit(1);
    }
    // allocate memory for PROGRESS_STATUS struct and calculate total bytes
    // AKA total characters
    // initialize prog_stat struct values, set pointer to index for thread
    PROGRESS_STATUS prog_stat = *(PROGRESS_STATUS*) malloc(sizeof(prog_stat)); 
    prog_stat.InitialValue = 0;
    prog_stat.CurrentStatus = &index;
    stat(charFileName, &stats); // calculate total bytes of file
    prog_stat.TerminationValue = stats.st_size; //Set the amount of bytes for the file as the termination value

    // create thread for progress_monitor function
    pthread_t mainThread;
    pthread_create(&mainThread, NULL, progress_monitor, (void *) &prog_stat);

    // go character by character and count spaces
    // if previous spot is not a space and next spot is, increase word count
    // increase (*prog_stat.CurrentStatus) for thread progress for each character read
    // if file is empty, exit program
    if(myfile.peek() == EOF){
        cout << filename << " is empty, please use file with words" << endl;
        exit(1);
    }
    char ptr;
    char prevPtr;
    while(myfile.get(ptr)) { //open the file using the 'filename' parameter
        if(!isspace(prevPtr) && isspace(ptr)){
            wordCount++;
        }
        prevPtr = ptr;
        (*prog_stat.CurrentStatus)++;
    }
    if (!isspace(ptr)){
        wordCount++;
    }

    // close file
    myfile.close();

    // join main thread for progress bar progress
    pthread_join(mainThread, NULL);

    // display word count in opened file
    cout << endl << "\nThere are " << wordCount << " words in " << filename << ".\n";

    //return word count
    return wordCount;
}

//main method
int main(int argc, char **argv) {
    string filename;
    //First we check if there are 2 inputs, if not we go ahead and exit the program while printing the correct usage case
    if ((argc < 2 || argc > 2)) {
        if (argc < 2) {
            cout << "No file was input, proper usage: ./wordcount 'filename'" << endl;
            exit(1);
        }
        else {
            cout << "Too many arguments were passed, proper usage: ./wordcount 'filename'" << endl;
            exit(1);
        }
        //If there are 2 arguments, we check that the second argument's last 4 characters are '.txt' in order to be able to read it.
    } else if (argc == 2){
        filename = argv[1];
        int found = filename.find_last_of(".");
        if (filename.substr(found, filename.length() - 1) == ".txt"){
            //Once it's confirmed that we have a correct filename we can go ahead and pass it through to wordcount as wordcount will handle null exceptions for the file IF it's missing.
            wordcount(filename);
        }
    } else {
        cout << "File not found!" << endl;
        exit(1);
    }
    //Do all thread prog_stat
    //Get file bit count by using fstat
    //return 0 to show that the program ran and completed with 0 errors.
    return 0;
}

