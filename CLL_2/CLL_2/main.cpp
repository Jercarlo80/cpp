#include <iostream>
#include "CLL_2.hpp"

using namespace std;

int main() {

    List L;
    createList(L);
    printList(L);
    add(L,"ALONE","Marshmello");
    add(L,"Pamit","Tulus");
    add(L,"Kali Kedua","Raisa");
    printList(L);
    cout << endl;
    moveToEnd("ALONE","Marshmello",L);
    printList(L);
    playLaguToLagu("ALONE","Marshmello","Kali Kedua","Raisa",L);
    
    return 0;
    
}
