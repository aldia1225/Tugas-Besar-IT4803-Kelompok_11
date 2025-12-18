#include "menu.h"
#include <iostream>
using namespace std;

void createDummyData(List_kurir &LK, List_paket &LP, List_relasi &LR) {
    insertLastKurir(LK, createElementKurir(1, "Motor"));
    insertLastKurir(LK, createElementKurir(2, "Mobil"));
    insertLastKurir(LK, createElementKurir(3, "Motor"));
    insertLastKurir(LK, createElementKurir(4, "Mobil"));
    insertLastKurir(LK, createElementKurir(10, "Mobil"));
    insertLastKurir(LK, createElementKurir(5, "Mobil"));

    insertLastPaket(LP, createElementPaket(101, "Jl. A", "Kecil"));
    insertLastPaket(LP, createElementPaket(102, "Jl. B", "Besar"));
    insertLastPaket(LP, createElementPaket(103, "Jl. C", "Kecil"));
    insertLastPaket(LP, createElementPaket(104, "Jl. D", "Besar"));
    insertLastPaket(LP, createElementPaket(105, "Jl. E", "Kecil"));

    addr_kurir K; addr_paket P;

    K = findElementKurir(LK, 1); P = findElementPaket(LP, 101);
    connectRelasi(LR, K, P);

    K = findElementKurir(LK, 2); P = findElementPaket(LP, 102);
    connectRelasi(LR, K, P);
}

int main() {
    List_kurir LK; createListKurir(LK);
    List_paket LP; createListPaket(LP);
    List_relasi LR; createListRelasi(LR);

    createDummyData(LK, LP, LR);
    menuUtama(LK, LP, LR);

    return 0;
}
