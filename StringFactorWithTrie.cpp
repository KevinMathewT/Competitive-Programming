#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll maxi;

struct trie{
	trie* children[2];
	ll val;
	ll depth;
	ll eow;

	trie(){
		val = 0;
		eow = 0;
	}
};

void insert(trie *root, string word){
	cout << word << "\n";
	trie *curr = root;

	for(ll i=0;i<word.size();i++){
		cout << word[i] << " ";
		if(word[i] == 'x'){
			cout << curr->children[0] << " ";
			trie *node = curr->children[0];
			cout << (node == NULL) << " ";
			if(!(node)){
				node = new trie();
				curr->children[0] = node;
			}
			curr->children[0]->val+=1;
			cout << curr->children[0]->val << " ";
			curr->children[0]->depth = i+1;
			cout << curr->children[0]->depth << "\n";
			if(i == word.size()-1)
				curr->children[0]->eow = 1;

			curr = curr->children[0];
		}
		if(word[i] == 'y'){
			if(!(curr->children[1]))
				curr->children[1] = new trie();
			curr->children[1]->val++;
			cout << curr->children[1]->val << " ";
			curr->children[1]->depth = i+1;
			cout << curr->children[1]->depth << "\n";
			if(i == word.size()-1)
				curr->children[1]->eow = 1;

			curr = curr->children[1];
		}
	}
}

void dfs(trie *curr){
	maxi = max(maxi, curr->val * curr->depth);
	if(curr->children[0])
		dfs(curr->children[0]);
	if(curr->children[1])
		dfs(curr->children[1]);
}

void te(){
	ll n;
	cin >> n;
	string s[n];
	for(ll i=0;i<n;i++)
		cin >> s[i];

	trie *root = new trie();

	for(ll i=0;i<n;i++){
		insert(root, s[i]);
	}

	maxi = -1;

	cout << root->children[0]->depth << "\n";
	// dfs(root->children[0]);
	// dfs(root->children[1]);

	cout << maxi << "\n";
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