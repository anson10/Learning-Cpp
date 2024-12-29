#include<iostream>

void alpha_ramp(int n)
{
    char ch = 'A';

    for(int i=1; i<=n; i++){
        for (int j=1; j<=i; j++)
        {
            std::cout<<ch << " ";
        }
        ch+=1;
        std::cout<<std::endl;
    }
}

int main()
{
    int n;
    std::cout<<"Enter a number: ";
    std::cin>>n;

    alpha_ramp(n);
}
