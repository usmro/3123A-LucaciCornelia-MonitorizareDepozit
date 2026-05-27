#include "Produs.h"

Produs::Produs() : id(0), nume(""), cantitate(0), pret(0), pragAlerta(0) {}

Produs::Produs(int id, std::string nume, int cantitate, double pret, int pragAlerta, Furnizor furnizor)
    : id(id), nume(nume), cantitate(cantitate), pret(pret), pragAlerta(pragAlerta), furnizor(furnizor) {
}

int Produs::getId() const {
    return id;
}

std::string Produs::getNume() const {
    return nume;
}

int Produs::getCantitate() const {
    return cantitate;
}

double Produs::getPret() const {
    return pret;
}

int Produs::getPragAlerta() const {
    return pragAlerta;
}

Furnizor Produs::getFurnizor() const {
    return furnizor;
}

void Produs::setCantitate(int cantitate) {
    this->cantitate = cantitate;
}

Produs& Produs::operator+=(int valoare) {
    cantitate += valoare;
    return *this;
}

Produs& Produs::operator-=(int valoare) {
    if (cantitate - valoare < 0) {
        throw std::runtime_error("Cantitate insuficienta!");
    }

    cantitate -= valoare;
    return *this;
}

void Produs::afiseaza() const {
    std::cout << "ID: " << id
        << " | Nume: " << nume
        << " | Cantitate: " << cantitate
        << " | Pret: " << pret
        << " | Prag alerta: " << pragAlerta
        << " | ";

    furnizor.afiseaza();

    std::cout << std::endl;
}
