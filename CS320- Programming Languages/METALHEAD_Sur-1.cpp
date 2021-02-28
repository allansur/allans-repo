//Allan Sur
//C++ Assignment
//June 22nd, 2020
//Professor Healey CS 320

#include <iostream>
#include <tgmath.h>
using namespace std;

class Guitar{
    private:
        unsigned char numberOfFrets;
        
    
    public: 
    double gStrings[6];
        Guitar(){
            gStrings[0] = 82.41;
            gStrings[1] = 110;
            gStrings[2] = 146.8;
            gStrings[3] = 196;
            gStrings[4] = 246.9;
            gStrings[5] = 329.6;
            numberOfFrets = 21;
        }

    bool setFretBoardLength(const unsigned char numFrets){
        if ((int)numFrets >= 1 && (int)numFrets <= 24){
            numberOfFrets = numFrets;
            std::cout << numberOfFrets << " frets have been set\n";
        }
        else {
            std::cout << "The input you made is invalid\n";
        }
    }

    double pitchAt(const unsigned char &stringNumber, const unsigned char &fret){
        int accessNumber = stringNumber - 1;
        double exponent = fret/12.0;
        double power = pow(2, exponent);
        double pitch = gStrings[accessNumber] * power;
        return pitch;
    }

    std::pair<unsigned char, unsigned char> getStringAndFret( double pitch ){ 
        double dif, comparison, temp;
        int index, stringNum, fret;
        dif = 100;
        for (int i = 0; i < 5; i++){
            for(int j = 0; j < numberOfFrets; j++){
                if(abs(pitchAt(i, j) - pitch) < dif){
                    dif = abs(pitchAt(i,j) - pitch);
                    index = i;
                    fret = j;
                }
            }
        }
        std::cout << "The closest String/Fret combo for the given pitch is string: " << index << " on fret: " << fret << "\n";
        pair <unsigned char, unsigned char> pairing;
        pairing.first = index;
        pairing.second = fret;
        return pairing;
    }

    void tuneString(unsigned char& string, const double& pitch){
        gStrings[string - 1] = pitch;
        std::cout <<"The string: " << string << " has been tuned to the pitch: " << pitch << "Hz\n";
    }
    
};

int main(){
  bool cont = true;
  int choice;
  while(cont == true){
      std::cout << "\n**MENU**\n";
      std::cout << "1. pitchAt Function\n";
      std::cout << "2. getStringAndFret Function\n";
      std::cout << "3. setFretBoardLength Function\n";
      std::cout << "4. tuneString Function\n";
      std::cout << "5. Exit Program\n";
      std::cout << "\nPlease pick a number 1 - 5\n";
      std::cin >> choice;
      Guitar g1;
      
      if(choice > 0 && choice < 6){
      switch (choice){
            case 1: 
                int stringNum, fret;
                std::cout << "pitchAt Function\n";
                std::cout << "Please enter a string number (1 - 5)\n";
                std::cin >> stringNum;
                std::cout << "Please enter a fret number\n";
                std::cin >> fret;
                std::cout << "The pitch is: " << g1.pitchAt(stringNum, fret) << "Hz\n";
                break;
            case 2:
                double pitch;
                std::cout << "getStringAndFret Function\n";
                std::cout << "Please enter a pitch you'd like to find the string and fret closest to\n";
                std::cin >> pitch;
                g1.getStringAndFret(pitch);
                break;
            case 3:
                int numFrets;
                std::cout << "setFretBoardLength Function\n";
                std::cout << "Please enter the amount of frets on the guitar you'd like (1-24)\n";
                std::cin >> numFrets;
                g1.setFretBoardLength(numFrets);
                break;
            case 4:
                unsigned char str;
                double pitchSet;
                std::cout << "tuneString Function\n";
                std::cout << "Please give the string # to set (1-5)\n";
                std::cin >> str;
                std::cout << "Please enter the pitch you'd like to set the " << str<< " to\n";
                std::cin >> pitchSet;
                g1.tuneString(str, pitchSet);
                break;
            case 5: 
                std::cout << "Thank you for using the program!\n";
                cont = false;
                break;
        }
      }
      else {
          std::cout << "Please enter a valid choice 1-5\n";
      }
    }
return 0;
}