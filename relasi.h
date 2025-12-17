#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "paket.h"
#include "kurir.h"

typedef struct relasi *addr_relasi;

struct relasi {
    addr_paket paket ;
    addr_kurir kurir;
    addr_relasi next;
};

struct List_relasi {
    addr_relasi first;
};

void createListRelasi(List_relasi &L);
bool isEmpty_relasi(List_relasi L);
addr_relasi createElementRelasi(infotype x);
void printInfo_Relasi(List L);
addr_relasi findElementRelasi(List_relasi L, addr_relasi p);
void insertFirstRelasi(List_relasi &L, addr_relasi p);
void insertLastRelasi(List_relasi &L, addr_relasi p);
void insertAfterRelasi(List_relasi &L, addr_relasi p, addr_relasi prec);
void deleteFirstRelasi(List_relasi &L, addr_relasi &p);
void deleteLastRelasi(List_relasi &L, addr_relasi &p);
void deleteAfterRelasi(List_relasi &L, addr_relasi p, addr_relasi prec);
void showChildFromParent(List_relasi LR, List_kurir LK, int IDKurir);
void showAllParentWithChild(List_relasi LR, List_kurir LK);
void showAllChildWithParent(List_relasi LR, List_paket LP);
void showParentFromChild(List_relasi LR, List_paket LP, int IDPaket);
void editRelasi(List_relasi &LR, List_kurir LK, List_paket LP, int IDKurir, int IDPaketLama, int IDPaketBaru);
void autoInputRelasi(List_relasi &LR, List_kurir &LK, List_paket LP);
#endif // RELASI_H_INCLUDED
