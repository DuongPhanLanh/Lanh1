
#include<iostream>
using namespace std;
int main()
{
  int n;
  long S = 0;
  cout<<"\nNhập vào số n: ";
  cin>> n;
  for(int i = 1; i <= n; i++)
  {
     S = S + i * i;
  }
 
  cout<<"\nTổng 1^2 + 2^2 + ... + " << n << " là: "<< S;
}
