#include "ListaPracownikow.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

ListaPracownikow::ListaPracownikow()
	: m_pPoczatek(NULL)
	, m_nLiczbaPracownikow(0)
{
}


ListaPracownikow::~ListaPracownikow()
{
	m_pPoczatek = NULL;
	m_nLiczbaPracownikow = 0;
	std::cout << "Zaklad upadl, Janusz ukradl caly piniadz." << std::endl;
	WypiszPracownikow();
}


void ListaPracownikow::Dodaj(Pracownik & p)
{
	/*Pracownik temp = p;
	Pracownik curr;

	if (m_pPoczatek == NULL)
	{
		m_pPoczatek = &temp;
		m_pPoczatek->m_pNastepny = NULL;
		m_nLiczbaPracownikow++;
	}
	else
	{
		curr = *m_pPoczatek;
		while (curr.m_pNastepny != NULL)
		{
			curr = *curr.m_pNastepny;
		}
		curr.m_pNastepny = &temp;
		m_nLiczbaPracownikow++;
	}
	*/

	Pracownik *current = m_pPoczatek;
	Pracownik *next = NULL;
	int count = 0;

	if (m_nLiczbaPracownikow == 0)
	{
		m_pPoczatek = &p;
		p.m_pNastepny = NULL;
		m_nLiczbaPracownikow++;
		return;
	}
	else if (m_nLiczbaPracownikow == 1)
	{
		if (current->Porownaj(p) > 0) //na przod
		{
			m_pPoczatek = &p;
			p.m_pNastepny = current;
			m_nLiczbaPracownikow++;
			return;
		}
		else //na tyl
		{
			current->m_pNastepny = &p;
			p.m_pNastepny = NULL;
			m_nLiczbaPracownikow++;
			return;
		}
	}
	else
	{
		next = current->m_pNastepny;
		if (current->Porownaj(p) > 0) // na przod
		{
			m_pPoczatek = &p;
			p.m_pNastepny = current;
			m_nLiczbaPracownikow++;
			return;
		}

		while (count <= m_nLiczbaPracownikow)
		{
			if (next->Porownaj(p) > 0) // po currencie
			{
				current->m_pNastepny = &p;
				p.m_pNastepny = next;
				m_nLiczbaPracownikow++;
				return;
			}
			else if (next->Porownaj(p) < 0)//przegladanie listy
			{
				current = next;
				next = current->m_pNastepny;
				count++;
			}
			if (next == NULL)//na koniec
			{
				current->m_pNastepny = &p;
				p.m_pNastepny = NULL;
				m_nLiczbaPracownikow++;
				return;
			}
		}
	}
}


void ListaPracownikow::Usun(const Pracownik& wzorzec)
{
	Pracownik *current = m_pPoczatek;
	Pracownik *prev = NULL;
	if (m_nLiczbaPracownikow == 0)
		std::cout << "W zakladzie nie ma pracownikow." << std::endl;

	else if (&wzorzec != NULL)
	{
		for (int i = 1; i <= m_nLiczbaPracownikow; i++)
		{
			if (current->Porownaj(wzorzec) == 0)
			{
				if (current = m_pPoczatek)
					m_pPoczatek = current->m_pNastepny;
				else
					prev->m_pNastepny = current->m_pNastepny;

				m_nLiczbaPracownikow--;
				std::cout << "Usunieto pracownika." << std::endl << std::endl;
				return;
			}
			else
			{
				prev = current;
				current = current->m_pNastepny;
			}
		}
	}

}

void ListaPracownikow::WypiszPracownikow() const
{
	/*Pracownik temp = *m_pPoczatek;
	if (&temp == NULL)
		std::cout << "Lista pusta" << std::endl;
	else
	{
		Pracownik curr = *m_pPoczatek;
		while (curr.m_pNastepny != NULL)
		{
			curr.Wypisz();
			std::cout << std::endl;
			curr = *curr.m_pNastepny;
		}

	}*/

	Pracownik *current = m_pPoczatek;

	if (m_nLiczbaPracownikow == 0)
		std::cout << "W zakladzie nie ma pracownikow." << std::endl;
	else
	{
		for (int i = 1; i <= m_nLiczbaPracownikow; i++)
		{
			std::cout << "Pracownik #" << i << ": ";
			current->Wypisz();
			current = current->m_pNastepny;
		}

		std::cout << std::endl << "Liczba pracownikow wynosi " << m_nLiczbaPracownikow << std::endl << std::endl;
	}


}



const Pracownik* ListaPracownikow::Szukaj(const char* nazwisko, const char* imie)
{

	Pracownik *current = m_pPoczatek;

	if (m_nLiczbaPracownikow == 0)
	{
		std::cout << "W zakladzie nie ma pracownikow." << std::endl;
		return NULL;
	}
	else
	{
		for (int i = 1; i <= m_nLiczbaPracownikow; i++)
		{
			if ((current->SprawdzImie(imie) == 0) && (current->SprawdzNazwisko(nazwisko) == 0))
			{
				std::cout << "Znaleziono pracownika: ";
				current->Wypisz();
				return current;
			}
			else
			{
				current = current->m_pNastepny;
			}
		}
		std::cout << "Nie znaleziono pracownika " << nazwisko << " " << imie << std::endl << std::endl;
		return NULL;
	}
}

void ListaPracownikow::ZapisDoPliku()
{
	std::ofstream plik;
	plik.open("lista.dat", std::fstream::out);
	if (!plik.good())
	{
		std::cout << "Fatal error, plik nie bangla" << std::endl;
	}
	else
	{
		std::cout << "Plik otwarto pomyslnie.";
		int count{ 0 };
		Pracownik *current = m_pPoczatek;
		for (int i = 0; i < m_nLiczbaPracownikow; i++)
		{
			if (current != NULL)
			{
				plik << *current << std::endl;
			}
			current = current->m_pNastepny;
			count++;
		}
		plik.close();
		std::cout << "Zapisano " << count << " pracownikow." << std::endl;
	}
}

int ListaPracownikow::WczytajZPliku()
{
	std::fstream plik;
	plik.open("lista.dat", std::fstream::in);
	if (!plik.good())
	{
		std::cout << "Fatal error, plik nie bangla" << std::endl;
		return -1;
	}
	else
	{
		std::cout << "Plik otwarto pomyslnie.";
		m_nLiczbaPracownikow = 0;
		m_pPoczatek = NULL;
		int ID{ 1 };
		std::vector<int> IDs;
		Pracownik *temp = new Pracownik(-1);
		while (plik >> *temp)
		{
			IDs.push_back(temp->GetID());
			Dodaj(*temp);

			temp = new Pracownik(++ID);
		}

		std::cout << "Dodano " << ID - 1 << " pracownikow." << std::endl << std::endl;
		return (*std::max_element(IDs.begin(), IDs.end())) + 1;
	}

}
