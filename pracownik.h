#ifndef Pracownik_H
#define Pracownik_H

class Tasmociag;

class Pracownik
{
private:
	int id;
	int masaCeg�y;

public:
	Pracownik(int id, int masaCeg�y);
	void dodajCegle(Tasmociag& tasmociag);
};
#endif // Pracownik_H

