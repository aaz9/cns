// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

long long int primitive(long long int q)
{
    long long int i = 1, n = q - 1;

    for (int i = 1; i <= n; i++)
    {
        set<long long int> sett;
        int flag = 1;
        for (int j = 1; j <= n; j++)
        {
            long long int t = ((long long int)pow(i, j)) % q;
            if (sett.find(t) == sett.end())
            {
                sett.insert(t);
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    //  x=private and y = public
    long long int q, al, xa, xb, ya, yb, ka, kb;
    q = 7;
    al = primitive(q);
    cout << "The primitive root(alpha) al :" << al << endl;
    cout << "Enter the private key for Alice :";
    cin >> xa;
    cout << "Enter the private key for Bob :";
    cin >> xb;

    ya = ((long long int)pow(al, xa)) % q;
    yb = ((long long int)pow(al, xb)) % q;

    ka = ((long long int)pow(yb, xa)) % q;
    kb = ((long long int)pow(ya, xb)) % q;

    cout << "The key for Alice is :" << ka << endl;
    cout << "The key for Bob is :" << kb << endl;

    cout << "Man in the middle -------------------------------------" << endl;

    long long int xe, yad, k1, k2, kae, kbe;

    cout << "Enter the private key for Eve :";
    cin >> xe;
    yad = ((long long int)pow(al, xe)) % q;

    ka = ((long long int)pow(yad, xa)) % q;
    kb = ((long long int)pow(yad, xb)) % q;

    k1 = ((long long int)pow(ya, xe)) % q;
    k2 = ((long long int)pow(yb, xe)) % q;

    kae = ((long long int)pow(pow(al, xe), xa)) % q;
    kbe = ((long long int)pow(pow(al, xe), xb)) % q;

    cout << "The key key between Alice and Eve is :" << kae << endl;
    cout << "The key key between Alice and Eve is :" << kbe << endl;

    return 0;
}