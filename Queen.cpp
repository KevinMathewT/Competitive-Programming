#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, p[100010], c[100010], res[100010], nres[100010];
unordered_map<ll, ll> um;

void te(){
	cin >> n;
	for(ll i=1;i<=n;i++){
		cin >> p[i] >> c[i];
		res[i] = nres[i] = 0;
	}

	for(ll i=1;i<=n;i++){
		if(p[i] == -1)
			continue;
		if(c[i] == 0)
			res[p[i]]++;
		else
			nres[p[i]]++;
	}

	priority_queue<ll, vector<ll>, greater<ll> > pq;

	for(ll i=1;i<=n;i++)
		if(res[i] == 0 && c[i] != 0)
			pq.push(i);

	ll flag = 0;
	while(!pq.empty()){
		ll curr = pq.top();
		pq.pop();
		cout << curr << "\n";
		flag = 1;
	}
	if(flag == 0)
		cout << -1 << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}