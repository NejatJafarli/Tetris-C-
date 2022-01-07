#pragma once
#include <iostream>;
#include <string>

using namespace std;
class Adres
{
public:
	string Sokak;
	string ApartmanAdi;
	int DaireNumarasi;
	string Mahalle;
	string Sehir;

	Adres(string sokak, string apartmanadi, int daire, string mahalle, string sehir) {
		Sokak = sokak;
		ApartmanAdi = apartmanadi;
		DaireNumarasi = daire;
		Mahalle = mahalle;
		Sehir = sehir;
	};

};
