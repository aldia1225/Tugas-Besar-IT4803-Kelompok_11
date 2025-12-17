#include "paket.h"
void insertFirstpaket(List_paket &L, addr_paket P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    }else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertBeforepaket(List_paket &L, addr_paket P, addr_paket prec) {
    if (prec == L.first) {
        insertFirst(L, P);
    }else {
        P->next = prec;
        P->prev = prec->prev;
        prec->prev->next = P;
        prec->prev = P;
    }
}

void deleteFirstpaket(List_paket &L, addr_paket &P) {
    if (L.first == nullptr) {
        P = nullptr;
    }else if (L.first == L.last) {
        P = L.first;
        L.first = nullptr;
        L.last = nullptr;
    }else {
        P = L.first;
        L.first = L.first->next;
        L.first->prev = nullptr;
        P->next = nullptr;
    }
}


void showpaket(List_paket L) {
    addr_paket P = L.first;
    if (P == nullptr){
        cout << "List Paket kosong." << endl;
        return;
    }while (P != nullptr){
        cout << "ID Paket       : " << P->info.ID_paket << endl;
        cout << "Alamat         : " << P->info.alamat << endl;
        cout << "Ukuran Paket   : " << P->info.ukuran<< endl;
        cout << "--------------------" << endl;
        P = P->next;
    }
}
