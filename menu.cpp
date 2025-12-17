#include "menu.h"
#include <iostream>
using namespace std;

void menuUtama(List_kurir &LK, List_paket &LP, List_relasi &LR) {
    int pil;
    do {
        cout << "\n=== SISTEM LOGISTIK ===" << endl;
        cout << "1. ADMIN" << endl;
        cout << "2. USER" << endl;
        cout << "0. Exit" << endl;
        cout << "Pilih: "; cin >> pil;
        if(pil==1) menuAdmin(LK, LP, LR);
        else if(pil==2) menuUser(LK, LP, LR);
    } while(pil!=0);
}

void menuAdmin(List_kurir &LK, List_paket &LP, List_relasi &LR) {
    int pil;
    do {
        cout << "\n-- ADMIN DASHBOARD --" << endl;
        cout << "1. Kelola Kurir" << endl;
        cout << "2. Kelola Paket" << endl;
        cout << "3. Kelola Relasi" << endl;
        cout << "0. Kembali" << endl;
        cout << "Pilih: "; cin >> pil;
        if(pil==1) menuAdminKurir(LK);
        else if(pil==2) menuAdminPaket(LP);
        else if(pil==3) menuAdminRelasi(LK, LP, LR);
    } while(pil!=0);
}

void menuAdminKurir(List_kurir &LK) {
    int pil, id; string k;
    addr_kurir P, Prec; int idRef;
    do {
        cout << "\n[ADMIN] KURIR" << endl;
        cout << "1. Insert First\n2. Insert Last\n3. Insert After\n4. Delete First\n5. Delete Last\n6. Delete After\n7. Find\n8. Show\n0. Back\n>> "; cin >> pil;
        if(pil>=1 && pil<=3){
            cout<<"ID: "; cin>>id;
            // VALIDASI ID UNIK
            if(findElementKurir(LK, id) != nullptr) {
                cout << "Error: ID Kurir sudah ada!" << endl;
                continue;
            }

            cout<<"Kendaraan (Mobil/Motor): "; cin>>k;
            if(k!="Mobil" && k!="Motor") { cout<<"Input Salah!\n"; continue; }

            P = createElementKurir(id, k, 0);
            if(pil==1) insertFirstKurir(LK, P);
            else if(pil==2) insertLastKurir(LK, P);
            else {
                cout<<"After ID: "; cin>>idRef;
                Prec=findElementKurir(LK, idRef);
                if(Prec) insertAfterKurir(LK, Prec, P);
            }
        } else if(pil==4) deleteFirstKurir(LK, P);
        else if(pil==5) deleteLastKurir(LK, P);
        else if(pil==6) {
            cout<<"After ID: "; cin>>idRef;
            Prec=findElementKurir(LK, idRef);
            if(Prec) deleteAfterKurir(LK, Prec, P);
        } else if(pil==7){
            cout<<"ID: "; cin>>id;
            if(findElementKurir(LK, id)) cout<<"Ada.\n"; else cout<<"Tidak Ada.\n";
        } else if(pil==8) showKurir(LK);
    } while(pil!=0);
}

void menuAdminPaket(List_paket &LP) {
    int pil, id; string a, u;
    addr_paket P, Prec; int idRef;
    do {
        cout << "\n[ADMIN] PAKET" << endl;
        cout << "1. Insert First\n2. Insert Last\n3. Insert After\n4. Delete First\n5. Delete Last\n6. Delete After\n7. Find\n8. Show\n0. Back\n>> "; cin >> pil;
        if(pil>=1 && pil<=3){
            cout<<"ID: "; cin>>id;
            // VALIDASI ID UNIK
            if(findElementPaket(LP, id) != nullptr) {
                cout << "Error: ID Paket sudah ada!" << endl;
                continue;
            }

            cout<<"Alamat: "; cin>>a;
            cout<<"Ukuran (Besar/Kecil): "; cin>>u;
            if(u!="Besar" && u!="Kecil") { cout<<"Input Salah!\n"; continue; }

            P = createElementPaket(id, a, u);
            if(pil==1) insertFirstPaket(LP, P);
            else if(pil==2) insertLastPaket(LP, P);
            else {
                cout<<"After ID: "; cin>>idRef;
                Prec=findElementPaket(LP, idRef);
                if(Prec) insertAfterPaket(LP, Prec, P);
            }
        } else if(pil==4) deleteFirstPaket(LP, P);
        else if(pil==5) deleteLastPaket(LP, P);
        else if(pil==6) {
            cout<<"After ID: "; cin>>idRef;
            Prec=findElementPaket(LP, idRef);
            if(Prec) deleteAfterPaket(LP, Prec, P);
        } else if(pil==7){
            cout<<"ID: "; cin>>id;
            if(findElementPaket(LP, id)) cout<<"Ada.\n"; else cout<<"Tidak Ada.\n";
        } else if(pil==8) showPaket(LP);
    } while(pil!=0);
}

