#include <iostream>

using namespace std;

int main(){
    int n,a=0,i=1,b,m[100][100];
    n = 3;
    b=n/2;
    while(i<=(n*n)){
        if(a<0)a=n-1;
        if(b==n)b=0;
        if(m[a][b]>=1&&m[a][b]<=(n*n)){
            a=a+2;b--;
            if (!(a<n))a=a-n;
            if(b<0)b=n-1;
            m[a][b]=i;
        }
        else {m[a][b]=i;}
        --a;++b;
        i++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)    cout<<m[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}