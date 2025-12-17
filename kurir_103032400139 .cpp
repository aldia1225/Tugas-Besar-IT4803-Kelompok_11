#include "kurir.h"

void insertFirstKurir(List_kurir &L, addr_kurir P){
    if(isEmpty_kurir(L)){
        L.first = P; }
    else {
        P->next = L.first; L.first = P;
    }
}

void deleteFirstKurir(List_kurir &L, addr_kurir &P){
    if(isEmpty_kurir(L)){
        P = nullptr;
    }
    else {
        P = L.first; L.first = L.first->next; P->next = nullptr;
    }
}

void showKurir(List_kurir L){
    addr_kurir P = L.first;
    if(P == nullptr){
        cout << "List Kurir Kosong." << endl;
    }
    else {
        cout << "=== DAFTAR KURIR ===" << endl;
        while(P != nullptr){
            cout << "ID: " << P->info.ID_kurir
                 << " | " << P->info.kendaraan
                 << " | Beban: " << P->info.jmlpkt << endl;
            P = P->next;
        }
        cout << "--------------------" << endl;
    }
}
