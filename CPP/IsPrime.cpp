#include <iostream>
using namespace std;

// تابع بررسی عدد اول
bool isPrime(int x);

int main() {
    int num;
    char ans;

    while (true) {
        cout << "Enter a Number: ";
        cin >> num;

        if (isPrime(num))
            cout << "\nNumber " << num << " is Prime.";
        else
            cout << "\nNumber " << num << " is NOT Prime.";

        cout << "\n\nDo you want to continue? (Y/N): ";
        cin >> ans;

        if (ans == 'N' || ans == 'n') {
            break;
        }
    }

    return 0;
}

// تعریف تابع isPrime
bool isPrime(int x) {
    if (x <= 1) {
        return false;
    }

    for (int i = 2; i <= x / 2; i++) {
        if (x % i == 0)
            return false;
    }

    return true;
}
