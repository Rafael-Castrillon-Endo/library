const int LOG = 20;

int up[MX][LOG];
int depth[MX];
vector<int> g[MX];
 
void dfs(int u, int p, int d = 0){
    depth[u] = d;
    up[u][0] = p;
    for(int i = 1; i < LOG; i++){
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for(int v : g[u]){
        if(v != p){
            dfs(v, u, d + 1);
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
