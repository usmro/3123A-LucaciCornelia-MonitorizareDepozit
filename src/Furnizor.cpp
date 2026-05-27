#include "Furnizor.h"

Furnizor::Furnizor() : id(0), nume(""), telefon("") {}

Furnizor::Furnizor(int id, std::string nume, std::string telefon)
    : id(id), nume(nume), telefon(telefon) {
}

int Furnizor::getId() const {
    return id;
}

std::string Furnizor::getNume() const {
    return nume;
}

std::string Furnizor::getTelefon() const {
    return telefon;
}

void Furnizor::afiseaza() const {
    std::cout << "Furnizor: " << nume
        << " | Tel: " << telefon << std::endl;
}