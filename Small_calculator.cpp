
#include "Small_calculator.h"


 
void welcome_words() {

    
    cout    << '\n'
            << "Для начала введите выражение, завершите его "
            << print
            << " . Для завершения -  "
            << exit_simbol
            << '\n'
            << '\n';
}

int main()
{
    try {

        welcome_words();

        calculation();
    }
    catch(const char* err){

        cerr << err << "Произошла неизвестная ошибка!";
        system("pause");

    }
    
    return 0;
	
}
