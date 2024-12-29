#include<iostream>

void nStarDiamond(int n) {
	for(int i=0; i < n; i++)
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

    nStarDiamond(n);

    return 0;
}