#include "CLL_1.hpp"
#include <iostream>

using namespace std;

void createList_1302204115(List &L) {
    first(L) = nil;
    last(L) = nil;
}
/*
    Procedure createList(input/output L:List)
    kamus
    algoritma
        first(L) <- NIL
        last(L) <- NIL
*/
address createNewElm_1302204115(string NIM, string nama, int usia) {
    address P = new elm;
    
    nama(P) = nama;
    NIM(P) = NIM;
    usia(P) = usia;
    
    next(P) = nil;
    return P;
    return 0;
}
/*
    Function createNewElmt (nim, nama: string, usia: integer) → address
    kamus
    algoritma
         alokasi(P) <- new elm
         nama(P) <- nama;
         NIM(P) <- NIM;
         usia(P) <- usia;
         
         next(P) <- nil;
         return P
*/
bool isEmpty_1302204115(List L) {
    if(first(L) == nil) {
        return true;
    } else {
        return false;
    }
}
/*
    Function isEmpty(L:List) → boolean
    kamus
    algoritma
         if(first(L) == NIL) then
            return true
         else
            return false
*/
void pemilihan_1302204115(List L, group &G) {
    if(isEmpty_1302204115(L)) {
        return;
    } else {
        address P = new elm;
        int min_usia, max_usia;
        min_usia = usia(P);
        max_usia = usia(P);
        do {
            if(min_usia >= usia(P)) {
                min_usia = usia(P);
                G.bendahara = P;
            }
            if(max_usia <= usia(P)) {
                max_usia = usia(P);
                G.ketua = P;
            }
            P = next(P);
        } while(P != first(L));
    }
}
/*
    Procedure pemilihan(input L: List; input/output G: group)
    kamus
        min_usia, max_usia : integer
    algoritma
         if(isEmpty(L)) then
             return
         else
             alokasi(P) <- new elm
             min_usia <- usia(P)
             max_usia <- usia(P)
             repeat
                if(min_usia >= usia(P)) then
                    min_usia <- usia(P)
                    G.Bendahara <- P
                if(max_usia <= usia(P)) then
                    max_usia <- usia(P)
                    G.ketua <- P
                P = next(P)
             until while(P != first(L))
*/
void tambahAnggota_1302204115(List &L, string NIM, string nama, int usia) {
    address P = createNewElm_1302204115(NIM, nama, usia);
    if(first(L) == nil) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
        next(last(L)) = first(L);
    }
}
/*
    Procedure tambahAnggota(input/output L:List; input nim, nama: string, usia: integer)
    kamus
    algoritma
         alokasi(P) <- createNewElm(NIM, nama, usia)
         if(first(L) == NIL) then
            first(L) <- P
            last(L) <- P
         else
            next(P) <- first(L)
            first(L) <- P
            next(last(L)) <- first(L)
*/
void tampilData_1302204115(List &L) {
    address P = first(L);
    int i = 1;
    if(P == nil) {
        cout << "Data tidak ditemukan\n";
    } else {
        do {
            cout << "=============================\n";
            cout << "Data ke-" << i << endl;
            cout << "Nama : " << nama(P) << endl;
            cout << "NIM  : " << NIM(P) << endl;
            cout << "Usia : " << usia(P) << endl;
            cout << "=============================\n";
            i++;
            P = next(P);
        } while(P != first(L));
    }
    cout << "Data telah ditampilkan\n";
}
/*
    Procedure pemilihan(input L: List; input/output G: group)
    kamus
        i : integer
    algoritma
         if(P == nil) then
             output ("Data tidak ditemukan\n")
         else
            repeat
                 output ("=============================\n")
                 output ("Data ke-", i)
                 output ("Nama : ", nama(P))
                 output ("NIM  : ", NIM(P))
                 output ("Usia : ", usia(P))
                 output "=============================\n"
                 i++
                 P <- next(P)
            until while(P != first(L));
         }
         output("Data telah ditampilkan\n")
*/
