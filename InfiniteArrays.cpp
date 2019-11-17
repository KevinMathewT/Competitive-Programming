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

ll n, q, a[1010000], cum[1001000], M = 1000000007, L[1010000], R[1010000];

void solve(){
    cin >> n;
    for(ll i=0;i<n;i++)
        cin >> a[i];
    cum[0] = a[0];
    for(ll i=0;i<n;i++)
        a[i] = a[i] % M;
    for(ll i=1;i<n;i++)
        cum[i] = (a[i] + cum[i-1]) % M;

    ll q;
    // cout << n << "\n";
    // cout << a[n-1] << "\n";
    cin >> q;
    for(ll i=0;i<q;i++)
        cin >> L[i];
    for(ll i=0;i<q;i++)
        cin >> R[i];
        
    // cout << q << "\n";

    for(ll i=0;i<q;i++){
        ll l = L[i], r = R[i], sumL = 0, sumR = 0;
        l -= 2;
        r -= 1;

        if(l != -1){
            sumL = ((sumL + ((((ll)(l / n) % M) * (cum[n-1])) % M))) % M;
            sumL = (sumL + cum[l % n]) % M;
        }

        if(r != -1){
            sumR = ((sumR + ((((ll)(r / n) % M) * (cum[n-1])) % M))) % M;
            sumR = (sumR + cum[r % n]) % M;
        }

        cout << ((sumR - sumL + M) % M) << " ";
    }
}

int main()
{
    freopen("input.txt", "r", stdin);        //Comment
    freopen("output.txt", "w", stdout);        //this out.
    ios::sync_with_stdio(false);            //Not
    cin.tie(NULL);                            //this.
    cout.tie(0);                            //or this.

    ll T;
    cin >> T;
    while(T--)
        solve();

    return 0;
}