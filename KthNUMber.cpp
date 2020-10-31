#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define P 1000000007
vector<ll>  t[400005];
vector<ll> merge(vector<ll> &a, vector<ll> &b)
{
  
    ll s1 = a.size();
    ll s2 = b.size();
    ll i = 0;
    ll j = 0;
    vector<ll> temp;
    while (i < s1 && j < s2)
    {
        if (a[i] <= b[j])
        {
            temp.push_back(a[i]);
            i++;
        }
        else
        {
            temp.push_back(b[j]);
            j++;
        }
    }

    while (i < s1)
    {
        temp.push_back(a[i]);
        i++;
    }
    while (j < s2)
    {
        temp.push_back(b[j]);
        j++;
    }

    return temp;
}

void build(vector<ll> a, ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
         t[v] = {a[tl]};
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        t[v] = merge(t[2*v], t[2 * v + 1]);
    }
}

vector<ll> get(ll v, ll tl, ll tr, ll l, ll r)
{   if(l > r)
    return {};
    if (tl == l && tr == r)
    {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    vector<ll> v1 = get(2 * v, tl, tm, l, min(tm, r));
    vector<ll>  v2 = get(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
    return (merge(v1, v2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i, j, n, m;
    cin >> n >> m;
    vector<ll> a;

    for (i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a.push_back(x);
    }
    build(a, 1, 0, n - 1);

    while (m--)
    {
        ll l, r, z;
        cin >> l >> r >> z;
        l--;
        r--;
        z--;
        vector<ll> temp = get(1, 0, n - 1, l, r);
        cout<<temp[z]<<"\n";
    }

    return (0);
}