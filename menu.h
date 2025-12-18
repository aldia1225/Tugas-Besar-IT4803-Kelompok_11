#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "relasi.h"

void menuUtama(List_kurir &LK, List_paket &LP, List_relasi &LR);
void menuAdmin(List_kurir &LK, List_paket &LP, List_relasi &LR);
void menuAdminKurir(List_kurir &LK);
void menuAdminPaket(List_paket &LP);
void menuAdminRelasi(List_kurir LK, List_paket LP, List_relasi &LR);
void menuUser(List_kurir LK, List_paket LP, List_relasi LR);

#endif
