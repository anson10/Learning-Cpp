#include <bits/stdc++.h>

void symmetric_void(int N)
{
      int start = 0;
      for(int i=0;i< N;i++){
          
          for(int j=1;j<=N-i;j++){
              std::cout<<"*";
          }
          
          for(int j=0;j<start;j++){
              std::cout<<" ";
          }
          
          for(int j=1;j<=N-i;j++){
              std::cout<<"*";
          }
          
          start+=2;
          std::cout<<std::endl;
      }
      
      start = 2*N -2;
      for(int i=1;i<=N;i++){
          
          for(int j=1;j<=i;j++){
              std::cout<<"*";
          }
          
          for(int j=0;j<start;j++){
              std::cout<<" ";
          }
          
          for(int j=1;j<=i;j++){
              std::cout<<"*";
          }
          
        start-=2;
        std::cout<<std::endl;
      }
      
}

int main()
{   
  
    int n;
    std::cout<<"Enter a number: ";
    std::cin>>n;

    
    symmetric_void(n);

    return 0;
}