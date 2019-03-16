#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll fact[(ll) 1e6 + 100];
vector<ll> primes;

void te(){
	ll n;
	cin >> n;

	ll a[n], ass[n];
	for(ll i=0;i<n;i++){
		cin >> a[i];
		ass[n] = 0;
	}

	char ch[n];
	for(ll i=0;i<n;i++)
		cin >> ch[i];

	unordered_map<ll, vector<ll> > m;

	for(ll i=0;i<n;i++){
		ll t = a[i];
		while(t > 1){
			m[fact[t]].push_back(i);
			t /= fact[t];
		}
	}

	ll groups = n;

	for(ll i=0;i<primes.size();i++){
		if(m[primes[i]].size() == 0)
			continue;
		ll male = 0, female = 0;

		for(ll j=0;j<m[primes[i]].size();j++)
			if(ch[m[primes[i]][j]] == 'M')
				male++;
			else
				female++;

		if(male == 1 && female == 1)
			groups--;

		
	}
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll size = (ll) 1e6 + 100;
	for(ll i=0;i<size;i++)
		fact[i] = i;

	fact[0] = 0; fact[1] = 1;

	for(ll i=2;i<size;i++)
		if(fact[i] == i){
			primes.push_back(i);
			for(ll j=i*i;j<size;j+=i)
				fact[j] = i;
		}

	te();

	return 0;
}