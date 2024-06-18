#include <iostream>
#include "convertToScientific.h"

using namespace std;

int findLength(char* x)
{
    int length = strlen(x);

    return length;
}

void convertNumberToScientific(char* number)
{
    char result[1001];
    char tempNumber[1001];
    int exponent = 0;

    if (number[0] == '0')
    {
        exponent = -1;

        strcpy(tempNumber, number + 2);

        char* token2 = strtok(tempNumber, "."); // Get the second token if it exists

        if (!token2) // Change here: Added null pointer check
        {
            strcpy(result, "Invalid input");
            cout << result;
            return;
        }

        for (int i = 0; i < strlen(token2); i++)
        {
            if (token2[i] == '0')
            {
                exponent--;
            }
            else
            {
                result[0] = token2[i];
                result[1] = '.';
                int resultIndex = 2;

                // Copy the remaining digits of the fractional part
                for (int j = i + 1; j < strlen(token2); j++)
                {
                    result[resultIndex++] = token2[j];
                }

                result[resultIndex] = '\0';
                break;
            }

        }
        sprintf(result + strlen(result), "e%d", exponent);
        cout << result;
    }
    else
    {
        strcpy(tempNumber, number + 1);
        result[0] = number[0];
        result[1] = '.'; // Change here: Explicitly set the second character
        result[2] = '\0';

        char* token1 = strtok(tempNumber, "."); // Get the first token
        char* token2 = strtok(nullptr, "."); // Get the second token if it exists
        if (token1)
            strcat(result, token1); // Concatenate the first token
        if (token2)
            strcat(result, token2);

        exponent = strlen(token1);
        strcat(result, "e");

        char exponentToChar[20];
        sprintf(exponentToChar, "%d", exponent);

        strcat(result, exponentToChar);
        cout << result;
    }
}