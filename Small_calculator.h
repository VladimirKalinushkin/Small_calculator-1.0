
#include <iostream>
#include <fstream>
#include <thread>

#include <string>
#include <vector>
#include <math.h>

using namespace std;

const char exit_simbol = 'q';
const char* promt = ">>";
const char* print_result = ": ";
const char print = ';';
const char type_is_number = 'n';
const char type_is_error = 'e';

#include "class_TokenStream.cpp"
#include "calculation.cpp"


void welcome_words();

