#include "Depozit.h"
#include <iostream>
#include <stdexcept>

void Depozit::adaugaProdus(const Produs& produs) {

    if (produse.find(produs.getId()) != produse.end()) {
        throw std::runtime_error("Exista deja un produs cu acest ID!");
    }

    produse[produs.getId()] = produs;
}

void Depozit::eliminaProdus(int id) {

    if (produse.find(id) == produse.end()) {
        throw std::runtime_error("Produs inexistent!");
    }

    produse.erase(id);
}

void Depozit::restockProdus(int id, int cantitate) {

    if (produse.find(id) == produse.end()) {
        throw std::runtime_error("Produs inexistent!");
    }

    produse[id] += cantitate;
}

void Depozit::vindeProdus(int id, int cantitate) {

    if (produse.find(id) == produse.end()) {
        throw std::runtime_error("Produs inexistent!");
    }

    produse[id] -= cantitate;
}

void Depozit::afiseazaToateProdusele() const {

    for (const auto& pair : produse) {
        pair.second.afiseaza();
    }
}

void Depozit::raportProduseSubPrag() const {

    std::cout << "\nProduse sub prag:\n";

    for (const auto& pair : produse) {

        if (pair.second.getCantitate() < pair.second.getPragAlerta()) {
            pair.second.afiseaza();
        }
    }
}