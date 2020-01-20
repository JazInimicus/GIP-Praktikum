#pragma once
#include "CharListenKnoten.h"
#include <string>

class MyString2
{
	friend void friend_append_internal(MyString2& s, char p_data);
	friend void friend_delete_internal(MyString2& s);
	friend CharListenKnoten* friend_deep_copy_internal(MyString2& s);
private:
	CharListenKnoten* anker; //Anker
protected:
	void append_internal(char p_data); //neuer Knoten hinten anhaengen mit p_data als wert
	void delete_internal(); //loescht alle eintraege des MyStrings
	CharListenKnoten* deep_copy_internal() const; //kopiert das Pointerarray und gibt seine Anker zurueck
public:
	MyString2(); //Default Konstruktor: anker = nullptr
	MyString2(std::string input); //Konstruktor mit Wert
	~MyString2(); //Destruktor

	MyString2(const MyString2& source); //inizialisieren durch Kopie eines vorhandenen MyString2
	MyString2& operator = (const MyString2& source); // Ersetzen mit einer Kopie von MyString2
	MyString2 operator +(char c) const; // Buchstabe anhaengen

	void set_anker(CharListenKnoten* anker); // setzt den Anker
	CharListenKnoten* get_anker(); //gibt den Anker zurueck
	unsigned int length() const; //laenge des MyString2
	char at(unsigned int pos) const; //wert an Position, wenn nicht vorhanden '\0'
	std::string to_string(); //Rückgabe als String
};