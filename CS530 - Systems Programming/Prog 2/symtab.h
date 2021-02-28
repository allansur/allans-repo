#ifndef symtab_header
#define symtab_header

//Import all libraries that we will need for the symtab to be operational
#include <string>
#include <utility>
#include <map>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>

class symbol_table{
    private:
     //Create all of our private variables that we will need for Symtab.cpp
        std::multimap<std::string, std::string> sym_tab;
        std::multimap<std::string, std::string> lit_tab;
        std::multimap<std::string, std::string> registers;
    //All of our public classes and variables for the Symtab class
    public:
        symbol_table(std::ifstream& is_symbol);
        std::string get_abs_sym(std::string is_symbol);
        std::string get_rel_sym(std::string is_symbol);
        std::string get_reverse_rel(std::string is_symbol);
        std::string get_reg(std::string reg_num);
        std::pair<std::string, std::string> get_literal(std::string lit_adder);
        std::multimap<std::string, std::string> get_abs_tab();
        std::multimap<std::string, std::string> get_sym_tab();
};

#endif