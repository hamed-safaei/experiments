#include <iostream>
using namespace std;
void input(int [10]);
template <typename T>
void sort(T[], int);
void print(int[10]);

int main()
{
  int A[10], B[150];
  input(A);
  sort(A, 10);
  sort(B, 150);
  print(A);
}
void input(int B[10])
{
  for (int i = 0; i < 10;i++)
  {
    cout << "B[" << i << "] = ";
    cin >> B[i];
  }
}
template <typename T>
void sort(T C[], int n)
{
  for(int i = 1; i < n; i++)
    for(int j = 0; j < n - i; j++)
      if (C[j] > C[j + 1])
      {
        T temp = C[j];
        C[j] = C[j + 1];
        C[j + 1] = temp;
      }
}
void print(int B[10])
{
  for (int i = 0; i < 10; i++)
    cout << B[i] << '\t';
}
