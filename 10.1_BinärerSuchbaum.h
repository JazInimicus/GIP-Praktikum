#pragma once

namespace suchbaum
{
	struct BaumKnoten //Datenstuktur
	{
		int data; // Wert der Datenstruktur
		BaumKnoten* lower; // höherer Integerwert
		BaumKnoten* higher; // niedrigerer Integerwert
	};
	void einfuegen(BaumKnoten*& anker, int neuer_Wert);
	void ausgeben(BaumKnoten*& anker);
	
	void knoten_ausgeben(BaumKnoten* knoten, int tiefe);
}
