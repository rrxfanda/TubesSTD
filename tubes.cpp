#include "tubes.h"

void createListHotel(listHotel &L) {
    first(L) = NULL;
}

void createListUser(listUser &L) {
    first(L) = NULL;
}

adrHotel createElmHotel(infoHotel x) {
    adrHotel p = new elmHotel;

    info(p) = x;
    pelanggan(p) = NULL;
    next(p) = NULL;

    return p;
}

adrUser createElmUser(infoUser x) {
    adrUser p = new elmUser;

    info(p) = x;
    next(p) = NULL;

    return p;
}

void insertFirstHotel(listHotel &L, adrHotel p) {
    next(p) = first(L);
    first(L) = p;
}

void insertFirstUser(listUser &L, adrUser p) {
    next(p) = first(L);
    first(L) = p;
}

void insertLastHotel(listHotel &L, adrHotel p) {
    adrHotel last;

    if (first(L) == NULL) {
        first(L) = p;
    } else {
        last = first(L);

        while (next(last) != NULL) {
            last = next(last);
        }

        next(last) = p;
    }
}

void insertLastUser(listUser &L, adrUser p) {
    adrUser last;

    if (first(L) == NULL) {
        first(L) = p;
    } else {
        last = first(L);

        while (next(last) != NULL) {
            last = next(last);
        }

        next(last) = p;
    }
}

adrHotel searchHotel(listHotel L, string kode) {
    adrHotel p = first(L);

    while (p != NULL) {
        if (info(p).kode == kode) {
            return p;
        }

        p = next(p);
    }

    return NULL;
}

adrUser searchUser(listUser L, string id) {
    adrUser p = first(L);

    while (p != NULL) {
        if (info(p).id == id) {
            return p;
        }

        p = next(p);
    }

    return NULL;
}

adrHotel deleteHotel(listHotel &L, string kode) {
    adrHotel p, prec;

    p = searchHotel(L, kode);

    if (p == NULL) return NULL;

    if (first(L) == p) {
        first(L) = next(p);
    } else {
        prec = first(L);

        while (next(prec) != p) {
            prec = next(prec);
        }

        next(prec) = next(p);
    }

    next(p) = NULL;

    return p;
}

adrUser deleteUser(listUser &L, string id) {
    adrUser p, prec;

    p = searchUser(L, id);

    if (p == NULL) return NULL;

    if (first(L) == p) {
        first(L) = next(p);
    } else {
        prec = first(L);

        while (next(prec) != p) {
            prec = next(prec);
        }

        next(prec) = next(p);
    }

    next(p) = NULL;

    return p;
}

void showAllHotel(listHotel L) {
    adrHotel p = first(L);

    if (p == NULL) {
        cout << "Data Hotel Kosong!" << endl;
    } else {
        while (p != NULL) {
            cout << "Nama           : " << info(p).nama << endl;
            cout << "Kode           : " << info(p).kode << endl;
            cout << "Tahun Berdiri  : " << info(p).tahunBerdiri << endl;
            cout << endl;

            p = next(p);
        }
    }
}

void showAllUser(listUser L) {
    adrUser p = first(L);

    if (p == NULL) {
        cout << "Data User Kosong!" << endl;
    } else {
        while (p != NULL) {
            cout << "Nama   : " << info(p).nama << endl;
            cout << "ID     : " << info(p).id << endl;
            cout << "Usia   : " << info(p).usia << endl;
            cout << endl;

            p = next(p);
        }
    }
}

int countHotel(listHotel L) {
    int n = 0;
    adrHotel p = first(L);

    while (p != NULL) {
        n++;
        p = next(p);
    }

    return n;
}

int countUser(listUser L) {
    int n = 0;
    adrUser p = first(L);

    while (p != NULL) {
        n++;
        p = next(p);
    }

    return n;
}

