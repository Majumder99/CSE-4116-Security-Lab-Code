#include<bits/stdc++.h>
#define ll long long

using namespace std;


ll int gcd(ll int a, ll int b)
{
    if(b == 0)
        return a;
    return gcd(b,a%b);
}

ll int modInverse(ll int base, ll int modulus)
{
    for(int x = 1; x< modulus; x++)
    {
        if((((base%modulus)*(x%modulus))%modulus) == 1)
        {
            return x;
        }
    }

}


ll int modPow(ll int base, ll int exponent, ll int modulus)
{
    if(modulus == 1)
        return 0;
    ll int result = 1;

    base = (base % modulus + modulus) % modulus;
    while(exponent>0)
    {
        if(exponent%2 == 1)
        {
            result = (result * base) % modulus;
        }

        exponent/=2;

        base = (base*base)%modulus;

    }
    return result;
}



int main()
{

    ll int p = 10009;
    ll int q = 10007;
    ll int fi_n = (p-1)*(q-1);
    ll int e = 101 ;
    ll int d ;
    if(gcd(e,fi_n)==1)
        d = modInverse(e,fi_n);
    ll int n = p*q;
    ll int m1 = 14;
    ll int c1 = modPow(m1,e,n);

    ll int m2 = 20;
    ll int c2 = modPow(m2,e,n);

    ll int c = (c1*c2)%n;

    ll int m11 = modPow(c1,d,n);
    ll int m22 = modPow(c2,d,n);

    cout<<m11*m22<<endl;

    ll int M1 = m1*m2;
    cout<<M1<<endl;

    ll int M2 = modPow(c,d,n);
    cout<<M2<<endl;
    if (M1 == M2)
        cout<<"success"<<endl;
    else
        cout<<"unsuccess"<<endl;


}
