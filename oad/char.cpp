#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

bool smaller(char *a, char *b){
	int aux, i=0;
	while(true){
		aux = *(a+i) - *(b+i);
		if(aux<0) return true;
		else if(aux>0) return false;
		if(*(a+i+1)=='\0' and *(b+i+1)!='\0') return true;
		i++;
	}
	return false;
}

void print(char *t){
	while(*t != '\0'){
		cout << *t;
		t++;
	}
	cout << endl;
}


void par_impar(long int *a, long int *b, long int *c, int t){
	int j = 0, k = 0;
	for(int i=0; i<t;i++){
		if((*(a+i)%2)==0){
			*(b+j) = *(a+i);
			j++;
		}
		else{
			*(c+k) = *(a+i);
			k++;
		}
	}
	if(j!=t) *(b+j) = -1;
	if(k!=t) *(c+k) = -1;
}

void print1(long int *x){
	while(*x != -1){
		cout << *x << " ";
		x++;
	}
	cout << endl << endl;
}

void print2(long int *a, int t){
	for(int i=0;i<t;i++) cout << *(a+i) << " ";
	cout << endl << endl;
}

void fibo(long int *a, int t){
	long int x, y;
	cout << "primer numero: "; cin >> x;
	cout << "segundo numero: "; cin >> y;
	*(a+0) = x;
	*(a+1) = y;
	int i = 2;
	for(int i=2;i<t;i++){
		*(a+i) = *(a+i-2) + *(a+i-1);
	}
}

int main(int argc, char const *argv[]){
	char a[10] = "dayana";
	char b[10] = "day";
	cout << smaller(a,b) << endl;
	return 0;
}
