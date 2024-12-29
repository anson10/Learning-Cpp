#include<iostream>

void ninja_pattern(int n)
{
    for(int i=0; i< n; i++)
    {
        for(int j = 0;j< n; j++)
        {
            if(i == 0 || j==0 || i == n-1 || j == n-1)
            {
                std::cout<< "*";
            }
            else std::cout<<" ";
        }
        std::cout<<std::endl;
    }
}
int main()
{
    int n;
    std::cout<<"Enter a number: ";
    std::cin>>n;

    ninja_pattern(n);
}