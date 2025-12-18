#include "menu.h"
#include <iostream>
using namespace std;

// === MENU UTAMA ===
void menuUtama(List_kurir &LK, List_paket &LP, List_relasi &LR) {
    int pil = -1;
    while (pil != 0) {
        cout << "\n=== SISTEM LOGISTIK ===" << endl;
        cout << "1. ADMIN MENU" << endl;
        cout << "2. USER MENU" << endl;
        cout << "0. Exit" << endl;
        cout << "Pilih: ";
        cin >> pil;

        if (pil == 1) {
            menuAdmin(LK, LP, LR);
        } else if (pil == 2) {
            menuUser(LK, LP, LR);
        }
    }
}

// === MENU ADMIN DASHBOARD ===
void menuAdmin(List_kurir &LK, List_paket &LP, List_relasi &LR) {
    int pil = -1;
    while (pil != 0) {
        cout << "\n-- ADMIN DASHBOARD --" << endl;
        cout << "1. Kelola Kurir" << endl;
        cout << "2. Kelola Paket" << endl;
        cout << "3. Kelola Relasi" << endl;
        cout << "0. Kembali" << endl;
        cout << "Pilih: ";
        cin >> pil;

        if (pil == 1) {
            menuAdminKurir(LK);
        } else if (pil == 2) {
            menuAdminPaket(LP);
        } else if (pil == 3) {
            menuAdminRelasi(LK, LP, LR);
        }
    }
}

// === MENU ADMIN: KELOLA KURIR ===
void menuAdminKurir(List_kurir &LK) {
    int pil = -1;
    int id, idPrec;
    string k;
    addr_kurir P, Prec;

    while (pil != 0) {
        cout << "\n[ADMIN] KELOLA KURIR" << endl;
        cout << "1. Insert First Kurir" << endl;
        cout << "2. Insert Last Kurir" << endl;
        cout << "3. Insert After Kurir" << endl;
        cout << "4. Delete First Kurir" << endl;
        cout << "5. Delete Last Kurir" << endl;
        cout << "6. Delete After Kurir" << endl;
        cout << "7. Delete Kurir Tertentu (By ID)" << endl;
        cout << "8. Find Kurir" << endl;
        cout << "9. Show All Kurir" << endl;
        cout << "0. Back" << endl;
        cout << "Pilih: ";
        cin >> pil;

        if (pil == 1 || pil == 2 || pil == 3) {
            cout << "Masukkan ID Kurir: ";
            cin >> id;
            cout << "Jenis (Mobil/Motor): ";
            cin >> k;
            P = createElementKurir(id, k);

            if (pil == 1) {
                insertFirstKurir(LK, P);
                cout << "Insert First Berhasil." << endl;
            } else if (pil == 2) {
                insertLastKurir(LK, P);
                cout << "Insert Last Berhasil." << endl;
            } else if (pil == 3) {
                cout << "Insert setelah ID Kurir berapa? ";
                cin >> idPrec;
                Prec = findElementKurir(LK, idPrec);
                if (Prec != nullptr) {
                    insertAfterKurir(LK, Prec, P);
                    cout << "Insert After Berhasil." << endl;
                } else {
                    cout << "Kurir Prec tidak ditemukan." << endl;
                }
            }
        }
        else if (pil == 4) {
            deleteFirstKurir(LK, P);
            if (P) cout << "Hapus First: ID " << P->info.ID_kurir << " terhapus." << endl;
        } else if (pil == 5) {
            deleteLastKurir(LK, P);
            if (P) cout << "Hapus Last: ID " << P->info.ID_kurir << " terhapus." << endl;
        } else if (pil == 6) {
            cout << "Hapus setelah ID Kurir berapa? ";
            cin >> idPrec;
            Prec = findElementKurir(LK, idPrec);
            if (Prec != nullptr) {
                deleteAfterKurir(LK, Prec, P);
                if (P) cout << "Hapus After: ID " << P->info.ID_kurir << " terhapus." << endl;
            } else {
                cout << "Kurir Prec tidak ditemukan." << endl;
            }
        }
        else if (pil == 7) {
            cout << "Masukkan ID Kurir yang ingin dihapus: ";
            cin >> id;

            if (isEmpty_kurir(LK)) {
                cout << "List kosong." << endl;
            } else if (LK.first->info.ID_kurir == id) {
                deleteFirstKurir(LK, P);
                cout << "Berhasil menghapus kurir (First)." << endl;
            } else {
                Prec = LK.first;
                while (Prec->next != nullptr && Prec->next->info.ID_kurir != id) {
                    Prec = Prec->next;
                }

                if (Prec->next != nullptr) {
                    deleteAfterKurir(LK, Prec, P);
                    cout << "Berhasil menghapus kurir ID " << id << "." << endl;
                } else {
                    cout << "Kurir tidak ditemukan." << endl;
                }
            }
        }
        else if (pil == 8) {
            cout << "Masukkan ID dicari: ";
            cin >> id;
            P = findElementKurir(LK, id);
            if (P) cout << "Ditemukan: " << P->info.kendaraan << endl;
            else cout << "Tidak ditemukan." << endl;
        } else if (pil == 9) {
            showKurir(LK);
        }
    }
}

