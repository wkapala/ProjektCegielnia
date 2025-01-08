#ifndef TASMOCIAG_H
#define TASMOCIAG_H

#include <queue>


class Tasmociag
{
private:
    int maxIloscCegiel_;       ///< K - maksymalna liczba cegie�, kt�re mog� by� jednocze�nie na ta�moci�gu
    int maxLacznaMasa_;        ///< M - maksymalna ��czna masa cegie� na ta�moci�gu
    std::queue<int> cegly_;    ///< Kolejka przechowuj�ca masy cegie� (FIFO)
    int aktualnaLacznaMasa_;   ///< Suma mas cegie� obecnych na ta�moci�gu

public:
    
    Tasmociag(int maxIloscCegiel, int maxLacznaMasa);

    
    ~Tasmociag();

    
    bool dodajCegle(int masaCegly);

    
    int pobierzCegle();

    
    int getLiczbaCegiel() const;

    
    int getMaxIloscCegiel() const;

    
    int getMaxLacznaMasa() const;
};

#endif // TASMOCIAG_H
