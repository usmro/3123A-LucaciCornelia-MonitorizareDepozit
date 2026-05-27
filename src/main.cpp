#include <iostream>
#include <fstream>
#include <sstream>

#include "Depozit.h"

void citesteProduseDinFisier(const std::string& numeFisier, Depozit& depozit) {

    std::ifstream fisier(numeFisier);

    if (!fisier) {
        throw std::runtime_error("Fisierul nu a putut fi deschis!");
    }

    std::string linie;

    while (getline(fisier, linie)) {

        std::stringstream ss(linie);

        std::string token;

        int id;
        std::string nume;
        int cantitate;
        double pret;
        int prag;

        getline(ss, token, ',');
        id = stoi(token);

        getline(ss, nume, ',');

        getline(ss, token, ',');
        cantitate = stoi(token);

        getline(ss, token, ',');
        pret = stod(token);

        getline(ss, token, ',');
        prag = stoi(token);

        Produs produs(id, nume, cantitate, pret, prag);

        depozit.adaugaProdus(produs);
    }

    fisier.close();
}

int main() {

    Depozit depozit;

    try {

        citesteProduseDinFisier("produse.txt", depozit);

        std::cout << "\nTOATE PRODUSELE:\n";
        depozit.afiseazaToateProdusele();

        int idVanzare = 10;
        int cantitateVanduta = 45;

        Produs produsVandut = depozit.getProdus(idVanzare);

        std::cout << "\nVANZARE PRODUS\n";

        std::cout << "ID: "
            << produsVandut.getId()
            << " | Nume: "
            << produsVandut.getNume()
            << " | Cantitate vanduta: "
            << cantitateVanduta
            << std::endl;

        depozit.vindeProdus(idVanzare, cantitateVanduta);

        Produs produsActualizat = depozit.getProdus(idVanzare);

        std::cout << "Stoc ramas: "
            << produsActualizat.getCantitate()
            << std::endl;

        int idRestock = 465;
        int cantitateAdaugata = 20;

        Produs produsRestock = depozit.getProdus(idRestock);

        std::cout << "\nRESTOCK PRODUS\n";

        std::cout << "ID: "
            << produsRestock.getId()
            << " | Nume: "
            << produsRestock.getNume()
            << " | Cantitate adaugata: "
            << cantitateAdaugata
            << std::endl;

        depozit.restockProdus(idRestock, cantitateAdaugata);

        Produs produsNou = depozit.getProdus(idRestock);

        std::cout << "Stoc nou: "
            << produsNou.getCantitate()
            << std::endl;

        std::cout << "\nProduse sub prag:\n";

        depozit.raportProduseSubPrag();

    }
    catch (const std::exception& e) {

        std::cout << "Eroare: " << e.what() << std::endl;
    }

    return 0;
}