#pragma once
#include <iostream>

class Data
{
public:
	Data(int d , int m , int r);
	~Data();
private:
	int m_nDzien;
	int m_nMiesiac;
	int m_nRok;
public:
	void Ustaw(int d, int m, int r);
	int Dzien() const;
	int Miesiac() const;
	int Rok() const;
	void Wypisz() const;
	void Wpisz();
	void Koryguj();
	int Porownaj(const Data & wzor) const;

	friend std::ostream &operator<<(std::ostream & wy, const Data & d);
	friend std::istream &operator>>(std::istream & we, Data & d);
};

