#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include "file_parser.h"
#include "file_parse_exception.h"

using namespace std;

//Public methods
file_parser::file_parser(string input){
filename = input;
};

file_parser::~file_parser(){};
void file_parser::print_file(){};

string file_parser::get_token(unsigned int, unsigned int){return "";};

void file_parser::read_file(){
	readin_sourcefile();
	splitTotokens();
};

int file_parser::size(){return numOflines;};

//Private methods
void file_parser::readin_sourcefile(){
ifstream infile;
infile.open(filename.c_str(),ios::in);
if(!infile) throw file_parse_exception("File failed to open!");
string inLine;
numOflines = 0;
while(!infile.eof())
{
        getline(infile,inLine);
        numOflines++;
        fileContents.push_back(inLine);
}
infile.close();
};

void file_parser::splitTotokens(){
 string str;
        char delimiters[] = " \t";
        char buffer[100];
        vector<string>::iterator itr;
        for(itr=fileContents.begin(); itr < fileContents.end(); itr++){
                str = *itr;
                if(str.length() > 99) {
                        cout<< "Line too long" << endl;
                        exit(1);
                }
strcpy(buffer,str.c_str());
                char *ptr;
                ptr = strtok(buffer,delimiters);
                while(ptr != NULL){  
                        cout << ptr << endl;
                        ptr = strtok(NULL, delimiters);
                }
        }
};
file_parse_exception::file_parse_exception(string);
file_parse_exception::file_parse_exception();
