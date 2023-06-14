#include<bits/stdc++.h>
#define ll long long int
using namespace std;

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

int main()
{
    ll p, alpha, beta, d=18;
    p = 1009;
    alpha = 11;
    cout<<"alpha ="<<alpha<<endl;
    beta = BigMod(alpha, d, p);

    ll m = 100;

    ll r1 = 10, r2 = 20;

    ll c1 = BigMod(alpha, r1, p);
    ll c2 = m * BigMod(beta, r1, p);



    ll c1p = BigMod(alpha, r1+r2, p);
    ll c2p = m * BigMod(beta, r1+r2, p);


    cout<<"mgs = "<<m<<endl;

    ll dec = (c2p * BigMod(c1p, p - 1 - d, p))%p ;
    std::cout << "dec = " << dec << std::endl;

    return 0;
}
