#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include "file_parser.h"
#include "file_parse_exception.h"

using namespace std;


file_parser::file_parser(string){};
file_parser::~file_parser(){};
void file_parser::print_file(){};
string file_parser::get_token(unsigned int, unsigned int){return "";};
void file_parser::read_file(){};
int file_parser::size(){return 1;};

file_parse_exception::file_parse_exception(string);
file_parse_exception::file_parse_exception();
