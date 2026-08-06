const int MOD = 10000007, oo = 2000000001, MX = 200001;
const int LOG = 20;
 
int up[MX][LOG], sp[MX][LOG];
int depth[MX];
vector<pair<int, int>> g[MX];
 
//min +oo
//max -oo
const int CMP = oo;
 
int op(int a, int b){
    return min(a, b);
}
 
void dfs(int u, int p, int w, int d = 0){
    depth[u] = d, up[u][0] = p;
    sp[u][0] = (u != p ? w : CMP);
    for(int i = 1; i < LOG; i++){
        up[u][i] = up[up[u][i - 1]][i - 1];
        sp[u][i] = op(sp[u][i - 1], sp[up[u][i - 1]][i - 1]);
    }
    for(auto v : g[u]){
        if(v.ff != p){
            dfs(v.ff, u, v.ss, d + 1);
        }
    }
}
 
int log(int x){
    return 31 - __builtin_clz(x);
}
 
int getUP(int u, int s, const int e){
    if(s == e){
        return u;
    }
    int nxt = up[u][log(s - e)];
    return getUP(nxt, depth[nxt], e);
}
 
int lca(int u, int v){
    if(depth[u] > depth[v]){
        u = getUP(u, depth[u], depth[v]);
    }else if(depth[v] > depth[u]){
        v = getUP(v, depth[v], depth[u]);
    }
    if(u == v){
        return u;
    } 
    int mx = log(depth[u]);
    for(int i = mx; i >= 0; i--){
        if(up[u][i] != up[v][i]){
            u = up[u][i], v = up[v][i];
        }
    }
    return up[u][0];
}
 
pair<int, int> getUPQ(int u, int s, int value, const int e){
    if(s == e){
        return {u, value};
    }else{
        int nxt = up[u][log(s - e)];
        return getUPQ(nxt, depth[nxt], op(value, sp[u][log(s - e)]), e);
    }
}
 
int query(int u, int v){
    int m = lca(u, v);
    int res = CMP;
    res = op(res, getUPQ(u, depth[u], CMP, depth[m]).ss);
    res = op(res, getUPQ(v, depth[v], CMP, depth[m]).ss);
    return res;
}
struct Edge{
    int u, v, w;
};
