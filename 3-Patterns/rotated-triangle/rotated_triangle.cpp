#include<iostream>

void rotated_triangle(int n)
{
for(int i=0; i<=2*n-1; i++)
{
    int asterisk = i;
    if(i>n) asterisk = 2*n-i;
    for(int j=1; j<=asterisk; j++)
    {
        std::cout<<"*";
    }
    std::cout<<std::endl;
}
}

int main()
{
    int n;
    std::cout<<"Enter a number: ";
    std::cin>>n;

    rotated_triangle(n);
}