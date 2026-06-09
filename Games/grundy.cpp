/*
    G(u) = MEX(G(v), ... ,G(v))
    donde G(v) son estados que puedo llegar desde u

    si G(u) > 0 hay una serie de pasos que puedo realizar para ganar

    si tengo multiples "pilas" trato como juegos "separados"
    G_total = G(pila1) ^ G(pila^)... ^ G(pila3)
    G_total > 0, primero puede ganar
    
    si la cantidad de pilas es par el segundo sin importar si G_total > 0, perdere

*/  

/*
G(u) para donde puedo ir a estado de u - x donde x pertenece a divisores de u NO menores que k
*/
int grundy(int u, int k){
    //k mayor divisor valido
    if(dp.count(u)){
        return dp[u];
    }
 
    set<int> my;
    for(int i = 2; i * i <= u; i++){
        if((u % i == 0)){
            if(i >= k && i != u){
                my.insert(grundy(i, k));
            }
            if(i * i != u){
                if((u / i >= k) && (u / i) != u){
                    my.insert(grundy(u / i, k));
                }
            }
        }
    }
 
    int mex = 0;
    while(my.count(mex)) mex++;
    dp[u] = mex; 
    return dp[u];
}