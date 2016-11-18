#include <iostream>
#include <unistd.h>
#include <sys/time.h>
using namespace std;



void swap1(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort(int *a, int t, bool (*compare)(int,int)){
    struct timeval ti, tf;
    double tiempo;
    gettimeofday(&ti, NULL);

    int aux=1;
    for(int i=t-1;aux!=0 and i>0;i--){
        aux = 0;
        for(int j=0;j<i;j++)
            if(compare(*(a+j+1),*(a+j))){
                swap1((a+j+1),(a+j));
                aux+=1;
            }
    }

    gettimeofday(&tf, NULL);
    tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000;
    printf("time bubble_sort:       %.28f segundos\n", tiempo/1000);
}

void insertion_sort(int *a, int t, bool (*compare)(int, int)){
    struct timeval ti, tf;
    double tiempo;
    gettimeofday(&ti, NULL);

    int aux;
    for(int i=1;i<t;i++){
        aux = *(a+i);
        for(int j=i;j>0 and compare(aux,*(a+j-1));j--){
            swap1((a+j),(a+j-1));
            *(a+j-1) = aux;
        }
    }

    gettimeofday(&tf, NULL);
    tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000;
    printf("time insertion_sort:    %.28f segundos\n", tiempo/1000);
}

void select_sort(int *a, int t, bool (*compare)(int, int)){
    struct timeval ti, tf;
    double tiempo;
    gettimeofday(&ti, NULL);

    int *temp, aux;
    for(int i=0;i<t-1;i++){
        for(int j=i+1;j<t;j++)
            if(compare(*(a+j),*(a+i)))   swap1(a+j, a+i);
    }

    gettimeofday(&tf, NULL);
    tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000;
    printf("time select_sort:       %.28f segundos\n", tiempo/1000);
}

void cocktail_sort(int *p, int tam, bool (*compare)(int, int)){
    struct timeval ti, tf;
    double tiempo;
    gettimeofday(&ti, NULL);

    int izq=0, der=tam-1;
    bool ter=true;
    int cont=0;
    for (int i=0; i<tam/2; i++){
        for (int j=izq; j<der; j++){
            if(compare(*(p+j+1),*(p+j))){
                swap1((p+j+1), (p+j));
                ter = false;
            }
        }
        der--;
        for (int j=der; j>izq; j--){
            if(!compare(*(p+j-1),*(p+j))){
                swap1((p+j-1), (p+j));
                ter = false;
            }
        }
        izq++;
        if (ter==true)
            break;
    }

    gettimeofday(&tf, NULL);
    tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000;
    printf("time cocktail_sort:     %.28f segundos\n", tiempo/1000);    
}

void quick_sort(int *a,int izq, int der , bool (*compare)(int, int)){ 
    int i, j, x; 
    i = izq; 
    j = der; 
    x = *(a + (izq+der)/2); 
    do{ 
        while(compare(*(a+i),x) and (j<=der))    i++;
        while(compare(x,*(a+j)) and (j>izq)) j--;
 
        if(i<=j){ 
            swap1((a+i), (a+j));
            i++;  j--; 
        }
         
    }while(i<=j); 
 
    if(izq<j)   quick_sort( a, izq, j, compare); 
    if(i<der)   quick_sort( a, i, der, compare); 
}