#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;

string unidad[10];
string unidiez[6];
string decena[10];
string complemento[10];
int digtem[3];

void datos(){
    unidad[0]=" ";          decena[1]="diez ";       unidiez[1]="once ";               complemento[0]="dieci";
    unidad[1]="un";         decena[2]="veinte ";     unidiez[2]="doce ";               complemento[1]="cientos ";
    unidad[2]="dos";        decena[3]="trenta ";     unidiez[3]="trece ";              complemento[2]="cien";
    unidad[3]="tres";       decena[4]="cuarenta ";   unidiez[4]="catorce ";            complemento[3]="un millon ";
    unidad[4]="cuatro";     decena[5]="cincuenta ";  unidiez[5]="quince ";             complemento[4]=" millones ";
    unidad[5]="cinco";      decena[6]="sesenta ";    unidiez[0]="";                    complemento[5]="quinientos ";
    unidad[6]="seis";       decena[7]="setenta ";                                      complemento[6]="ciento ";
    unidad[7]="siete";      decena[8]="ochenta ";                                      complemento[7]="sete";
    unidad[8]="ocho";       decena[9]="noventa ";                                      complemento[8]=" mil ";
    unidad[9]="nueve";      decena[0]="veinti";                                        complemento[9]="nove";
}
int contdigit(int num){
    int can=0;
    while(num>0){
        num=num/10;
        can++;
    }
    return can;
}
string converdos(int indice, int numero, int digit[2]){
    string let;

    if (numero>15 && numero<20){
        let=complemento[0];
        let=let+unidad[digit[1]];
    }
    else if(numero==21 && indice==1)
        let=decena[0]+"uno";
    else if(digit[0]==0 && digit[1]==1 && indice==1)
        let="uno";
    else if(digit[1]==1 && digit[0]!=1 && indice==1)
        let=decena[digit[0]]+"y uno";
    else if(digit[0]==1 && digit[1]==0)
        let=decena[1];
    else if(numero==20)
        let=decena[digit[0]];
    else if(numero>20 && numero<30){
        let=decena[0];
        let=let+unidad[digit[1]];
    }
    else if(digit[0]==0 && digit[1]==0)
        let="";
    else if(digit[0]==0)
        let=unidad[digit[1]];
    else if(numero<=15)
        let=unidiez[digit[1]];
    else if(digit[1]==0)
        let=decena[digit[0]];
    else{
        let=decena[digit[0]];
        let=let + "y ";
        let=let+unidad[digit[1]];
    }
    return let;
}

void entregar(int nume[3]){
    for (int i=0; i<3; i++)
        digtem[i]=nume[i];
}

string trans(int indice, int digit[3]){
    string tem;
    int temporal[2], temNum=0;
    temporal[0]=digit[1];        temporal[1]=digit[2];
    temNum=digit[1]*10+digit[2];

    tem=converdos(indice,temNum, temporal);

    if (digit[0]==1 && digit[1]==0 && digit[2]==0)
        tem=complemento[2];
    else if (digit[0]==1){
        tem=complemento[6]+tem;
    }
    else if (digit[0]==0 && digit[1]==0){
        tem=tem;
    }
    else if (digit[0]==5)
        tem=complemento[5] + tem;
    else if (digit[0]==7 || digit[2]==9){
        tem=complemento[1]+tem;
        tem=complemento[digit[0]]+tem;
    }
    else if(digit[0]!=0){
        tem=complemento[1]+tem;
        tem=unidad[digit[0]]+tem;
    }

    return tem;
}
int main()
{
    int numero=0, temp=0;
    cout<<"ingrese el numero: "<<endl;
    cin>>numero;
    temp=numero;
    //ingresamos todos los nombres de numeros posibles
    datos();
    string letras[10];
    //contamos los digitos
    int digitos=contdigit(numero);

    int digit[digitos];
    int digits1[3],digits2[3],digits3[3];
    int indi=1;
    //ingresamos lo digitos en una matriz;
    for(int i=0; i<digitos-1;i++)
        indi=indi*10;
    for (int i=0; i<digitos;i++){
        digit[i]=temp/indi;
        temp=temp%indi;
        indi=indi/10;
    }
    int ind;
    if (digitos>=3){
        if (digitos<=6 && digitos>3){
            ind=digitos%3;
            if (ind==0)ind=3;
            int i=0,a=0;
            for (i=0;i<ind;i++)
                digits2[i]=digit[i];
            for (i=i;i<ind+3;i++){
                digits3[a]=digit[i];
                a++;
            }
        }
        else if (digitos>6){
            ind=digitos%3;
            if (ind==0)ind=3;
            int i=0,a=0;
            for (i=0;i<ind;i++)
                digits1[i]=digit[i];
            for (i=i;i<ind+3;i++){
                digits2[a]=digit[i];
                a++;
            }
            a=0;
            for (i=i;i<ind+6;i++){
                digits3[a]=digit[i];
                a++;
            }
        }
        else{
            for (int i=0;i<3;i++)
                digits3[i]=digit[i];
        }
    }
    string tem;

    if (digitos<=3){
        if (numero==1)tem="uno";
        else if (digitos==1 && numero!=1)tem=unidad[digit[0]];
        else if(digitos==2)tem=converdos(1,numero,digit);
        else tem=trans(1,digits3);
    }
    if (digitos<=6 && digitos>3){
        int tamano=digitos%3;
        if (tamano==0)tamano=3;
        if (tamano==1 && digits2[0]!=1)tem=unidad[digits2[0]];
        else if (tamano==1 && digits2[0]==1)tem="";
        else if(tamano==2)tem=converdos(0,digits2[0]*10+digits2[1],digits2);
        else tem=trans(0,digits2);

        tem=tem+complemento[8];
        string tem2;
        tem2=trans(1,digits3);
        tem=tem+tem2;
    }
    if (digitos<=9 && digitos>6){
        int tamano=digitos%3;
        if (tamano==0)tamano=3;
        if (tamano==1 && digits1[0]!=1)tem=unidad[digits1[0]]+complemento[4];
        else if (tamano==1 && digits1[0]==1)tem=complemento[3];
        else if(tamano==2)tem=converdos(0,digits1[0]*10+digits1[1],digits1)+complemento[4];
        else tem=trans(0,digits1)+complemento[4];

        string tem1;
        tem1=trans(0,digits2);
        if (tem1!="")tem1=tem1+complemento[8];
        tem=tem+tem1;
        string tem2;
        tem2=trans(1,digits3);
        tem=tem+tem2;
    }
//////////////////////////////////////////////////////
    cout<<tem<<endl;

    return 0;
}
