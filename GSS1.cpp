#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define P 1000000007
#define inf 1e18
struct node
{
    ll pref;
    ll suf;
    ll sum;
    ll seg;
};

node t[400005];
node merge(node &a, node &b)
{
    node temp;
    temp.sum = a.sum + b.sum;
    temp.pref = max(a.sum + b.pref, a.pref);
    temp.suf = max(b.sum + a.suf, b.suf);
    temp.seg = max(max(a.seg, b.seg), a.suf + b.pref);
    return temp;
}
void build(ll a[], ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        t[v].pref = a[tl];
        t[v].seg = a[tl];
        t[v].suf = a[tl];
        t[v].sum = a[tl];
    }
    else
    {

        ll tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
}

node get(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
         { 
             node temp; 
             temp.pref = temp.seg = temp.sum = temp.suf = 0;
             return temp;
         }
    if (tl == l && tr == r)
    {
        return t[v];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        node x1 = get(2 * v, tl, tm, l, min(r, tm));
        node x2 = get(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
        return (merge(x1,x2));
    }
}

int main()
{
    ll i, j, n;
    cin >> n;
    ll a[n + 5];
    for (i = 0; i < n; i++)
        cin >> a[i];
    build(a, 1, 0, n - 1);
    ll m;
    cin >> m;
    while (m--)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        cout <<max((ll)0,get(1, 0, n - 1, l, r).seg)<<"\n";
         
    }

    return (0);
}