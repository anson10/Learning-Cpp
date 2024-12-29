#include<iostream>

void binary_triangle(int n)
{
int start = 1;
for(int i=1; i<=n; i++){
    start = (i % 2 == 0) ? 0: 1;
    for(int j=1; j<=i; j++)
    {
        std::cout<< start <<" ";
        start = 1 - start;
    }
    std::cout<<std::endl;
}
}

int main()
{
    int n;
    std::cout<<"Enter a number: ";
    std::cin>>n;

    binary_triangle(n);
}
