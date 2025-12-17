#ifndef KURIR_H_INCLUDED
#define KURIR_H_INCLUDED

#include <iostream>
using namespace std;

struct data_kurir {
    int ID_kurir;
    string kendaraan; // "Mobil" / "Motor"
    int jmlpkt;       // Counter muatan
};

typedef data_kurir infotype_kurir;
typedef struct kurir *addr_kurir;

struct kurir {
    infotype_kurir info;
    addr_kurir next;
};

struct List_kurir {
    addr_kurir first;
};

void createListKurir(List_kurir &L);
bool isEmpty_kurir(List_kurir L);
addr_kurir createElementKurir(int ID, string Kendaraan, int Jml);
addr_kurir findElementKurir(List_kurir L, int ID);

void insertFirstKurir(List_kurir &L, addr_kurir P);
void insertLastKurir(List_kurir &L, addr_kurir P);
void insertAfterKurir(List_kurir &L, addr_kurir Prec, addr_kurir P);

void deleteFirstKurir(List_kurir &L, addr_kurir &P);
void deleteLastKurir(List_kurir &L, addr_kurir &P);
void deleteAfterKurir(List_kurir &L, addr_kurir Prec, addr_kurir &P);

void showKurir(List_kurir L);

#endif
