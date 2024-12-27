#include<iostream>

void n_triangles(int n) {
	for(int i=1; i < n; i++)
	{
		for(int j=1; j <= i; j++)
		{
			std::cout<< j;
		}
	std::cout<<"\n";
	}
}

int main()
{
    int n;
    std::cout<<"Enter a number: 0";
    std::cin>>n;

    n_triangles(n);

    return 0;
}
