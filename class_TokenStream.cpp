#include "class_TokenStream.h"//не забудьте в программе создать объект потока!!!

char TokenStream::Token_type(){ return buffer.type; }
double TokenStream::Token_value(){ return buffer.value; }

void TokenStream::get() {

	if (!InBuffer)
        {

        cin >> buffer.type;

        switch (buffer.type){
            case '-': case '+': case '*': case '/': case print: case exit_simbol: case '(': case ')': {
                break;
                }
            case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '0': {
                cin.putback(buffer.type);
                cin >> buffer.value;
                buffer.type = type_is_number;
                break;
            }
            default:{
                throw " Неправильный ввод! \n";
                break;
            }
        }
	}

	else InBuffer = false;

	return;

}

void TokenStream::putback() {

    if(InBuffer) throw " Ошибка в структуре программы, дважды возвращен Token в поток! \n";
    InBuffer = true;

}

void TokenStream::putback(Token t) {

    if(InBuffer) throw " Ошибка в структуре программы, дважды возвращен Token в поток! \n";
	buffer = t;
    InBuffer = true;

}
