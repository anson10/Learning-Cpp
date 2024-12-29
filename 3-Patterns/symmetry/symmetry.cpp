#include <bits/stdc++.h>

void symmetry(int n)
{
    int spaces = 2*n - 2;

    for(int i=1; i<=2*n-1; i++){
        int stars = i;
        if(i > n) stars = 2*n - i;
        for(int j = 1; j<=stars; j++)
        {
            std::cout<<"*"<<"  ";
        }
        for(int j =1; j<=spaces; j++)
        {
            std::cout<<" ";
        }
        for(int j=1; j<=stars; j++)
        {
            std::cout<<"*"<<"  ";
        }
        std::cout<<std::endl;
        if(i<n) spaces-=2;
        else spaces+=2;
    }

}

int main()
{   
  
    int n;
    std::cout<<"Enter a number: ";
    std::cin>>n;

    
    symmetry(n);

    return 0;
}