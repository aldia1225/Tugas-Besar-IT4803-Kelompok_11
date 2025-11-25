#include "relasi.h"

void createListRelasi(List_relasi &L){
     L.first = nullptr;
}

bool isEmpty_relasi(List_relasi L){
    return L.first == nullptr;
}

addr_relasi createElementRelasi(addr_kurir p, addr_paket q){
    addr_relasi r = new relasi;
    r -> kurir = p;
    r -> paket = q;
    r -> next = nullptr;
    return r;
}

addr_relasi findElementRelasi(List_relasi L, addr_kurir p, addr_paket q){
    addr_relasi r = L.first;
    while (r != nullptr || r.paket == q && r.kurir == p) {
        r = r->next;
    }
    if (r != nullptr){
        return r;
    }else{
        return nullptr;
    }
}

void insertFirstRelasi(List_relasi &L, addr_relasi p){
    if (isEmpty_relasi(L)) {
        L.first = p;
    } else {
        p->next = L.first;
        L.first->prev = p;
        L.first = p;
    }
}

void insertLastRelasi(List_relasi &L, addr_relasi p){
    addr_relasi q;

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
void insertAfterRelasi(List_relasi &L, addr_relasi p, addr_relasi prec){

}

void deleteFirstRelasi(List_relasi &L, addr_relasi &p){
    if (isEmpty_relasi(L)) {
        p = nullptr;
    } else if (L.first -> next == nullptr) {
        p = L.first;
        L.first = nullptr;
    } else {
        p = L.first;
        L.first = L.first->next;
        L.first->prev = nullptr;
        p->next = nullptr;
    }
}

void deleteLastRelasi(List_relasi &L, addr_relasi &p){
    addr_relasi q;

    if (isEmpty_relasi(L)) {
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

void deleteAfterRelasi(List_relasi &L, addr_relasi p, addr_relasi prec){

}
