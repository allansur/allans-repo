//Allan Sur
//CS530 Leonard
//Project 1
//09/21/2020

#include <iostream>
#include <iomanip>
#include <cstring>
#include <streambuf>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


string hexBin(string hexs){
    string binary;
    for(int j = 0; j < (signed)hexs.length(); j++){
                switch (hexs[j]){
                    case '0': 
                        binary.append("0000");
                        break;
                    case '1': 
                        binary.append("0001");
                        break;
                    case '2':
                        binary.append("0010");
                        break;
                    case '3':
                        binary.append("0011");
                        break;
                    case '4':
                        binary.append("0100");
                        break;
                    case '5':
                        binary.append("0101");
                        break;
                    case '6':
                        binary.append("0110");
                        break;
                    case '7': 
                        binary.append("0111");
                        break;
                    case '8':
                        binary.append("1000");
                        break;
                    case '9':
                        binary.append("1001");
                        break;
                    case 'a':
                        binary.append("1010");
                        break;
                    case 'b':
                        binary.append("1011");
                        break;
                    case 'c':
                        binary.append("1100");
                        break;
                    case 'd':
                        binary.append("1101");
                        break;
                    case 'e':
                        binary.append("1110");
                        break;
                    case 'f':
                        binary.append("1111");
                        break;
            } 
                if(j % 2 == 1){
                    binary.push_back(' ');
                }

    }
                return binary;
}
void binaryDump(string contents){
    unsigned long address = 0;
    string printables;                                          
    string hexCode; 
    string binCode;                                            
    ostringstream hexOSS;                                       
    bool extraLines = contents.length() % 6 != 0;                  //check if the binary dump needs an extra line ie ! %6 == 0

    for(int i = 0; i < contents.length() - 1; i++){                 //loop to add either . or the character to our printables string
       char curr = contents[i];     
       if((int) curr < 32){
           printables.push_back('.');
       }
       else{
           printables.push_back(curr);
       }
       hexOSS << setfill('0') << setw(2) << hex << (int) curr;  //setting our fill for the hexOSS to be able to parse it for our hexToBin method
       if((i + 1)% 6 == 0 ){                                    //if we have reached a number of % 6 then we can call this, has to be i+1 or else the 0th indexed will be printed alone
            hexCode = hexOSS.str();
            binCode = hexBin(hexCode);                        //turns all our hex numbers in the 6 hex codes into binary code by calling hexToBin
            cout << setfill('0') << setw(7);                        //setting and printing address and the rest of our variables.
            cout << address << ": ";
            cout << binCode << " ";
            cout << printables << endl; //print everything in correct order then clear all items for next line
            hexOSS.str("");
            hexOSS.clear();
            binCode.clear();
            printables.clear();
            address +=6;
       }
    }
    if(extraLines){                                             //if we need extra lines it runs this method
        hexCode = hexOSS.str();
        binCode = hexBin(hexCode);                              //converts hex to bin
        cout << setfill('0') << setw(7);                        //setting and printing address and the rest of our variables.
        cout << address << ": ";                            
        cout << binCode;                                    
        int fLength = 57 - binCode.length();                       //set the length of the line in order to match formatting for the extra line. filling with spaces in the next line
        cout << setfill(' ') << setw(fLength)<< printables << "\n" << endl;
    }
}

void hexDump(string contents){
    unsigned long address = 0;
    string printables;                                          //Var for all characters that are > 32 in decimal
    string hexCode;                                             //Var for the hex code that will be displayed to the user
    ostringstream hexOSS;                                       //stringstream to get all of our characters
    bool extraLines = contents.length() % 16 != 0;

    for(int i = 0; i < contents.length() - 1; i++){             //for loop basically adds everything to printables, if < 32 adds a '.' and if >= 32 we add that character
       char curr = contents[i];     
       if((int) curr < 32){
           printables.push_back('.');
       }
       else{
           printables.push_back(curr);
       }
       hexOSS << setfill('0') << setw(2) << hex << (int) curr;  //basically set hexOSS equal to the hex values of our current character and add a space between each two, 4a 4b
       if((i + 1) % 16 == 0) {                                  //Basically allowing it so that we cna have 16 characters on a line
            hexCode = hexOSS.str();                             //convert our stream into a string
            for(int j = 0; j < hexCode.length() - 1; j++){      //This loops basically just inserts spaces for formatting every 4th character for the ouput
                if(j % 3 == 0){
                    hexCode.insert(j, " ");
                }
            }
            cout << setfill('0') << setw(7);                    // Setting the fill of the address to 0 and width to 7 so that it will match wanted output
            cout << address << ": ";
            cout << hexCode << " " << printables << endl;       //From this line to the end of the first loop on line 16, we are just printing and then clearing each variable
            hexOSS.str("");
            hexCode.clear();
            printables.clear();
            address += 10;
        }
    }
    if (extraLines){                                            //if our extraLines var is set to True, we run this section of our function
        hexCode = hexOSS.str();
        for(int j = 0; j < hexCode.length() - 1; j++){
                if(j % 3 == 0){
                    hexCode.insert(j, " ");
                }
            }
        cout << setfill('0') << setw(7);                        //setting and printing address and the rest of our variables.
        cout << address << ": ";
        cout << hexCode;
        cout << setfill(' ') << setw(53 - hexCode.length()) << printables << endl; //we need to set fill here because it is an extra line we don't know if it will fill the entire space and we have to for correct formatting.
        cout << "\n";
    }

}

int main(int argc, char* argv[]){
    cout << "HEX/BINARY DUMP PROGRAM CS530 \n \n";
    char* dashB= argv[1];
    if(strcmp(dashB, "-b") == 0){                               //First check if there is a "-b" given to us from the command line which would indicate a binary dump instead of a hexdump
        ifstream file(argv[2]);
        string tbc((std::istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
        binaryDump(tbc);
    }
    if(strcmp(dashB, "-a") == 0){
        ifstream file(argv[2]);
        string tbc((std::istreambuf_iterator<char>(file)), (istreambuf_iterator<char>())); //the "-a" command will print both the hex and bianry dumps
        string secondTBC = tbc;
        hexDump(secondTBC);
        binaryDump(tbc);
    }
    else {
        ifstream file(argv[1]);
        string tbc((std::istreambuf_iterator<char>(file)), (istreambuf_iterator<char>())); //iterate through the target file and turn everything into a string named tbc.
        hexDump(tbc);                                           //call our hexdump method on all of the contents of our string
    }   
    return 0;
}