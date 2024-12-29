#include<iostream>

void star_triangle(int n) {
	for(int i=n-1; i >=0 ; i--)
	{
		for(int j=0; j<n-i-1; j++)
		{
			std::cout<<" ";
		}
        for(int j=0; j<2*i+1; j++)
		{
			std::cout<<"*";
		}
        for(int j=0; j<n-i+1; j++)
		{
			std::cout<<" ";
		}

	std::cout<<std::endl;
	}
}

int main()
{
    int n;
    std::cout<<"Enter a number: 0";
    std::cin>>n;

    star_triangle(n);

    return 0;
}