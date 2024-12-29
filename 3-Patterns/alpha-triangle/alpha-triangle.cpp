#include<iostream>

void alpha_triangle(int n)
{
    char start_char = 'A' + (n - 1);

    for (int i = 0; i < n; i++)
    {
        for (char ch = start_char; ch >= start_char - i; ch--)
        {
            std::cout << ch << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int n;
    std::cout<<"Enter a number :";
    std::cin>>n;

    alpha_triangle(n);
}