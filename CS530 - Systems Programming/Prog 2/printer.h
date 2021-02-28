//This class will be the header for both our optab and our print records cpp file
#ifndef printRec_opTab_h
#define printRec_opTab_h

#include <iostream>
#include <map>
#include <utility>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

//we only need to includce calculation.h and symtab because these combine our converter headers too
#include "symtab.h"
#include "Calculation.h"

//Unfortunately Prettier Code doesn't work with CPP such a tragedy so try and keep this code a bit more clean
class op_tab{
  private:
  
    std::multimap<std::string, std::string> op;
  
  public:
    
    op_tab();

    std::pair<std::string, std::string> get_op_tab(std::string op_code);
    
};

void print_res(symbol_table& is_in_symbol, std::string final_text_rec, std::string text_address,std::ofstream& inStream);
void print_txt(std::string label, std::string mnemonic, std::string operand, std::ofstream& inStream, bool x_flag, bool e_flag, bool n_flag, bool i_flag);
void print_hdr(std::string label, std::string first_address,std::ofstream& inStream);
void print_end(std::string end_rec, std::ofstream& inStream);



#endif
