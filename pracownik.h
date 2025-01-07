#ifndef Pracownik_H
#define Pracownik_H

class Tasmociag;

class Pracownik
{
private:
	int id;
	int masaCeg³y;

public:
	Pracownik(int id, int masaCeg³y);
	void dodajCegle(Tasmociag& tasmociag);
};
#endif // Pracownik_H

