#include "paket.h"

void insertFirstPaket(List_paket &L, addr_paket P){
    if(isEmpty_paket(L)){ L.first = P; L.last = P; }
    else { P->next = L.first; L.first->prev = P; L.first = P; }
}

void deleteFirstPaket(List_paket &L, addr_paket &P){
    if(isEmpty_paket(L)){ P = nullptr; }
    else if(L.first == L.last){ P = L.first; L.first = nullptr; L.last = nullptr; }
    else { P = L.first; L.first = L.first->next; L.first->prev = nullptr; P->next = nullptr; }
}

void showPaket(List_paket L){
    addr_paket P = L.first;
    if(P == nullptr){ cout << "List Paket Kosong." << endl; }
    else {
        cout << "=== DAFTAR PAKET ===" << endl;
        while(P != nullptr){
            cout << "ID: " << P->info.ID_paket
                 << " | " << P->info.ukuran
                 << " | " << P->info.alamat << endl;
            P = P->next;
        }
        cout << "--------------------" << endl;
    }
}
