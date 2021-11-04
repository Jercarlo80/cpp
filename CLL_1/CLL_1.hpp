#ifndef CLL_1_hpp
#define CLL_1_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

#define first(L) (L).first

#define NIM(P) (P) -> NIM
#define nama(P) (P) -> nama
#define usia(P) (P) -> usia
#define next(P) (P) -> next

#define last(L) (L).last
#define nil NULL

typedef struct elm *address;
//  type address: pointer to elm
struct elm {
    string NIM;
    string nama;
    int usia;
    address next;
};
/*
type elm: <
 nim, nama: string
 umur: integer
 next: address >
*/
struct List {
    address first;
    address last;
};
/*
 type list : <
 first, last: address
 >
*/
struct group {
    address ketua;
    address bendahara;
};
/*
 type group : <
 ketua, bendahara: address
 >
*/


//  Function createNewElmt (nim, nama: string, usia: integer) → address
address createNewElm_1302204115(string NIM, string nama, int usia);

//  Function isEmpty(L:List) → boolean
bool isEmpty_1302204115(List L);

//  Procedure pemilihan(input L: List; input/output G: group)
void pemilihan_1302204115(List L, group &G);

//  Procedure tambahAnggota(input/output L:List; input nim, nama: string, usia: integer)
void tambahAnggota_1302204115(List &L, string NIM, string nama, int usia);

//  Procedure createList(input/output L:List)
void createList_1302204115(List &L);

//  Procedure tampilData(input/output L:List)
void tampilData_1302204115(List &L);

#endif /* CLL_1_hpp */
