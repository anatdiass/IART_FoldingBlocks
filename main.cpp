#include <iostream>

#include "Algorithms.h"
#include "Game.h"

using namespace std;

int main() {

    /*TESTES*/

/*    int row, col,V,s;
    cout<<"nRows: "; cin>>row; cout<<"nCols: "; cin>>col;

    Board b(row, col);

    //TEST BFS
    V = row * col;
    Graph graph(V);

    b.setPiece(1,1,'a');

    for(unsigned int i = 0; i < b.getNumRows(); i++){
        for(unsigned int j = 0; j < b.getNumCols(); j++){
            if(b.getBoard().at(i).at(j) != ' '){
                s = 1+j+i*b.getNumRows();
                graph.addEdge(s,1+(j-1)+(i-1)*b.getNumRows());
                graph.addEdge(s,1+(j)+(i-1)*b.getNumRows());
                graph.addEdge(s,1+(j+1)+(i-1)*b.getNumRows());
                graph.addEdge(s,1+(j-1)+(i)*b.getNumRows());
                graph.addEdge(s,1+(j+1)+(i)*b.getNumRows());
                graph.addEdge(s,1+(j-1)+(i+1)*b.getNumRows());
                graph.addEdge(s,1+(j)+(i+1)*b.getNumRows());
                graph.addEdge(s,1+(j+1)+(i+1)*b.getNumRows());
            }
        }
    }

    graph.BFS(s);*/

    Game g=Game();
}
