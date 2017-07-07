#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

    int A[20][20], B[20][20], C[20][20];
    int k, m, n;
    m = 3;  k = 5;  n = 6;
    srand(time(NULL));
    
    //A: k*m
    //B: m*n
    //C: k*n

    for(int i=0; i<k; ++i)
        for(int j=0; j<m; ++j)
            A[i][j] = i%(k-1);
    
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            B[i][j] = 1;

    for(int i=0; i<k; ++i)
        for(int j=0; j<n; ++j)
            C[i][j] = 0;

    for(int i=0; i<k; ++i)
        for(int j=0; j<n; ++j)
            for(int z=0; z<m; ++z)
                C[i][j] += A[i][z] * B[z][j];

    cout<<"Matriz A: "<<endl;
    for(int i=0; i<k; ++i){
        for(int j=0; j<m; ++j)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }

    cout<<"\nMatriz B: "<<endl;
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j)
            cout<<B[i][j]<<" ";
        cout<<endl;
    }

    cout<<"\nMatriz C: "<<endl;
    for(int i=0; i<k; ++i){
        for(int j=0; j<n; ++j)
            cout<<C[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}