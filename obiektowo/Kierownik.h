#pragma once
#include "Pracownik.h"
class Kierownik :
	public Pracownik
{
public:
	Kierownik(int id, Napis nazwa="", int liczba=0);
	Kierownik(const Kierownik &wzor);
	~Kierownik();

	Kierownik &operator=(const Kierownik & wzor);
	bool operator==(const Kierownik &wzor) const;
	virtual void WypiszDane();
	virtual Kierownik* KopiaObiektu();

	friend std::ostream & operator<<(std::ostream & wy, const Kierownik & p);
	friend std::istream & operator >> (std::istream & we, Kierownik & p);

private:
	Napis m_NazwaDzialu;
	int m_nLiczbaPracownikow;
};

