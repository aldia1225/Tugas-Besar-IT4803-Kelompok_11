#include "relasi.h"

void createListRelasi(List_relasi &L) {
    L.first = nullptr;
}

addr_relasi createElementRelasi(addr_kurir K, addr_paket P) {
    addr_relasi R = new relasi;
    R->kurir = K;
    R->paket = P;
    R->next = nullptr;
    return R;
}

addr_relasi findElementRelasi(List_relasi L, addr_kurir K, addr_paket P) {
    addr_relasi R = L.first;
    while (R != nullptr) {//Cek apakah elemen saat ini menunjuk ke Kurir K DAN Paket P yang dicari
        if (R->kurir == K && R->paket == P) {
            return R;
        }
        R = R->next;// Jika tidak cocok, lanjut ke elemen berikutnya
    }
    return nullptr;
}

void insertLastRelasi(List_relasi &L, addr_relasi P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        addr_relasi Q = L.first;
        while (Q->next != nullptr) {// Loop sampai menemukan elemen terakhir yang nextnya nill
            Q = Q->next;
        }
        Q->next = P;
    }
}

void deleteRelasi(List_relasi &L, addr_relasi &P) {
    if (L.first == nullptr) {
        P = nullptr;
        return;
    }
    if (L.first == P) {// sikon 1 menghapus elemen pertama First
        L.first = P->next;
        P->next = nullptr;
    } else {// sikon 2 menghapus elemen di tengah atau akhir
        addr_relasi Q = L.first;
        while (Q->next != nullptr && Q->next != P) {
            Q = Q->next;
        }
        if (Q->next == P) {// Jika Q->next menunjuk ke P, berarti P ditemukan
            Q->next = P->next;
            P->next = nullptr;
        } else {
            P = nullptr;
        }
    }
}
