//LEVEL OF EACH NODE
void dfsLevel(ll curr, ll parent, unordered_map<ll, vector<ll>> &m, vector<ll> &level, ll curLevel)
{
    cout << curr << ' ';
    level[curr] = curLevel;
    for(auto it: m[curr])
    {
        if(it != parent)
        {
            dfsLevel(it, curr, m, level, (curLevel + 1));
        }
    }
}

//SUBTREE SIZE
void dfsSubtree(ll curr, ll parent, unordered_map<ll, vector<ll>> &m, vector<ll> &subtree)
{
    for(auto it: m[curr])
    {
        if(it != parent)
        {
            dfsSubtree(it, curr, m, subtree);
            subtree[curr] += subtree[it];
        }
    }

    subtree[curr]++;
}


/****************   BFS     ******************/
    vector<ll> vis((n + 1), 0);
    ll root = 1;
    queue<ll> qu;
    qu.push(root);
    while(!qu.empty())
    {
        ll curr = qu.front();
        qu.pop();
        vis[curr] = 1;
        for(auto it: m[curr])
        {
            if(!vis[it])
            {
                qu.push(it);
            }
        }
    }
    cout << '\n';

//****************** dfsMaxDistFromGivenNode
void dfsMaxDistFromGivenNode(ll curr, ll parent, unordered_map<ll, vector<ll>> &m, vector<ll> &distance)
{
    if(parent == 0)
    {
        distance[curr] = 0;
    }
    else
    {
        distance[curr] = (1 + distance[parent]);
    }

    for(auto it: m[curr])
    {
        if(it != parent)
        {
            dfsMaxDistFromGivenNode(it, curr, m, distance);
        }
    }
}


vector<ll> isLeaf(n + 1, 0);
void dfsIsLeaf(ll cur, ll par, unordered_map<ll, vector<ll>> &up, vector<ll> isLeaf)
{
    ll flg = 0;
    for(auto child : up[cur])
    {
        if(child != par)
        {
            flg = 1;
            dfsIsLeaf(child, cur, up, isLeaf);
        }
    }

    isLeaf[cur] = (flg) ? 0LL : 1LL;
}


//****  IN-OUT Time Trick for Ancestor/Descendant Problem
void dfsInOut(ll curr, ll parent, unordered_map<ll, vector<ll>> &m, vector<ll> &in, vector<ll> &out, ll &time)
{
    in[curr] = time;
    time++;
    for(auto it: m[curr])
    {
        if(it != parent)
        {
            dfsInOut(it, curr, m, in, out, (time));
        }
    }
    out[curr] = time;
    time++;
}

bool isAncestor(ll x, ll y, vector<ll> &in, vector<ll> &out) // -> checks if x is ancestor of y
{
    if(in[x] < in[y] && out[y] < out[x])
    {
        return true;
    }
    return false;
}


// ********(MOST IMPORTANT) -> BINARY LIFTING *************
void dfs1stParent(ll curr, ll parent, unordered_map<ll, vector<ll>> &m, vector<vector<ll>> &up)
{
    up[0][curr] = parent;

    for(auto it : m[curr])
    {
        if(it != parent)
        {
            dfs1stParent(it, curr, m, up);
        }
    }
}

ll findkthparentofx(ll x, ll k, vector<vector<ll>> &up)
{
    ll n = up[0].size();
    for(ll i=0; i<=(ceil(log2(n))); i++)
    {
        if((1 << i) & k)
        {
            x = up[i][x];
            if(x == -1)
            {
                return -1;
            }
        }
    }
    return x;
}

void tantanmaymay()
{ 
    ll n, q;
    cin >> n >> q;

    unordered_map<ll, vector<ll>> m;
    for(ll i=2; i<=n; i++)
    {
        ll a;
        cin >> a;
        m[a].push_back(i);
        m[i].push_back(a);
    }

    vector<vector<ll>> up((ceil(log2(n)) + 1), vector<ll> ((n + 1), -1));

    dfs1stParent(1, -1, m, up);

    for(ll i=1; i<=(ceil(log2(n))); i++)
    {
        for(ll j=1; j<=n; j++)
        {
            if(up[i - 1][j] == -1)
            {
                continue;
            }
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    } lien(up)

    while(q--)
    {
        ll x, k;
        cin >> x >> k;
        cout << findkthparentofx(x, k, up) << '\n';
    }

    return;
}


