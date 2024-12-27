#include<iostream>

void rev_num_triangle(int n) {
	for(int i=1; i <= n; i++)
	{
		for(int j=1; j<=n-i+1; j++)
		{
			std::cout<<j <<" ";
		}
	std::cout<<"\n";
	}
}

int main()
{
    int n;
    std::cout<<"Enter a number: 0";
    std::cin>>n;

    rev_num_triangle(n);

    return 0;
}
