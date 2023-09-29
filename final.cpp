#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

// Function to generate a random private key
string generateRandomKey()
{
    string privateKey = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    random_shuffle(privateKey.begin(), privateKey.end());
    return privateKey;
}

// Function to apply Caesar Cipher encryption
void caesarCipherEncrypt(vector<int> &indices, int shift)
{
    for (int &index : indices)
    {
        if (index >= 0)
        {
            index = (index + shift) % 62; // 62 is the size of the key
        }
    }
}

// Function to apply Shift Cipher encryption
void shiftCipherEncrypt(vector<int> &indices, int shift)
{
    for (int &index : indices)
    {
        if (index >= 0)
        {
            index = (index + shift) % 62; // 62 is the size of the key
        }
    }
}

// Function to encode a message using the private key and multiple encryption layers
vector<int> encodeMessage(const string &message, const string &privateKey)
{
    vector<int> encodedIndices;
    for (char c : message)
    {
        int index = privateKey.find(c);
        if (index != -1)
        {
            encodedIndices.push_back(index);
        }
        else
        {
            encodedIndices.push_back(-1);
        }
    }

    // Apply Caesar Cipher encryption with a shift of 3
    caesarCipherEncrypt(encodedIndices, 3);

    // Apply Shift Cipher encryption with a shift of 5
    shiftCipherEncrypt(encodedIndices, 5);

    return encodedIndices;
}

// Function to reverse Shift Cipher encryption
void shiftCipherDecrypt(vector<int> &indices, int shift)
{
    for (int &index : indices)
    {
        if (index >= 0)
        {
            index = (index - shift + 62) % 62; // 62 is the size of the key
        }
    }
}

// Function to reverse Caesar Cipher encryption
void caesarCipherDecrypt(vector<int> &indices, int shift)
{
    for (int &index : indices)
    {
        if (index >= 0)
        {
            index = (index - shift + 62) % 62; // 62 is the size of the key
        }
    }
}

// Function to decode an encoded message using the private key and reverse multiple encryption layers
string decodeMessage(const vector<int> &encodedIndices, const string &privateKey)
{
    // Reverse Shift Cipher encryption with a shift of 5
    vector<int> decodedIndices = encodedIndices;
    shiftCipherDecrypt(decodedIndices, 5);

    // Reverse Caesar Cipher encryption with a shift of 3
    caesarCipherDecrypt(decodedIndices, 3);

    string decodedMessage;
    for (int index : decodedIndices)
    {
        if (index >= 0 && index < privateKey.length())
        {
            decodedMessage += privateKey[index];
        }
        else
        {
            decodedMessage += '?';
        }
    }
    return decodedMessage;
}

int main()
{
    // Seed for random number generation
    srand(static_cast<unsigned>(time(0)));

    // Generate a random private key
    string privateKey = generateRandomKey();
    cout << "Private Key: " << privateKey << endl;

    // Get the message from the sender
    string message;
    cout << "Enter your message: ";
    getline(cin, message);

    // Encode the message using the private key and multiple encryption layers
    vector<int> encodedIndices = encodeMessage(message, privateKey);

    cout << "Encoded Indices: ";
    for (int index : encodedIndices)
    {
        cout << index << ' ';
    }
    cout << endl;

    // Decode the encoded message using the private key and reverse multiple encryption layers
    string decodedMessage = decodeMessage(encodedIndices, privateKey);
    cout << "Decoded Message: " << decodedMessage << endl;

    return 0;
}
