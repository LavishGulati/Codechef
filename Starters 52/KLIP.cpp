#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair< int, pair<int, int> > tii;
typedef pair< long long, pair<long long, long long> > tll;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define MAX 100005
#define MOD 1000000007

// Updates a node in Binary Index Tree (BITree) at given index
// in BITree. The given value 'val' is added to BITree[i] and
// all of its ancestors in tree.
void updateBIT(int BITree[], int n, int index, int val)
{
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
 
    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
        // Add 'val' to current node of BI Tree
        BITree[index] += val;
 
        // Update index to that of parent in update View
        index += index & (-index);
    }
}
 
// Constructs and returns a Binary Indexed Tree for given
// array of size n.
int *constructBITree(int arr[], int n)
{
    // Create and initialize BITree[] as 0
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;
 
    // Store the actual values in BITree[] using update()
    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);
 
    // Uncomment below lines to see contents of BITree[]
    //for (int i=1; i<=n; i++)
    //      cout << BITree[i] << " ";
 
    return BITree;
}
 
// SERVES THE PURPOSE OF getElement()
// Returns sum of arr[0..index]. This function assumes
// that the array is preprocessed and partial sums of
// array elements are stored in BITree[]
int getSum(int BITree[], int index)
{
    int sum = 0; // Initialize result
 
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
 
    // Traverse ancestors of BITree[index]
    while (index>0)
    {
        // Add current element of BITree to sum
        sum += BITree[index];
 
        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}
 
// Updates such that getElement() gets an increased
// value when queried from l to r.
void update(int BITree[], int l, int r, int n, int val)
{
    // Increase value at 'l' by 'val'
    updateBIT(BITree, n, l, val);
 
    // Decrease value at 'r+1' by 'val'
    updateBIT(BITree, n, r+1, -val);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		int *a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = 0;
		}
		
		int *bit = constructBITree(a, n);

		string s;
		cin >> s;
		int total = n-k+1;
		for (int i = 0; i < n; i++) {
			int num = getSum(bit, i);
			if (num%2) {
				s[i] = (s[i] == '0' ? '1' : '0');
			}
			if (n-i >= k && total > 0 && s[i] == '1') {
				s[i] = '0';
				update(bit, i+1, i+k-1, n, 1);
				total--;
			}
		}
		cout << s << endl;
	}
}