#include <iostream>
using namespace std; 
 
int main() 
{ 
 int A[10]; 
 cout << "Please enter 10 integer numbers : \n"; 
 for (int i = 0; i < 10; i++) 
 { 
  cout << "A [" << i << "] = "; 
  cin >> A[i]; 
 } 
 for (int i = 1; i < 10; i++) 
  for (int j = 0; j < 10 - i; j++) 
   if (A[j] > A[j + 1]) 
   { 
    int temp; 
    temp = A[j]; 
    A[j] = A[j + 1]; 
    A[j + 1] = temp; 
   } 
 for (int i = 0; i < 10;i++) 
  cout << A[i] << '\t'; 
}