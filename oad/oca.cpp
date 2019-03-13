#include <iostream>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

using namespace std;

class caja{
public:
    string castigo;
    int lugar;
    int pos;
    int per_dado=0;
    int numero=0;
};

void llenar(caja *Ptr_oca){
	string castigos[]={"Puente","La Posada","El Pozo","Los Dados","El Laberinto", "La Carcel", "La Calabera o la Muerte","GANASTE"};
	for(int i=0; i<63;i++){
        if(i==5){
            (Ptr_oca)->castigo=castigos[0];
            Ptr_oca->lugar=11;
        }
        else if(i==11){ (Ptr_oca)->castigo=castigos[0]; Ptr_oca->lugar=5;   }
        else if(i==18){ (Ptr_oca)->castigo=castigos[1]; Ptr_oca->lugar=1;   }
        else if(i==30){ (Ptr_oca)->castigo=castigos[2]; Ptr_oca->lugar=2;   }
        else if(i==25){ (Ptr_oca)->castigo=castigos[3]; Ptr_oca->lugar=52;  }
        else if(i==52){ (Ptr_oca)->castigo=castigos[3]; Ptr_oca->lugar=25;  }
        else if(i==41){ (Ptr_oca)->castigo=castigos[4]; Ptr_oca->lugar=29;  }
        else if(i==51){ (Ptr_oca)->castigo=castigos[5]; Ptr_oca->lugar=3;   }
        else if(i==57){ (Ptr_oca)->castigo=castigos[6]; Ptr_oca->lugar=1;   }
        else if(i==62){ (Ptr_oca)->castigo=castigos[7]; Ptr_oca->lugar=0;   }
        else{   (Ptr_oca)->castigo="";  Ptr_oca->lugar=0;   }

        Ptr_oca->pos = i+1;
        Ptr_oca++;
    }
}

void print(int t){
    for(int j=0; j<=63; j++)
        (j==t)? cout << "0": cout << "_";
    cout << endl;
}

int main(){
    caja oca[63];
    int n;
    cout<<"cuantos jugadores quieres: "<<endl;
    cin>>n;
    
    caja *jugadores[n];
    caja *Ptr_oca;

    Ptr_oca=oca;
    llenar(Ptr_oca);

    for(int i=0; i<n; i++){
    	jugadores[i]=oca;
    }

    caja *jugador;
    jugador = oca;
    int i=0, dado, Per_jug=0, sws=0;
    srand(time(NULL));
    while(true){
        if(sws==n){
            cout << endl << endl;
            sws = 0;
        }

        sws++;
        dado=(rand()%6)+1;
        usleep(1000000);
        jugador=jugadores[i];

        if(jugador->per_dado>0){
            jugador->per_dado--;
            cout << "0:  ";
            print(jugador->pos);
	        i++;
	        if(i==n)   i=0;
            continue;
        }
        if ((jugador->pos+dado)>63){
            int ps=(jugador->pos+dado)%63;
            ps=63-ps;
            jugador=&oca[ps];
        }

        else jugador=jugador+dado;

        cout << dado << ":  ";
        print(jugador->pos);
        
        string cast;
        cast=jugador->castigo;
        if (cast=="Puente" && jugador->pos==6)          jugador=&oca[11];
        else if (cast=="Puente" && jugador->pos==12)    jugador=&oca[5];
        else if (cast=="La Posada")                     jugador->per_dado=1;
        else if (cast=="El Pozo")                       jugador->per_dado=2;
        else if (cast=="Los Dados" && jugador->pos==26) jugador=&oca[52];
        else if (cast=="Los Dados" && jugador->pos==53) jugador=&oca[25];
        else if (cast=="El Laberinto")                  jugador=&oca[29];
        else if (cast=="La Carcel")                     jugador->per_dado=3;
        else if (cast=="La Calabera o la Muerte")       jugador=oca;
        else if (cast=="GANASTE")                       jugador->per_dado=-1;
        else Per_jug=0;

        jugadores[i]=jugador;
        if (jugador->per_dado==-1){cout<<"gano el jugador: "<<i+1<<endl;break;}
        
        i++;
        if (i==n)   i=0;
    }
    return 0;
}