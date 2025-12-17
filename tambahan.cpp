#include "relasi.h"
#include <iostream>
using namespace std;

// Cek apakah paket sudah diambil (1 Paket = 1 Kurir)
bool isPaketAssigned(List_relasi LR, addr_paket P) {
    addr_relasi R = LR.first;
    while(R != nullptr) {
        if (R->paket == P) return true;
        R = R->next;
    }
    return false;
}

// --- LOGIC AUTO DISTRIBUSI ---
void autoInputRelasi(List_relasi &LR, List_kurir &LK, List_paket LP) {
    addr_paket P = LP.first;

    addr_kurir turnMobil = LK.first;
    addr_kurir turnMotor = LK.first;
    int count = 0;

    cout << "Mulai Distribusi Otomatis..." << endl;

    while (P != nullptr) {
        if (!isPaketAssigned(LR, P)) {
            addr_kurir assignedK = nullptr;

            // 1. Paket BESAR -> MOBIL
            if (P->info.ukuran == "Besar") {
                addr_kurir start = turnMobil;
                if(start != nullptr) {
                    do {
                        if (turnMobil->info.kendaraan == "Mobil") {
                            assignedK = turnMobil;
                            turnMobil = turnMobil->next;
                            if (turnMobil == nullptr) turnMobil = LK.first;
                            break;
                        }
                        turnMobil = turnMobil->next;
                        if (turnMobil == nullptr) turnMobil = LK.first;
                    } while (turnMobil != start);
                }
            }
            // 2. Paket KECIL -> MOTOR
            else if (P->info.ukuran == "Kecil") {
                addr_kurir start = turnMotor;
                if(start != nullptr) {
                    do {
                        if (turnMotor->info.kendaraan == "Motor") {
                            assignedK = turnMotor;
                            turnMotor = turnMotor->next;
                            if (turnMotor == nullptr) turnMotor = LK.first;
                            break;
                        }
                        turnMotor = turnMotor->next;
                        if (turnMotor == nullptr) turnMotor = LK.first;
                    } while (turnMotor != start);
                }
            }

            if (assignedK != nullptr) {
                insertLastRelasi(LR, createElementRelasi(assignedK, P));
                assignedK->info.jmlpkt++;
                cout << "[OK] Paket " << P->info.ID_paket << " (" << P->info.ukuran << ") -> "
                     << assignedK->info.kendaraan << " ID:" << assignedK->info.ID_kurir << endl;
                count++;
            }
        }
        P = P->next;
    }
    cout << "Selesai. " << count << " paket didistribusikan." << endl;
}

// --- TAMPILAN FORMAT LIST (SESUAI REQUEST) ---

void showAllParentWithChild(List_relasi LR, List_kurir LK){
    addr_kurir K = LK.first;
    cout << "\n=== DATA MUATAN KURIR ===" << endl;
    while(K != nullptr){
        cout << "Kurir " << K->info.ID_kurir << " (" << K->info.kendaraan << "):" << endl;

        // Loop Relasi untuk Kurir ini
        addr_relasi R = LR.first;
        bool ada = false;
        while(R != nullptr){
            if(R->kurir == K){
                cout << "  - Paket " << R->paket->info.ID_paket
                     << " (" << R->paket->info.ukuran << ", " << R->paket->info.alamat << ")" << endl;
                ada = true;
            }
            R = R->next;
        }

        if(!ada) cout << "  (Tidak ada muatan)" << endl;
        cout << endl; // Spasi antar kurir
        K = K->next;
    }
}

void showAllChildWithParent(List_relasi LR, List_paket LP){
    addr_paket P = LP.first;
    cout << "\n=== STATUS PAKET ===" << endl;
    while(P != nullptr){
        cout << "Paket " << P->info.ID_paket << " (" << P->info.ukuran << "):" << endl;

        addr_relasi R = LR.first;
        bool ada = false;
        while(R != nullptr){
            if(R->paket == P){
                cout << "  - Kurir " << R->kurir->info.ID_kurir
                     << " (" << R->kurir->info.kendaraan << ")" << endl;
                ada = true;
            }
            R = R->next;
        }

        if(!ada) cout << "  (Belum diambil)" << endl;
        cout << endl;
        P = P->next;
    }
}

void showChildFromParent(List_relasi LR, List_kurir LK, int IDKurir){
    addr_kurir K = findElementKurir(LK, IDKurir);
    if(!K){ cout << "Kurir tidak ditemukan." << endl; return; }

    cout << "\nKurir " << IDKurir << " (" << K->info.kendaraan << "):" << endl;
    addr_relasi R = LR.first;
    bool found = false;
    while(R){
        if(R->kurir == K) {
            cout << "  - Paket " << R->paket->info.ID_paket << " (" << R->paket->info.ukuran << ")" << endl;
            found = true;
        }
        R = R->next;
    }
    if(!found) cout << "  (Kosong)" << endl;
}

void showParentFromChild(List_relasi LR, List_paket LP, int IDPaket){
    addr_paket P = findElementPaket(LP, IDPaket);
    if(!P) { cout << "Paket tidak ditemukan." << endl; return; }

    cout << "\nPaket " << IDPaket << ":" << endl;
    addr_relasi R = LR.first;
    bool found = false;
    while(R){
        if(R->paket == P) {
            cout << "  - Kurir " << R->kurir->info.ID_kurir << endl;
            found = true;
        }
        R = R->next;
    }
    if(!found) cout << "  (Belum diambil)" << endl;
}

void editRelasi(List_relasi &LR, List_kurir LK, List_paket LP, int IDKurir, int IDPaketLama, int IDPaketBaru){
    addr_kurir K = findElementKurir(LK, IDKurir);
    addr_paket PBaru = findElementPaket(LP, IDPaketBaru);

    if(K && PBaru){
        // Validasi Kendaraan vs Paket
        if ( (K->info.kendaraan == "Mobil" && PBaru->info.ukuran != "Besar") ||
             (K->info.kendaraan == "Motor" && PBaru->info.ukuran != "Kecil") ) {
             cout << "Gagal: Jenis Kendaraan & Ukuran Paket Tidak Cocok!" << endl;
             return;
        }
        // Validasi Ketersediaan
        if (isPaketAssigned(LR, PBaru)) {
             cout << "Gagal: Paket Baru sudah diambil kurir lain." << endl;
             return;
        }

        addr_relasi R = LR.first;
        while(R){
            if(R->kurir == K && R->paket->info.ID_paket == IDPaketLama){
                R->paket = PBaru;
                cout << "Sukses menukar paket." << endl;
                return;
            }
            R = R->next;
        }
        cout << "Relasi lama tidak ditemukan." << endl;
    } else cout << "ID Salah." << endl;
}
