#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a, b) for (ll i = a; i < b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
#define print(x) cerr << #x << " is " << x << endl;
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    string s;
    cin >> s;
    string z = "";
    while (n)
    {
        ll k = n & 1;
        n >>= 1;
        z.pb('0' + k);
    }
    reverse(z.begin(), z.end());
    if (z.length() > s.length())
    {
        cout << 0;
        return 0;
    }
    ll x = z.length(), y = s.length();
    f(1, s.length())
    {
        if (y <= x)
            break;
        if (s[i] == '1')
            s[i] = '#', y--;
    }
    string r;
    f(0, s.length()) if (s[i] != '#') r.pb(s[i]);
    if (r <= z)
        cout << s.length() - z.length();
    else
        cout << s.length() - z.length() + 1;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}