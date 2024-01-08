#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) (L).first
#define info(P) (P)->info
#define next(P) (P)->next
#define user(P) (P)->user
#define pelanggan(P) (P)->pelanggan
#define id(P) (P)->id

typedef struct elmHotel *adrHotel;
typedef struct elmUser *adrUser;
typedef struct elmPelanggan *adrPelanggan;

struct infoHotel {
    string nama;
    string kode;
    string tahunBerdiri;
};

struct infoUser {
    string nama;
    string id;
    int usia;
};

struct elmHotel {
    infoHotel info;
    adrHotel next;
    adrPelanggan pelanggan;
};

struct elmUser {
    infoUser info;
    adrUser next;
};

struct elmPelanggan {
    adrPelanggan next;
    string id;
    adrUser user;
};

struct listHotel {
    adrHotel first;
};

struct listUser {
    adrUser first;
};

//Fungsi Utama
void createListHotel(listHotel &L);
void createListUser(listUser &L);
adrHotel createElmHotel(infoHotel x);
adrUser createElmUser(infoUser x);
void insertFirstHotel(listHotel &L, adrHotel p);
void insertFirstUser(listUser &L, adrUser p);
void insertLastHotel(listHotel &L, adrHotel p);
void insertLastUser(listUser &L, adrUser p);
adrHotel searchHotel(listHotel L, string kode);
adrUser searchUser(listUser L, string id);
adrHotel deleteHotel(listHotel &L, string kode);
adrUser deleteUser(listUser &L, string id);
void showAllHotel(listHotel L);
void showAllUser(listUser L);
int countHotel(listHotel L);
int countUser(listUser L);

//Fungsi Relasi
void addPelanggan(listHotel LH, listUser LU, string kode, string id);
adrPelanggan searchPelanggan(listHotel L, string kode, string id);
adrPelanggan deletePelanggan(listHotel L, string kode, string id);
int countPelanggan(listHotel L, string kode);
void showAllPelanggan(listHotel L, string kode);

//Fungsi Menu & Tambahan
void menuHotel(listHotel &L);
void menuUser(listUser &LU, listHotel &LH);
void menuRelasi(listHotel &LH, listUser &LU);
void pause();
void clearScreen();

#endif // TUBES_H_INCLUDED
