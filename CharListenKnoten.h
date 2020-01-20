#pragma once
class CharListenKnoten
{
	char data;
	CharListenKnoten* next;
public:
	CharListenKnoten(char data = '\0') //Ohne data wird der Char eh mit '\0' beschrieben
	{
		set_data(data);
		set_next(nullptr);
	}
	char get_data() { return data; }
	void set_data(char data) { this->data = data; }

	CharListenKnoten* get_next() { return next; }
	void set_next(CharListenKnoten* next) { this->next = next; }
};
