

#include "Wektor.h"
#include <iostream>
#include <print>

Wektor::Wektor(unsigned int rozmiar)
    : pojemnosc{rozmiar}, dlugosc{rozmiar}, wektor_liczb{new double[rozmiar]}
{
    /*pojemnosc    = rozmiar;
    dlugosc      = rozmiar;
    wektor_liczb = new double[rozmiar];*/

    for (unsigned int i = 0; i < pojemnosc; i++) {
        wektor_liczb[i] = i;
    }

    std::cout << "Konstruktor ZWYKŁY wykonany, dlugosc: " << dlugosc << "; Pojemność: " << pojemnosc
              << "Wektor liczba (adres): " << wektor_liczb << std::endl;
}

Wektor::Wektor(const Wektor& other) : Wektor(other.pojemnosc)
{
    for (unsigned int i = 0; i < pojemnosc; i++) {
        wektor_liczb[i] = other.wektor_liczb[i];
    }

    std::cout << "Konstruktor KOPIUJĄCY wykonany, dlugosc: " << dlugosc
              << "; Pojemność: " << pojemnosc << "Wektor liczba (adres): " << wektor_liczb
              << std::endl;
}

Wektor& Wektor::operator=(const Wektor& other)
{
    if (this == &other)
        return *this;

    this->pojemnosc = other.pojemnosc;
    this->dlugosc   = other.dlugosc;
    delete[] this->wektor_liczb;

    this->wektor_liczb = new double[other.pojemnosc];

    for (unsigned int i = 0; i < other.pojemnosc; i++) {
        this->wektor_liczb[i] = other.wektor_liczb[i];
    }

    std::cout << "Operator PRZYPISANIA wykonany, dlugosc: " << dlugosc
              << "; Pojemność: " << pojemnosc << "Wektor liczba (adres): " << wektor_liczb
              << std::endl;

    return *this;
}

Wektor::Wektor(Wektor&& other) noexcept
    : pojemnosc{other.pojemnosc}, dlugosc{other.dlugosc}, wektor_liczb{other.wektor_liczb}
{
    other.wektor_liczb = nullptr;
    other.dlugosc      = 0;
    other.pojemnosc    = 0;

    std::cout << "Konstruktor PRZENOSZĄCY wykonany, dlugosc: " << dlugosc
              << "; Pojemność: " << pojemnosc << "Wektor liczba (adres): " << wektor_liczb
              << std::endl;
}

Wektor& Wektor::operator=(Wektor&& other) noexcept
{
    if (this == &other) {
        return *this;
    };

    this->pojemnosc    = std::move(other.pojemnosc);
    this->dlugosc      = std::move(other.dlugosc);
    this->wektor_liczb = std::move(other.wektor_liczb);

    delete[] other.wektor_liczb;
    other.wektor_liczb = nullptr;

    other.pojemnosc = 0;
    other.dlugosc   = 0;

    std::cout << "PRZENOSZĄCY operator przypisania wykonany, dlugosc: " << dlugosc
              << "; Pojemność: " << pojemnosc << "Wektor liczba (adres): " << wektor_liczb
              << std::endl;

    return *this;
}

Wektor::~Wektor()
{
    delete[] wektor_liczb;

    std::cout << "Destruktur wykonany, dlugosc: " << dlugosc << "; Pojemność: " << pojemnosc
              << "Wektor liczba (adres): " << wektor_liczb << std::endl;
}

unsigned int Wektor::getDlugosc() const
{
    return dlugosc;
}
unsigned int Wektor::getPojemnosc() const
{
    return pojemnosc;
}



void Wektor::zmienDlugosc(unsigned int nowa_dlugosc)

{

    if (nowa_dlugosc < dlugosc) {
        // zmniejszanie pola dlugosc, ignorujemy, że w pamięci jest zaalokowane więcej miejsc
        // (pojemnosc)
        dlugosc = nowa_dlugosc;
    }

    else if (nowa_dlugosc > dlugosc && nowa_dlugosc <= pojemnosc) {

        for (int i = dlugosc; i < nowa_dlugosc; i++) {
            wektor_liczb[i] = 0.0;
        }

        dlugosc = nowa_dlugosc;
    }
    else if (nowa_dlugosc > pojemnosc) {
        double* nowy_wektor = new double[nowa_dlugosc];

        for (int i = 0; i < dlugosc; i++) {
            nowy_wektor[i] = wektor_liczb[i];
        }

        for (int i = dlugosc; i < nowa_dlugosc; i++) {
            nowy_wektor[i] = 0.0;
        }

        delete[] wektor_liczb;
        this->wektor_liczb = nowy_wektor;

        pojemnosc = nowa_dlugosc;
        dlugosc   = nowa_dlugosc;
    }
}

void Wektor::print() const
{
    for (unsigned int i = 0; i < dlugosc; i++) {
        std::cout << wektor_liczb[i] << " ";
    }
    std::cout << std::endl;
}

double Wektor::operator[](unsigned int i)
{
    if (i > dlugosc) {
        std::cout << "Indeks poza zakresem; długość zostanie zmieniona \n";
        zmienDlugosc(i + 1);
    }

    return wektor_liczb[i];
}
