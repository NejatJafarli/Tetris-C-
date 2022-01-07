#pragma once

#include "Adress.h"

class Insan
{
public:
	string Isim;
	int Tc;
	Adres Adresi;

	Insan(string isim,int tc,Adres adresim):
		Adresi(adresim)
	{
		Isim = isim;
		Tc = tc;
	}
};



