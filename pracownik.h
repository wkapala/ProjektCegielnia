#ifndef Pracownik_H
#define Pracownik_H

class Tasmociag;

class Pracownik
{
private:
	int id;
	int masaCegly;

public:
	Pracownik(int id, int masaCegly);
	void dodajCegle(Tasmociag& tasmociag);
};
#endif // Pracownik_H

