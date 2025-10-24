#include <iostream>
using namespace std;
unsigned fibo(unsigned);

int main()
{
  unsigned int n;
  cout << "Enter the statement number : ";
  cin >> n;
  cout << "fibonacci ( " << n << " ) = " << fibo(n);
}
unsigned fibo(unsigned m)
{
  if (m == 1 || m == 2)
    return 1;
  return fibo(m - 1) + fibo(m - 2);
}