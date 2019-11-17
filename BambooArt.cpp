#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, a[2510], f[1000010];
unordered_map<ll, ll> diff[1000010];

void solve(){
    cin >> n;
    for(ll i=0;i<n;i++)
        cin >> a[i];

    ll best = 1, ans;

    sort(a, a + n);

    fill(f, f + 1000010, 0);
    for(ll i=0;i<n;i++)
        f[a[i]] = 1;

    for(ll i=0;i<n;i++)
        for(ll j=(i + 1);j<n;j++){
            ll d = a[j] - a[i];
            if(diff[a[j]][d] == 1)
                continue;

            ans = 2;
            ll next = a[j] + a[j] - a[i];

            while(f[next] == 1){
                ans++;
                diff[a[j]][d] = 1;
                next += a[j] - a[i];
            }

            best = max(best, ans);
        }

    cout << best << "\n";
}

int main()
{
    // freopen("input.txt", "r", stdin);        //Comment
    // freopen("output.txt", "w", stdout);        //this out.
    ios::sync_with_stdio(false);            //Not
    cin.tie(NULL);                            //this.
    cout.tie(0);                            //or this.

    solve();

    return 0;
}