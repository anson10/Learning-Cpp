#include<iostream>

void n_2_Forest(int n) {
	for(int i=0; i < n; i++)
	{
		for(int j=0; j <= i; j++)
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

    n_2_Forest(n);

    return 0;
}
