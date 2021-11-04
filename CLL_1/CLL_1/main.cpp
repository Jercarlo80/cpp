#include <iostream>
#include "CLL_1.hpp"

using namespace std;

int main() {
    // insert code here...
    List L;
    group G;
    createList_1302204115(L); 
    tampilData_1302204115(L);
    tambahAnggota_1302204115(L, "1130501", "Andi", 19);
    tambahAnggota_1302204115(L, "1130502", "Tono", 21);
    tambahAnggota_1302204115(L, "1130503", "Ayu", 24);
    tambahAnggota_1302204115(L, "1130504", "Budi", 18);
    tampilData_1302204115(L);
    pemilihan_1302204115(L, G);
    
    cout << "\nKetua     : " << nama(G.ketua);
    cout << "\nBendahara : " << nama(G.bendahara);

    
    return 0;
}
