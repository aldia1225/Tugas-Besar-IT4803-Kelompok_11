#ifndef PAKET_H_INCLUDED
#define PAKET_H_INCLUDED

#include <iostream>
using namespace std;

struct data_paket {
    int ID_paket;
    string alamat;
    string ukuran; // "Besar" / "Kecil"
};

typedef data_paket infotype_paket;
typedef struct paket *addr_paket;

struct paket {
    infotype_paket info;
    addr_paket next;
    addr_paket prev;
};

struct List_paket {
    addr_paket first;
    addr_paket last;
};

void createListPaket(List_paket &L);
bool isEmpty_paket(List_paket L);
addr_paket createElementPaket(int ID, string Alamat, string Ukuran);
addr_paket findElementPaket(List_paket L, int ID);

void insertFirstPaket(List_paket &L, addr_paket P);
void insertLastPaket(List_paket &L, addr_paket P);
void insertAfterPaket(List_paket &L, addr_paket Prec, addr_paket P);

void deleteFirstPaket(List_paket &L, addr_paket &P);
void deleteLastPaket(List_paket &L, addr_paket &P);
void deleteAfterPaket(List_paket &L, addr_paket Prec, addr_paket &P);

void showPaket(List_paket L);

#endif
