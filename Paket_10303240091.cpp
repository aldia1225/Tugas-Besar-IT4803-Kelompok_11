#include "paket.h"

void createListPaket(List_paket &L){
     L.first = nullptr;
}

bool isEmpty_paket(List_paket L){
    return L.first == nullptr;
}

addr_paket createElementPaket(int IDPaket, string alamat, string ukuran){
    addr_paket p = new paket;
    p -> info.ID_paket = IDPaket;
    p -> info.alamat = alamat;
    p -> info.ukuran = ukuran;
    p -> next = nullptr;
    return p;
}

addr_paket findElementPaket(List_paket L,  int IDPaket){
    addr_paket p = L.first;
    while (p != nullptr || p -> info.ID_paket == IDPaket) {
        p = p->next;
    }
    if (p != nullptr){
        return p;
    }else{
        cout << "paket tidak ditemukan";
        return nullptr;
    }
}

void insertLastPaket(List_paket &L, addr_paket p){
    addr_paket q;

    if (L.first == nullptr) {
            L.first = p;
    }else {
        q = L.first;
        while (q -> next != nullptr){
            q = q -> next;
        }
         q -> next = p;
    }
}
void insertAfterPaket(List_paket &L, addr_paket p, addr_paket prec){
    if (prec == nullptr) {
        cout << "prec tidak ditemukan";
    }else{
        p->next = prec->next;
        prec->next = p;
    }
}

void deleteLastPaket(List_paket &L, addr_paket &p){
    addr_paket q;

    if (isEmpty_paket(L)) {
        p = nullptr;
    } else if (L.first -> next == nullptr) {
        p = L.first;
        L.first = nullptr;
    } else {
        q = L.first;
        while (q -> next -> next != nullptr){
            q = q -> next;
        }
         p = q -> next;
         q -> next = nullptr;
    }
}

void deleteAfterPaket(List_paket &L, addr_paket p, addr_paket prec){
    if (isEmpty_paket(L)) {
        cout << "List paket kosong";
        p = nullptr;
    }else if (prec == nullptr){
        cout << "prec tidak ditemukan";
        p = nullptr;
    }else if (prec->next != nullptr) {
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    } else {
        p = nullptr;
    }
}
