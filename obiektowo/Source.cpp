#include "Data.h"
#include  <iostream>
#include "Napis.h"
#include "Pracownik.h"
#include "ListaPracownikow.h"

using namespace std;


int main()
{
	/*
	Pracownik p1, p2, p3;
	p1.Imie("Adam");
	p1.Nazwisko("Adamszki");
	p1.DataUrodzenia(1, 2, 1960);


	p2.Imie("Badam");
	p2.Nazwisko("Badamszki");
	p2.DataUrodzenia(1, 2, 1960);


	p3.Imie("Cadam");
	p3.Nazwisko("Cadamszki");
	p3.DataUrodzenia(1, 2, 1960);

	ListaPracownikow lista;

	lista.Dodaj(p1);
	lista.WypiszPracownikow();

	lista.Dodaj(p2);
	lista.WypiszPracownikow();

	lista.Dodaj(p3);

	lista.WypiszPracownikow();

	lista.Usun(*lista.Szukaj("Badamszki", "Badam"));
	lista.WypiszPracownikow();
	
	*/

	ListaPracownikow lista;
	Pracownik *nowy;
	Napis imie, nazwisko;
	bool toExit{ 0 };
	int ID{ 1 };
	int w;

	while (!toExit) 
	{
		cout << endl;
		cout << "1. Dodaj pracownika." << endl;
		cout << "2. Usun pracownika." << endl;
		cout << "3. Wyswietl liste." << endl;
		cout << "4. Wyszukaj pracownika." << endl;
		cout << "5. Wczytaj z pliku." << endl;
		cout << "6. Zapisz do pliku." << endl;
		cout << "9. Usun cala liste." << endl;
		cout << "0. Wyjscie." << endl;
		cout << "Wybierz akcje: ";
		cin.clear();
		cin >> w;
		cout << endl;

		switch (w)
		{
		case 1:
			cin.clear();
			nowy = new Pracownik(ID);
			nowy->Wpisz();
			lista.Dodaj(*nowy);
			ID++;
			break;
		case 2:
			cout << "Podaj imie i nazwisko usuwanego pracownika:" << endl;
			cout << "Podaj imie: ";
			imie.Wpisz();
			cout << "Podaj nazwisko: ";
			nazwisko.Wpisz();
			cout << endl;
			lista.Usun(*lista.Szukaj(nazwisko.Zwroc(), imie.Zwroc()));
			break;
		case 3:
			lista.WypiszPracownikow();
			cout << "Nastepne ID to " << ID; 
			break;
		case 4:
			cout << "Podaj imie i nazwisko szukanego pracownika:" << endl;
			cout << "Podaj imie: ";
			imie.Wpisz();
			cout << "Podaj nazwisko: ";
			nazwisko.Wpisz();
			cout << endl;
			lista.Szukaj(nazwisko.Zwroc(), imie.Zwroc());
			break;
		case 5:
			ID = lista.WczytajZPliku();
			lista.WypiszPracownikow();
			cout << "Nastepne ID to " << ID;
			break;
		case 6:
			lista.ZapisDoPliku();
			break;
		case 9:
			lista.~ListaPracownikow();
			ID = 1;
			break;
		case 0:
			toExit = 1;
			break;
		default:
			break;
		}
	}
}