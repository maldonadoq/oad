#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define tipos 8

int billetes[] = {200,100,50,20,10,5,2,1};
int cambio[] = {0,0,0,0,0,0,0,0};

void machine(int vuelto){
	int aux=0;
	int temp = 0;
	while(vuelto!=0){
		cambio[aux] = vuelto/billetes[aux];
		vuelto = vuelto%billetes[aux];
		aux++;
	}
	for(int i=0;i<tipos;i++){
		cout << "billetes de " << billetes[i] << " : " << cambio[i] << endl; 
	}
}

int main(int argc, char const *argv[]){
	int vuelto;
	cout << "cantidad de vuelto: "; cin >> vuelto;
	machine(vuelto);
	return 0;
}