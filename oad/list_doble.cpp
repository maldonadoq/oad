#include <iostream>
#include <stdio.h>

using namespace std;

template<class T>
class node{
public:
	T _dato;
	node<T> *next, *prev;
	node(T x){
		this->_dato = x;
		this->next = NULL;
		this->prev = NULL;
	}
};

template<class T>
class list{
public:
	int t;
	node<T> *primero, *ultimo;
	list(){	
		this->primero = NULL;
		this->ultimo = NULL;
		this->t = 0;
	}
	void push(T);
	void pop(int);
	void print();
	void print_reverse();
	~list(){	};
};

template<typename T>
void list<T>::push(T x){
	if(!primero){
		primero  = new node<T>(x);
		ultimo =primero;
		this->t++;
	}
	else{
		node<T> *aux = ultimo;
		ultimo->next = new node<T>(x);
		ultimo = ultimo->next;
		ultimo->prev = aux;
		this->t++;
	}
}

template<typename T>
void list<T>::pop(int z){
	node<T> *temp = primero;
    int a = 0;
    bool b = true;
    if(z>=t) cout << "segmentation_fault" << endl;
    else if(z==0){
    	this->primero = temp->next;
    	this->primero->next = temp->next->next;
    	this->primero->prev = NULL;
    }
    else{
    	while(true){
    		a++;
    		if(a==z){
	    		if(!temp->next->next){
	    			temp->next = NULL;
	    			this->ultimo = temp;
	    		}
	    		else{
	    			temp->next = temp->next->next;
	    			temp->next->prev = temp;
	    		}
	    		break;
	    	}
	    	temp = temp->next;
	    }
    }
}	

template<typename T>
void list<T>::print(){
	node<T> *temp = primero;
	while(temp!=NULL){
		cout << temp->_dato << "  ";
		temp = temp->next;
	}
	cout << endl;
}

template<typename T>
void list<T>::print_reverse(){
	node<T> *temp = ultimo;
	while(temp!=NULL){
		cout << temp->_dato << "  ";
		temp = temp->prev;
	}
	cout << endl;
}

int main(int argc, char const *argv[]){
	list<int> *A = new list<int>;
	for(int i=0; i<10; i++)	A->push(i);
	A->print();
	return 0;
}