#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

#include "Depozit.h"

Furnizor getFurnizorPentruProdus(const std::string& numeProdus) {

    std::string lower = numeProdus;

    std::transform(lower.begin(), lower.end(), lower.begin(),
        [](unsigned char c) { return std::tolower(c); });

    if (lower.find("laptop") != std::string::npos ||
        lower.find("mouse") != std::string::npos ||
        lower.find("monitor") != std::string::npos ||
        lower.find("tastatura") != std::string::npos ||
        lower.find("procesor") != std::string::npos ||
        lower.find("ssd") != std::string::npos ||
        lower.find("ram") != std::string::npos ||
        lower.find("router") != std::string::npos) {

        return Furnizor(1, "Altex", "0722000001");
    }

    if (lower.find("masa") != std::string::npos ||
        lower.find("scaun") != std::string::npos ||
        lower.find("pat") != std::string::npos ||
        lower.find("dulap") != std::string::npos ||
        lower.find("canapea") != std::string::npos ||
        lower.find("birou") != std::string::npos) {

        return Furnizor(2, "Dedeman", "0722000002");
    }

    if (lower.find("masina") != std::string::npos ||
        lower.find("anvelope") != std::string::npos ||
        lower.find("ulei") != std::string::npos ||
        lower.find("baterie") != std::string::npos ||
        lower.find("jante") != std::string::npos ||
        lower.find("compresor") != std::string::npos ||
        lower.find("motor") != std::string::npos) {

        return Furnizor(3, "Select Auto", "0722000003");
    }

    return Furnizor(4, "Metro Cash & Carry", "0722000004");
}

void citesteProduseDinFisier(const std::string& numeFisier, Depozit& depozit) {

    std::ifstream fisier(numeFisier);

    if (!fisier) {
        throw std::runtime_error("Fisierul nu a putut fi deschis!");
    }

    std::string linie;

    while (getline(fisier, linie)) {

        if (linie.empty()) {
            continue;
        }

        try {

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

            Furnizor furnizor = getFurnizorPentruProdus(nume);

            Produs produs(id, nume, cantitate, pret, prag, furnizor);

            depozit.adaugaProdus(produs);
        }
        catch (...) {

            std::cout << "Linie invalida: " << linie << std::endl;
        }
    }

    fisier.close();
}

int main() {

    Depozit depozit;

    try {

        citesteProduseDinFisier("produse.txt", depozit);

        std::cout << "\n<<< TOATE PRODUSELE >>>\n";
        depozit.afiseazaToateProdusele();

        std::cout << "\n<<< Vanzari >>>\n";

        int id1 = 10;
        int cant1 = 45;

        Produs p1 = depozit.getProdus(id1);

        std::cout << "ID: " << p1.getId()
            << " | Nume: " << p1.getNume()
            << " | Cantitate vanduta: " << cant1
            << std::endl;

        depozit.vindeProdus(id1, cant1);

        std::cout << "Stoc ramas: "
            << depozit.getProdus(id1).getCantitate()
            << "\n\n";

        int id2 = 145;
        int cant2 = 5;

        Produs p2 = depozit.getProdus(id2);

        std::cout << "ID: " << p2.getId()
            << " | Nume: " << p2.getNume()
            << " | Cantitate vanduta: " << cant2
            << std::endl;

        depozit.vindeProdus(id2, cant2);

        std::cout << "Stoc ramas: "
            << depozit.getProdus(id2).getCantitate()
            << "\n\n";

        int idRestock = 465;
        int cantitateAdaugata = 20;

        Produs produsRestock = depozit.getProdus(idRestock);

        std::cout << "\n<<< Restock produs >>>\n";

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

        std::cout << "\n<<< Produse sub prag >>>\n";

        depozit.raportProduseSubPrag();

        //re-comanda
        depozit.produsePentruRecomanda();

        //sortare dupa cantitate
        depozit.afiseazaProduseSortateCantitate();

    }
    catch (const std::exception& e) {

        std::cout << "Eroare: " << e.what() << std::endl;
    }

    return 0;

}