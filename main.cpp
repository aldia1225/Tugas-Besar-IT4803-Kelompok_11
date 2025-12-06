#include <iostream>
#include "main.h"
#include <cstdlib>

using namespace std;

int main()
{
    int option=-99;
    while (option != 0) {
        system("cls");
        cout << "============ Menu ============ " << endl;
        cout << "|| 1. admin                 ||" << endl;
        cout << "|| 2. User                  ||" << endl;
        cout << "|| 0. exit                  ||" << endl;
        cout << "============================== " << endl;
        cout << "Choose your option : ";
        cin >> option;
        switch(option) {
           case 1  :
              cout << "you choose option 1" << endl;
              menuAdmin();
              break;
           case 2  :
              cout << "you choose option 2" << endl;
              menuUser();
              break;

           default :
              exit(1);
        }
    }


    return 0;
}