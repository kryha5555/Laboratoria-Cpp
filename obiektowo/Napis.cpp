#define _CRT_SECURE_NO_WARNINGS
#include "Napis.h"

Napis::Napis(const char* nap)
{
	m_nDl = strlen(nap) + 1;
	m_pszNapis = new char[m_nDl];
	strcpy(m_pszNapis, nap);

}

Napis::Napis(const Napis & wzor)
{
	m_nDl = wzor.m_nDl;
	m_pszNapis = new char[m_nDl];
	strcpy(m_pszNapis, wzor.m_pszNapis);
}

/*Napis::Napis()
{

}
*/

Napis::~Napis()
{
	delete[] m_pszNapis;
}


const char* Napis::Zwroc() const
{
	return this->m_pszNapis;
}


void Napis::Ustaw(const char* nowy_napis)
{
	m_nDl = strlen(nowy_napis) + 1;
	m_pszNapis = new char[m_nDl];
	strcpy(m_pszNapis, nowy_napis);

}


void Napis::Wypisz() const
{
	//for (int i = 0; i < 40 && m_pszNapis[i] != '\0'; i++)
		//std::cout << m_pszNapis[i];
	std::cout << m_pszNapis;
}

void Napis::Wpisz()
{

	/*int i = 0;
	char c;
	do
	{
		c = std::cin.get();
		m_pszNapis[i] = c;
		i++;
	} while (c != '\n' && i < 40);
	if (i < 40)
		m_pszNapis[i - 1] = '\0';
	for (i; i < 40; i++)
		m_pszNapis[i] = '\0';*/

	std::string napis;
	std::cin >> napis;
	Ustaw(napis.c_str());

}

int Napis::SprawdzNapis(const char* por_napis) const
{
	/*for (int i = 0; i < 40; i++)
	{
		if (m_pszNapis[i] == '\0' && por_napis[i] == '\0')
			return 0;
		else if (m_pszNapis[i] > por_napis[i])
			return 1; //dalej
		else if (m_pszNapis[i] < por_napis[i])
			return -1; // blizej
			}*/
	return strcmp(m_pszNapis, por_napis);
	
}

Napis & Napis::operator=(const Napis & wzor)
{
	if (this == &wzor)
		return *this;

	m_nDl = wzor.m_nDl;
	m_pszNapis = new char[m_nDl];
	strcpy(m_pszNapis, wzor.m_pszNapis);
	return *this;

}

bool Napis::operator==(const Napis & wzor) const
{
	if (this == &wzor)
		return true;

	if (m_nDl == wzor.m_nDl && !strcmp(m_pszNapis, wzor.m_pszNapis))
		return true;
	else
		return false;
}

std::ostream & operator<<(std::ostream & wy, const Napis & p)
{
	wy << p.m_pszNapis;
	return wy;
}

std::istream & operator >> (std::istream & we, Napis & p)
{
	std::string str;
	we >> str;
	p.m_nDl = str.length() + 1;
	p.m_pszNapis = new char[p.m_nDl];
	strcpy(p.m_pszNapis, str.c_str());
	return we;
}