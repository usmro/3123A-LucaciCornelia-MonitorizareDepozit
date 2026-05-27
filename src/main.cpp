#include <iostream>
#include "Depozit.h"

int main() {

    Depozit depozit;

    try {

        Produs p1(1, "Laptop", 10, 3500.50, 3);
        Produs p2(2, "Mouse", 5, 120.99, 2);
        Produs p3(3, "Tastatura", 2, 250.00, 4);

        depozit.adaugaProdus(p1);
        depozit.adaugaProdus(p2);
        depozit.adaugaProdus(p3);

        std::cout << "Produse initiale:\n";
        depozit.afiseazaToateProdusele();

        std::cout << "\nVanzare 3 mouse:\n";
        depozit.vindeProdus(2, 3);

        std::cout << "\nRestock tastatura:\n";
        depozit.restockProdus(3, 10);

        std::cout << "\nProduse actualizate:\n";
        depozit.afiseazaToateProdusele();

        depozit.raportProduseSubPrag();

        std::cout << "\nStergere produs ID 1\n";
        depozit.eliminaProdus(1);

        std::cout << "\nProduse finale:\n";
        depozit.afiseazaToateProdusele();

    }
    catch (const std::exception& e) {
        std::cout << "Eroare: " << e.what() << std::endl;
    }

    return 0;
}