#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or 
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = ((res%p)*(x%p)) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = ((x%p)*(x%p)) % p; 

    } 
    return res; 
} 
  
// Returns n^(-1) mod p 
ll modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p); 
} 
  
// Returns nCr % p using Fermat's little 
// theorem. 
ll nCrModPFermat(ll n, ll r, ll p) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
  
    // Fill factorial array so that we 
    // can find all factorial of r, n 
    // and n-r 
    ll fac[n+1]; 
    fac[0] = 1; 
    for (ll i=1 ; i<=n; i++) 
        fac[i] = ((fac[i-1]%p)*(i%p))%p; 
  
    return (((((fac[n]%p)* modInverse(fac[r], p) % p) %p) * 
            modInverse(fac[n-r], p) % p)) % p; 
}

ll nCrModpDP(ll n, ll r, ll p) 
{
    ll C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1;
  
    for (ll i = 1; i <= n; i++) 
    { 
        for (ll j = min(i, r); j > 0; j--) 
  
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
}

ll nCrModpLucas(ll n, ll r, ll p) 
{ 
   if (r==0) 
      return 1; 
   ll ni = n%p, ri = r%p;
   return (nCrModpLucas(n/p, r/p, p) *
           nCrModpDP(ni, ri, p)) % p;
}

void te(){
	ll n, k;
	cin >> n >> k;
	// n--; k--;

	cout << nCrModpDP(5, 0, (ll)1e9+7) << "-\n";

	ll t;
	t = n;
	n = k;
	k = n;
	ll sum = 0;
	for(ll i=1;i<5;i++){
	for(ll j=1;j<5;j++){
	n = j;
	k = i;
	sum = 0;
	for(ll i=0;i<n;i++){
		sum += nCrModpLucas(n-1, i, (ll)1e9+7) * nCrModpLucas(k+i, n, (ll)1e9+7);
	}
	cout << sum << " ";
	}
	cout << "\n";
	}

	cout << sum << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--);
	te();

	return 0;
}