

#include "Wektor.h"
#include <iostream>
#include <windows.h>
#include <print>


#pragma execution_character_set("utf-8")


int main()
{
    std::cout << "OutputCP = " << GetConsoleOutputCP() << "\n";
    std::cout << "InputCP  = " << GetConsoleCP() << "\n";

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    std::cout << "OutputCP = " << GetConsoleOutputCP() << "\n";
    std::cout << "InputCP  = " << GetConsoleCP() << "\n";

    std::cout << "test polskich znaków: ćźÓlŃąń\n"; 

    Wektor w(5);
    w.zmienDlugosc(3);
    w.zmienDlugosc(7);

    std::cout << "test" << "\n";
    std::cout << w[0] << "\n";
    std::cout << w[1] << "\n";
    std::cout << w[2] << "\n";
    std::cout << w[3] << "\n";
    std::cout << w[4] << "\n";
    std::cout << w[10] << "\n";


    Wektor w2(8);

    w2 = w; 




  /* 
  testowanie l-value, r-value

  double a = w[0];
    a++;
    w[0] = 42.; */

    return 0;
}
