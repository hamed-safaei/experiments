#include <iostream>
    using namespace std;

    int main () {

        const int array_size = 10 ;
        int arr[ array_size ] , Odd = 0 , Even = 0 ;

        cout << endl << " Enter " << array_size << " number : " << endl ;

        for( int i = 0 ; i < array_size ; i++ ){
            cout << " Enter Value for [" << i << "] : " ;
            cin >> arr[i] ; // 0 - 9 => 10
        }

        for( int i = 0 ; i < array_size ; i++ ){

            if( arr[i] %2 == 0 ){ // [0] => 5%2 = 1 == 0
                Even++;
            } else {
                Odd++;
            }
        }

        cout << endl << " Odd  Count : " << Odd
             << endl << " Even Count : " << Even
             << endl ;

        return 0;
    }