
#include <iostream>
using namespace std;
int input(int[] , int) ;

template <typename T>
void sort(T [], int n)  ;

bool binarySearch(int [], int n, int x);
int main()
{
 int A[10], item;
 item = input(A, 10);
 sort(A, 10);
 if (binarySearch(A, 10, item))
  cout << "search is successful";
 else
  cout << "search is unsuccessful";
}

bool binarySearch(int B[], int n, int x) 
{
 int beg = 0, end = n-1, mid = (beg + end) / 2;
 while (beg <= end)
 {
  if (B[mid] == x)
   return true;
  if (x > B[mid])
   beg = mid + 1;
  else
   end = mid - 1;
  mid = (beg + end) / 2;
 }
 return false;
}

int input(int B[], int n)
{
 cout << "Enter 10 integer numbers \n";
 for (int i = 0; i < n; i++)
 {
  cout << "A [ " << i + 1 << " ] = ";
  cin >> B[i];
 }
 int x;
 cout << "Enter an integer number for search : ";
 cin >> x;
 return x;
}

template <typename T>
void sort(T B[], int n) 
{
 for (int i = 1; i < n; i++)
  for (int j = 0; j < n - i; j++)
   if (B[j] > B[j + 1]) 
   {
    T temp;
    temp = B[j];
    B[j] = B[j + 1];
    B[j + 1] = temp;
   }
}