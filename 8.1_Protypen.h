#pragma once
#include <string>

struct Person
{
	std::string nachname;
	std::string vorname;
	std::string geburtsdatum;
};
Person extrahiere_person(std::string eingabezeile);

void spalte_ab_erstem(std::string eingabe, char zeichen, std::string& erster_teil, std::string& zweiter_teil);
std::string trimme(std::string s);
