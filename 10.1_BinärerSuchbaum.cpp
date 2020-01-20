#include <iostream>
#include "binaerer_suchbaum.h"
using namespace std;

void suchbaum::einfuegen(BaumKnoten*& anker, int neuer_Wert) //einfügen des Wertes neuer Wert in den Baum
{
	BaumKnoten* neuer_eintrag = new BaumKnoten;
	neuer_eintrag->data = neuer_Wert;
	neuer_eintrag->lower = nullptr;
	neuer_eintrag->higher = nullptr;
	if (anker == nullptr)
		anker = neuer_eintrag;
	else
	{
		BaumKnoten* ptr = anker;
		while (true) 
		{
			if (ptr->data > neuer_eintrag->data)
			{
				if (ptr->lower != nullptr)
					ptr = ptr->lower;
				else
				{
					ptr->lower = neuer_eintrag;
					break;
				}
			}
			else if (ptr->data < neuer_eintrag->data)
			{
				if (ptr->higher != nullptr)
					ptr = ptr->higher;
				else
				{
					ptr->higher = neuer_eintrag;
					break;
				}
			}
			else if (ptr->data == neuer_eintrag->data)
			{
				delete neuer_eintrag;
				break;
			}
		}
	}
}

void suchbaum::ausgeben(BaumKnoten*& anker)
{
	if (anker != nullptr)
	{
		int tiefe = 0;
		knoten_ausgeben(anker, tiefe);
	}
	else
	{
		cout << "Leerer Baum." << endl;
	}
}


void suchbaum::knoten_ausgeben(suchbaum::BaumKnoten* knoten, int tiefe)
{
	if (knoten->higher != nullptr)
	{
		knoten_ausgeben(knoten->higher, tiefe + 1); //nicht tiefe++, da dabei beim neuen Funktionsaufruf die Tiefe des Aktuellen Aufruf geändert wird
	}
	for (int i = 0; i < tiefe; i++)
	{
		cout << "++";
	}
	cout << knoten->data << endl;
	if (knoten->lower != nullptr)
	{
		knoten_ausgeben(knoten->lower, tiefe + 1);
	}
};

