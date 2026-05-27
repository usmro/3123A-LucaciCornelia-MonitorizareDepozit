#ifndef DEPOZIT_H
#define DEPOZIT_H

#include <map>
#include "Produs.h"

class Depozit {

private:
    std::map<int, Produs> produse;

public:
    void adaugaProdus(const Produs& produs);
    void eliminaProdus(int id);

    void restockProdus(int id, int cantitate);
    void vindeProdus(int id, int cantitate);

    void afiseazaToateProdusele() const;
    void raportProduseSubPrag() const;

    Produs getProdus(int id) const;
};

#endif