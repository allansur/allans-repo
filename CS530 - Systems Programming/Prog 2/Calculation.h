#ifndef calculation_h
#define calculation_h

//libraries
#include <bitset>
#include <iostream>
#include <iomanip>
#include <map>
#include <sstream>
#include <string>

//variables within converter

std::string int_to_str(int in_Int);
std::string hex_to_dec(std::string hex_Str);
std::string mask_op_bit(std::string op_code);
std::string hex_to_bin(std::string hex_Str);
int dec_to_int(std::string in_Str);
//variables within calcAddy
std::string base_Reg(std::string temp_Addy, std::map<std::string,std::string> txt_Rec, bool flag);
int subtract_Addy(std::string lower_Bnd, std::string upper_Bnd);
std::string add_Addy(std::string loc, std::string new_Leng, int pc_Flag);


#endif