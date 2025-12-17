#include "kurir.h"

void createListKurir(List_kurir &L){
     L.first = nullptr;
}

bool isEmpty_kurir(List_kurir L){
    return L.first == nullptr;
}

addr_kurir createElementKurir(int ID, string Kendaraan, int Jml){
    addr_kurir P = new kurir;
    P->info.ID_kurir = ID;
    P->info.kendaraan = Kendaraan;
    P->info.jmlpkt = Jml;
    P->next = nullptr;
    return P;
}

addr_kurir findElementKurir(List_kurir L, int ID){
    addr_kurir P = L.first;
    while(P != nullptr && P->info.ID_kurir != ID){
        P = P->next;
    }
    return P;
}

void insertLastKurir(List_kurir &L, addr_kurir P){
    if(isEmpty_kurir(L)){
        L.first = P;
    }else {
        addr_kurir Q = L.first;
        while(Q->next != nullptr){
            Q = Q->next;}
        Q->next = P;
    }
}

void insertAfterKurir(List_kurir &L, addr_kurir Prec, addr_kurir P){
    if(Prec != nullptr){
        P->next = Prec->next; Prec->next = P;
    }
}

void deleteLastKurir(List_kurir &L, addr_kurir &P){
    if(isEmpty_kurir(L)){
        P = nullptr;
    }else if(L.first->next == nullptr){
        P = L.first; L.first = nullptr;
    }else {
        addr_kurir Q = L.first;
        while(Q->next->next != nullptr){
            Q = Q->next;
        }
        P = Q->next; Q->next = nullptr;
    }
}

void deleteAfterKurir(List_kurir &L, addr_kurir Prec, addr_kurir &P){
    if(Prec != nullptr && Prec->next != nullptr){
        P = Prec->next; Prec->next = P->next; P->next = nullptr;
    }else {
        P = nullptr;
    }
}
