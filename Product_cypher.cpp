#include <bits/stdc++.h>
using namespace std;
#define ll long long int

long long int BigMod(long long int base, long long int power, long long int mod){
    if(power == 0) return 1;
    else if(power % 2 == 1){
        long long int a = base%mod;
        long long int b = (BigMod(base, power - 1, mod))% mod;
        return (a*b) % mod;
    }
    else if(power % 2 == 0){
        long long int a = (BigMod(base, power/2, mod)) % mod;
        return (a*a) % mod;
    }
}

long long int modinv(long long int b, long long int n) {
    long long int r1 = n, r2 = b, t1 = 0, t2 = 1;

    while (r2 > 0) {
        long long int q = r1 / r2;
        long long int r = r1 - q * r2;
        r1 = r2;
        r2 = r;
        long long int t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }

    if (t1 < 0)
        t1 += n;

    return t1;
}
ll exgcd(ll a, ll b, ll *c, ll *d)
{
    if (a == 0)
    {
        *c = 0;
        *d = 1;
        return b;
    }
    ll x, y;
    ll gcd = exgcd(b % a, a, &x, &y);
    *c = y - (b / a) * x;
    *d = x;
    return gcd;
}

int main()
{
    ll i, j;
    ll p = 7477;
    ll alpha = 11;
    ll a = 13; // private key
    ll m1 = 14;
    ll m2 = 5;

    ll beta = BigMod(alpha, a, p);
    cout << "Public Key(P,alpha, beta): " << p << ", " << alpha << ", " << beta << endl;
    ll r1 = 2 + rand() % 10;
    ll c11 = BigMod(alpha, r1, p);
    ll c21 = (m1 * BigMod(beta, r1, p)) % p;
    cout << "Cipher1: " << c11 << ", " << c21 << endl;

    ll r2 = 2 + rand() % 10;
    ll c12 = BigMod(alpha, r2, p);
    ll c22 = (m2 * BigMod(beta, r2, p)) % p;
    cout << "Cipher2: " << c12 << ", " << c22 << endl;

    ll c1 = (c11 * c12) % p;
    ll c2 = (c21 * c22) % p;

    ll mInv1, yy;
    ll tmp = modinv(BigMod(c11, a, p), p);
//    tmp = (p + tmp) % p;
    ll dec1 = (c21 * tmp) % p;
    cout << "Decryption1: " << dec1 << endl;

    ll mInv2;
    tmp = modinv(BigMod(c12, a, p), p);
//    tmp = (p + tmp) % p;
    ll dec2 = (c22 * tmp) % p;
    cout << "Decryption2: " << dec2 << endl;

    cout << "M: " << dec1 * dec2 << endl;

    ll mInv3;
    tmp = modinv(BigMod(c1, a, p), p);
//    tmp = (p + tmp) % p;
    ll dec3 = (c2 * tmp) % p;
    cout << "Decryption3: " << dec3 << endl;

    return 0;
}
