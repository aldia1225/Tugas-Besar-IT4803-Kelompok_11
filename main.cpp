#include "menu.h"

int main() {
    List_kurir LK; createListKurir(LK);
    List_paket LP; createListPaket(LP);
    List_relasi LR; createListRelasi(LR);
    menuUtama(LK, LP, LR);
    return 0;
}
