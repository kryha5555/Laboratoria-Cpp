#include "Pracownik.h"
#include <iostream>


Pracownik::Pracownik(int id, const char* im, const char* naz, int dzien, int miesiac, int rok)
	: m_DataUrodzenia(dzien, miesiac,rok)
	, m_Imie(im)
	, m_Nazwisko(naz)
	, m_nIDZatrudnienia(id)
{

}

Pracownik::Pracownik(const Pracownik & wzor)
	: m_DataUrodzenia(wzor.m_DataUrodzenia)
	, m_Imie(wzor.m_Imie)
	, m_Nazwisko(wzor.m_Nazwisko)
	, m_nIDZatrudnienia(wzor.m_nIDZatrudnienia +1)
{
}


Pracownik::~Pracownik()

{
}


const char* Pracownik::Imie() const
{
	return m_Imie.Zwroc();
}

const char* Pracownik::Nazwisko() const
{
	return m_Nazwisko.Zwroc();
}
void Pracownik::Imie(const char* nowe_imie)
{
	m_Imie.Ustaw(nowe_imie);
}
void Pracownik::Nazwisko(const char* nowe_nazwisko)
{
	m_Nazwisko.Ustaw(nowe_nazwisko);
}
void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
	m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}
void Pracownik::Wypisz() const
{
	std::cout << "ID: " << m_nIDZatrudnienia << '\t';
	m_Imie.Wypisz();
	std::cout << '\t';
	m_Nazwisko.Wypisz();
	std::cout << '\t';
	m_DataUrodzenia.Wypisz();

}
void Pracownik::Wpisz()
{
	std::cout << "Podaj imie: ";
	m_Imie.Wpisz();
	std::cout << "Podaj nazwisko: ";
	m_Nazwisko.Wpisz();
	std::cout << "Podaj date urodzenia: ";
	m_DataUrodzenia.Wpisz();

}
int Pracownik::SprawdzImie(const char* por_imie) const
{
	return m_Imie.SprawdzNapis(por_imie);
}
int Pracownik::SprawdzNazwisko(const char* por_nazwisko) const
{
	return m_Nazwisko.SprawdzNapis(por_nazwisko);
}

int Pracownik::GetID()
{
	return m_nIDZatrudnienia;
}


int Pracownik::Porownaj(const Pracownik& wzorzec) const // na ten moment bez porownywania dat
{
	if (m_Nazwisko.SprawdzNapis(wzorzec.Nazwisko()) == 0 && m_Imie.SprawdzNapis(wzorzec.Imie()) == 0)
	{
		return 0; // tacy sami
	}
	else if ((m_Nazwisko.SprawdzNapis(wzorzec.Nazwisko()) == 1)  || (m_Nazwisko.SprawdzNapis(wzorzec.Nazwisko()) == 0 && m_Imie.SprawdzNapis(wzorzec.Imie()) == 1))
	{
		return 1;
	}
	else
		return -1;
}

Pracownik & Pracownik::operator=(const Pracownik & wzor)
{
	if (this == &wzor)
		return *this;

	m_DataUrodzenia = wzor.m_DataUrodzenia;
	m_Imie = wzor.m_Imie;
	m_Nazwisko = wzor.m_Nazwisko;
	return *this;
}

bool Pracownik::operator==(const Pracownik & wzor) const
{
	if (this == &wzor)
		return true;

	if (this->Porownaj(wzor) == 0)
		return true;
	else
		return false;
}

void Pracownik::WypiszDane()
{
}

Pracownik * Pracownik::KopiaObiektu()
{
	return nullptr;
}

std::ostream & operator<<(std::ostream & wy, const Pracownik & p)
{
	wy << p.m_nIDZatrudnienia << std::endl << p.m_Imie << std::endl << p.m_Nazwisko << std::endl << p.m_DataUrodzenia << std::endl;
	return wy;

}

std::istream & operator >> (std::istream & we, Pracownik & p)
{
	we >> p.m_nIDZatrudnienia >> p.m_Imie >> p.m_Nazwisko >>  p.m_DataUrodzenia;
	return we;
}
