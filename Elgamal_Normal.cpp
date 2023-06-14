#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
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
void findPrimitiveElements(lli p) {
    bool isPrimitive;
    cout << "Primitive elements modulo " << p << ": ";
    for (lli a = 2; a < p; ++a) {
        isPrimitive = true;
        for (lli i = 1; i < p - 1; ++i) {
            lli x = BigMod(a, i, p);
            if (x == 1) {
                isPrimitive = false;
                break;
            }
        }
        if (isPrimitive) {
            cout << a << " ";
            break;
        }
    }
    cout << endl;
}
int main()
{
    long long int p = 100003, alpha = 2, a = 3, x = 18070, k = 5;
    long long int y1,y2,beta, j,o;

//    Encryption
    y1 = BigMod(alpha, k, p);
    beta = BigMod(alpha, a, p);
    j = BigMod(beta, k ,p);
    o = x % p;
    y2 = (j * o) % p;
    cout << "Y1 " << y1 << " y2 " << y2 << endl;

//    Decyption
    long long int r,t,f,g,h;
    r = y2 % p;
    t = BigMod(y1, a, 10000000000000000);
    h = modinv(t,p);
    g =(r*h)%p;
    cout << "G" << " " << r << " " << t << " " << h << " " << g << endl;

}
