#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcdextended(ll a, ll b, ll* x, ll* y);

ll modInverse(ll a, ll b)
{
    ll x, y,result,g;
    g=gcdextended(a,b,&x,&y);
    if(g!=1)
    {
        cout<<"Inverse doesn't exist"<<endl;
    }
    else
    {
        result=(x%b+b)%b;
    }
    return result;
}

ll gcdextended(ll a,ll b,ll* x,ll* y)
{

    if(a==0)
    {
        *x=0,*y=1;
        return b;
    }
    ll x1, y1;
    ll gcd=gcdextended(b % a, a, &x1, &y1);
    *x=y1-(b/a)*x1;
    *y=x1;
    return gcd;
}
int main()
{
    ll r,i,n,p,q,lambda,phi,gcd,miu,g,l,tmp,tmp1,tmp2,m,c,xx;
    p=1009;
    q=1013;
    n=p*q;
    phi=(p-1)*(q-1);
    gcd=__gcd(p-1,q-1);
    lambda=phi/gcd; //lambda is equal to lcm of p-1 and q-1
    g=2;
    while(__gcd(g,n*n)!=1) //g and n*n have to be coprime
    {
        g++;
    }
    tmp=1;
    for(i=0; i<lambda; i++) //calculating (g^lambda) mod n*n
    {
        tmp*=g;
        tmp%=(n*n);
    }
    tmp=tmp%(n*n);
    tmp=(tmp-1)/n;
    miu=modInverse(tmp,n);
    cout<<"Private keys are lambda :"<<lambda<<" and miu :"<<miu<<endl;
    cout<<"Public keys are n:"<<n<<" and g :"<<g<<endl;
    cout<<"Enter message between 1 to 23(due to oveflow in c++) :"<<endl;
    cin>>m;
    tmp1=1;
    for(i=0; i<m; i++)
    {
        tmp1*=g;
        tmp1%=(n*n);
    }
    tmp1=tmp1%(n*n);
    r=1;
    while(__gcd(r,n)!=1)
    {
        r++;
    }
    tmp2=1;
    for(i=0; i<n; i++)//calculating ciphertext
    {
        tmp2*=r;
        tmp2%=(n*n);
    }
    tmp2=tmp2%(n*n);
    c=(tmp1*tmp2)%(n*n);
    cout<<"Corresponding ciphertext after encryption : "<<c<<endl;
    tmp=1;
    for(i=0; i<lambda; i++)//calculating messsage
    {
        tmp*=c;
        tmp%=(n*n);
    }
    tmp%=(n*n);
    tmp=(tmp-1)/n;
    tmp*=miu;
    tmp%=n;
    cout<<"Corresponding message after decryption : "<<tmp<<endl;
}
