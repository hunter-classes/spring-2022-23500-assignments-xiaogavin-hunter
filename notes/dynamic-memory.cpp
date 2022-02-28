#include <iostream>

int main() {
    int a = 11;
    int b = 222; 
    int ar[4] = { 10, 20, 30, 40 };

    int *p1, *p2;
    int i; 

    p1 = &a;
    p2 = &b;
    
    std::cout << "p1 and a " << &a << " " << p1 << " " << *p1 << std::endl;
    std::cout << "p2 and b " << &b << " " << p2 << " " << *p2 << std::endl; 

    *p1 = 400;

    std::cout << a << " " << *p1 << std::endl;

    return 0;
}