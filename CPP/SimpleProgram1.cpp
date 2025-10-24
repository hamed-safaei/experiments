#include <iostream>
using namespace std;

int main()
{

int x , sum = 0;
char answer='y' ;

while( answer == 'y' )
{

cout << "enter number :" ;
cin >> x;
sum = sum + (x * x) ;
cout << "Do you want to continue ? (y/n) " ;
cin >> answer ;

}

cout << "sum is = " << sum ;

}