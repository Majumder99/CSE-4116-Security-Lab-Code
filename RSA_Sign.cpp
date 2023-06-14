#include<bits/stdc++.h>
using namespace std;

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
long long int gcd(long long int a, long long int b)
{
    if(b > a)
        swap(a, b);
    long long int c = a % b;
    if(c == 0)
        return b;
    return gcd(b, c);
}
int main() {
    long long int p = 7907;
    long long int q = 7919;

    long long int n = p * q;
    long long int fi_n = (p - 1) * (q - 1);

    long long int message = 18070999;
    cout << "message: " << message << endl;

    long long int e = 0;
    for (long long int i = 2; i < fi_n; i++) {
        if (gcd(i, fi_n) == 1) {
            e = i;
            break;
        }
    }
    cout << "e: " << e << endl;

    long long int d = modinv(e,fi_n);

    long long int signing = BigMod(message, d, n); // message^d mod n
    cout << "signing: " << signing << endl;

    long long int verification = BigMod(signing, e, n); // signing^e mod n
    cout << "verification: " << verification << endl;

    return 0;
}
