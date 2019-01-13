#pragma once
#include "Pracownik.h"
#include "Kierownik.h"

class ListaPracownikow
{
public:
	ListaPracownikow();
	~ListaPracownikow();
private:

	Pracownik* m_pPoczatek;
	int m_nLiczbaPracownikow;

public:
	void Dodaj(Pracownik & p);
	void Usun(const Pracownik& wzorzec);
	void WypiszPracownikow() const;
	const Pracownik* Szukaj(const char* nazwisko, const char* imie);
	void ZapisDoPliku();
	int WczytajZPliku();
};