void addPelanggan(listHotel LH, listUser LU, string kode, string id) {
    adrPelanggan pPelanggan, last;

    adrHotel pHotel = searchHotel(LH, kode);
    adrUser pUser = searchUser(LU, id);

    if (pHotel == NULL) {
        cout << "Data Hotel dengan kode " << kode << " tidak dapat ditemukan" << endl;
    } else if (pUser == NULL) {
        cout << "Data User dengan ID " << id << " tidak dapat ditemukan" << endl;
    } else {
        pPelanggan = new elmPelanggan;
        id(pPelanggan) = id;
        user(pPelanggan) = pUser;
        next(pPelanggan) = NULL;

        if (pelanggan(pHotel) == NULL) {
            pelanggan(pHotel) = pPelanggan;
        } else {
            last = pelanggan(pHotel);

            while (next(last) != NULL) {
                last = next(last);
            }

            next(last) = pPelanggan;
        }
    }
}

adrPelanggan searchPelanggan(listHotel L, string kode, string id) {
    adrPelanggan pPelanggan;
    adrHotel pHotel = searchHotel(L, kode);

    if (pHotel == NULL) {
        cout << "data Hotel dengan kode " << kode << " tidak dapat ditemukan" << endl;
        return NULL;
    } else {
        pPelanggan = pelanggan(pHotel);

        while (pPelanggan != NULL) {
            if (id(pPelanggan) == id) {
                return pPelanggan;
            }

            pPelanggan = next(pPelanggan);
        }

        return pPelanggan;
    }
}

adrPelanggan deletePelanggan(listHotel L, string kode, string id) {
    adrPelanggan pPelanggan, prec;
    adrHotel pHotel = searchHotel(L, kode);

    pPelanggan = searchPelanggan(L, kode, id);

    if (pHotel == NULL) {
        cout << "data Hotel dengan kode " << kode << " tidak dapat ditemukan" << endl;
        return NULL;
    } else if (pPelanggan == NULL) {
        cout << "data pelanggan dengan ID " << id << " tidak dapat ditemukan" << endl;
        return NULL;
    } else {
        if (pelanggan(pHotel) == pPelanggan) {
            pelanggan(pHotel) = next(pPelanggan);
        } else {
            prec = pelanggan(pHotel);

            while (next(prec) != NULL) {
                prec = next(prec);
            }

            next(prec) = next(pPelanggan);
        }

        return pPelanggan;
    }
}

int countPelanggan(listHotel L, string kode) {
    adrPelanggan t;
    adrHotel p = searchHotel(L, kode);
    int n = 0;

    if (p == NULL) {
        return 0;
    } else {
        t = pelanggan(p);

        while (t != NULL) {
            n++;
            t = next(t);
        }

        return n;
    }
}

void showAllPelanggan(listHotel L, string kode) {
    adrPelanggan pPelanggan;
    adrUser pUser;
    adrHotel p = searchHotel(L, kode);

    if (p == NULL) {
        cout << "Hotel dengan kode " << kode << " tidak dapat ditemukan!" << endl;
    } else {
        pPelanggan = pelanggan(p);

        if (pPelanggan == NULL) {
            cout << "Data pelanggan Hotel " << info(p).nama << " masih kosong!" << endl;
        } else {
            while (pPelanggan != NULL) {
                pUser = user(pPelanggan);
                cout << "Nama   : " << info(pUser).nama << endl;
                cout << "ID     : " << info(pUser).id << endl;
                cout << "Usia   : " << info(pUser).usia << endl;
                cout << endl;

                pPelanggan = next(pPelanggan);
            }
        }
    }
}

