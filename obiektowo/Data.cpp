#include "Data.h"
#include <iostream>

Data::Data(int d, int m, int r)
{
	m_nDzien = d;
	m_nMiesiac = m;
	m_nRok = r;
	this->Koryguj();
}

Data::~Data()
{
}


void Data::Ustaw(int d, int m, int r)
{
	m_nDzien = d;
	m_nMiesiac = m;
	m_nRok = r;
	this->Koryguj();
}

int Data::Dzien() const
{
	return m_nDzien;
}



int Data::Miesiac() const
{
	return m_nMiesiac;
}


int Data::Rok() const
{
	return m_nRok;
}


void Data::Wypisz() const
{
	std::cout << Dzien() << "-" << Miesiac() << "-" << Rok();
}

void Data::Wpisz()
{
	std::cout << "Podaj dzien: ";
	std::cin >> m_nDzien;
	std::cout << "Podaj miesiac: ";
	std::cin >> m_nMiesiac;
	std::cout << "Podaj rok: ";
	std::cin >> m_nRok;
	this->Koryguj();
}



void Data::Koryguj()
{
	if (m_nMiesiac < 1)
		m_nMiesiac = 1;
	else if (m_nMiesiac > 12)
		m_nMiesiac = 12;

	if (m_nDzien < 1)
		m_nDzien = 1;
	else if (m_nMiesiac == 1 || m_nMiesiac == 3 || m_nMiesiac == 5 || m_nMiesiac == 7 || m_nMiesiac == 8 || m_nMiesiac == 10 || m_nMiesiac == 12)
	{
		if (m_nDzien > 31)
			m_nDzien = 31;
	}
	else if (m_nMiesiac == 4 || m_nMiesiac == 6 || m_nMiesiac == 9 || m_nMiesiac == 11)
	{
		if (m_nDzien > 30)
			m_nDzien = 30;
	}
	else if (m_nRok % 4 == 0 && m_nRok % 100 != 0 || m_nRok % 400 == 0)
	{
		if (m_nDzien > 29)
			m_nDzien = 29;
	}
	else if (m_nDzien > 28)
		m_nDzien = 28;

}


int Data::Porownaj(const Data & wzor) const
{
	if (this->Rok() == wzor.Rok() && this->Miesiac() == wzor.Miesiac() && this->Dzien() == wzor.Dzien())
		return 0;


	else if ((this->Rok() > wzor.Rok()) || (this->Rok() == wzor.Rok() && this->Miesiac() > wzor.Miesiac()) || (this->Rok() == wzor.Rok() && this->Miesiac() == wzor.Miesiac() && this->Dzien() > wzor.Dzien()))
		return -1;
	else return 1;
}

std::ostream & operator<<(std::ostream & wy, const Data &d)
{
	wy << d.m_nDzien << std::endl << d.m_nMiesiac << std::endl << d.m_nRok << std::endl;
	return wy;
}

std::istream & operator >> (std::istream & we, Data & d)
{
	we >> d.m_nDzien >> d.m_nMiesiac >> d.m_nRok;
	d.Koryguj();
	return we;
}


