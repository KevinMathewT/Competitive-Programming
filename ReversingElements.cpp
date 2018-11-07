#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

struct subarray{
	ll max_prefix;
	ll max_suffix;
	ll tot_sum;
	ll max_subarray;
};

ll a[(ll) 1e5 + 100];
subarray tree[4 * (ll) 1e5 + 100];


subarray query(ll i, ll a, ll b, ll l, ll r){
	subarray min;
	min.max_prefix = LLONG_MIN / 2;
	min.max_suffix = LLONG_MIN / 2;
	min.tot_sum = 0;
	min.max_subarray = LLONG_MIN / 2;
	if(r < l || r < a || l > b)
		return min;

	if(a >= l && b <= r)
		return tree[i];

	ll mid = (a + b) >> 1;
	subarray leftChild = query((i<<1), a, mid, l, r);
	subarray rightChild = query((i<<1)+1, mid+1, b, l, r);

	subarray ans;
	ans.max_prefix = max(leftChild.max_prefix, leftChild.tot_sum + rightChild.max_prefix);
	ans.max_suffix = max(rightChild.max_suffix, rightChild.tot_sum + leftChild.max_suffix);
	ans.tot_sum = leftChild.tot_sum + rightChild.tot_sum;
	ans.max_subarray = max(leftChild.max_suffix+rightChild.max_prefix, max(leftChild.max_subarray, rightChild.max_subarray));

	return ans;
}

void printSubArray(subarray a){
	cout << a.max_prefix << " " << a.max_suffix << " " << a.tot_sum << " " << a.max_subarray << "\n";
}

void buildTree(ll i, ll l, ll r){
	// cout << i << " " << l << " " << r << "\n";
	if(l == r){
		tree[i].max_prefix = a[l];
		// cout << a[l] << "\n";
		// cout << tree[i].max_prefix << " 434\n";
		tree[i].max_suffix = a[l];
		tree[i].max_subarray = a[l];
		tree[i].tot_sum = a[l];
		// printSubArray(tree[i]);
		return;
	}

	ll mid = (l + r) >> 1;
	// cout << i << " " << mid << "-\n";

	buildTree(i << 1, l, mid);
	buildTree((i << 1) + 1, mid + 1, r);

	tree[i].max_prefix = max(tree[(i<<1)].max_prefix, tree[(i<<1)].tot_sum + tree[(i<<1)+1].max_prefix);
	tree[i].max_suffix = max(tree[(i<<1)+1].max_suffix, tree[(i<<1)+1].tot_sum + tree[(i<<1)].max_suffix);
	tree[i].tot_sum = tree[(i<<1)].tot_sum + tree[(i<<1)+1].tot_sum;
	tree[i].max_subarray = max(tree[(i<<1)].max_suffix+tree[(i<<1)+1].max_prefix, max(tree[(i<<1)].max_subarray, tree[(i<<1)+1].max_subarray));
}

subarray merge(subarray leftChild, subarray rightChild){
	subarray ans;
	ans.max_prefix = max(leftChild.max_prefix, leftChild.tot_sum + rightChild.max_prefix);
	ans.max_suffix = max(rightChild.max_suffix, rightChild.tot_sum + leftChild.max_suffix);
	ans.tot_sum = leftChild.tot_sum + rightChild.tot_sum;
	ans.max_subarray = max(leftChild.max_suffix+rightChild.max_prefix, max(leftChild.max_subarray, rightChild.max_subarray));
	return ans;
}

subarray swap(subarray a){
	ll t = a.max_prefix;
	a.max_prefix = a.max_suffix;
	a.max_suffix = t;
	return a;
}

void te(){
	ll n, q;
	cin >> n >> q;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	buildTree(1, 0, n-1);

	// for(ll i=1;i<=13;i++){
	// 	cout << i << " ";
	// 	printSubArray(tree[i]);
	// }
	// for(ll i=0;i<n;i++)
	// 	for(ll j=i;j<n;j++){
	// 		cout << i << " " << j << " " ;
	// 		printSubArray(query(1, 0, n-1, i, j));
	// 	}

	while(q--){
		ll l, r;
		cin >> l >> r;

		if(l == 1 && r == n){
			cout << query(1, 0, n-1, 0, n-1).max_subarray << "\n";
			continue;
		}
		if(l == 1){
			subarray left = query(1, 0, n-1, 0, r-1);
			subarray right = query(1, 0, n-1, r, n-1);
			// printSubArray(left);
			// printSubArray(right);
			left = swap(left);
			subarray ans = merge(left, right);
			ll final_ans = max(left.max_subarray, max(right.max_subarray, ans.max_subarray));
			cout << final_ans << "\n"; 
			continue;
		}
		if(r == n){
			subarray left = query(1, 0, n-1, 0, l-2);
			subarray right = query(1, 0, n-1, l-1, n-1);
			right = swap(right);
			subarray ans = merge(left, right);
			ll final_ans = max(left.max_subarray, max(right.max_subarray, ans.max_subarray));
			cout << final_ans << "\n"; 
			continue;
		}
		else{
			subarray left = query(1, 0, n-1, 0, l-2);
			subarray mid = query(1, 0, n-1, l-1, r-1);
			subarray right = query(1, 0, n-1, r, n-1);
			mid = swap(mid);
			subarray ans = merge(left, merge(mid, right));
			ll final_ans = max(mid.max_subarray, max(left.max_subarray, max(right.max_subarray, ans.max_subarray)));
			cout << final_ans << "\n"; 
			continue;
		}
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