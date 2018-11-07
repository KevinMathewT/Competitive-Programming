#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define I insert
#define vll vector<ll>
ll power(ll a, ll b, ll mod)
{
    ll c = 1;
    while (b > 0)
    {
        if (b % 2)
            c *= a, c %= mod;
        b /= 2;
        a *= a;
        a %= mod;
    }
    return c;
}
#define MAX 1000000007
string s;
ll n;
ll i_need_a_dot(ll i)
{
    if(i>=(n))
    return -MAX;
    if(s[i]=='.')
    return 0;
    else
    {
        ll a = i_need_a_dot(i+1);
        ll b = i_need_a_dot(i+2);
        s[min(i+1,n-1)]='#';
        s[min(i,n-1)]='.';
        return a+b+1;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);       //Comment
    freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s;
        ll step=0,flag=0,left=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='.')
            left=1;
            if(left==0)
            continue;
            if(s[i]=='#')
            {
                ll a =i_need_a_dot(i+1);
                // ll b =i_need_a_dot(i+2);
                if(a<0)
                {
                    flag=1;
                    break;
                }
                step+=(a);
            }
        }
        if(flag==1)
        {cout<<"-1\n";continue;}
        ll dot=0,count=0;
        for(ll i = 0; i < n; i++)
        {
            if(s[i]=='#')
            {
                step+=(i-count);
                count++;
            }
        }
        cout<<step<<"\n";
        

    }
}