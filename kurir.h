#ifndef KURIR_H_INCLUDED
#define KURIR_H_INCLUDED
using namespace std;

typedef data_kurir infotype;
typedef struct kurir *addr_kurir;

struct data_kurir  {
    int ID_kurir;
    string kendaraan;
    int berat;
};

struct kurir {
    infotype info;
    addr_kurir next;
  
};

struct List_kurir {
    addr_kurir first;

};

void createListKurir(List_kurir &L);
bool isEmpty_kurir(List_kurir L);
addr_kurir createElementKurir(int IDKurir, string Nama, string Kendaraan);
addr_kurir findElementKurir(List_kurir L,  int IDKurir);
void insertLastKurir(List_kurir &L, addr_kurir p);
void insertAfterKurir(List_kurir &L, addr_kurir p, addr
void insertFirst(List_kurir &L, addr_kurir P);
void deleteLast(List_kurir &L, addr_kurir &P);
void deleteFirst(List_kurir &L, addr_kurir &P);
void show(List_kurir L) ;


#endif // KURIR_H_INCLUDED
