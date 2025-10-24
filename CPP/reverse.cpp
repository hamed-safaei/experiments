#include <iostream>
using namespace std ;

int main()
{
int x , reverse = 0;
cout << "Enter an integer number : " ;
cin >> x ;

do
{
    reverse = reverse * 10 + x % 10 ;
    x /= 10;

}while(x != 0 ) ;

cout << "reverse is : " << reverse ;
}