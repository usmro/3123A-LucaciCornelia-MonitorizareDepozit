#pragma once
#ifndef PRODUS_H
#define PRODUS_H

#include <string>
#include <iostream>

class Produs {
private:
    int id;
    std::string nume;
    int cantitate;
    double pret;
    int pragAlerta;

public:
    Produs();
    Produs(int id, std::string nume, int cantitate, double pret, int pragAlerta);

    // Getteri
    int getId() const;
    std::string getNume() const;
    int getCantitate() const;
    double getPret() const;
    int getPragAlerta() const;

    // Setteri
    void setCantitate(int cantitate);

    // Operatori supraincarcati
    Produs& operator+=(int valoare);
    Produs& operator-=(int valoare);

    // Afisare
    void afiseaza() const;
};

#endif