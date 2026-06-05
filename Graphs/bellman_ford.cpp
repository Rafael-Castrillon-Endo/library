
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
int64_t oo = 100000000000000;
template <typename T>
struct BM{
    struct Edge{
        int a, b;
        T w;
    };
    
    int n, m, x;
    vector<int> p;
    vector<Edge> edges;
    vector<T> dist;
    bool neg_cycle, runf, readf;

    BM(T _n, int _m){
        n = _n, m = _m;
        neg_cycle = runf = readf = 0;
        dist.resize(n + 1, oo);
        p.resize(n + 1, -1);
    } 

    void read(){
        readf = 1;
        for(int i = 0; i < m; i++){
            int u, v; cin >> u >> v;
            T w; cin >> w;
            edges.push_back({u, v, w});
        }
    }

    void run(int s){
        assert(readf == true);

        dist[s] = 0, p[s] = -1;
        //shuffle(edges.begin(), edges.end(), gen);
        //fill(dist.begin(), dist.end(), 0);// solo valido para detectar ciclo
        runf = 1;

        for(int i = 0; i < n; i++){
            x = -1;
            bool work = 0;
            for(Edge e : edges){
                if(dist[e.a] != oo && dist[e.b] > dist[e.a] + e.w){
                    dist[e.b] = dist[e.a] + e.w;
                    p[e.b] = e.a;
                    x = e.b;
                    work = 1;
                }
            }
            if(!work) break;
        }
        neg_cycle = (x != -1);
    }

    vector<int> find_cycle(){
        assert(runf == true);
        assert(neg_cycle == true);

        for(int i = 0; i < n; i++)
            x = p[x];
        
        vector<int> cycle;
        int y = x;
        do{
            cycle.push_back(y);
            y = p[y];
        }while(y != x);

        cycle.push_back(x);
        reverse(cycle.begin(), cycle.end());
        return cycle;
    }
    
};

