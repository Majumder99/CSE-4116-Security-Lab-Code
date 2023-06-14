#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll modinv(ll b, ll n)
{
    ll r1=n,r2=b,t1=0,t2=1,q,r,t;
    while(r2>0)
    {
        q=r1/r2;
        r=r1-q*r2;
        r1=r2;
        r2=r;
        t=t1-q*t2;
        t1=t2;
        t2=t;
    }
    if(t1<0)
        t1+=n;
    return t1;
}
/*ll power(ll a,ll b,ll p)
{
    ll ans=1,i;
    for(i=0;i<b;i++)
    {
        ans*=a;
        ans%=p;
    }
    ans%=p;
    return ans;
}*/
ll power(ll a,ll b,ll mod)
{
    if(b==0)
    {
        return 1;
    }
    if(b==1)
    {
        return a%mod;
    }
    ll xx=power(a,b/2,mod);
    if(b%2==0)
    {
        return ((xx%mod)*(xx%mod))%mod ;
    }
    else
    {
        return (((xx%mod)*(xx%mod))%mod * (a%mod)) %mod ;
    }
}
ll primitive_root(ll p)
{
    ll i,j,x;
    bool f;
    for(i=2;i<p;i++)
    {
        map<ll,ll>mp;
        f=true;
        for(j=0;j<p-1;j++)
        {
            x=power(i,j,p);
            mp[x]++;
            if(mp[x]>1 || x<1 || x>p-1)
            {
                f=false;
                break;
            }
        }
        if(f==true && __gcd(p,i)==1)
        {
            return i;
        }
    }
}
int main()
{
    ll p=10000019,y,c1,c2,c1p,c2p,xx1,tmp1,tmp2,k,g,m,xx,x=3,w;
    cin>>m;
    cin>>w;
    g=primitive_root(p);
    cout<<g<<endl;
    for(k=2;k<=p-2;k++)
    {
        if(__gcd(k,p-1)==1)
        {
            break;
        }
    }
    y=power(g,x,p);
    c1=power(g,k,p);
    c2=((m%p)*power(y,k,p))%p;
    tmp1=(c2%p);
    tmp2=power(c1,x,10000000000000000);
    tmp2=modinv(tmp2,p);
    xx=(tmp1*tmp2)%p;
    c1p=power(g,k*w,p);
    c2p=(power(m,w,p)*power(y,k*w,p))%p;
    tmp1=(c2p%p);
    tmp2=power(c1p,x,10000000000000000);
    tmp2=modinv(tmp2,p);
    xx1=(tmp1*tmp2)%p;
    cout<<xx<<endl;
    cout<<xx1<<endl;
}
