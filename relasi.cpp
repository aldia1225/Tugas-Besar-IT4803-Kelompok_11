#include "relasi.h"

void createListRelasi(List_relasi &L){ L.first = nullptr; }

addr_relasi createElementRelasi(addr_kurir K, addr_paket P){
    addr_relasi R = new relasi;
    R->kurir = K; R->paket = P; R->next = nullptr;
    return R;
}

addr_relasi findElementRelasi(List_relasi L, addr_kurir K, addr_paket P){
    addr_relasi R = L.first;
    while(R != nullptr){
        if(R->kurir == K && R->paket == P) return R;
        R = R->next;
    }
    return nullptr;
}

void insertLastRelasi(List_relasi &L, addr_relasi P){
    if(L.first == nullptr){ L.first = P; }
    else {
        addr_relasi Q = L.first;
        while(Q->next != nullptr){ Q = Q->next; }
        Q->next = P;
    }
}

void deleteRelasi(List_relasi &L, addr_relasi &P){
    if(L.first == nullptr){ P = nullptr; return; }
    if(L.first == P){ L.first = P->next; P->next = nullptr; }
    else {
        addr_relasi Q = L.first;
        while(Q->next != nullptr && Q->next != P){ Q = Q->next; }
        if(Q->next == P){ Q->next = P->next; P->next = nullptr; }
        else { P = nullptr; }
    }
}
