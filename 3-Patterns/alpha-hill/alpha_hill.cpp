#include<iostream>

void alpha_hill(int n)
{
for(int i=0; i<n; i++)
{
    for(int j=0; j<n-i-1; j++)
    {
        std::cout << "  ";
    }

    //characters
    char ch = 'A';
    int breakpoint = (2 * i + 1) / 2;

    for (int j = 1; j <= 2 * i + 1; j++)
    {
        std::cout << ch << " ";
    if(j <= breakpoint) ch++; 
    else ch--;
    }

     for(int j=0; j<n-i-1; j++)
    {
        std::cout<<"  ";
    }

    std::cout<<std::endl;
}
}

int main()
{
    int n;
    std::cout<<"Enter a number :";
    std::cin>>n;

    alpha_hill(n);
}