#include "printer.h"

using namespace std;


pair<string,string> op_tab::get_op_tab(std::string op_code) {    
    //utilizes iterator (iter)
    if( op.count ( op_code ) == 0)
        //opcode count 
        return make_pair("" , "");
    
    pair<multimap<string,string>::iterator, multimap<string,string>::iterator> iter;
    iter = op.equal_range( op_code );
    string masked_op;
    string format;
    pair<string,string> data;
    multimap<string,string>::iterator it1 = iter.first;
    masked_op = it1->second;
    it1++;
    //increase
    format = it1->second;
    data = make_pair( masked_op , format );
    return data; 
    // gets menonic and format
}
op_tab::op_tab() {
    //creating the optab
    op.insert(pair<string,string>("1B","ADD"));
    op.insert(pair<string,string>("1B","3/4"));
    op.insert(pair<string,string>("5B","ADDF"));
    op.insert(pair<string,string>("5B","3/4"));
    op.insert(pair<string,string>("93","ADDR"));
    op.insert(pair<string,string>("93","2"));
    op.insert(pair<string,string>("43","AND"));
    op.insert(pair<string,string>("43","3/4"));
    op.insert(pair<string,string>("B7","CLEAR"));
    op.insert(pair<string,string>("B7","2"));
    op.insert(pair<string,string>("2B","COMP"));
    op.insert(pair<string,string>("2B","3/4"));
    op.insert(pair<string,string>("8B","COMPF"));
    op.insert(pair<string,string>("8B","3/4"));
    op.insert(pair<string,string>("A3","COMPR"));
    op.insert(pair<string,string>("A3","2"));
    op.insert(pair<string,string>("27","DIV"));
    op.insert(pair<string,string>("27","3/4"));
    op.insert(pair<string,string>("67","DIVF"));
    op.insert(pair<string,string>("67","3/4"));
    op.insert(pair<string,string>("9F","DIVR"));
    op.insert(pair<string,string>("9F","2"));
    op.insert(pair<string,string>("C7","FIX"));
    op.insert(pair<string,string>("C7","1"));
    op.insert(pair<string,string>("C3","FLOAT"));
    op.insert(pair<string,string>("C3","1"));
    op.insert(pair<string,string>("F7","HIO"));
    op.insert(pair<string,string>("F7","1"));
    op.insert(pair<string,string>("3F","J"));
    op.insert(pair<string,string>("3F","3/4"));
    op.insert(pair<string,string>("33","JEQ"));
    op.insert(pair<string,string>("33","3/4"));
    op.insert(pair<string,string>("37","JGT"));
    op.insert(pair<string,string>("37","3/4"));
    op.insert(pair<string,string>("3B","JLT"));
    op.insert(pair<string,string>("3B","3/4"));
    op.insert(pair<string,string>("4B","JSUB"));
    op.insert(pair<string,string>("4B","3/4"));
    op.insert(pair<string,string>("03","LDA"));
    op.insert(pair<string,string>("03","3/4"));
    op.insert(pair<string,string>("6B","LDB"));
    op.insert(pair<string,string>("6B","3/4"));
    op.insert(pair<string,string>("53","LDCH"));
    op.insert(pair<string,string>("53","3/4"));
    op.insert(pair<string,string>("73","LDF"));
    op.insert(pair<string,string>("73","3/4"));
    op.insert(pair<string,string>("0B","LDL"));
    op.insert(pair<string,string>("0B","3/4"));
    op.insert(pair<string,string>("6F","LDS"));
    op.insert(pair<string,string>("6F","3/4"));
    op.insert(pair<string,string>("77","LDT"));
    op.insert(pair<string,string>("77","3/4"));
    op.insert(pair<string,string>("07","LDX"));
    op.insert(pair<string,string>("07","3/4"));
    op.insert(pair<string,string>("D3","LPS"));
    op.insert(pair<string,string>("D3","3/4"));
    op.insert(pair<string,string>("23","MUL"));
    op.insert(pair<string,string>("23","3/4"));
    op.insert(pair<string,string>("63","MULF"));
    op.insert(pair<string,string>("63","3/4"));
    op.insert(pair<string,string>("9B","MULR"));
    op.insert(pair<string,string>("9B","2"));
    op.insert(pair<string,string>("CB","NORM"));
    op.insert(pair<string,string>("CB","1"));
    op.insert(pair<string,string>("47","OR"));
    op.insert(pair<string,string>("47","3/4"));
    op.insert(pair<string,string>("DB","RD"));
    op.insert(pair<string,string>("DB","3/4"));
    op.insert(pair<string,string>("AF","RMO"));
    op.insert(pair<string,string>("AF","2"));
    op.insert(pair<string,string>("4F","RSUB"));
    op.insert(pair<string,string>("4F","3/4"));
    op.insert(pair<string,string>("A7","SHIFTL"));
    op.insert(pair<string,string>("A7","2"));
    op.insert(pair<string,string>("AB","SHIFTR"));
    op.insert(pair<string,string>("AB","2"));
    op.insert(pair<string,string>("F3","SIO"));
    op.insert(pair<string,string>("F3","1"));
    op.insert(pair<string,string>("EF","SSK"));
    op.insert(pair<string,string>("EF","3/4"));
    op.insert(pair<string,string>("0F","STA"));
    op.insert(pair<string,string>("0F","3/4"));
    op.insert(pair<string,string>("7B","STB"));
    op.insert(pair<string,string>("7B","3/4"));
    op.insert(pair<string,string>("57","STCH"));
    op.insert(pair<string,string>("57","3/4"));
    op.insert(pair<string,string>("83","STF"));
    op.insert(pair<string,string>("83","3/4"));
    op.insert(pair<string,string>("D7","STI"));
    op.insert(pair<string,string>("D7","3/4"));
    op.insert(pair<string,string>("17","STL"));
    op.insert(pair<string,string>("17","3/4"));
    op.insert(pair<string,string>("7F","STS"));
    op.insert(pair<string,string>("7F","3/4"));
    op.insert(pair<string,string>("EB","STSW"));
    op.insert(pair<string,string>("EB","3/4"));
    op.insert(pair<string,string>("87","STT"));
    op.insert(pair<string,string>("87","3/4"));
    op.insert(pair<string,string>("13","STX"));
    op.insert(pair<string,string>("13","3/4"));
    op.insert(pair<string,string>("1F","SUB"));
    op.insert(pair<string,string>("1F","3/4"));
    op.insert(pair<string,string>("5F","SUBF"));
    op.insert(pair<string,string>("5F","3/4"));
    op.insert(pair<string,string>("97","SUBR"));
    op.insert(pair<string,string>("97","2"));
    op.insert(pair<string,string>("B3","SVC"));
    op.insert(pair<string,string>("B3","2"));
    op.insert(pair<string,string>("E3","TD"));
    op.insert(pair<string,string>("E3","3/4"));
    op.insert(pair<string,string>("FB","TIO"));
    op.insert(pair<string,string>("FB","1"));
    op.insert(pair<string,string>("2F","TIX"));
    op.insert(pair<string,string>("2F","3/4"));
    op.insert(pair<string,string>("BB","TIXR"));
    op.insert(pair<string,string>("BB","2"));
    op.insert(pair<string,string>("DF","WD"));
    op.insert(pair<string,string>("DF","3/4"));
}


