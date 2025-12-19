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

// --- Fungsi Primitif (Diimplementasi di relasi.cpp) ---
void createListRelasi(List_relasi &L);
addr_relasi createElementRelasi(addr_kurir K, addr_paket P);
void insertLastRelasi(List_relasi &L, addr_relasi P);
void deleteRelasi(List_relasi &L, addr_relasi &P);
addr_relasi findElementRelasi(List_relasi L, addr_kurir K, addr_paket P);

// --- Fungsi Logika Tambahan (Diimplementasi di tambahan.cpp) ---
void connectRelasi(List_relasi &LR, addr_kurir K, addr_paket P);
void disconnectRelasi(List_relasi &LR, addr_kurir K, addr_paket P);
bool isPaketAssigned(List_relasi LR, addr_paket P);
void autoInputRelasi(List_relasi &LR, List_kurir &LK, List_paket LP);
void disconnectAllRelasi(List_relasi &LR);

void showAllParentWithChild(List_relasi LR, List_kurir LK);
void showAllChildWithParent(List_relasi LR, List_paket LP);
void showChildFromParent(List_relasi LR, List_kurir LK, int IDKurir);
void showParentFromChild(List_relasi LR, List_paket LP, int IDPaket);

void showCountRelasiEveryParent(List_relasi LR, List_kurir LK);
int countRelasiByChild(List_relasi LR, addr_paket P);
int countChildNoRelation(List_relasi LR, List_paket LP);

#endif
