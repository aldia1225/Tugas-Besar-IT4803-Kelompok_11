#include "paket.h"

void createListPaket(List_paket &L) {
    L.first = nullptr;
    L.last = nullptr;
}

bool isEmpty_paket(List_paket L) {
    return L.first == nullptr;
}

addr_paket createElementPaket(int ID, string Alamat, string Ukuran) {
    addr_paket P = new paket;
    P->info.ID_paket = ID;
    P->info.alamat = Alamat;
    P->info.ukuran = Ukuran;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

addr_paket findElementPaket(List_paket L, int ID) {
    addr_paket P = L.first;
    while (P != nullptr && P->info.ID_paket != ID) {
        P = P->next;
    }
    return P;
}

void insertLastPaket(List_paket &L, addr_paket P) {
    if (isEmpty_paket(L)) {
        L.first = P;// Node P menjadi elemen pertama sekaligus terakhir
        L.last = P;
    } else {
        P->prev = L.last;// Sambungkan prev milik P ke node terakhir saat ini (L.last)
        L.last->next = P;// Sambungkan next milik node terakhir ke P
        L.last = P;
    }
}

void insertAfterPaket(List_paket &L, addr_paket Prec, addr_paket P) {
    if (Prec != nullptr) {// cek pastikan node pendahulu (Prec) ada
        P->next = Prec->next;
        P->prev = Prec;
        if (Prec->next != nullptr) {// Update pointer balik dari node setelah Prec (jika ada)
            Prec->next->prev = P;
        } else {// Jika Prec adalah node terakhir, maka P akan menjadi node terakhir baru
            L.last = P;
        }
        Prec->next = P;
    }
}

void deleteLastPaket(List_paket &L, addr_paket &P) {
    if (isEmpty_paket(L)) {
        P = nullptr;
    } else if (L.first == L.last) {// sikon 2 cuman ada 1 elemen di list
        P = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {//sikon 3 banyak elemen
        P = L.last;
        L.last = L.last->prev;
        L.last->next = nullptr;// Putus hubungan ke node lama
        P->prev = nullptr;
    }
}

void deleteAfterPaket(List_paket &L, addr_paket Prec, addr_paket &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;// P adalah target yang akan dihapus (node setelah Prec)
        Prec->next = P->next;
        if (P->next != nullptr) {//  Update Prev dari node setelah P (jika ada)
            P->next->prev = Prec;
        } else {// Jika P adalah node terakhir, maka Prec menjadi node terakhir baru
            L.last = Prec;
        }
        P->next = nullptr;
        P->prev = nullptr;
    } else {
        P = nullptr;
    }
}
