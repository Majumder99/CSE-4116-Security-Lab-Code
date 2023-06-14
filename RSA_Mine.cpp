#include <bits/stdc++.h>
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
int main()
{
    long long int i, a, b, c, d, n, p, q, m, e, phi_n, x;
//    a = 12, b = 16;
//    cout<<gcd(b, a)<<endl;

    p = 7907;
    q = 7919;

    n = p * q;
    phi_n = (p - 1) * (q - 1);

    e = 2;
    while(e < phi_n)
    {
        if(gcd(e, phi_n) == 1)
            break;
        e++;
    }

    d = modinv(e, phi_n);

    cout<<"The e: "<<e<<endl;
    cout<<"The phi_n: "<<phi_n<<endl;
    cout<<"The d: "<<d<<endl<<endl;




    m = 18070999;
    cout<<"The message: "<<m<<endl<<endl;
    a = BigMod(m, e, n);
    cout<<"The encrypted message: "<<a<<endl<<endl;
    b = BigMod(a, d, n);
    cout<<"The decrypted message: "<<b<<endl<<endl;

}
