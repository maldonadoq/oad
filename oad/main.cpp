#include <iostream>
#include <thread>
#include "../func/sort.cpp"

using namespace std;

template<typename T>
T v_ab(T a){
	if(a < 0)	return 0-a;
	return a;
}

bool compare(int a, int b){
	//return (a<b)? true: false;
	return (v_ab<int>(a)<v_ab<int>(b))? true: false;
}

void print(int *a, int t){
	for(int i=0; i<t; i++)	cout << *(a+i) << " ";
	cout << endl;
}

int main(int argc, char const *argv[]){
	int t, aux;
	cout << "numeros a ordenar:  "; cin >> t;
	int *A = new int[t];
	int *B = new int[t];
	int *C = new int[t];
	int *D = new int[t];
	int *E = new int[t];

    for(int i=0; i<t; i++){
    	aux = rand()%100;
    	A[i] = aux;
    	B[i] = aux;
    	C[i] = aux;
    	D[i] = aux;
    	E[i] = aux;
    }

    thread a(bubble_sort, A, t, compare);
    thread b(select_sort, B, t, compare);
    thread c(insertion_sort, C, t, compare);
    thread d(cocktail_sort, D, t, compare);
    
    struct timeval ti, tf;
    double tiempo;
    gettimeofday(&ti, NULL);
    thread e(quick_sort, E, 0, t-1, compare);
    e.join();
    gettimeofday(&tf, NULL);
    tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000;
    printf("time quick_sort:	%.28f segundos\n", tiempo/1000);

    a.join(); b.join(); c.join(); d.join(); 
    delete []A; delete []B; delete []C; delete []D; delete []E; 
	return 0;
}	
