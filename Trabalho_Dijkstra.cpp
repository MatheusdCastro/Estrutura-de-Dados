#include<iostream>
#include<cfloat>
#include<vector>
#include<queue>
using namespace std;

class Grafo2{
    public:
    int N; // vertíces
    int M; //arestas
    vector<vector<int> > adjL;
    vector<vector<double> > peso;

    void Dijkstra(int s);
    void Dijkstra_Melhorado(int s);
};

int main(){
    Grafo2 G;
    // exemplo de um grafo de 5 vértices e 6 arestas para teste
    G.N = 5;
    G.M = 6;
    G.adjL.resize(G.N);
    G.peso.resize(G.N);
    G.adjL[0].push_back(1); G.peso[0].push_back(2.0);
    G.adjL[0].push_back(2); G.peso[0].push_back(4.0);
    G.adjL[1].push_back(2); G.peso[1].push_back(1.0);
    G.adjL[1].push_back(3); G.peso[1].push_back(7.0);
    G.adjL[2].push_back(4); G.peso[2].push_back(3.0);
    G.adjL[3].push_back(4); G.peso[3].push_back(1.0);
    cout<<"Algoritmo de Dijkstra normal:\n";
    G.Dijkstra(0);
    cout<<"\nAlgoritmo de Dijkstra com heap minima:\n";
    G.Dijkstra_Melhorado(0);
    return 0;
}

// Dijkstra normal
void Grafo2::Dijkstra(int s){
    if(N<=0) return;
    int x,y,i,j;
    vector<int> pai(N,s);
    vector<int> ok(N,0);
    vector<double> dist(N,DBL_MAX);
    dist[s]=0;
    for(i=0;i<N;i++){
        double d_min=DBL_MAX;
        for(y=0;y<N;y++){
            if((!ok[y])&&(d_min>=dist[y])){
                d_min=dist[y];
                x=y;
            }
        }
        ok[x]=1;
        for(j=0;j<adjL[x].size();j++){
            y=adjL[x][j];
            double p=peso[x][j];
            if((!ok[y])&&(dist[y]>p+dist[x])){
                dist[y]=p+dist[x];
                pai[y]=x;
            }
        }
    }
     cout << "Vertices:  ";
    for (x=0; x<N; x++) cout << x << " ";
    cout << "\n";

    cout << "Distancia: ";
    for (x=0; x<N; x++) cout << dist[x] << " ";
    cout << "\n";

}

// Dijkstra com Fila de Prioridade
void Grafo2::Dijkstra_Melhorado(int s){
    if(N<=0) return;
    int x,y,i,j;
    vector<int> pai(N,s);
    vector<int> ok(N,0);
    vector<double> dist(N,DBL_MAX);
    dist[s]=0;
    priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> fila_prioridade; // (distância,vértice) com heap mínima
    fila_prioridade.push({0,s});
    while(!fila_prioridade.empty()){
        pair<double, int> topo = fila_prioridade.top();
        double d = topo.first;
        int x = topo.second;
        fila_prioridade.pop();
        if(ok[x])continue;
        ok[x]=1;
        for(j=0;j<adjL[x].size();j++){
            y=adjL[x][j];
            double p = peso[x][j];
             if((!ok[y])&&(dist[y]>p+dist[x])){
                dist[y]=p+dist[x];
                pai[y]=x;
                fila_prioridade.push({dist[y],y});
            }
        }
    }
     cout << "Vertices:  ";
    for (i=0; i<N; i++) cout << i << " ";
    cout << "\n";

    cout << "Distancia: ";
    for (i=0; i<N; i++) cout << dist[i] << " ";
    cout << "\n";
}