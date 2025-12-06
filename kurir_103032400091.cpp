#include <iostream>
#include "kurir.h"
using namespace std;
void createListKurir(List_kurir &L){
     L.first = nullptr;
}

bool isEmpty_kurir(List_kurir L){
    return L.first == nullptr;
}

addr_kurir createElementKurir(int IDKurir, string Nama, string Kendaraan){
    addr_kurir k = new kurir;
    k -> info.IDKurir = IDKurir;
    k -> info.Nama = Nama;
    k -> info.Kendaraan = Kendaraan;
    k -> next = nullptr;
    return k;
}

addr_kurir findElementKurir(List_kurir L,  int IDKurir){
    addr_kurir k = L.first;
    while (k != nullptr || k -> info.IDKurir == IDKurir) {
        k = k->next;
    }
    if (k != nullptr){
        return k;
    }else{
        cout << "Kurir tidak ditemukan";
        return nullptr;
    }
}

void insertLastKurir(List_kurir &L, addr_kurir p){
    addr_kurir q;

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
void insertAfterKurir(List_kurir &L, addr_kurir p, addr_kurir prec){
    if (prec == nullptr) {
        cout << "prec tidak ditemukan";
    }else{
        p->next = prec->next;
        prec->next = p;
    }
}

void deleteLastKurir(List_kurir &L, addr_kurir &p){
    addr_kurir q;

    if (isEmpty_kurir(L)) {
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

void deleteAfterKurir(List_kurir &L, addr_kurir p, addr_kurir prec){
    if (isEmpty_kurir(L)) {
        cout << "List kurir kosong";
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
