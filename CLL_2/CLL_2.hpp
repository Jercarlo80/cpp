#ifndef CLL_2_hpp
#define CLL_2_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

#define first(L) (L).first
#define info(P) (P) -> info
#define next(P) (P) -> next
#define prev(P) (P) -> prev
#define nil NULL
#define last(L) (L).last

struct lagu {
    string judul;
    string artist;
};
/*
 type lagu: <
 judul, artist : string
 >
*/

typedef lagu infotype;
//  type infotype: lagu
typedef struct elmList* address;
//  type address: pointer to elmList

struct elmList {
    infotype info;
    address next;
    address prev;
};
/*
 type elmList: <
    info : infotype
    next : address
    prev : address
 >
*/

struct List {
    address first;
    address last;
};
/*
 type List: <
    first : address
    last : address
 >
*/

void createList(List &L);
//  Procedure createList(input/output L : List)

address createNewElm(string judul, string penyanyi);
//  Function createNewElm(input judul, penyanyi : string) -> address

void insertLast(List &L, address P);
//   Procedure insertLast(input/output L : List, input P : address

void add(List &L, string judul, string penyanyi);
//  Procedure add(input/output L : List, input judul, penyanyi : string)

void printList(List L);
//  Procedure deleteFirst(input/output L : List, input P : address)

void deleteFirst(List &L, address P);
//  Procedure deleteAfter(input/output L : List, input prec : address, input P : address)

void deleteAfter(List &L, address prec, address P);
//  Function searchLagu(input judul, penyanyi : string, input L : List) -> address

address searchLagu(string judul, string penyanyi, List L);
//  Procedure moveToEnd(input judul, penyanyi : string, input/output L : List)

void moveToEnd(string judul, string penyanyi, List &L);
//  Procedure playLaguToLagu (In judul1, penyanyi1, judul2, penyanyi2: String, L: List)

void playLaguToLagu(string judul1, string penyanyi1, string judul2, string penyanyi2, List L);
//   Procedure printList(input L : List)

#endif /* CLL_2_hpp */