//print records
void print_res(symbol_table& is_in_symbol, std::string final_text_rec, std::string text_address,std::ofstream& inStream){
    multimap<std::string, std::string>::iterator temp_iter;
    multimap<std::string, std::string> res_symtab = is_in_symbol.get_sym_tab();
    multimap<std::string, std::string>::iterator it = res_symtab.begin();

    while ((it -> first).compare(final_text_rec) < 0){
        std::advance(it, 2);
    }
    temp_iter = it;
    while((( ++temp_iter) -> second).compare("A") == 0 ){
        std::advance(it, 2);
        temp_iter = it;
    }
    std::string prev_sym = it -> first;
    std::advance(it, 2);
    bool org_flag = false;
    std::string org_stop = "";
    int remaining_length = 0;
    int res_length = 0;
    std::string name = "";

    while((it -> first).compare(text_address) <= 0){
        temp_iter = it;
        if(((++temp_iter) -> second).compare("A") == 0){
            std::advance(it, 2);
            if (it == res_symtab.end() || (it -> first).compare(text_address) > 0){
                if (prev_sym.compare(text_address) != 0){
                    name = is_in_symbol.get_rel_sym(prev_sym);
                    res_length = subtract_Addy(prev_sym, text_address);

                    if (res_length % 3 == 0){
                        inStream << name << "   RESW   " << int_to_str(res_length / 3) << "\n";
                    }
                    else {
                        inStream << name << "   RESB   " << int_to_str(res_length) << "\n";
                    }
                }

                if (org_stop.compare("") != 0){
                    inStream << "      ORG   " << org_stop << "\n";
                break;
                }
                continue;
            }

            res_length = subtract_Addy(prev_sym, it -> first);
            if (org_flag) {
                name = is_in_symbol.get_reverse_rel(prev_sym);
                org_flag = false;
            }
            else {
                name = is_in_symbol.get_rel_sym(prev_sym);
            }
            if (res_length == 0) {
                remaining_length = subtract_Addy(prev_sym, text_address);
                if (remaining_length % 3 == 0){
                    inStream << name << "   RESW   " << int_to_str(remaining_length / 3) << "\n";
                }
                else {
                    inStream << name << "   RESB   " << int_to_str(remaining_length) << "\n";
                }
                inStream << "      ORG    " << name << "\n";
                org_flag = true;
                org_stop = name + "+" + int_to_str(remaining_length);
            }
            else {
                if (res_length % 3 == 0){
                    inStream << name << "   RESW   " << int_to_str(res_length / 3) << "\n";
                }
                else {
                    inStream << name << "   RESB   " << int_to_str(res_length) << "\n";
                }
            }
            prev_sym = it -> first;
            std::advance(it, 2);
            if (it == res_symtab.end() || (it -> first).compare(text_address) > 0){
                name = is_in_symbol.get_rel_sym(prev_sym);
                res_length = subtract_Addy(prev_sym, text_address);
                if (res_length % 3 == 0){
                    inStream << name << "   RESW   " << int_to_str(res_length / 3) << "\n";
                }
                else {
                    inStream << name << "   RESB   " << int_to_str(res_length) << "\n";
                }
            
            }
            if (org_stop.compare("") != 0){
                inStream << "     ORG   " << org_stop << "\n";
            }
            break;
        }
    }
}
//Our print text record will go here we have to check if it's just all 0s first 
void print_txt(std::string label, std::string mnemonic, std::string operand, std::ofstream& inStream, bool x_flag, bool e_flag, bool n_flag, bool i_flag){
    std::string temp_Mne = mnemonic;
    mnemonic = " " + mnemonic;
    std::string temp_operation = operand;
    operand = " " + operand;
    if (operand.compare("0") == 0 || operand.compare("00") == 0 || operand.compare("000") == 0 \
     && operand.compare("0000") == 0 || operand.compare("00000") == 0 || operand.compare("000000") == 0){
        operand = "0";
    }
    if (operand.compare("0") != 0){
        operand = operand.erase(0,operand.find_first_not_of('0'));
    }
    if (e_flag) {
        mnemonic = "+" + temp_Mne;
    }
    if (n_flag){
        operand = "@" + temp_operation;
    }
    else if (i_flag){
        operand = "#" + temp_operation;
    }
    if (x_flag){
        operand = operand + ",X";
    }
    inStream << label << setw(8 - label.size()) << ' ' << mnemonic << setw(8 - mnemonic.size()) << ' ' << operand << "\n";
}
//Printing our header 
void print_hdr(std::string label, std::string first_address,std::ofstream& inStream){
    if (first_address.compare("000000") == 0 ){
        inStream << setw(6) << label << setw(3) << ' ' << "START" << ' ' << "0" << "\n";
    }
    else {
        inStream << setw(6) << label << setw(3) << ' ' << "START" << ' ' << first_address.erase(0,first_address.find_first_not_of('0')) << "\n";
    }
}
//Print out our end record
void print_end(std::string end_rec, std::ofstream& inStream){
    if (end_rec.size() > 0) {
        //I have 6 spaces and then 3 for the END part 
        inStream << "      " << "END    " << end_rec.substr(1, 6)<< "\n";
    }
    else {
        inStream << "      " << "END" << "\n";
    }
}






