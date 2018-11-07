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
struct dt
{
    ll l, r, d;
};
int main()
{
    freopen("input.txt", "r", stdin);       //Comment
    freopen("output.txt", "w", stdout); 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll l[n], r[n];
        dt arr[n];
        vll v;
        for (ll i = 0; i < n; i++)
        {
            cin >> l[i] >> r[i];
            arr[i].l = l[i];
            arr[i].r = r[i];
            arr[i].d = r[i] - l[i];
            v.push_back(arr[i].d);
        }
        // sort(arr,arr+n)
        sort(l, l + n);
        sort(r, r + n);
        ll ii = 0;
        ll p1 = l[0], p2 = 0,index_p2;
        ll temp_ans=0;
        for(ll i=0;i<n;i++)
        {
            p1 = l[i];
            index_p2 = (upper_bound(r, r + n, p1+temp_ans) - r);
            if(index_p2==n)
            continue;
            for (index_p2; index_p2 < n; index_p2++)
            {
                p2=r[index_p2];
                ll c = 0;
                for (ll j = 0; j < n; j++)
                {
                    if ((arr[j].l <= p1) && (arr[j].r >= p2))
                        c++;
                    if (c >= k)
                        {temp_ans= p2-p1;break;}
                }
                if(c<k)
                break;
            }
            
        }
        // if(t % 8 == 0 && t != 0)
        //     cout << "\n";
        cout<<temp_ans<<" ";
    }
}