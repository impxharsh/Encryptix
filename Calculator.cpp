#include<iostream>
using namespace std;

int main() {

    float a, b;
    int n;
    char choice;

    do {
        cout << "Enter the two numbers:" << endl;
        cin >> a >> b;

        cout << "Press 1 to add these numbers" << endl;
        cout << "Press 2 to subtract these numbers" << endl;
        cout << "Press 3 to multiply these numbers" << endl;
        cout << "Press 4 to divide the first number by the second number" << endl;
        cout << "Press 0 to exit" << endl;
        cin >> n;

        switch(n) {
            case 1:
                cout << a << " + " << b << " = " << a + b << endl;
                break;

            case 2:
                cout << a << " - " << b << " = " << a - b << endl;
                break;

            case 3:
                cout << a << " * " << b << " = " << a * b << endl;
                break;

            case 4:
                if (b != 0) {
                    cout << a << " / " << b << " = " << a / b << endl;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                }
                break;

            case 0:
                cout << "Exiting the calculator." << endl;
                break;

            default:
                cout << "Invalid option. Please enter a number between 0 and 4." << endl;
        }

        if (n != 0) {
            cout << "Do you want to perform another calculation? (y/n): ";
            cin >> choice;
        } else {
            choice = 'n';
        }

    } while(choice == 'y' || choice == 'Y');

    return 0;
}
