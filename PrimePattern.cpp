#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll a, b;
ll c = 0;

//Code referred from GeeksForGeeks

void simpleSieve(ll limit, vector<ll> &primes) 
{
    bool seive[limit+1]; 
    memset(seive, true, sizeof(seive)); 
  
    for (ll p=2; p*p<limit; p++){ 
        if (seive[p] == true){ 
            for (ll i=p*2; i<limit; i+=p) 
                seive[i] = false; 
        } 
    } 
  
    for (ll p=2; p<limit; p++){ 
        if (seive[p] == true){ 
            primes.push_back(p); 
            c++;
        } 
    } 
} 
  
void segmentedSieve(ll n) 
{ 
    ll limit = floor(sqrt(n))+1; 
    vector<ll> primes;  
    simpleSieve(limit, primes);  
  
    ll low = limit; 
    ll high = 2*limit; 
  
    while (low < n){ 
        if (high >= n)  
           high = n; 
         
        bool seive[limit+1]; 
        memset(seive, true, sizeof(seive)); 
  
        for (ll i = 0; i < primes.size(); i++){
            ll l = floor(low/primes[i]) * primes[i]; 
            if (l < low) 
                l += primes[i];
            for (ll j=l; j<high; j+=primes[i]) 
                seive[j-low] = false; 
        } 
  
        for (ll i = low; i<high; i++) 
            if (seive[i - low] == true) 
            	c++;
  
        low = low + limit; 
        high = high + limit; 
    } 
} 
  
void te() 
{
	cin >> a >> b;
	c = 0;
    segmentedSieve(a);
    cout << c << "\n";
    if(b <= c)
    	cout << "YES\n";
    else
    	cout << "NO\n";
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
	while(T--)
		te();

	return 0;
}