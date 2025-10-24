#include <iostream>

    using namespace std;

    int timeConversion( int , int , int );

    int main(){

        int Hour , Minute , Second ;

        cout << " Enter Time ( Format : HH MM SS ) :   " ;
        cin >> Hour >> Minute >> Second ;

        cout << " Total Second(s) is : " << timeConversion(Hour , Minute , Second ) << endl ;
        return 0;
    }

    int timeConversion( int hour , int minute , int second ){

        return ( ( hour * 3600 ) + ( minute * 60 ) + second ) ;
    }