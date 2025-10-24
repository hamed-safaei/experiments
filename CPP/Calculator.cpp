#include <iostream>
using namespace std;

int main()
{
    int N1 , N2 ;
    char op;

cout << "enter the equation : " ;
cin >> N1 >>  op >> N2 ;

/*
if(op == '+'){
    cout << "sum is : " << N2 + N1 ;
}

if(op == '-'){
    cout << "submission is : " << N1 - N2 ;
}

if(op == '*'){
    cout << "product is : " << N1 * N2 ;
}

if(op == '/'){
    if(N2 != 0){
        cout << "Division is : " << N1 / N2 ;
    }

    else{
        cout << "This Equation is not corect !!" ;
    }
if(op == '%'){
    cout << "remain is : " << N1 % N2 ; 
}

}
*/

switch(op){
    case '+' :
    cout << "sum is : " << N1 + N2 ;
break;
    case '-' :
    cout << "submission is : " << N1 - N2 ;
break;
    case '*' :
    cout << "product is : " << N1 * N2 ;
break;
    case '/' :
    
    if(N2 != 0){
        cout << "division is : " << N1 / N2 ;
    }
    else {
            cout << "equation is not corect ";
        }
break;
    case '%' :
    cout << "remain is : " << N1 % N2 ;
}

}