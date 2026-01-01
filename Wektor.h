#pragma once

class Wektor
{
private:
    unsigned int dlugosc;
    unsigned int pojemnosc;
    double*      wektor_liczb;

public:
    
    Wektor(unsigned int rozmiar);
    ~Wektor();

    Wektor& operator=(const Wektor& other);

   Wektor(const Wektor& other);


    unsigned int getDlugosc() const;
    unsigned int getPojemnosc() const;

    double operator[](unsigned int i);

    void zmienDlugosc(unsigned int nowa_dlugosc); 

    void print() const; 
};
