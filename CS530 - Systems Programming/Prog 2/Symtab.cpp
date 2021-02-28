#include "symtab.h"
#include <limits>
//The first thing we need to do is be able to load all of the symbols into a symtab from our input file stream
using namespace std;
symbol_table::symbol_table(std::ifstream& is_symbol){
    //We ned to ignore the first 2 lines of the symbol table and use '\n' as our delimiter to make sure we start reading after that char
    is_symbol.ignore(numeric_limits<streamsize>::max(), '\n');
    is_symbol.ignore(numeric_limits<streamsize>::max(), '\n');
    
    std::string sym; //This is going to be the string we put out sym into
    
    //Adding the symbol into the symbol_table if it is there along with the literal

    while(getline(is_symbol, sym)){
        if (sym.empty()){
            //If it's empty we're going to skip the lines so that we would get the next symbol if it's there
            is_symbol.ignore(numeric_limits<streamsize>::max(), '\n');
            is_symbol.ignore(numeric_limits<streamsize>::max(), '\n');

            while(getline(is_symbol, sym)){
                if (sym.empty()){
                    break; //Just break us out of the while loop
                }
                    string lit_address = sym.substr(22, 6);
                    lit_tab.insert(pair<std::string, std::string>(lit_address, sym.substr(8, 7)));
                    lit_tab.insert(pair<std::string, std::string>(lit_address, sym.substr(19, 1)));
            }
                break;
        } 
        //Getting and adding the address of our sym_table
        string sym_address = sym.substr(8, 6);
        sym_address.erase(remove(sym_address.begin(), sym_address.end(), ' '), sym_address.end());
        sym_tab.insert(pair<std::string, std::string>(sym_address, sym.substr(0, 6)));
        sym_tab.insert(pair<std::string, std::string>(sym_address, sym.substr(16, 1)));
        }
        //Now we have to add in all of our registers for the SIC/XE machine into our registers multimap we created in our header file for this cpp file.
        
        registers.insert(pair<std::string, std::string>("1","X"));
        registers.insert(pair<std::string, std::string>("2","L"));
        registers.insert(pair<std::string, std::string>("3","B"));
        registers.insert(pair<std::string, std::string>("4","S"));
        registers.insert(pair<std::string, std::string>("5","T"));
        registers.insert(pair<std::string, std::string>("6","F"));
        registers.insert(pair<std::string, std::string>("8","PC"));
        registers.insert(pair<std::string, std::string>("9","SW"));
        registers.insert(pair<std::string, std::string>("0","A"));
};

//Now we need to get a table of only absolute syms so i'm gonna try to implement this using a multimap and our get_abs_tab method from our header
std::multimap<std::string, std::string> symbol_table::get_abs_tab(){

    std::multimap<std::string, std::string>::iterator temp;
    std::multimap<std::string, std::string> abs_map;
    

    for (multimap<std::string, std::string>::iterator i = sym_tab.begin(); i != sym_tab.end(); ++i){
        temp = i;
        if (((++i)-> second).compare("A") == 0){
            abs_map.insert(pair<std::string, std::string>(temp -> first, temp -> second));
        }
    }
    return abs_map;
};
//Function that lets us get only the absolute symbol name from our table
std::string symbol_table::get_abs_sym(std::string is_symbol){
    pair<std::multimap<std::string, std::string>::iterator, std::multimap<std::string, std::string>::iterator> iter;
    iter = sym_tab.equal_range(is_symbol);
    std::string symbol_name = "";
    std::multimap<std::string, std::string>::iterator  temp_it;

    for(std::multimap<std::string, std::string>::iterator i = iter.first; i != iter.second; ++i){
        temp_it = i;
        if (((++i) -> second).compare("A") == 0){
            symbol_name = temp_it -> second;
            break;
        }
    }
    return symbol_name;

};

//Implementing the function get_sym_tab which will allow us to return a copy of our symbol table after it's created
std::multimap<std::string, std::string> symbol_table::get_sym_tab(){
    std::multimap<std::string, std::string> copy;

     for (std::multimap<std::string, std::string>::iterator i = sym_tab.begin(); i != sym_tab.end(); ++i){
         copy.insert(pair<std::string, std::string>(i -> first, i -> second));
     }
     return copy;
};

//Now we are going to create the class that only gets the relative symbol name
std::string symbol_table::get_rel_sym(std::string is_symbol){
    stringstream in_symtab_str;
    in_symtab_str << setfill('0') << setw(6) << is_symbol;//Formatted Symtab
    pair<std::multimap<std::string, std::string>::iterator, std::multimap<std::string, std::string>::iterator> iter;
    std::string f_sym =  in_symtab_str.str();
    iter = sym_tab.equal_range(f_sym);
    std::string name = "";
    std::multimap<std::string, std::string>::iterator temp_it;

    for(std::multimap<std::string, std::string>::iterator i = iter.first; i != iter.second; ++i) {
        temp_it = i;
        if(((++i) -> second).compare("R") == 0){
            name = temp_it -> second;
            break;
        }
    }
    return name;
};

//Implementing the function get_reverse_rel to get the last relative symbol of our address
std::string symbol_table::get_reverse_rel(std::string is_symbol){
    pair<std::multimap<std::string, std::string>::iterator, std::multimap<std::string, std::string>::iterator> iter;
    iter = sym_tab.equal_range(is_symbol);
    std::multimap<std::string, std::string> temp_map;

    for(std::multimap<std::string, std::string>::iterator i = iter.first; i != iter.second; ++i) {
        temp_map.insert(pair<std::string, std::string>(i-> first, i -> second));
    }
    std::multimap<std::string, std::string>::reverse_iterator rev_it;
    for (rev_it = temp_map.rbegin(); rev_it != temp_map.rend(); ++rev_it){
            if ((rev_it++ -> second).compare("R") == 0){
                return rev_it -> second;
                break;
            }
    }

};
//Small function to return the name of a register
std::string symbol_table::get_reg(std::string reg_num){
    std::multimap<std::string, std::string>::iterator iter = registers.find(reg_num);
    if (iter == registers.end()){
        return "";
    }
    return iter -> second;
};

//Lastly we need to implement our function to get a literal's name and address
std::pair<std::string, std::string> symbol_table::get_literal(std::string lit_adder){
if (lit_tab.count(lit_adder) == 0){ return make_pair("", "");}
if (lit_adder.size() != 6){
    stringstream new_address;
    new_address << setfill('0') << setw(6) << lit_adder;
    lit_adder = new_address.str();
}

pair<std::multimap<std::string, std::string>::iterator, std::multimap<std::string, std::string>::iterator> iter;
iter = lit_tab.equal_range(lit_adder);
std::string literal, l_length;
pair<std::string, std::string> lit_output;
std::multimap<std::string, std::string>::iterator i = iter.first;
literal = i -> second;
i++;
l_length = i -> second;
lit_output = make_pair(literal, l_length);
return lit_output;

};
