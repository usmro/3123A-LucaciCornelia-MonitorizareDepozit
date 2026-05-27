#include "Depozit.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

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

    bool exista = false;

    for (const auto& pair : produse) {

        const Produs& produs = pair.second;

        if (produs.getCantitate() <= produs.getPragAlerta()) {

            exista = true;

            produs.afiseaza();
        }
    }

    if (!exista) {
        std::cout << "Nu exista produse sub prag.\n";
    }
}

Produs Depozit::getProdus(int id) const {

    auto it = produse.find(id);

    if (it == produse.end()) {
        throw std::runtime_error("Produs inexistent!");
    }

    return it->second;
}

void Depozit::produsePentruRecomanda() const {

    std::vector<Produs> recomandari;

    for (const auto& pair : produse) {

        const Produs& produs = pair.second;

        if (produs.getCantitate() <= produs.getPragAlerta()) {
            recomandari.push_back(produs);
        }
    }

    std::sort(recomandari.begin(), recomandari.end(),
        [](const Produs& a, const Produs& b) {

            int deficitA = a.getPragAlerta() - a.getCantitate();
            int deficitB = b.getPragAlerta() - b.getCantitate();

            return deficitA > deficitB;
        });

    std::cout << "\n<<< Produse recomandate pentru RE-COMANDA >>>\n";

    if (recomandari.empty()) {

        std::cout << "Nu exista produse care necesita reaprovizionare.\n";
        return;
    }

    for (const auto& produs : recomandari) {

        produs.afiseaza();
    }
}

void Depozit::afiseazaProduseSortateCantitate() const {

    std::vector<Produs> listaProduse;

    for (const auto& pair : produse) {
        listaProduse.push_back(pair.second);
    }

    std::sort(listaProduse.begin(), listaProduse.end(),
        [](const Produs& a, const Produs& b) {

            return a.getCantitate() < b.getCantitate();
        });

    std::cout << "\n<<< Produse sortate dupa cantitate >>>\n";

    for (const auto& produs : listaProduse) {
        produs.afiseaza();
    }
}