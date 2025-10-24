#include <iostream>
using namespace std ;


int main()
{
int i , j , z ;

for(i = 1 ; i < 10; i++){

if(i < 6)
{
            for( j = 5 - i ; j > 0 ; j--)
            cout << "   ";

                  for(z = 1 ; z <= 2 * i - 1 ; z++)
                  cout << "*  " ;
                  cout << endl ;
}
else
{
    for(j = 1 ; j <= i - 5 ; j++)
    cout << "   " ;

        for(z = i * 2 ; z < 19 ; z++)
        cout << "*  ";
        cout << endl ;
}
}
}