#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "kurir.h"
#include "paket.h"

typedef struct relasi *addr_relasi;

struct relasi {
    addr_kurir kurir;
    addr_paket paket;
    addr_relasi next;
};

struct List_relasi {
    addr_relasi first;
};

// Fungsi Dasar
void createListRelasi(List_relasi &L);
addr_relasi createElementRelasi(addr_kurir K, addr_paket P);
void insertLastRelasi(List_relasi &L, addr_relasi P);
void deleteRelasi(List_relasi &L, addr_relasi &P);
addr_relasi findElementRelasi(List_relasi L, addr_kurir K, addr_paket P);

// Fungsi Helper
bool isPaketAssigned(List_relasi LR, addr_paket P);

// Fungsi Tampilan & Laporan (Updated Format)
void showChildFromParent(List_relasi LR, List_kurir LK, int IDKurir);
void showAllParentWithChild(List_relasi LR, List_kurir LK);
void showAllChildWithParent(List_relasi LR, List_paket LP);
void showParentFromChild(List_relasi LR, List_paket LP, int IDPaket);

void editRelasi(List_relasi &LR, List_kurir LK, List_paket LP, int IDKurir, int IDPaketLama, int IDPaketBaru);
void autoInputRelasi(List_relasi &LR, List_kurir &LK, List_paket LP);

#endif
