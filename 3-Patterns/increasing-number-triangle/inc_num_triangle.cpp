#include<iostream>

void inc_num_triangle(int n)
{
    int number = 1;
    for(int i=1; i<=n; i++){
        for (int j=1; j<=i; j++)
        {
            std::cout<<number << " ";
            number+=1;
        }
        std::cout<<std::endl;
    }
}

int main()
{
    int n;
    std::cout<<"Enter a number: ";
    std::cin>>n;

    inc_num_triangle(n);
}
