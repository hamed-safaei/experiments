#include <iostream>
using namespace std;
long int fact(int);

int main()
{
  int x;
  cout << "Enter an integer number : ";
  cin >> x;
  cout << x << "! = " << fact(x);

}
long int fact(int n)
{
  if (!n)
    return 1;
  return n * fact(n - 1);
}