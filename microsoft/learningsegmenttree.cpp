#include <iostream>
using namespace std;

int a[100005], seg[4 * 100005];

void build_segment_tree(int ind, int low, int high)
{
    if (low == high)
    {
        seg[ind] = a[low];
        return;
    }
    int mid = (low + high) / 2;
    build_segment_tree(2 * ind + 1, low, mid);
    build_segment_tree(2 * ind + 2, mid + 1, high);
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}
int query(int ind, int low, int high, int l, int r)
{
    // condition-1 range completely exists
    if (low >= l && high <= r)
    {
        return seg[ind];
    }

    // range doesn't lies
    if (high < l || low > r)
    {
        return INT_MIN;
    }

    int mid = (low + high) / 2;
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);
    return max(left, right);
}
int main()
{
    int n;
    cout << "enter array size ";
    cin >> n;
    cout << "\nenter array elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build_segment_tree(0, 0, n - 1);
    int q;
    cout << "\nenter no of queries\n";
    cin >> q;
    while (q--)
    {
        cout << "\nenter left and right index\n";
        int l, r;
        cin >> l >> r;
        cout << query(0, 0, n - 1, l, r);
    }
}