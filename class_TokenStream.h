
// не забудьте в программе создать объект потока!!!

//создаем объект виртуального (!) потока ввода вывода
//в нем хранится только один объект Token,
//но для работы обработчик TokenStream :: get(); запрашивает данные из потока cin
//если в объекте помечено, что объект был возвращен из потка, (в реальности, в нем в любом случае есть объект Token)
//происходит просто обратная пометка о том, что его забрали

class Token
{
public:

    char type = 'z'; //off zero
    double value = 0;

};

class TokenStream {

public:

	char Token_type();
    double Token_value();

    void get();
    void putback();
    void putback(Token t);

private:

    Token buffer;
	bool InBuffer = false;

};
