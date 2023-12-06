
#include "calculation.h"

//в заголовке объявлен новый объект виртуального потока stream
//для получения всех данных используем только этот объект (как виртуальный поток)


void calculation() {

    while (cin) {
        
        cout << promt;

        try {
            
            stream.get();

            if (stream.Token_type() == exit_simbol) return;
            stream.putback();

            cout
                << print_result
                << summary()
                << '\n';

            stream.get();
            if(stream.Token_type() !=print){

                throw " Выражение неправильно завершено! \n";

            }
        }
        catch (const char* msg) {
            
            cin.clear();
            cin.ignore(32000, '\n');
            stream.get();

            cerr << msg;

        }

    }
    
}

double summary() {

    double result = multiplication();

    while (cin) {
               
        stream.get();

        switch (stream.Token_type()) {
            case '+':
            result +=  multiplication();
            break;
        case '-':
            result -= multiplication();
            break;
        default:
            stream.putback();
            return result;
            break;
        }

    }
    
    return result;
}

double multiplication() {
    
    double result = primary();

    while (cin) {

        stream.get();
        switch (stream.Token_type())
        {
        case '*': {

            stream.get();
            if (stream.Token_type() == 'n' || stream.Token_type() == '(') {
                stream.putback();
                result *= primary();
            }
            else {
                throw " За знаком * должно быть число или скобка! \n";
            }
            break; }
        case '/': {

            stream.get();
            if (stream.Token_type() == 'n' || stream.Token_type() == '(') {
                stream.putback();
                double b = primary();
                if (b == 0)throw " Деление на нуль! \n";
                result /= b;
            }
            else {
                throw " За знаком * должно быть число или скобка! \n";
            }
            break; }
        default:
            stream.putback();
            return result;
            break;
        }
    }

    return result;
}

double primary() {

    stream.get();

    switch (stream.Token_type())
    {
    case type_is_number: {
        return stream.Token_value();
        break; }
    case '+': {
        return primary();
        break; }
    case '-': {
        return  - primary();
        break; }
    case '(': {
        double result = summary();
        stream.get();

        if (stream.Token_type() != ')') throw "нет ')' \n";
        else return result;

        break; }
    default: {
        stream.putback();
        throw " Нет первичного выражения! \n";
        break;
    }
    };

    return 0;
}
