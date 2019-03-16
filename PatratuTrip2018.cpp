#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll arr[(ll) 1e5 + 10];
ll tree[4 * ((ll) 1e5 + 10)];
ll lazy[4 * ((ll) 1e5 + 10)];

void build_tree(ll node, ll a, ll b) {
  	if(a > b) return;
  	
  	if(a == b) {
  		tree[node] = arr[a];
		return;
	}
	
	build_tree(node*2, a, (a+b)/2);
	build_tree(node*2+1, 1+(a+b)/2, b);
	
	tree[node] = max(tree[node*2], tree[node*2+1]);
}

void update_tree(ll node, ll a, ll b, ll i, ll j, ll s) {
  
  	if(lazy[node] != 0) {
  		tree[node] += (b - a + 1) * lazy[node];

		if(a != b) {
			lazy[node*2] += lazy[node];
    		lazy[node*2+1] += lazy[node];
		}

   		lazy[node] = 0;
  	}
  
	if(a > b || a > j || b < i)
		return;
    
  	if(a >= i && b <= j) {
  		tree[node] += (b - a + 1) * s;

		if(a != b) {
			lazy[node*2] += s;
			lazy[node*2+1] += s;
		}

    		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j, s);
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, s);

	tree[node] = max(tree[node*2], tree[node*2+1]);
}

ll query_tree(ll node, ll a, ll b, ll i, ll j) {
	if(a > b || a > j || b < i) return -1;

	if(lazy[node] != 0) {
  		tree[node] += (b - a + 1) * lazy[node];

		if(a != b) {
			lazy[node*2] += lazy[node];
    		lazy[node*2+1] += lazy[node];
		}

		lazy[node] = 0;
		// cout << "Hello\n";
	}

	if(a >= i && b <= j){
		ll q1 = tree[node];
		// cout << node << " " << q1.red << " " << q1.green << " " << q1.blue << '\n';
		return tree[node];
	}

	ll q1 = query_tree(node*2, a, (a+b)/2, i, j);
	ll q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);

	// cout << node << " " << q1.red << " " << q1.green << " " << q1.blue << '\n';
	// cout << node << " " << q2.red << " " << q2.green << " " << q2.blue << '\n';
	
	return max(q1, q2);
}

void te(){
	ll n;
	cin >> n;

	for(ll i=0;i<n;i++)
		cin >> arr[i];

	for(ll i=0;i<4 * ((ll) 1e5 + 10);i++){
		lazy[i] = 0;
	}

	build_tree(1, 0, n-1);

	ll q;
	cin >> q;
	while(q--){
		ll ch;
		cin >> ch;

		if(ch == 1){
			ll l, r, s;
			cin >> l >> r >> s;
			update_tree(1, 0, n-1, l-1, r-1, s);
		}

		if(ch == 2){
			ll pos;
			cin >> pos;
			pos--;

			if(pos == n-1){
				cout << "WOW\n";
				continue;
			}

			ll l = pos, r = n-1;

			while(l < r){
				ll mid = (l + r) / 2;

				ll val = query_tree(1, 0, n-1, pos+1, mid);

				if(val <= query_tree(1, 0, n-1, pos, pos))
					l = mid + 1;
				else
					r = mid;
			}

			// for(ll i=0;i<n;i++)
			// 	cout << query_tree(1, 0, n-1, i, i) << " ";
			// cout << "\n";
			if(query_tree(1, 0, n-1, pos, pos) < query_tree(1, 0, n-1, l, l))
				cout << query_tree(1, 0, n-1, l, l) << "\n";
			else
				cout << "WOW\n";
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);

	te();
	
	return 0;
}