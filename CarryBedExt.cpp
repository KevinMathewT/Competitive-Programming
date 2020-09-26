#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define endl '\n'
 
using namespace std;

int t; 
void read()
{
	cin >> t; 
}

const int maxn = 5003; 
const long long inf = 1e18; 

int n, k;  
int a[maxn];

pair <int, int> tr[maxn * 4];
void merge(int v)
{
	tr[v] = max(tr[v * 2], tr[v * 2 + 1]); 
}

void build(int v, int l, int r)
{
	if (l == r)
	{
		tr[v] = {a[l], l}; 
		return;
	}
	
	int mid = (l + r) / 2;
	build(v * 2, l, mid);
	build(v * 2 + 1, mid + 1, r); 
	
	merge(v);
}

pair <int, int> get(int v, int l, int r, int ll, int rr)
{
	if (l > rr || r < ll)
	return {INT_MIN, -1};
	
	if (l >= ll && r <= rr)
	return tr[v];
	
	int mid = (l + r) / 2;
	return max(get(v * 2, l, mid, ll, rr), get(v * 2 + 1, mid + 1, r, ll, rr));
}

vector <long long> f(int l, int r)
{
	if (l > r)
	return {0}; 
	
	int idx = get(1, 1, n, l, r).second;
	vector <long long> v1 = f(l, idx-1), v2 = f(idx+1, r), ans;
	
	ans.resize(min(r - l + 2, k + 1), inf); 
	
	int sz1 = v1.size(), sz2 = v2.size();
	for (int i = 0; i < sz1; i++)
	for (int j = 0; j < sz2 && i + j <= k; j++) 
	{
		ans[i+j] = min(ans[i+j], v1[i] + v2[j] + 1ll * i * j * a[idx]);
		
		if (i + j + 1 <= k)
		ans[i+j+1] = min(ans[i+j+1], v1[i] + v2[j] + 1ll * i * j * a[idx] + 1ll * a[idx] * (i + j + 1));
	}
	
	return ans; 
}

void solve()
{
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		cin >> a[i];
		
		build(1, 1, n); 
		
		auto ans = f(1, n);
		cout << ans[k] << endl; 
	}
}
 
int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	read();
	solve();
}
