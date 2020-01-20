#include "MyString2.h"
#include "CharListenKnoten.h"

void MyString2::append_internal(char p_data) //analog zu hinten anfuegen in Praktikum 9.01
{
	CharListenKnoten* neuer_eintrag = new CharListenKnoten;
	neuer_eintrag->set_data(p_data);
	neuer_eintrag->set_next(nullptr);
	if (this->anker == nullptr)
		this->anker = neuer_eintrag;
	else
	{
		CharListenKnoten* ptr = anker;
		while (ptr->get_next() != nullptr)
			ptr = ptr->get_next();
		ptr->set_next(neuer_eintrag);
	}
}

void MyString2::delete_internal()
{
	CharListenKnoten* ptr = anker;
	if (ptr != nullptr)
	{
		while (ptr->get_next() != nullptr)
		{
			ptr = ptr->get_next();
			delete this->anker;
			this->anker = ptr;
		}
		delete ptr;
		anker = nullptr;
	}
}

CharListenKnoten* MyString2::deep_copy_internal() const
{
	if (this->anker == nullptr) //da wir sonnst ein CharListenknoten erstellen würden, mit leeren Datenwert ('/0')
		return nullptr;
	CharListenKnoten* new_anker = new CharListenKnoten(this->at(0));
	for (int i = 1; i < this->length(); i++)
	{
		CharListenKnoten* neuer_eintrag = new CharListenKnoten;
		neuer_eintrag->set_data(this->at(i));
		neuer_eintrag->set_next(nullptr);
		CharListenKnoten* ptr = new_anker;
		while (ptr->get_next() != nullptr)
			ptr = ptr->get_next();
		ptr->set_next(neuer_eintrag);
	}
	return new_anker;
}

MyString2::MyString2()
{
	anker = nullptr;
}

MyString2::MyString2(std::string input)
{//leeres Input überprüfen
	if (input != "")
	{
		anker = new CharListenKnoten(input[0]);
		for (int i = 1; i < input.length(); i++)
		{
			this->append_internal(input[i]);
		}
	}
}

MyString2::~MyString2()
{
	delete_internal();
}

MyString2::MyString2(const MyString2& source)
{
	this->anker = source.deep_copy_internal();
}
MyString2& MyString2::operator = (const MyString2& source)
{
	this->delete_internal();
	this->anker = source.deep_copy_internal();
	return *this;
}

MyString2 MyString2::operator +(char c) const
{
	MyString2 result(*this);
	result.append_internal(c);
	return result;
}

void MyString2::set_anker(CharListenKnoten* anker) { this->anker = anker; }

CharListenKnoten* MyString2::get_anker() { return anker; }

unsigned int MyString2::length() const
{
	int length_count = 0;
	CharListenKnoten* ptr = this->anker;
	while (ptr != nullptr)
	{
		length_count++;
		ptr = ptr->get_next();
	}
	return length_count;
}

char MyString2::at(unsigned int pos) const
{
	CharListenKnoten* ptr = this->anker;
	for (unsigned int i = 0; i < pos; i++)
	{
		if (ptr == nullptr)
			break;
		ptr = ptr->get_next();
	}
	if (ptr == nullptr)
		return '\0';
	else
		return ptr->get_data();
}

std::string MyString2::to_string()
{
	std::string result = "";
	for (unsigned int i = 0; i < this->length(); i++)
	{
		result += this->at(i);
	}
	return result;
}

