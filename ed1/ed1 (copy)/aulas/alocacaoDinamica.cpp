#include <iostream>
#include <string>
using namespace std;

int main(){

    int* p1 = (int*) malloc(sizeof(int));
    *p1 = 200;
    printf("\n");
    printf("p1: %u\n", p1);
    printf("*p1: %u\n", *p1);
    printf("&p1: %u\n", &p1);

    int* p2 = new int(250);
    // *p2 = 50;
    printf("\n");
    
    printf("p2: %u\n", p2);
    printf("*p2: %u\n", *p2);
    printf("&p2: %u\n", &p2);

    free(p1);
    delete p2;
    return 0;
}