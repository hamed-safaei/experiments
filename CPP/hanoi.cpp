#include <iostream>
using namespace std;
void hanoi(int, char, char, char);

int main()
{
  int x;
  cout << "Enter the number of disks : ";
  cin >> x;
  hanoi(x, 'A', 'B', 'C');
}
void hanoi(int n, char source, char help, char target)
{
  if (n == 1)
  {
    cout << source << " ----> " << target << endl;
    return;
  }
  hanoi(n - 1, source, target, help);
  cout << source << " ----> " << target << endl;
  hanoi(n - 1, help, source, target);
}