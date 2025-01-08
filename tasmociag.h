#ifndef TASMOCIAG_H
#define TASMOCIAG_H

#include <queue>


class Tasmociag
{
private:
    int maxIloscCegiel_;       ///< K - maksymalna liczba cegie³, które mog¹ byæ jednoczeœnie na taœmoci¹gu
    int maxLacznaMasa_;        ///< M - maksymalna ³¹czna masa cegie³ na taœmoci¹gu
    std::queue<int> cegly_;    ///< Kolejka przechowuj¹ca masy cegie³ (FIFO)
    int aktualnaLacznaMasa_;   ///< Suma mas cegie³ obecnych na taœmoci¹gu

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
