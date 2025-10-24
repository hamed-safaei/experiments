#include <iostream>
    using namespace std;

    void findMax( int , int , int );

    int main(){
        int value1 , value2 , value3 ;

        cout << " Enter Tree value :  " ;
        cin >> value1 >> value2 >> value3 ;

        findMax( value1 , value2 , value3 );
        return 0;
    }

    void findMax( int A , int B , int C ){

        int maxValue ;

        if( A > B ){
            if( A > C ){
                maxValue = A ;
            }else{
                maxValue = C ;
            }
        }else{
            if( B > C ){
                maxValue = B ;
            }else{
                maxValue = C ;
            }
        }

        cout << " Maximum value is : "  << maxValue ;
    }