#include<iostream>

void nForest(int n) {
	for(int i=0; i < n; i++)
	{
		for(int j=0; j < n; j++)
		{
			std::cout<<"* ";
		}
	std::cout<<"\n";
	}
}

int main()
{
    int n;
    std::cout<<"Enter a number: 0";
    std::cin>>n;

    nForest(n);

    return 0;
}
