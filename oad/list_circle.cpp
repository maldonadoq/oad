#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

template<class T>
class node{
public:
	node(T);
	T _dato;
	node<T> *next;
};

template<class T>
class list_circle{
public:
	int t;
	node<T> *primero, *ultimo;
	list_circle();
	void push(T);
	void pop(int);
	void print();
	int tam(); 
	void josefus(int, int);
	~list_circle(){	};
};

template<typename T>
node<T>::node(T x){
	this->_dato = x;
	this->next = NULL;
}

template<typename T>
list_circle<T>::list_circle(){
	this->primero = NULL;
	this->ultimo = NULL;
	this->t = 0;
}

template<typename T>
void list_circle<T>::push(T x){
	if(!primero){
		primero = new node<T>(x);
		ultimo = primero;
		ultimo->next = primero;
		this->t++;
	}
	else{
		ultimo->next = new node<T>(x);
		ultimo = ultimo->next;
		ultimo->next = primero;
		this->t++;
	}
}

template<typename T>
void list_circle<T>::pop(int z){
	node<T> *temp = primero;
	int a = 0;
    if(z>=t) cout << "segmentation_fault" << endl;
    else if(z==0){
    	this->primero = temp->next;
    	this->primero->next = temp->next->next;
    	this->ultimo->next = this->primero;
    	this->t--;
    }
    else{
    	while(true){
    		a++;
    		if(a==z){
	    		if(temp->next->next == primero){
	    			temp->next = primero;
	    			this->ultimo = temp;
	    		}
	    		else	temp->next = temp->next->next;
	    		this->t--;
	    		break;
	    	}
	    	temp = temp->next;
	    }
    }
}

template<typename T>
void list_circle<T>::josefus(int s, int x){
	node<T> *temp = primero;
	int c = 0;
	bool tr = true;
	do{
		c++;
		if(c == x-1){
			//cout << temp->next->_dato << "  ";
			temp->next = temp->next->next;
			this->t--;
			c = 0;
		}
		temp = temp->next;
	}	while(this->t != s);
	primero = temp;
}

template<typename T>
void list_circle<T>::print(){
	node<T> *temp = primero;
	do{
		cout << temp->_dato << "  ";
		temp = temp->next;
	}	while(temp!=primero);
	cout << endl;
}

int main(int argc, char const *argv[]){
	list_circle<int> *A = new list_circle<int>;
	for(int i=1; i<=50; i++)	A->push(i);
	A->print();
	A->josefus(2,7);
	A->print();
	return 0;
}