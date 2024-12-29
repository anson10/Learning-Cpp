#include<iostream>

void inc_letter_triangle(int n)
{
    for(int i=1; i<=n; i++){
        char ch = 'A';
        for (int j=1; j<=i; j++)
        {
            std::cout<<ch << " ";
            ch+=1;
        }
        std::cout<<std::endl;
    }
}

int main()
{
    int n;
    std::cout<<"Enter a number: ";
    std::cin>>n;

    inc_letter_triangle(n);
}
