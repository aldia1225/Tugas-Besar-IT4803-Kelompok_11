#include "paket.h"

void createListPaket(List_paket &L){ L.first = nullptr; L.last = nullptr; }
bool isEmpty_paket(List_paket L){ return L.first == nullptr; }

addr_paket createElementPaket(int ID, string Alamat, string Ukuran){
    addr_paket P = new paket;
    P->info.ID_paket = ID;
    P->info.alamat = Alamat;
    P->info.ukuran = Ukuran;
    P->next = nullptr; P->prev = nullptr;
    return P;
}

addr_paket findElementPaket(List_paket L, int ID){
    addr_paket P = L.first;
    while(P != nullptr && P->info.ID_paket != ID){ P = P->next; }
    return P;
}

void insertLastPaket(List_paket &L, addr_paket P){
    if(isEmpty_paket(L)){ L.first = P; L.last = P; }
    else { P->prev = L.last; L.last->next = P; L.last = P; }
}

void insertAfterPaket(List_paket &L, addr_paket Prec, addr_paket P){
    if(Prec != nullptr){
        P->next = Prec->next; P->prev = Prec;
        if(Prec->next != nullptr){ Prec->next->prev = P; }
        else { L.last = P; }
        Prec->next = P;
    }
}

void deleteLastPaket(List_paket &L, addr_paket &P){
    if(isEmpty_paket(L)){ P = nullptr; }
    else if(L.first == L.last){ P = L.first; L.first = nullptr; L.last = nullptr; }
    else { P = L.last; L.last = L.last->prev; L.last->next = nullptr; P->prev = nullptr; }
}

void deleteAfterPaket(List_paket &L, addr_paket Prec, addr_paket &P){
    if(Prec != nullptr && Prec->next != nullptr){
        P = Prec->next; Prec->next = P->next;
        if(P->next != nullptr){ P->next->prev = Prec; }
        else { L.last = Prec; }
        P->next = nullptr; P->prev = nullptr;
    } else { P = nullptr; }
}
