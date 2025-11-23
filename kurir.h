#ifndef KURIR_H_INCLUDED
#define KURIR_H_INCLUDED

typedef data_kurir infotype;
typedef struct kurir *addr_kurir;

struct data_kurir  {
    int ID_kurir;
    string kendaraan;
    int berat;
};

struct kurir {
    infotype info;
    addr_pkt next;
  
};

struct List_kurir {
    addr_pkt first;

};


#endif // KURIR_H_INCLUDED
