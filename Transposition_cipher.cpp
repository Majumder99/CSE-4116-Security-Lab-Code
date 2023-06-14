#include<bits/stdc++.h>
using namespace std;

int main()
{
    string plainText, key;
    cin>>plainText;
    cin>>key;
    string tempKey = key;
    int a[100];
    int keySize = key.length();
    int plainSize = plainText.length();
    sort(key.begin(),key.end());

    for(int i = 0 ; i < keySize ; i++)
    {
        char c = key[i];
        for(int j = 0 ; j < keySize ; j++)
        {
            if(c == tempKey[j])
            {
                a[j] = i + 1;
            }
        }
    }

    int rows = (plainSize % keySize == 0) ? (plainSize / keySize) : (plainSize / keySize + 1);
    int cols = keySize;


    char grid[rows][cols];

    //ciphertext process
    int index = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int colIndex = a[j] - 1;
            if (index < plainSize)
            {
                grid[i][colIndex] = tolower(plainText[index]);
                cout << grid[i][colIndex] << " ";
                index++;
            }
            else
            {
                grid[i][colIndex] = '2';
                cout << grid[i][colIndex] << " ";
            }
        }
        cout << endl;
    }


    char ciphertext[100];
    index = 0;
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            ciphertext[index] = grid[j][i];
            cout << ciphertext[index] << " ";
            index++;
        }
        cout << endl;
    }
    cout << "Ciphertext: " << ciphertext << endl;


    //decipher process
    char mainText[100];
    index = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int colIndex = a[j] - 1;
            if(grid[i][colIndex] == '2')
            {
                continue;
            }
            else
            {

                mainText[index] = toupper(grid[i][colIndex]);
                cout << mainText[index] << " ";
                index++;
            }
        }
        cout << endl;
    }

    cout << "MainText: " << mainText << endl;
}
