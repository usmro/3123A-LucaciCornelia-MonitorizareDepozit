#pragma once
#ifndef FURNIZOR_H
#define FURNIZOR_H

#include <string>
#include <iostream>

class Furnizor {
private:
    int id;
    std::string nume;
    std::string telefon;

public:
    Furnizor();
    Furnizor(int id, std::string nume, std::string telefon);

    int getId() const;
    std::string getNume() const;
    std::string getTelefon() const;

    void afiseaza() const;
};

#endif