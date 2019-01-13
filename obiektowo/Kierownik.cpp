#include "Kierownik.h"





Kierownik::Kierownik(int id, Napis nazwa, int liczba)
	: Pracownik(id, "", "", 1, 1, 2000)
	, m_NazwaDzialu{ nazwa }
	, m_nLiczbaPracownikow{ liczba }
{
}

Kierownik::Kierownik(const Kierownik & wzor)
	: m_NazwaDzialu{ wzor.m_NazwaDzialu }
	, m_nLiczbaPracownikow{ wzor.m_nLiczbaPracownikow }
//	, Pracownik(wzor.GetID(), wzor.Imie(), wzor.Nazwisko(), wzor.m_DataUrodzenia.Dzien(), wzor.m_DataUrodzenia.Miesiac(), wzor.m_DataUrodzenia.Rok())
	, Pracownik(wzor)
{

}



Kierownik::~Kierownik()
{
}

Kierownik & Kierownik::operator=(const Kierownik & wzor)
{
	if (this == &wzor)
		return *this;

	m_DataUrodzenia = wzor.m_DataUrodzenia;
	m_Imie = wzor.m_Imie;
	m_Nazwisko = wzor.m_Nazwisko;
	m_NazwaDzialu = wzor.m_NazwaDzialu;
	m_nLiczbaPracownikow = wzor.m_nLiczbaPracownikow;
	return *this;
}

bool Kierownik::operator==(const Kierownik & wzor) const
{
	if (this == &wzor)
		return true;

	if (Porownaj(wzor) == 0 && wzor.m_NazwaDzialu == m_NazwaDzialu && wzor.m_nLiczbaPracownikow == m_nLiczbaPracownikow)
		return true;
	else
		return false;
}

void Kierownik::WypiszDane()
{
	std::cout << "ID: " << m_nIDZatrudnienia << '\t';
	m_Imie.Wypisz();
	std::cout << '\t';
	m_Nazwisko.Wypisz();
	std::cout << '\t';
	m_DataUrodzenia.Wypisz();
	std::cout << '\t';
	m_NazwaDzialu.Wypisz();
	std::cout << '\t';
	std::cout << m_nLiczbaPracownikow << "	pracownikow\t";
	std::cout << std::endl;
}

Kierownik * Kierownik::KopiaObiektu()
{
	Kierownik* nowyKierownik;
	nowyKierownik = new Kierownik(*this);
	return nowyKierownik;
}

std::ostream & operator<<(std::ostream & wy, const Kierownik & p)
{
	wy << p.m_nIDZatrudnienia << std::endl << p.m_Imie << std::endl << p.m_Nazwisko << std::endl << p.m_DataUrodzenia << std::endl << p.m_NazwaDzialu << std::endl << p.m_nLiczbaPracownikow << std::endl;;
	return wy;
}

std::istream & operator>>(std::istream & we, Kierownik & p)
{
	we >> p.m_nIDZatrudnienia >> p.m_Imie >> p.m_Nazwisko >> p.m_DataUrodzenia >> p.m_NazwaDzialu >> p.m_nLiczbaPracownikow;
	return we;
}
