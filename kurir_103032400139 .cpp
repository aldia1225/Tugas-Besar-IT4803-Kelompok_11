#include "kurir.h"
#include <iostream>
using namespace std;

void createListKurir(List_kurir &L) {
    L.first = nullptr;
}

bool isEmpty_kurir(List_kurir L) {
    return L.first == nullptr;
}

addr_kurir createElementKurir(int IDKurir, string Kendaraan, int Berat) {
    addr_kurir P = new kurir;
    P->info.ID_kurir = IDKurir;
    P->info.kendaraan = Kendaraan;
    P->info.berat = Berat;
    P->next = nullptr;
    return P;
}

void insertFirstkurir(List_kurir &L, addr_kurir P) {
    if (isEmpty_kurir(L)) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
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

void deleteLastkurir(List_kurir &L, addr_kurir &P) {
    if (isEmpty_kurir(L)) {
        P = nullptr;
        cout << "List Kurir Kosong." << endl;
    } 
    else if (L.first->next == nullptr) {
        P = L.first;
        L.first = nullptr;
    } 
    else {
        addr_kurir Q = L.first;
        while (Q->next->next != nullptr) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = nullptr;
    }
}

void showkurir(List_kurir L) {
    if (isEmpty_kurir(L)) {
        cout << "List Kurir kosong." << endl;
        return;
    }
    
    addr_kurir P = L.first;
    while (P != nullptr) {
        cout << "ID        : " << P->info.ID_kurir << endl;
        cout << "Kendaraan : " << P->info.kendaraan << endl;
        cout << "Berat     : " << P->info.berat << " kg" << endl; 
        cout << "--------------------" << endl;
        P = P->next;
    }
}