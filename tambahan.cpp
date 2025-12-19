#include "relasi.h"
#include <iostream>
using namespace std;

void connectRelasi(List_relasi &LR, addr_kurir K, addr_paket P) {
    if (K != nullptr && P != nullptr) {
        insertLastRelasi(LR, createElementRelasi(K, P));
        K->info.jmlpkt++;
    }
}

void disconnectRelasi(List_relasi &LR, addr_kurir K, addr_paket P) {
    addr_relasi R = findElementRelasi(LR, K, P);// Cari alamat elemen relasi yang menghubungkan K dan P
    if (R != nullptr) {
        deleteRelasi(LR, R);// Hapus elemen tersebut dari List Relasi
        K->info.jmlpkt--;
    }
}

bool isPaketAssigned(List_relasi LR, addr_paket P) {
    addr_relasi R = LR.first;
    while (R != nullptr) {
        if (R->paket == P) return true;// Jika ditemukan relasi yang menunjuk ke paket P
        R = R->next;
    }
    return false;
}

void autoInputRelasi(List_relasi &LR, List_kurir &LK, List_paket LP) {
    addr_paket P = LP.first;
    int count = 0;
    cout << "Mulai Distribusi Otomatis..." << endl;
    while (P != nullptr) {
        if (!isPaketAssigned(LR, P)) {
            addr_kurir candidate = nullptr;// set kurir terbaik
            int minLoad = 9999;// Nilai awal beban minimal (set tinggi agar mudah dikalahkan)
            addr_kurir K = LK.first;
            while (K != nullptr) {
                bool isMatch = false;
                if (P->info.ukuran == "Besar" && K->info.kendaraan == "Mobil") isMatch = true;
                else if (P->info.ukuran == "Kecil" && K->info.kendaraan == "Motor") isMatch = true;

                if (isMatch) {// Jika jenis kendaraan cocok, cek beban kerjanya
                    if (K->info.jmlpkt < minLoad) {// Algoritma mencari minimum, lalu pilih yang paketnya paling sedikit
                        minLoad = K->info.jmlpkt;
                        candidate = K;// set kurir ini sebagai sementara
                    }
                }
                K = K->next;
            }
            if (candidate != nullptr) {// Jika ditemukan kandidat kurir yang cocok
                connectRelasi(LR, candidate, P);
                cout << "Paket " << P->info.ID_paket << " -> Kurir " << candidate->info.ID_kurir << endl;
                count++;
            }
        }
        P = P->next;// Lanjut ke paket berikutnya
    }
    cout << "Selesai. " << count << " paket didistribusikan." << endl;
}

void showAllParentWithChild(List_relasi LR, List_kurir LK) {
    addr_kurir K = LK.first;
    cout << "\n=== KURIR BESERTA PAKETNYA ===" << endl;
    while (K != nullptr) {
        cout << "Kurir " << K->info.ID_kurir << " (" << K->info.kendaraan << "):" << endl;
        addr_relasi R = LR.first;// Loop list relasi untuk mencari paket milik kurir K ini
        bool ada = false;
        while (R != nullptr) {
            if (R->kurir == K) {
                cout << "  -> Paket " << R->paket->info.ID_paket << " (" << R->paket->info.ukuran << ")" << endl;
                ada = true;
            }
            R = R->next;
        }
        if (!ada) cout << "  (Kosong)" << endl;
        cout << endl;
        K = K->next;
    }
}

void showAllChildWithParent(List_relasi LR, List_paket LP) {
    addr_paket P = LP.first;
    cout << "\n=== PAKET BESERTA KURIRNYA ===" << endl;
    while (P != nullptr) {
        cout << "Paket " << P->info.ID_paket << " (" << P->info.ukuran << "):" << endl;
        addr_relasi R = LR.first;// Loop list relasi untuk mencari kurir pengantar paket P ini
        bool ada = false;
        while (R != nullptr) {
            if (R->paket == P) {
                cout << "  -> Diantar oleh Kurir " << R->kurir->info.ID_kurir << endl;
                ada = true;
            }
            R = R->next;
        }
        if (!ada) cout << "  (Belum ada kurir)" << endl;
        cout << endl;
        P = P->next;
    }
}

void showChildFromParent(List_relasi LR, List_kurir LK, int IDKurir) {
    addr_kurir K = findElementKurir(LK, IDKurir);// Cari dulu pointer kurirnya
    if (!K) { cout << "Kurir tidak ditemukan." << endl; return; }
    cout << "\nDaftar Paket untuk Kurir " << IDKurir << ":" << endl;
    addr_relasi R = LR.first;
    bool found = false;
    while (R != nullptr) {// Cari di relasi yang kurirnya sama dengan K
        if (R->kurir == K) {
            cout << "- Paket " << R->paket->info.ID_paket << endl;
            found = true;
        }
        R = R->next;
    }
    if (!found) cout << "(Tidak ada muatan)" << endl;
}

void showParentFromChild(List_relasi LR, List_paket LP, int IDPaket) {
    addr_paket P = findElementPaket(LP, IDPaket);// Cari dulu pointer paketnya
    if (!P) { cout << "Paket tidak ditemukan." << endl; return; }
    cout << "\nPengantar Paket " << IDPaket << ":" << endl;
    addr_relasi R = LR.first;
    bool found = false;
    while (R != nullptr) {// Cari di relasi yang paketnya sama dengan P
        if (R->paket == P) {
            cout << "- Kurir " << R->kurir->info.ID_kurir << endl;
            found = true;
        }
        R = R->next;
    }
    if (!found) cout << "(Belum diantar siapapun)" << endl;
}

void showCountRelasiEveryParent(List_relasi LR, List_kurir LK) {
    addr_kurir K = LK.first;
    cout << "\n=== JUMLAH PAKET SETIAP KURIR ===" << endl;
    while (K != nullptr) {
        int count = 0;
        addr_relasi R = LR.first;
        while (R != nullptr) {
            if (R->kurir == K) count++;
            R = R->next;
        }
        cout << "Kurir " << K->info.ID_kurir << " membawa " << count << " paket." << endl;
        K = K->next;
    }
}

int countRelasiByChild(List_relasi LR, addr_paket P) {
    int count = 0;
    addr_relasi R = LR.first;
    while (R != nullptr) {
        if (R->paket == P) count++;
        R = R->next;
    }
    return count;
}

int countChildNoRelation(List_relasi LR, List_paket LP) {
    int count = 0;
    addr_paket P = LP.first;
    while (P != nullptr) {
        if (!isPaketAssigned(LR, P)) count++;
        P = P->next;
    }
    return count;
}

void disconnectAllRelasi(List_relasi &LR) {
    addr_relasi P = LR.first;
    addr_relasi temp;

    while (P != nullptr) {
        // Update data beban paket pada kurir agar berkurang
        if (P->kurir != nullptr) {
            P->kurir->info.jmlpkt--;
        }

        // Simpan alamat node saat ini untuk dihapus
        temp = P;

        // Pindah ke node berikutnya sebelum node saat ini dihapus
        P = P->next;

        // Hapus node dari memori
        delete temp;
    }

    LR.first = nullptr;
}
