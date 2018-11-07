#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll m[51][51];
ll vis[51];
vector<ll> v[51];
ll n;
ll primes[] = {53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379};

ll dfs(ll n){
	vis[n] = 1;
	for(ll i=0;i<v[n].size();i++)
		if(vis[v[n][i]] != 1)
			dfs(v[n][i]);
}

void te(){
	cin >> n;
	ll a[n], b[n];
	for(ll i=0;i<51;i++){
		v[i].clear();
		vis[i] = 0;
	}

	for(ll i=0;i<n;i++){
		cin >> a[i];
		b[i] = a[i];
	}

	if(n == 1){
		cout << 0 << "\n" << a[0] << "\n";
		return;
	}

	for(ll i=0;i<n;i++)
		for(ll j=i+1;j<n;j++)
			if(m[a[i]][a[j]] == 1){
				v[i].push_back(j);
				v[j].push_back(i);
			}

	ll count = 0;
	ll pos = 0;

	for(ll i=0;i<n;i++)
		if(vis[i] == 0){
			if(v[i].size() == 0)
				a[i] = 29;
			count++;
			dfs(i);
		}

	ll flag = 1;
	for(ll i=0;i<n;i++)
		if(b[i] != 29){
			flag = 0;
			break;
		}

	cout << count - 1 << "\n";

	if(flag){
		cout << 2 << " ";
		for(ll i=1;i<n;i++)
			cout << a[i] << " ";
		cout << "\n";	
		return;
	}

	if(count == n){
		cout << b[0] << " ";
		for(ll i=1;i<n;i++)
			cout << a[i] << " ";
		cout << "\n";	
	}
	else{
		for(ll i=0;i<n;i++)
			cout << a[i] << " ";
		cout << "\n";
	}
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	for(ll i=2;i<=50;i++)
		for(ll j=2;j<=50;j++)
			if(__gcd(i, j) == 1)
				m[i][j] = 1;
			else
				m[i][j] = 0;


	// cout << sizeof(primes)/sizeof(primes[0]) << "\n";
	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}