#include "CLL_2.hpp"
#include <iostream>

using namespace std;

void createList(List &L){
    first(L) = nil;
    last(L) = nil;
}
/*
    Procedure createList(input/output L : List)
    kamus
    algoritma
        first(L) <- nil
        last(L) <- nil
*/

address createNewElm(string judul, string penyanyi){
    address P = new elmList;
    info(P).judul = judul;
    info(P).artist = penyanyi;
    next(P) = nil;
    prev(P) = nil;
    return P;
}
/*
    Function createNewElm(input judul, penyanyi : string) -> address
    kamus
    algoritma
        alokasi(P) <- elmList
        info(P).judul <- judul
        info(P).artist <- penyanyi
        next(P) <- nil
        prev(P) <- nil
        return P
*/
void insertLast(List &L, address P){
    if (first(L) == nil) {
        first(L) = P;
        last(L) = P;
        next(P) = first(L);
        prev(P) = last(L);
    }
    else {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
        next(P) = first(L);
        prev(first(L)) = last(L);
    }
}
/*
    Procedure insertLast(input/output L : List, input P : address)
    kamus
    algoritma
         if (first(L) == nil) then
             first(L) <- P
             last(L) <- P
             next(P) <- first(L)
             prev(P) <- last(L)
         else
             prev(P) <- last(L)
             next(last(L)) <- P
             last(L) <- P
             next(P) <- first(L)
             prev(first(L)) <- last(L)
*/
void add(List &L, string judul, string penyanyi){
    address P = searchLagu(judul,penyanyi,L);
    if (P != nil) {
        return;
    }
    P = createNewElm(judul,penyanyi);
    insertLast(L,P);
}
/*
    Procedure add(input/output L : List, input judul, penyanyi : string)
    kamus
        P : address
    algoritma
        alokasi(P) <- searchLagu(judul,penyanyi,L)
        if(P != nil) then
            return
        P <- createNewElm(judul,penyanyi);
        insertLast(L,P);
        
*/
void deleteFirst(List &L, address P){
    if (next(first(L)) == first(L)){
        P = first(L);
        next(P) = nil;
        prev(P) = nil;
        first(L) = nil;
        last(L) = nil;
    } else {
        P = first(L);
        next(prev(first(L))) = next(first(L));
        prev(next(first(L))) = prev(first(L));
        first(L) = next(first(L));
        next(P) = nil;
        prev(P) = nil;
    }
}
/*
    Procedure deleteFirst(input/output L : List, input P : address)
    kamus
    algoritma
         if (next(first(L)) == first(L)) then
             P <- first(L)
             next(P) <- nil
             prev(P) <- nil
             first(L) <- nil
             last(L) <- nil
         else
             P <- first(L)
             next(prev(first(L))) <- next(first(L))
             prev(next(first(L))) <- prev(first(L))
             first(L) <- next(first(L))
             next(P) <- nil
             prev(P) <- nil
         
*/
void deleteAfter(List &L, address prec, address P){
    P = next(prec);
    next(prec) = next(P);
    prev(next(P)) = prec;
    next(P) = nil;
    prev(P) = nil;
}
/*
    Procedure deleteAfter(input/output L : List, input prec : address, input P : address)
    kamus
    algoritma
         P <- next(prec);
         next(prec) <- next(P);
         prev(next(P)) <- prec;
         next(P) <- nil;
         prev(P) <- nil;
*/
address searchLagu(string judul, string penyanyi, List L){
    address P = first(L);
    if (P == nil) return nil;
    do {
        if ((info(P).judul == judul)&&(info(P).artist == penyanyi)) {
            return P;
        }
        P = next(P);
    } while (P != first(L));
    return nil;

}
/*
    Function searchLagu(input judul, penyanyi : string, input L : List) -> address
    kamus
        P : address
    algoritma
        alokasi(P) <- first(L)
        if(P == nil) then
            return nil;
        repeat
            if((info(P).judul == judul) && (info(P).artist == penyanyi)) then
                return P
            P <- next(P)
        until while(P != first(L))
        return nil;
*/
void moveToEnd(string judul, string penyanyi, List &L){
    address P = searchLagu(judul,penyanyi,L);
    address Q = P;
    if (P == first(L)) {
        deleteFirst(L,P);
    } else if(P == last(L)){
        return;
    } else {
        deleteAfter(L,prev(P),P);
    }
    insertLast(L,Q);
}
/*
    Procedure moveToEnd(input judul, penyanyi : string, input/output L : List)
    kamus
    algoritma
    alokasi(P) <- searchLagu(judul,penyanyi,L)
    address Q <- P
     if (P == first(L)) then
         deleteFirst(L,P);
     else if(P == last(L)) then
         return;
     else
         deleteAfter(L,prev(P),P)
     insertLast(L,Q)
 
*/
void playLaguToLagu(string judul1, string penyanyi1, string judul2, string penyanyi2, List L){
    address P = searchLagu(judul1,penyanyi1,L);
    do {
        cout << info(P).judul << " - " << info(P).artist << endl;
        P = next(P);
    } while(!((info(P).judul == judul2)&&(info(P).artist == penyanyi2)));
    cout << info(P).judul << " - " << info(P).artist << endl;
    cout << "=====Selesai=====" << endl;
}
/*
    Procedure playLaguToLagu (In judul1, penyanyi1, judul2, penyanyi2: String, L: List)
    Kamus
        P : address
    algoritma
        alokasi(P) <- searchLagu(judul1,penyanyi1,L)
        repeat
            output(info(P).judul, " - ", info(P).artist, "\n")
            P <- next(P)
        until while(!((info(P).judul == judul2) && (info(P).artist == penyanyi2)))
        output(info(P).judul, " - ", info(P).artist, "\n")
        output("=====Selesai=====\n")
*/
void printList(List L){
    address P = first(L);
    if (P == nil){
        cout << "Data kosong" << endl;
    } else {
        do {
            cout << info(P).judul << " - " << info(P).artist << endl;
            P = next(P);
        } while(P != first(L));
        cout << "=====Selesai=====" << endl;
    }
}
/*
    Procedure printList(input L : List)
    kamus
        P : address
    algoritma
        alokasi(P) <- first(L)
        if(P == nil) then
            output("Data kosong\n")
        else
            repeat
                output(info(P).judul, " - ", info(P).artist, "\n")
                P <- next(P)
            until while(P != first(L))
            output("=====Selesai=====\n")
*/
