#include <iostream>

void number_crown(int n)
{
    int space = 2 * (n - 1); 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << j << " ";
        }

        for (int j = 1; j <= space; j++) {
            std::cout << " ";
        }

        for (int j = 1; j <= (n - i); j++) {
            std::cout << "  "; 
        }

        for (int j = i; j >= 1; j--) {
            std::cout << j << " ";
        }

        std::cout << std::endl;
        space -= 2; 
}
}

int main()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    number_crown(n);
    return 0;
}
