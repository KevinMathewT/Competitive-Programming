#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[100010];

void te(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	priority_queue<ll> pq;
	vector<ll> v;

	for(ll i=0;i<n;i++){
		pq.push(-a[i]);
	}

	while(!pq.empty()){
		ll smallest = -pq.top();
		pq.pop();
		while(!pq.empty()){
			v.push_back((-pq.top()) % smallest);
			pq.pop();
		}

		for(ll i=0;i<v.size();i++){
			// cout << v[i] << " ";
			if(v[i] != 0)
				pq.push(-v[i]);
		}

		// cout << "\n";

		v.clear();

		if(pq.empty()){
			cout << smallest << "\n";
			return;
		}

		pq.push(smallest);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}