// === MENU ADMIN: KELOLA PAKET ===
void menuAdminPaket(List_paket &LP) {
    int pil = -1;
    int id, idPrec;
    string al, uk;
    addr_paket P, Prec;

    while (pil != 0) {
        cout << "\n[ADMIN] KELOLA PAKET" << endl;
        cout << "1. Insert First Paket" << endl;
        cout << "2. Insert Last Paket" << endl;
        cout << "3. Insert After Paket" << endl;
        cout << "4. Delete First Paket" << endl;
        cout << "5. Delete Last Paket" << endl;
        cout << "6. Delete After Paket" << endl;
        cout << "7. Delete Paket Tertentu (By ID)" << endl;
        cout << "8. Find Paket" << endl;
        cout << "9. Show All Paket" << endl;
        cout << "0. Back" << endl;
        cout << "Pilih: ";
        cin >> pil;

        if (pil == 1 || pil == 2 || pil == 3) {
            cout << "ID Paket: "; cin >> id;
            cout << "Alamat: "; cin >> al;
            cout << "Ukuran (Besar/Kecil): "; cin >> uk;
            P = createElementPaket(id, al, uk);

            if (pil == 1) {
                insertFirstPaket(LP, P);
                cout << "Insert First Berhasil." << endl;
            } else if (pil == 2) {
                insertLastPaket(LP, P);
                cout << "Insert Last Berhasil." << endl;
            } else if (pil == 3) {
                cout << "Insert setelah ID Paket berapa? ";
                cin >> idPrec;
                Prec = findElementPaket(LP, idPrec);
                if (Prec) {
                    insertAfterPaket(LP, Prec, P);
                    cout << "Insert After Berhasil." << endl;
                } else cout << "Paket Prec tidak ditemukan." << endl;
            }
        }
        else if (pil == 4) {
            deleteFirstPaket(LP, P);
            if (P) cout << "Hapus First selesai." << endl;
        } else if (pil == 5) {
            deleteLastPaket(LP, P);
            if (P) cout << "Hapus Last selesai." << endl;
        } else if (pil == 6) {
            cout << "Hapus setelah ID Paket berapa? ";
            cin >> idPrec;
            Prec = findElementPaket(LP, idPrec);
            if (Prec) {
                deleteAfterPaket(LP, Prec, P);
                if (P) cout << "Hapus After selesai." << endl;
            } else cout << "Paket Prec tidak ditemukan." << endl;
        }
        else if (pil == 7) {
            cout << "Masukkan ID Paket yang ingin dihapus: ";
            cin >> id;
            P = findElementPaket(LP, id);

            if (P == nullptr) {
                cout << "Paket tidak ditemukan." << endl;
            } else {
                if (P == LP.first) {
                    deleteFirstPaket(LP, P);
                } else if (P == LP.last) {
                    deleteLastPaket(LP, P);
                } else {
                    Prec = P->prev;
                    deleteAfterPaket(LP, Prec, P);
                }
                cout << "Berhasil menghapus Paket ID " << id << endl;
            }
        }
        else if (pil == 8) {
            cout << "Masukkan ID dicari: ";
            cin >> id;
            P = findElementPaket(LP, id);
            if (P) cout << "Ditemukan: " << P->info.alamat << endl;
            else cout << "Tidak ditemukan." << endl;
        } else if (pil == 9) {
            showPaket(LP);
        }
    }
}