void menuHotel(listHotel &L) {
    string input, kode;
    infoHotel x;
    adrHotel p;

    while (true) {
        clearScreen();
        cout << "=============== MENU HOTEL ===============" << endl;
        cout << "1. Menambahkan Hotel" << endl;
        cout << "2. Mencari Hotel" << endl;
        cout << "3. Menampilkan Data Hotel" << endl;
        cout << "4. Menghapus Hotel" << endl;
        cout << "5. Menampilkan Banyak Hotel" << endl;
        cout << "0. Back" << endl;
        cout << endl;

        cout << "Pilih [1/2/3/4/5/0]: ";
        cin >> input;
        cout << endl;

        if (input == "1") {         // insert
            cout << "Masukkan Nama Hotel            : "; cin >> x.nama;
            cout << "Masukkan Kode Hotel            : "; cin >> x.kode;
            cout << "Masukkan Tahun Berdiri Hotel   : "; cin >> x.tahunBerdiri;
            cout << endl;

            p = createElmHotel(x);
            insertLastHotel(L, p);

            cout << "Data Hotel berhasil ditambahkan!" << endl;
            cout << endl;

        } else if (input == "2") {  // search
            cout << "Masukkan kode dari Hotel yang ingin dicari : "; cin >> kode;
            cout << endl;

            p = searchHotel(L, kode);

            if (p == NULL) {
                cout << "Data Hotel dengan kode " << kode << " tidak dapat ditemukan!" << endl;
                cout << endl;
            } else {
                cout << "Nama Hotel      : " << info(p).nama << endl;
                cout << "Kode Hotel      : " << info(p).kode << endl;
                cout << "Tahun Berdiri   : " << info(p).tahunBerdiri << endl;
                cout << endl;
            }

        } else if (input == "3") {  // show
            cout << "==================== DATA HOTEL ====================" << endl;
            showAllHotel(L);
            cout << "====================================================" << endl;
            cout << endl;

        } else if (input == "4") {  // delete
            cout << "Masukkan kode dari Hotel yang ingin dihapus : "; cin >> kode;
            cout << endl;

            p = deleteHotel(L, kode);

            if (p == NULL) {
                cout << "Data Hotel dengan kode " << kode << " tidak dapat ditemukan!" << endl;
                cout << endl;
            } else {
                cout << "Penghapusan Hotel berhasil!" << endl;
                cout << endl;
            }

        } else if (input == "5") {  // total
            cout << "Banyak data Hotel : " << countHotel(L) << endl;
            cout << endl;

        } else if (input == "0") {  // exit
            break;
        } else {
            cout << "Input anda salah." << endl;
            cout << endl;
        }

        cout << "Tekan Enter untuk lanjut...";
        pause();
        cout << endl;
    }
}

void menuUser(listUser &LU, listHotel &LH) {
    string input, id;
    infoUser x;
    adrUser p;
    adrHotel pHotel;
    adrPelanggan pPelanggan;

    while (true) {
        clearScreen();
        cout << "=============== MENU USER ===============" << endl;
        cout << "1. Menambahkan User" << endl;
        cout << "2. Mencari User" << endl;
        cout << "3. Menampilkan Data User" << endl;
        cout << "4. Menghapus User" << endl;
        cout << "5. Menampilkan Banyak User" << endl;
        cout << "0. Back" << endl;
        cout << endl;

        cout << "Pilih [1/2/3/4/5/0]: ";
        cin >> input;
        cout << endl;

        if (input == "1") {         // insert
            cout << "Masukkan Nama User     : "; cin >> x.nama;
            cout << "Masukkan ID User       : "; cin >> x.id;
            cout << "Masukkan Usia User     : "; cin >> x.usia;
            cout << endl;

            p = createElmUser(x);
            insertLastUser(LU, p);

            cout << "Data User berhasil ditambahkan!" << endl;
            cout << endl;

        } else if (input == "2") {  // search
            cout << "Masukkan ID dari User yang ingin dicari : "; cin >> id;
            cout << endl;

            p = searchUser(LU, id);

            if (p == NULL) {
                cout << "Data User dengan ID " << id << " tidak dapat ditemukan!" << endl;
                cout << endl;
            } else {
                cout << "Nama   : " << info(p).nama << endl;
                cout << "ID     : " << info(p).id << endl;
                cout << "Usia   : " << info(p).usia << endl;
                cout << endl;
            }

        } else if (input == "3") {  // show
            cout << "==================== DATA USER ====================" << endl;
            showAllUser(LU);
            cout << "===================================================" << endl;
            cout << endl;

        } else if (input == "4") {  // delete
            cout << "Masukkan ID dari User yang ingin dihapus : "; cin >> id;
            cout << endl;

            p = deleteUser(LU, id);

            if (p == NULL) {
                cout << "Data User dengan ID " << id << " tidak dapat ditemukan!" << endl;
                cout << endl;
            } else {
                pHotel = first(LH);

                while (pHotel != NULL) {
                    deletePelanggan(LH, info(pHotel).kode, id);
                    pHotel = next(pHotel);
                }

                cout << "Penghapusan User berhasil!" << endl;
                cout << endl;
            }

        } else if (input == "5") {  // total
            cout << "Banyak User : " << countUser(LU) << endl;
            cout << endl;

        } else if (input == "0") {  // exit
            break;
        } else {
            cout << "Input anda salah." << endl;
        }

        cout << "Tekan Enter untuk lanjut...";
        pause();
        cout << endl;
    }
}