void menuAdminRelasi(List_kurir LK, List_paket LP, List_relasi &LR) {
    int pil, idK, idP, idPBaru;
    addr_kurir K; addr_paket P; addr_relasi R;
    do {
        cout << "\n[ADMIN] RELASI" << endl;
        cout << "1. Connect Manual\n2. Disconnect\n3. Edit Relasi\n4. AUTO DISTRIBUSI\n5. Show Relasi\n0. Back\n>> "; cin >> pil;
        if(pil==1){
            showKurir(LK); showPaket(LP);
            cout<<"ID Kurir: "; cin>>idK; cout<<"ID Paket: "; cin>>idP;
            K=findElementKurir(LK, idK); P=findElementPaket(LP, idP);
            if(K && P){
                if (isPaketAssigned(LR, P)) { cout<<"Paket sudah diambil!\n"; continue; }
                if ( (K->info.kendaraan=="Mobil" && P->info.ukuran!="Besar") ||
                     (K->info.kendaraan=="Motor" && P->info.ukuran!="Kecil") ) {
                    cout<<"Kendaraan & Paket Tidak Cocok!\n"; continue;
                }
                insertLastRelasi(LR, createElementRelasi(K, P));
                K->info.jmlpkt++;
                cout<<"Sukses.\n";
            } else cout<<"Data Salah.\n";
        } else if(pil==2){
            cout<<"ID Kurir: "; cin>>idK; cout<<"ID Paket: "; cin>>idP;
            K=findElementKurir(LK, idK); P=findElementPaket(LP, idP);
            R=findElementRelasi(LR, K, P);
            if(R){ deleteRelasi(LR, R); K->info.jmlpkt--; cout<<"Putus.\n"; }
        } else if(pil==3){
             cout<<"ID Kurir: "; cin>>idK; cout<<"ID Paket Lama: "; cin>>idP; cout<<"ID Paket Baru: "; cin>>idPBaru;
             editRelasi(LR, LK, LP, idK, idP, idPBaru);
        } else if(pil==4){
            autoInputRelasi(LR, LK, LP);
        } else if(pil==5){
            showAllParentWithChild(LR, LK);
        }
    } while(pil!=0);
}

void menuUser(List_kurir LK, List_paket LP, List_relasi LR) {
    int pil, id;
    do {
        cout << "\n[USER] VIEW" << endl;
        cout << "1. Show Kurir\n2. Show Paket\n3. Show Kurir+Muatan\n4. Show Paket+Pengantar\n5. Detail Muatan Kurir Tertentu\n6. Cek Pengantar Paket\n0. Back\n>> "; cin >> pil;
        if(pil==1) showKurir(LK);
        else if(pil==2) showPaket(LP);
        else if(pil==3) showAllParentWithChild(LR, LK);
        else if(pil==4) showAllChildWithParent(LR, LP);
        else if(pil==5) { cout<<"ID Kurir: "; cin>>id; showChildFromParent(LR, LK, id); }
        else if(pil==6) { cout<<"ID Paket: "; cin>>id; showParentFromChild(LR, LP, id); }
    } while(pil!=0);
}
