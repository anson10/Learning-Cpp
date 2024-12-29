#include<iostream>

void number_pattern(int n)
{
    for(int i=0; i<2*n-1; i++){
        for(int j=0; j<2*n-1; j++)
        {
            int top = i;
            int down = (2*n - 2) - i;
            int left = j;
            int right = (2*n - 2) -j;

            std::cout << (n - std::min(std::min(top, down), std::min(left, right)));
        }
        std::cout<<std::endl;
    }
}
int main()
{
    int n;
    std::cout<<"Enter a number: ";
    std::cin>>n;

    number_pattern(n);
}