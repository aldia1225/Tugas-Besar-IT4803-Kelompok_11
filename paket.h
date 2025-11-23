#ifndef PAKET_H_INCLUDED
#define PAKET_H_INCLUDED

typedef data_paket infotype;
typedef struct paket *addr_pkt;

struct data_paket  {
    int ID_paket;
    string alamat;
    int berat;
};

struct paket {
    infotype info;
    addr_pkt next;
    addr_pkt prev;
};

struct List_paket {
    addr_pkt first;
    addr_pkt last;
};


#endif // PAKET_H_INCLUDED
