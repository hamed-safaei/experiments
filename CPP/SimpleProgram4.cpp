#include <iostream>
    using namespace std;


    int main(){

        int array_size , Positive = 0 , Negative = 0 ;
        cout << " Enter size of array : ";
        cin >> array_size ;
        int List[array_size];

        for( int i=0 ; i < array_size ; i++ ){
            cout << " Enter Value for [" << i << "] : " ;
            cin >> List[i] ;
            if( List[i] >= 0 ){
                Positive++;
            }else{
                Negative++;
            }
        }

        cout << endl << " Your Enter Data(s) : " ;
        for( int i = 0 ; i < array_size ; i++ ){
            cout << List[i] ;
            if( i < array_size - 1 ){
                cout << " , ";
            }
        }

        cout << endl << " Positive count (+) : " << Positive
             << endl << " Negative count (-) : " << Negative
             << endl ;
    }