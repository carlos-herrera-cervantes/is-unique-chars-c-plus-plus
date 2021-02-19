#include <iostream>
#include <string>

using namespace std;

/**
 * Check if the string has unique characters. This is the worst version of brute force. First we sort the entire
 * string and then we compare every char with its neighbor
 * @param str String to check
 * @returns If the string contains unique characters return true (1) otherwise return false (0)
 */
bool isUniqueCharsBruteForce1(string str)
{
    int key, j;

    for (int i = 1; i < str.length(); i++)
    {
        key = str[i];
        j = i - 1;

        while(j >= 0 && str[j] > key)
        {
            str[j + 1] = str[j];
            j = j - 1;
        }

        str[j + 1] = key;
    }

    for (int i = 0; i < str.length() - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            return false;
        }
    }

    return true;
}

/**
 * Check if the string has unique characters. This is the second best version of brute force. We compare
 * each character from the first traversal to each character from the second traversal
 * @param str String to check
 * @returns If the string contains unique characters return true (1) otherwise return false (0)
 */
bool isUniqueCharsBruteForce2(string str)
{
    for (int i = 0; i < str.length() - 1; i++)
    {
        for (int j = i + 1; j < str.length(); j++)
        {
            if (str.at(i) == str.at(j))
            {
                return false;
            }
        }
    }

    return true;
}

/**
 * Check if the string has unique characters. This is the third best version of brute force. We assume
 * that the string entered is in ASCII characters and we take this as a base case.
 * @param str String to check
 * @returns If the string contains unique characters return true (1) otherwise return false (0)
 */
bool isUniqueCharsBruteForce3(string str)
{
    if (str.length() > 128) return false;

    bool *charSet = new bool[128];

    for (int i = 0; i < str.length(); i++)
    {
        int val = str.at(i);

        if (charSet[val])
        {
            return false;
        }

        charSet[val] = true;
    }

    return true;
}

/**
 * Check if the string has unique characters. The is best solution for this algorithm. 
 * We only use one integer to do the comparation.
 * @param str String to check
 * @returns If the string contains unique characters return true (1) otherwise return false (0)
 */
bool isUniqueCharsOptimize(string str)
{
    int checker = 0;

    for (int i = 0; i < str.length(); i++)
    {
        int val = str.at(i) - 'a';

        if ((checker & (1 << val)) > 0)
        {
            return false;
        }

        checker |= (1 << val);
    }

    return true;
}

int main()
{
    string str;

    cout << "ENTER THE WORD: ";
    cin >> str;
    cout << "THE WORD HAVE UNIQUE CHARACTERS: " << isUniqueCharsBruteForce1(str);

    return 0;
}