#include <iostream>
#include <string>
using namespace std;

class Sef
{

public:
	string functie = "Vanzator";
	string loc;

	void detalii()
	{
		cout << "Functia: " << functie << endl;
	}

};

class Angajat : public Sef
{
public:

	string regiune = "Posta Veche";
	int varsta = 25;

	void informatie()
	{
		cout << "Regiunea: " << regiune << endl;
		cout << "Varsta: " << varsta << endl;
		cout << "Locul angajarii: " << loc << endl;
	}
};


int main()
{
	Angajat angajat;
	angajat.loc = "Bonjour Cafe";
	angajat.informatie();
	angajat.detalii();

	return 0;
}