#include "kurir.h"

void insertFirstKurir(List_kurir &L, addr_kurir P) {
    if (isEmpty_kurir(L)) {// Jika kosong, maka node P menjadi elemen pertama (First)
        L.first = P;
    } else {
        P->next = L.first;//Sambungkan node P ke node yang saat ini menjadi First
        L.first = P;
    }
}

void deleteFirstKurir(List_kurir &L, addr_kurir &P) {
    if (isEmpty_kurir(L)) {// Jika kosong, tidak ada yang bisa dihapus. P di-set null.
        P = nullptr;
    } else {
        P = L.first;
        L.first = L.first->next;//Geser pointer First ke elemen kedua (First->next)
        P->next = nullptr;
    }
}

void showKurir(List_kurir L) {
    addr_kurir P = L.first;//P menunjuk ke elemen pertama
    if (P == nullptr) {
        cout << "Daftar Kurir Kosong." << endl;
    } else {
        cout << "=== DAFTAR KURIR ===" << endl;
        while (P != nullptr) {
            cout << "ID: " << P->info.ID_kurir
                 << " | " << P->info.kendaraan
                 << " | Beban: " << P->info.jmlpkt << endl;
            P = P->next;
        }
        cout << "--------------------" << endl;
    }
}
