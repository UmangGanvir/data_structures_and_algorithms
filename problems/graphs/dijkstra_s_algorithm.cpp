#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int extractMinDistNode( vector<bool>& spSet, vector<int>& distFromSrc ){

    unsigned long int V = spSet.size();

    int minVal = numeric_limits<int>::max();
    int minNodeIdx = -1;
    for( int i=0; i<V; i++ ){
        if( !spSet[i] && distFromSrc[i] < minVal ){
            minVal = distFromSrc[i];
            minNodeIdx = i;
        }
    }

    spSet[minNodeIdx] = true;
    return minNodeIdx;
}

vector<int> dijkstra( vector<vector<int>> graph, int src ){

    unsigned long int V = graph.size();

    vector<bool> spSet( V, false );
    vector<int> distFromSrc( V, numeric_limits<int>::max() );

    // Initialization
    distFromSrc[ src ] = 0;

    for( int i=0; i<V-1; i++ ){

        int minDistNodeIdx = extractMinDistNode( spSet, distFromSrc );

        for( int j=0; j<V; j++ ){

            if(
                !spSet[j] &&
                graph[minDistNodeIdx][j] &&
                distFromSrc[minDistNodeIdx] != numeric_limits<int>::max() &&
                distFromSrc[j] > distFromSrc[minDistNodeIdx] + graph[minDistNodeIdx][j]
            ){
                distFromSrc[j] = distFromSrc[minDistNodeIdx] +  graph[minDistNodeIdx][j];
            }
        }
    }
    return distFromSrc;
}

int main() {

    vector<vector<int>> graph = {
            { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
            { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
            { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
            { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
            { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
            { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
            { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
            { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
            { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };

    vector<int> distancesFromSrc = dijkstra( graph, 0 );
    cout<<"Vertex   Distance from Source"<<endl;
    int n = (int) graph.size();
    for( int i=0; i<n; i++ )
        cout<<i<<"                "<<distancesFromSrc[i]<<" "<<endl;

    return 0;
}