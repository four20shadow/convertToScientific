#include <iostream>
#include "convertToScientific.h"

using namespace std;

int main()
{
    char number[1001];
    cout << "Enter number: ";
    cin >> number;

    cout << number << " in scientific notation is: ";
    convertNumberToScientific(number);

    return 0;
}
