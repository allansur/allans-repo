#include "Calculation.h"
//converter + address
using namespace std;
//converter 
//converts int to string
std::string int_to_str(int in_Int) {
    stringstream int_Str;
    int_Str << in_Int;
    return int_Str.str();
}

//converts hex to decimal
std::string hex_to_dec(string hex_Str) {
    unsigned int deci_Val;
    stringstream hexa_Str;
    hexa_Str << hex << hex_Str;
    hexa_Str >> deci_Val;
    stringstream decimal_Stream;
    decimal_Stream << deci_Val;
    return decimal_Stream.str();
}

//converts hex to binary
std::string hex_to_bin(string hex_Str) {
    unsigned int hexa_Val = strtoul(hex_Str.c_str(),NULL,16);
    bitset<4> hexa_Bit(hexa_Val);
    string binary_Str = hexa_Bit.to_string<char,string::traits_type,string::allocator_type>();
    return binary_Str;
}

//converts decimal to int
int dec_to_int(string in_String) {
    return atoi(in_String.c_str());
    //atoi converts string to integer
}

//calculate address code 
std::string base_Reg(string temp_Addy ,  map<string,std::string> txt_Rec , bool flag) {    //Calculate base register
    stringstream full_Addy;
    //initializes full_Addy variable
    full_Addy << setfill('0') << setw(6) << temp_Addy;
    std::string full_Temp_Addy = full_Addy.str();
    if(flag)    
        //imm operand
        return full_Temp_Addy;
    map<string,string>::iterator it = txt_Rec.begin(); 
    //simple & direct 
    std::string final_Addy = it->first;
    std::string final_Cont = it->second;
    //this skips to address that has been passed in
    while((it->first).compare(full_Temp_Addy) <= 0) {
        final_Addy = it->first;
        final_Cont = it->second;
        it++;
        if(it==txt_Rec.end())
            break;
    }
    if(full_Temp_Addy.compare(final_Addy) == 0)
        return final_Cont.substr(0,6);
    else if(full_Temp_Addy.compare(final_Addy) > 0)
        return final_Cont.substr(2*subtract_Addy(final_Addy,full_Temp_Addy),6);

}

// subtract address, uses lower bound and upper bound
int subtract_Addy(string lower_Bnd, string upper_Bnd) {
    int first_Addy;
    stringstream addy;
    addy << hex << lower_Bnd;
    addy >> first_Addy;
    int second_Addy;
    stringstream addy2;
    addy2 << hex << upper_Bnd;
    addy2 >> second_Addy;
    stringstream difference;
    difference << hex << second_Addy - first_Addy;
    int ans;
    difference >> ans;
    return ans;
}

// adds addy, uses PC relative mode
string add_Addy(string loc, string new_Leng, int pc_Flag) {    
    if(pc_Flag == 3 && new_Leng[0] >= '8')  
        new_Leng = "FFFFF" + new_Leng;
    unsigned int leng;
    stringstream loc_Stream;
    int location;
    loc_Stream << hex << loc;
    loc_Stream >> location;
    stringstream hexa_Leng;
    hexa_Leng << hex << new_Leng;
    hexa_Leng >> leng;
    stringstream new_loc;
    new_loc << hex << uppercase << setfill('0') << setw(6) << static_cast<int>(location)+leng+pc_Flag;
    return new_loc.str();
}   
std::string mask_op_bit(std::string op_code){
    unsigned int op_val;
    stringstream op_code_stream;
    op_code_stream << hex << op_code;
    op_code_stream >> op_val;
    bitset<8> op_bin(op_val);
    op_bin.set(0);
    op_bin.set(1);
    stringstream op_string;
    op_string << setfill('0') << setw(2) << hex << uppercase << op_bin.to_ulong();
    std::string result = op_string.str();
    return result;
}
