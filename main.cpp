#define CATCH_CONFIG_RUNNER
#include "catch.h" 

#include <iostream>
using namespace std;

#include "suchen.h" 

int main()
{

	if (Catch::Session().run()) {
		system("PAUSE"); return 1;
	}

	const unsigned int length = 21;
	char text[length] = { 0 };
	char zkette[length] = { 0 };

	cout << "Bitte geben Sie den Text ein : ";
	cin.getline(text, length);
	cin.clear();
	cout << "Bitte geben Sie die zu suchende Zeichenkette ein : ";
	cin.getline(zkette, length);
	cin.clear();
	if (zeichenkette_suchen(text, zkette) == -1)
	{
		cout << "Die Zeichenkette '" << zkette << "' ist NICHT in dem Text '" << text << "' enthalten." << endl;
	}
	else
	{
		cout << "Die Zeichenkette '" << zkette << "' ist in dem Text '" << text << "' enthalten." << endl;
		cout << "Sie startet ab Zeichen " << zeichenkette_suchen(text, zkette) << " (bei Zaehlung ab 0)." << endl;
	}
	system("PAUSE");
	return 0;
}