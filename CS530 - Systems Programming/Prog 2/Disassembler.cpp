  
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <exception>
#include <istream>
#include <string>
#include <map>
#include <exception>
#include "Calculation.h"
#include "symtab.h"
#include "printer.h"
//eventually we will need to split these up into specific headers for their parts cause we're gonna need to reuse some of them life for the OPTAB and the SYMTAB
using namespace std;


    

int main(int argc,char* argv[] ){
	if (argc <= 1 || argc > 2){ 							// If the command had not enough arguments or too many we tell them that it's not corect and exit
		std::cout << "This program is run using the command % dis <filename>.obj" << endl;
		exit(1);
	}
		
	string inputFile = argv[1];	
	int exit_pos = inputFile.find_last_of(".");						//Here we use IOSTREAM to check if the file with the name in argv[1] is in same location
	if (inputFile.substr(exit_pos + 1) != "obj"){ 				//if the file type is incorrect we go ahead and ignore it exiting out of the program
		std::cout << "This program can only be run with files of type .obj" << endl;
		exit(1);
	}
	ifstream objectFile(argv[1], ios::in);
	if (!objectFile) { 										//if the file isn't in that location we read an error message and exit the program
		std::cout << "The file you input was not found" << endl;
		exit(1);
	}
	if (objectFile.peek() == istream::traits_type::eof()){ 	//if the code makes it here we are checking if the file is empty
		std::cout << "This file is empty" << endl; 			//by using the peek() method and the istream EOF method, we are checking if the first thing in the file is equivalent to the end of the file and if it is this file is empty
		exit(1);
	}	
								//Take the name of the file they gave us and save it as a string
						//here we use find to find the first occurence of the '.' and save that position
												//add 1 to that position to allow us to find the last 3 characters of the string NOT including the period
	
	
	string file_name = inputFile.substr(0, exit_pos);  			//Repeating the same process here we check the inputfile for our symbol table and use subtr() to get the name 
	ifstream symbolFile((file_name + ".sym").c_str(), ios::in);  //We save the name + .sym extension into a c string and then check if it's in the same location
	if(!symbolFile){										//If the cstring doesn't exist in the same location they get an error and exit the program with 1
		std::cout << "The symbol file was not found" << endl; 
		exit(1);
	}
	
	if (symbolFile.peek() == istream::traits_type::eof()){	//Also checking here to see if the symbol file is empty or not based on the EOF and peek method
		std::cout << "This symbol file is empty." << endl;
		exit(1);
	}
	
	ofstream output((file_name + ".sxe").c_str());               //create an output file that is of the SXE type
	op_tab my_optab;
	symbol_table my_symtab(symbolFile);
	//my entire chunk of code is basically reading the header. this finds the text record, instructions, and mod record! header is then printed at the end 
	// need to work on variables for the last part, but other than that i think its solid
	// each goes thru the same structure w a while statement


std::cout << "Here 1";

//finding modrecord
vector<string> mod_record; //"mod record variable name x";
string modL; //"mod line variable name y";
	while(getline(objectFile,modL)) {
		if (modL[0] != 'M'){
			continue;
		}

	    mod_record.push_back(modL.substr(1,6));
	}
objectFile.clear();
objectFile.seekg(0,objectFile.beg);

string txt_line; //"text line y";
map <string,string> txtRec; // "txt record variable name x"
		while(getline(objectFile, txt_line)) { //objectFile in our sense is the input file that is taken from the command when it is given
			if(txt_line[0] != 'T'){ // if the line does NOT start with 'T' indicating it is not a text record we skip this line
				continue;
			}

			txtRec.insert(pair<string,string>(txt_line.substr(1,6),txt_line.substr(9))); //if this is considered a text record we take the address, skip the size, and then take the op code and store it in the map
		
			}
	objectFile.clear(); //idk forsure about this but i'm thinking that we're clearning the current buffer and then the next line says that 0 is now the beginning of txtRec.
	objectFile.seekg(0, objectFile.beg);
		//finding EQU
	string baseEqu; //"equ x";
	string equ; //"equ line y";
		while (getline(objectFile, equ)){
			if (equ[0] != 'T'){
				continue;
			}

			baseEqu = baseEqu + equ.substr(9);
		}
objectFile.clear();
objectFile.seekg(0, objectFile.beg);

//printing out header!
string header; //"header variable name x";
getline(objectFile, header);
string label = header.substr(1,6); //Takes the label from the first line, i.e chars 1-6
string address = header.substr(7,6); //takes the size from the first line i.e chars 7-13
string length = header.substr(13,6); //address 
//print( label, address, length);   //we need to develope a print header function
print_hdr(label, address, output);
//We now need ot parse EQU through being able to load all abs syms and remove any in the opcode
multimap<std::string, std::string> abs_map = my_symtab.get_abs_tab();
int position = 0;
int temp_pos = position;
multimap<std::string, std::string>::iterator it_equ;
while (position < baseEqu.size() ) {
	int count = 1;
	try {
		while ((it_equ = abs_map.find(baseEqu.substr(position, 2))) == abs_map.end()){
			if (position < 4){
				break;
		
			}
			position += 2;
		}
		if (it_equ == abs_map.end()){
			while ((it_equ = abs_map.find(baseEqu.substr(temp_pos, count * 2))) == abs_map.end()){
				if (count < 3){
					break;
				}
				++count;
			}
		}
	}

	catch (std::exception& e){
		std::cout << "Out of Range";
		break;
	}	

	position += count * 2;
	temp_pos = position;
	if (it_equ != abs_map.end()){
		abs_map.erase(it_equ);
	}
}

for (multimap<std::string, std::string>::iterator iter = abs_map.begin(); iter != abs_map.end(); ++iter){
	print_txt(iter -> second, "EQU", iter -> first, output, false, false, false, false);
}

std::string op_mne = "";
std::string text_addy;
std::string final_trec = address;
std::string operand;
std::string text_record;
std::string base_address;


while (getline(objectFile, text_record)) {
	if (text_record[0] != 'T') {
		text_addy = length;
		
		if (final_trec.compare(text_addy) != 0){
			print_res(my_symtab, final_trec, text_addy, output);
		}
		break;
	}
}
	int count = 9;
	text_addy = text_record.substr(1, 6);
	std::string location = text_addy;
	int max_location = text_record.length();
	std::string text_rec_length = text_record.substr(7, 2);

	if (final_trec.compare(text_addy) != 0){
		print_res(my_symtab, final_trec, text_addy, output);
	}
	final_trec = add_Addy(text_addy, text_rec_length, 0);

	while ( count < max_location) {
		//this loop has to stop when we reach the last char in the input
		try {
			label = "";
			std::string rel_sym = my_symtab.get_rel_sym(location);
				if (rel_sym.compare("") != 0){
					if (text_record.substr(count, 2).compare("00") == 0){
						int data = 1;
						std::string res_data = text_record.substr(count, data * 2);
						std::string temp_rdata = res_data;
						
						while (temp_rdata.erase(0, temp_rdata.find_first_not_of('0')).compare("") == 0){
							++data;
							res_data = text_record.substr(count, data * 2);
							temp_rdata = res_data;
						}

						--data;
						if (data % 3 == 0){
							print_txt(rel_sym, "RESW", int_to_str(data / 3), output, false, false, false, false); 
						}
						else {
							print_txt(rel_sym, "RESB", int_to_str(data / 3), output, false, false, false, false); 
						}

						location = add_Addy(location, int_to_str(data), 0);
						count += data * 2;
						continue;
					}

					else {
						label = rel_sym;
					}
			}

			//Now we need are going to implement a check for literals
			pair<std::string, std::string> literals = my_symtab.get_literal(location);

			if (literals.first.compare("") != 0){
				std::string literal = literals.first;
				std::string lit_length = literals.second;

				if (literal.substr(1, 1).compare("X") == 0){
					count += dec_to_int(lit_length);
					location = add_Addy(location, "1", 0);
				}

				else {
					
					count += dec_to_int(lit_length) * 2;
					location = add_Addy(location, "1", 0);
					
				}
				print_txt(" ", "LTORG", "", output, false, false, false, false);
				continue;
				
			}
			
			bool instruction = false;
			bool e_flag = false;
			bool n_flag = false;
			bool i_flag = false;
			bool x_flag = false;
			

			std::string op_code = text_record.substr(count, 2);
			std::string format = "";
			pair<std::string, std::string> op_data = my_optab.get_op_tab(mask_op_bit(op_code));
			std::string temp_adder = "";
			if ((op_data.first).compare("") != 0){
				instruction = true;
				op_mne = op_data.first;
				format = op_data.second;

				if (format.compare("1") == 0){
					std::string first_reg_num = text_record.substr(count + 2, 1);
					std::string second_reg_num = text_record.substr(count + 3, 1);
					if (second_reg_num.compare("0") == 0){
						operand = my_symtab.get_reg(first_reg_num);
					}
					else {
						operand = my_symtab.get_reg(first_reg_num) + ',' + my_symtab.get_reg(second_reg_num);
					}
					if (operand.compare("") == 0 || operand.compare(",") == 0){
						instruction = false;
					}

				}
				else {
					std::string n_i_flags = hex_to_bin(op_code.substr(1, 1));
					std::string x_b_p_e_flags = hex_to_bin(text_record.substr(count + 2, 1));
					pair<std::string, std::string> symbol_name("", "");

					if (n_i_flags[2] == '0' && n_i_flags[3] == '1') {
						
						if (x_b_p_e_flags[0] == '1') {
							x_flag = true;
						}
					}
					else if (n_i_flags[2] == '0' && n_i_flags[3] == '1'){
						i_flag = true;
					}
					else if (n_i_flags[2] == '1' && n_i_flags[3] == '0'){
						n_flag = true;
					}
					if (x_b_p_e_flags[1] == '0' && x_b_p_e_flags[2] == '0' \
					&& x_b_p_e_flags[3] == '1'){
						temp_adder = text_record.substr(count + 3, 5);
						e_flag = true;
					}
					else if(x_b_p_e_flags[1] == '0' && x_b_p_e_flags[2] == '1' \
					&& x_b_p_e_flags[3] == '0'){
						temp_adder = text_record.substr(count + 3, 3);
						temp_adder = add_Addy(location, temp_adder, 3);
					}
					else if(x_b_p_e_flags[1] == '1' && x_b_p_e_flags[2] == '0' \
					&& x_b_p_e_flags[3] == '0'){
						temp_adder = text_record.substr(count + 3, 3);
						temp_adder = add_Addy(location, temp_adder, 0);
					}
					else if(x_b_p_e_flags[1] == '1' && x_b_p_e_flags[2] == '0' \
					&& x_b_p_e_flags[3] == '0'){
						temp_adder = text_record.substr(count + 3, 3);
					}
					else {
						instruction = false;
					}

					symbol_name = my_symtab.get_literal(temp_adder);
					if (symbol_name.first.compare("") == 0){
						symbol_name.first = my_symtab.get_rel_sym(temp_adder);

						if (symbol_name.first.compare("") == 0){
							symbol_name.first = temp_adder;
						}
					}
					operand = symbol_name.first;

					if (i_flag && x_b_p_e_flags[1] != '1' && x_b_p_e_flags[2] != '1') {

						if (find(mod_record.begin(), mod_record.end(), add_Addy(location, "1", 0)) == mod_record.end()){
							operand = hex_to_dec(temp_adder);
						}
					}
				}

			}

			if (instruction) {
				int c = 1;
				std::string data_sym = "";
				std::string data_val = "";
				
				while ( c <= 3) {
					data_val = text_record.substr(count, c * 2);
					data_sym = my_symtab.get_abs_sym(data_val);
					++c;
				}

				if (data_sym.compare("") != 0 ){
					if (c == 3) {
						print_txt(data_sym, "BYTE", data_val, output, false, false, false, false);
					}
					else {
						print_txt(data_sym, "BYTE", data_val, output, false, false, false, false);
					}

					location = add_Addy(location, int_to_str(c), 0);
					c += c * 2;
					continue;
				}
				else {
					output << "NULL  " << "NULL   " << "\n";
					c += 2;
					location = add_Addy(location, "1", 0);
				}
			}

			if (format.size() != 1 && e_flag){
				format = format.substr(2, 1);
			}
			 else {
				 format = format.substr(0, 1);
			 }
			if (op_mne.compare("RSUB") == 0){
				operand = "";
			}
			print_txt(label, op_mne, operand, output, x_flag, e_flag, n_flag, i_flag);
			if (op_mne.compare("LDB") == 0){
				base_address = base_Reg(base_address, txtRec, i_flag);
				if (n_flag){
					base_address = base_Reg(base_address, txtRec, false);
				}
				print_txt("", "BASE", operand, output, false, false, false, false);

			}
		}
		catch (std::exception& e) {
			output << "NULL   " << "NULL   " << "NULL " << "\n";
			break;
		}

	}
	while (text_record[0] != 'E') {
		getline(objectFile, text_record);
	std::string end_rec = text_record;
	print_end(end_rec, output);
	objectFile.close();
	symbolFile.close();
	output.close();
	}
	std::cout << "Finally done!";
	return 1;


}
