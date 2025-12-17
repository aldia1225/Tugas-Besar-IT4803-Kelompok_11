#ifndef PAKET_H_INCLUDED
#define PAKET_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct data_paket infotype;
typedef struct paket *addr_paket;

struct data_paket {
    int ID_paket;
    string alamat;
    string ukuran;
};

struct paket {
    infotype info;
    addr_paket next;
    addr_paket prev;
};

struct List_paket {
    addr_paket first;
    addr_paket last;
};

void createListPaket(List_paket &L);
bool isEmpty_paket(List_paket L);
addr_paket createElementPaket(int IDPaket, string alamat, int berat);
addr_paket findElementPaket(List_paket L,  int IDPaket);
void insertLastPaket(List_paket &L, addr_paket p);
void insertAfterPaket(List_paket &L, addr_paket p, addr_paket prec);
void deleteLastPaket(List_paket &L, addr_paket &p);
void insertFirstpaket(List_paket &L, addr_paket P);
void insertBeforepaket(List_paket &L, addr_paket P, addr_paket prec);
void deleteFirstpaket(List_paket &L, addr_paket &P);
void showpaket(List_paket L) ;


#endif // PAKET_H_INCLUDED