void menuRelasi(listHotel &LH, listUser &LU) {
    string input, kode, id;
    adrHotel pHotel;
    adrUser pUser;
    adrPelanggan pPelanggan;
    int n;

    while (true) {
        clearScreen();
        cout << "=============== MENU PELANGGAN ===============" << endl;
        cout << "1. Menambahkan Pelangganan Hotel" << endl;
        cout << "2. Mencari Data User Pelangganan" << endl;
        cout << "3. Menampilkan Seluruh Data Pelangganan" << endl;
        cout << "4. Menghapus Pelangganan Hotel" << endl;
        cout << "5. Menampilkan Banyak Pelangganan Hotel" << endl;
        cout << "0. Back" << endl;
        cout << endl;

        cout << "Pilih [1/2/3/4/5/0]: ";
        cin >> input;
        cout << endl;

        if (input == "1") {         // insert
            if (countHotel(LH) == 0) {
                cout << "Data Hotel masih kosong! Isikan dulu." << endl;
                cout << endl;

                cout << "Tekan Enter untuk lanjut...";
                pause();
                cout << endl;
                continue;
            }

            if (countUser(LU) == 0) {
                cout << "Data User masih kosong! Isikan dulu." << endl;
                cout << endl;

                cout << "Tekan Enter untuk lanjut...";
                pause();
                cout << endl;
                continue;
            }

            cout << "Masukkan kode dari Hotel yang ingin dicari : "; cin >> kode;
            cout << "Masukkan ID dari User yang ingin dicari    : "; cin >> id;
            cout << endl;

            pHotel = searchHotel(LH, kode);
            pUser = searchUser(LU, id);

            if (pHotel == NULL) {
                cout << "Data Hotel dengan kode " << kode << " tidak dapat ditemukan!" << endl;
                cout << endl;
            } else if (pUser == NULL) {
                cout << "Data User dengan ID " << id << " tidak dapat ditemukan!" << endl;
                cout << endl;
            } else {
                addPelanggan(LH, LU, kode, id);

                cout << "Data Pelangganan berhasil ditambahkan!" << endl;
                cout << endl;
            }

        } else if (input == "2") {  // search
            if (countHotel(LH) == 0) {
                cout << "Data Hotel masih kosong! Isikan dulu." << endl;
                cout << endl;

                cout << "Tekan Enter untuk lanjut...";
                pause();
                cout << endl;
                continue;
            }

            if (countUser(LU) == 0) {
                cout << "Data User masih kosong! Isikan dulu." << endl;
                cout << endl;

                cout << "Tekan Enter untuk lanjut...";
                pause();
                cout << endl;
                continue;
            }

            cout << "Masukkan kode dari Hotel yang ingin dicari : "; cin >> kode;
            pHotel = searchHotel(LH, kode);

            if (pHotel == NULL) {
                cout << "Data Hotel dengan kode " << kode << " tidak dapat ditemukan!" << endl;
                cout << endl;

                cout << "Tekan Enter untuk lanjut...";
                pause();
                cout << endl;
                continue;
            } else if (pelanggan(pHotel) == NULL) {
                cout << "Data Hotel " << info(pHotel).nama << " masih kosong!" << endl;
                cout << endl;

                cout << "Tekan Enter untuk lanjut...";
                pause();
                cout << endl;
                continue;
            }

            cout << "Masukkan ID dari User yang ingin dicari : "; cin >> id;
            cout << endl;

            pUser = searchUser(LU, id);

            if (pUser == NULL) {
                cout << "Data User dengan ID " << id << " tidak dapat ditemukan!" << endl;
                cout << endl;
            } else {
                pPelanggan = searchPelanggan(LH, kode, id);

                cout << "Nama   : " << info(user(pPelanggan)).nama << endl;
                cout << "ID     : " << info(user(pPelanggan)).id << endl;
                cout << "Usia   : " << info(user(pPelanggan)).usia << endl;
                cout << endl;
            }

        } else if (input == "3") {  // show all
            if (countHotel(LH) == 0) {
                cout << "Data Hotel masih kosong! Isikan dulu." << endl;
                cout << endl;

                cout << "Tekan Enter untuk lanjut...";
                pause();
                cout << endl;
                continue;
            }

            if (countUser(LU) == 0) {
                cout << "Data User masih kosong! Isikan dulu." << endl;
                cout << endl;

                cout << "Tekan Enter untuk lanjut...";
                pause();
                cout << endl;
                continue;
            }

            cout << "Masukkan kode dari Hotel yang ingin dicari : "; cin >> kode;
            cout << endl;

            pHotel = searchHotel(LH, kode);

            if (pHotel == NULL) {
                cout << "Data Hotel dengan kode " << kode << " tidak dapat ditemukan!" << endl;
                cout << endl;
            } else {
                pPelanggan = pelanggan(pHotel);

                if (pPelanggan == NULL) {
                    cout << "Data Hotel " << info(pHotel).nama << " masih kosong!" << endl;
                    cout << endl;
                } else {
                    while (pPelanggan != NULL) {
                        pUser = user(pPelanggan);
                        cout << "Nama   : " << info(pUser).nama << endl;
                        cout << "ID     : " << info(pUser).id << endl;
                        cout << "Usia   : " << info(pUser).usia << endl;
                        cout << endl;

                        pPelanggan = next(pPelanggan);
                    }
                }

            }

        } else if (input == "4") {  // delete
            if (countHotel(LH) == 0) {
                cout << "Data Hotel masih kosong! Isikan dulu." << endl;
                cout << endl;

                cout << "Tekan Enter untuk lanjut...";
                pause();
                cout << endl;
                continue;
            }

            if (countUser(LU) == 0) {
                cout << "Data User masih kosong! Isikan dulu." << endl;
                cout << endl;

                cout << "Tekan Enter untuk lanjut...";
                pause();
                cout << endl;
                continue;
            }

            cout << "Masukkan kode dari Hotel yang ingin dicari : "; cin >> kode;

            pHotel = searchHotel(LH, kode);

            if (pHotel == NULL) {
                cout << endl;
                cout << "Data Hotel dengan kode " << kode << " tidak dapat ditemukan!" << endl;
                cout << endl;

                cout << "Tekan Enter untuk lanjut...";
                pause();
                cout << endl;
                continue;
            } else if (pelanggan(pHotel) == NULL) {
                cout << endl;
                cout << "Data User dengan ID " << id << " tidak dapat ditemukan!" << endl;
                cout << endl;

                cout << "Tekan Enter untuk lanjut...";
                pause();
                cout << endl;
                continue;
            }

            cout << "Masukkan ID dari User yang ingin dicari : "; cin >> id;
            cout << endl;

            pUser = searchUser(LU, id);

            if (pUser == NULL) {
            } else {
                pPelanggan = deletePelanggan(LH, kode, id);

                cout << "Penghapusan pelanggan berhasil!" << endl;
                cout << endl;
            }

        } else if (input == "5") {  // count
            if (countHotel(LH) == 0) {
                cout << "Data Hotel masih kosong! Isikan dulu." << endl;
                cout << endl;

                cout << "Tekan Enter untuk lanjut...";
                pause();
                cout << endl;
                continue;
            }

            cout << "Masukkan ID dari Hotel yang ingin dicari     : "; cin >> kode;
            cout << endl;

            pHotel = searchHotel(LH, kode);

            if (pHotel == NULL) {
                cout << "Data Hotel dengan kode " << kode << " tidak dapat ditemukan!" << endl;
                cout << endl;
            } else {
                n = countPelanggan(LH, kode);
                cout << "Jumlah pelanggan pada Hotel " << info(pHotel).nama << " adalah " << n << " User" << endl;
                cout << endl;
            }

        } else if (input == "0") {  // exit
            break;
        } else {
            cout << "Input anda salah" << endl;
            cout << endl;
        }

        cout << "Tekan Enter untuk lanjut...";
        pause();
        cout << endl;
    }
}

void pause() {
    fflush(stdin);
    getchar();
}

void clearScreen() {
    cout << "\033[H\033[2J" << flush;
}
