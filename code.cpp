#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "../func/func.cpp"

using namespace std;

class asd{
private:
	int mod;
	FILE *t_pl;
	FILE *t_ci;
	FILE *t_dsci;
public:
	asd();
	int plus(int, int);
	int subtract(int, int);
	int product(int , int);
	void cifrado(int);
	void descifrado(int);
};

asd::asd(){
	mod = 256;
	t_pl =fopen("sws/texto_plano.txt", "r");
	t_ci = fopen("sws/texto_cifrado.txt", "w+");
	t_dsci = fopen("sws/texto_descifrado.txt", "w");
}

int asd::plus(int x, int y){	return (x+y)%mod;	}

int asd::subtract(int x, int y){
	int asd = (x-y)%mod;
	if (asd<0)	return mod + asd; 
	else	return asd;
}
int asd::product(int x, int y){	return (x*y)%mod;	}

void asd::cifrado(int c_pu){
	int c, aux;
	while((c=getc(t_pl))!=EOF){
		aux = product(c,c_pu);
		fprintf(t_ci, "%c", aux);
	}
	fclose(t_ci);
}

void asd::descifrado(int c_pr){
	int aux, c;
	while((c=getc(t_ci))!=EOF){
		aux =product(c,c_pr);
		fprintf(t_dsci, "%c", aux);
	}
	fclose(t_dsci);
}

int main(int argc, char const *argv[]){
	int c_pu, c_pr;
	cout << "clave_publica: "; cin >> c_pu;
	c_pr = inverso_zn(c_pu, 256);
	cout << c_pr << endl;
	/*
	if(c_pr==-1) cout << "no_existe_clave_privada " << endl;
	else {
		cout << "tu clave privada es: " << c_pr << endl;
		asd emisor;
		asd receptor;
		emisor.cifrado(c_pu);
		receptor.descifrado(c_pr);
		cout << "compilado" << endl;
	}*/
	
	return 0;
}