// === MENU ADMIN: RELASI ===
void menuAdminRelasi(List_kurir LK, List_paket LP, List_relasi &LR) {
    int pil = -1;
    int idK, idP;
    addr_kurir K;
    addr_paket P;

    while (pil != 0) {
        cout << "\n[ADMIN] KELOLA RELASI" << endl;
        cout << "1. Connect Manual (Insert Relasi)" << endl;
        cout << "2. Delete Relasi (Putus Hubungan)" << endl;
        cout << "3. AUTO DISTRIBUSI" << endl;
        cout << "4. Show All Relasi" << endl;
        cout << "0. Back" << endl;
        cout << "Pilih: ";
        cin >> pil;

        if (pil == 1) {
            showKurir(LK);
            showPaket(LP);
            cout << "Masukkan ID Kurir: "; cin >> idK;
            cout << "Masukkan ID Paket: "; cin >> idP;

            K = findElementKurir(LK, idK);
            P = findElementPaket(LP, idP);

            if (K && P) {
                if (isPaketAssigned(LR, P)) {
                    cout << "Paket sudah diambil!" << endl;
                } else {
                    if ((K->info.kendaraan == "Mobil" && P->info.ukuran != "Besar") ||
                        (K->info.kendaraan == "Motor" && P->info.ukuran != "Kecil")) {
                        cout << "Kendaraan & Paket Tidak Cocok!" << endl;
                    } else {
                        connectRelasi(LR, K, P);
                        cout << "Relasi berhasil dibuat." << endl;
                    }
                }
            } else cout << "ID Salah." << endl;

        } else if (pil == 2) {
            cout << "Masukkan ID Kurir: "; cin >> idK;
            cout << "Masukkan ID Paket: "; cin >> idP;
            K = findElementKurir(LK, idK);
            P = findElementPaket(LP, idP);
            if (findElementRelasi(LR, K, P)) {
                disconnectRelasi(LR, K, P);
                cout << "Relasi dihapus." << endl;
            } else cout << "Relasi tidak ditemukan." << endl;

        } else if (pil == 3) {
            autoInputRelasi(LR, LK, LP);
        } else if (pil == 4) {
            showAllParentWithChild(LR, LK);
        }
    }
}

// === MENU USER ===
void menuUser(List_kurir LK, List_paket LP, List_relasi LR) {
    int pil = -1;
    int id;

    while (pil != 0) {
        cout << "\n=== USER VIEW & REPORT ===" << endl;
        cout << "1. Show all Kurir" << endl;
        cout << "2. Show all Paket" << endl;
        cout << "3. Show Kurir beserta Paketnya" << endl;
        cout << "4. Show Paket beserta Kurirnya" << endl;
        cout << "5. Show Paket dari Kurir tertentu" << endl;
        cout << "6. Show Kurir yang membawa Paket tertentu" << endl;
        cout << "7. Count Relasi setiap Kurir" << endl;
        cout << "8. Count Relasi Paket tertentu" << endl;
        cout << "9. Count Paket tanpa Kurir" << endl;
        cout << "0. Back" << endl;
        cout << "Pilih: ";
        cin >> pil;

        if (pil == 1) showKurir(LK);
        else if (pil == 2) showPaket(LP);
        else if (pil == 3) showAllParentWithChild(LR, LK);
        else if (pil == 4) showAllChildWithParent(LR, LP);
        else if (pil == 5) {
            cout << "ID Kurir: "; cin >> id;
            showChildFromParent(LR, LK, id);
        } else if (pil == 6) {
            cout << "ID Paket: "; cin >> id;
            showParentFromChild(LR, LP, id);
        } else if (pil == 7) showCountRelasiEveryParent(LR, LK);
        else if (pil == 8) {
            cout << "ID Paket: "; cin >> id;
            addr_paket P = findElementPaket(LP, id);
            if (P) cout << "Paket " << id << " memiliki " << countRelasiByChild(LR, P) << " relasi." << endl;
            else cout << "Paket tidak ditemukan." << endl;
        } else if (pil == 9) {
            cout << "Paket tanpa kurir: " << countChildNoRelation(LR, LP) << endl;
        }
    }
}
