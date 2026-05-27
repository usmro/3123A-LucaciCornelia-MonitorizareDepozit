#ifndef DEPOZIT_H
#define DEPOZIT_H

#include <unordered_map>
#include "Produs.h"

class Depozit {
private:
    std::unordered_map<int, Produs> produse;

public:
    void adaugaProdus(const Produs& produs);
    void eliminaProdus(int id);

    void restockProdus(int id, int cantitate);
    void vindeProdus(int id, int cantitate);

    void afiseazaToateProdusele() const;
    void raportProduseSubPrag() const;
};

#endif