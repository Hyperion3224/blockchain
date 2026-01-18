#include <iostream>

int main()
{
    int *x = new int(10);
    std::cout << *x;

    delete x;
}