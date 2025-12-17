#include <iostream>
#include "kurir.h"

using namespace std;

void insertFirstkurir(List_kurir &L, addr_kurir P) {
    if (isEmpty_kurir(L)) {
        L.first = P;
    }else {
        P->next = L.first;
        L.first = P;
    }
}

void deleteLastkurir(List_kurir &L, addr_kurir &P) {
    if (isEmpty_kurir(L)) {
        P = nullptr;
        cout << "List Kurir Kosong." << endl;
    } elseif(L.first->next == nullptr) {
        P = L.first;
        L.first = nullptr;
    }else {
        addr_kurir Q = L.first;
        while (Q->next->next != nullptr) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = nullptr;
    }
}

void deleteFirstkurir(List_kurir &L, addr_kurir &P) {
    if (isEmpty_kurir(L)) {
        P = nullptr;
        cout << "List Kurir Kosong." << endl;
    } else {
    P = L.first;
    L.first = L.first->next;
    P->next = nullptr;
}
}

void showkurir(List_kurir L) {
    addr_kurir P = L.first;
    if (isEmpty_kurir(L)) {
        cout << "List Kurir kosong." << endl;
        return;
    }
    while (P != nullptr) {
        cout << "ID        : " << P->info.ID_kurir << endl;
        cout << "Kendaraan : " << P->info.kendaraan << endl;
        cout << "Jumlah Paket     : " << P->info.jmlpkt << endl;
        cout << "--------------------" << endl;
        P = P->next;
    }
}
