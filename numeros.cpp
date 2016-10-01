#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
/*
   	int a,b,c,d,e,f,g,h,l;
	a = (n-n/10*10);
	b = (n-n/100*100-a)/10;
	c = (n-n/1000*1000-(a+b))/100;
	d = (n-n/10000*10000-(a+b+c))/1000;
	e = (n-n/100000*100000-(a+b+c+d))/10000;
	f = (n-n/1000000*1000000-(a+b+c+d+e))/100000;
	g = (n-n/10000000*10000000-(a+b+c+d+e+f))/1000000;
	h = (n-n/100000000*100000000-(a+b+c+d+e+f+g))/10000000;
	l = (n-n/1000000000*1000000000-(a+b+c+d+e+f+g+h))/100000000;
*/

void convert(int n){	
   	int i,j=1,p,r, res;
	i = log10(n)+1;
   	int num[i];
	for(int sw=0;sw<i;sw++){
		res = n%10;
		num[i-(sw+1)] = res;
		n = n/10;
	}

   	if(i>6 && i<=9)	p=6;
    else if(i>3 && i<=6){ p=3; j++; }
	else if(i>0 && i<=3){ p=0; j+=2; }
	
	while(j<=3){
  		if((i==3 || i==6)||(num[0]!=0 || num[3]!=0 || num[6]!=0) ){  // 300  1000    300000 3 != ' '
      		switch(num[i-(3+p)]){ // posicion de la centena
      			//nombre de las centenas
	 			case 1:
	 				if((num[(i-(3+p))+1]!=0) || (num[(i-(3+p))+2]!=0))	cout << "ciento ";
					else	cout << "cien ";
		 			break;
				case 2: cout << "doscientos ";break;
				case 3: cout << "trescientos ";break;
				case 4: cout << "cuatrocientos ";break;
				case 5: cout << "quinientos ";break;
				case 6: cout << "seiscientos ";break;
				case 7: cout << "setecientos ";break;
				case 8: cout << "ochocientos ";break;
				case 9: cout << "novecientos ";break;
      		}
      	}

	    switch(num[i-(p+2)]){ // 3_10 ya hemos probado que no 300
		 	// muestra las decenas cuando unidad es 0
		 	case 1:
		 		switch(num[(i-(p+2))+1]){
				    case 0: cout << "diez ";break;
				    case 1: cout << "once ";break;
				    case 2: cout << "doce ";break;
				    case 3: cout << "trece ";break;
				    case 4: cout << "catorce ";break;
				    case 5: cout << "quince ";break;
				    case 6: cout << "diesciseis ";break;
				    case 7: cout << "diescisiete ";break;
				    case 8: cout << "diesciocho ";break;
				    case 9: cout << "diescinueve ";break;
			 	}
			 	break;
		 	case 2 :
		 		if(num[(i-(p+2))+1]==0)   cout << "veinte ";
			 	else   cout << "veinti";
			 	break;
		 	case 3: cout << "treinta "; if(num[(i-1)-p]!=0) cout << "y "; break;
		 	case 4: cout << "cuarenta "; if(num[(i-1)-p]!=0) cout << "y "; break;
		 	case 5: cout << "cincuenta "; if(num[(i-1)-p]!=0) cout << "y "; break;
		 	case 6: cout << "secenta "; if(num[(i-1)-p]!=0) cout << "y "; break;
		 	case 7: cout << "setenta "; if(num[(i-1)-p]!=0) cout << "y "; break;
		 	case 8: cout << "ochenta " ;if(num[(i-1)-p]!=0) cout << "y "; break;
		 	case 9: cout << "noventa "; if(num[(i-1)-p]!=0) cout << "y "; break;
	    }

    	//301
    	if(num[i-(p+2)]!=1){
      		switch(num[(i-1)-p]){ //imprime las unidades
	 			case 1 :
			        if(p>=3) cout << "un " ; //cuando es mas de  3 cifras, 300000
					else cout << "uno";
					break;
				case 2 : cout << "dos ";break;
				case 3: cout << "tres ";break;
				case 4: cout << "cuatro ";break;
				case 5: cout << "cinco ";break;
				case 6: cout << "seis ";break;
				case 7: cout << "siete ";break;
				case 8: cout << "ocho ";break;
				case 9: cout << "nueve ";break;
			}
		}


    	if(p==6 && num[0]==0 && p==6 && num[1]==0 && p==6 && num[2]==0);
       	else if(p==6 && num[0]==1 && i==7)  cout << "millon ";
	  	else if(p==6)  cout << "millones ";
	 	//| p==3 && num[p+1]!=0 || p==3 && num[p+2]!=0    // and i!=7
      	if(p==3 && num[p]!= ' ') cout << "mil ";
      	p-=3;
      	j++;
	}
	cout << endl;
}

int main(int argc, char const *argv[]){
	int n;
	cout << "Introduce un numero: "; cin >> n;
	convert(n);
  	return 0;
}