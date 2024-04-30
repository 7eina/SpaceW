#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
#include "Rocket.h"

using namespace std;


class View
{
  public:
    void menu(const string* menu, int numItems, int& choice);
    void getNumber(int& num);
  
};

#endif
