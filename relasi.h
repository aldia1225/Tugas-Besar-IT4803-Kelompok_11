#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

typedef struct relasi *addr_relasi;

struct relasi {
    addr_pkt pkt ;
    addr_kurir kur;
    addr_relasi next;
};

struct List_relasi {
    addr_relasi first;

};


#endif // RELASI_H_INCLUDED
