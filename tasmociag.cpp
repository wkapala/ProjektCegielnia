#include "tasmociag.h"
#include <iostream> 

Tasmociag::Tasmociag(int maxIloscCegiel, int maxLacznaMasa)
    : maxIloscCegiel_(maxIloscCegiel),
    maxLacznaMasa_(maxLacznaMasa),
    aktualnaLacznaMasa_(0)
{
}

Tasmociag::~Tasmociag()
{
    
}

bool Tasmociag::dodajCegle(int masaCegly)
{
    // Sprawd�, czy jest miejsce liczbowe
    if (cegly_.size() >= static_cast<size_t>(maxIloscCegiel_))
    {
        
        return false;
    }

    // Sprawd�, czy przekroczymy ��czn� mas�
    if (aktualnaLacznaMasa_ + masaCegly > maxLacznaMasa_)
    {
        
        return false;
    }

    // Je�li warunki OK, to dodaj ceg��
    cegly_.push(masaCegly);
    aktualnaLacznaMasa_ += masaCegly;
    return true;
}

int Tasmociag::pobierzCegle()
{
    if (cegly_.empty())
    {
        
        return -1; // sygnalizujemy brak cegie�
    }

    // Pobieramy ceg�� z kolejki
    int masa = cegly_.front();
    cegly_.pop();
    aktualnaLacznaMasa_ -= masa;
    return masa;
}

int Tasmociag::getLiczbaCegiel() const
{
    return static_cast<int>(cegly_.size());
}

int Tasmociag::getMaxIloscCegiel() const
{
    return maxIloscCegiel_;
}

int Tasmociag::getMaxLacznaMasa() const
{
    return maxLacznaMasa_;
}
