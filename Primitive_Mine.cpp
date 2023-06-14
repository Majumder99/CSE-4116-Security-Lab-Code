#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

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

int main() {
    lli p = 13;

    findPrimitiveElements(p);

    return 0;
}
