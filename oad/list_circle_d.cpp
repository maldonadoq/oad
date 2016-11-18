#include <iostream>
#include <stdlib.h>

using namespace std;

template<class T>
class node{
public:
	T _dato;
	node<T> *next;
	node<T> *prev;
	node(T x){
		this->_dato = x;
		this->next = NULL;
		this->prev = NULL;
	}
};

template<class T>
class list_circle{
public:
	node<T> *primero;
	int t;
	list_circle(){	
		this->primero = NULL;
		this->t = 0;
	}
	void push(T);
	void pop(int);
	void print();
	void print_r();
	~list_circle(){	};
};

template<typename T>
void list_circle<T>::push(T x){
	node<T> *temp = new node<T>(x);
	if(!primero){
		this->primero = temp;
		this->primero->next = this->primero;
		this->primero->prev = this->primero;
		this->t++;
	}
	else{
		node<T> *aux = this->primero->prev;
		aux->next = temp;
		temp->next = this->primero;
		temp->prev = aux;
		this->primero->prev = temp;
		this->t++;
	}
}

template<typename T>
void list_circle<T>::pop(int z){
	node<T> *temp = primero;
	int a = 0;
	if(z>=t)	cout << "segmentation_fault" << endl;
	else if(z==0){
		this->primero = temp->next;
		this->primero->next = temp->next->next;
		this->primero->prev = temp->prev;
		this->primero->prev->next = this->primero;
	}
	else{
		while(true){
			a++;
			if(a==z){
				if(temp->next->next == primero){
					temp->next = primero;
					this->primero->prev = temp;
				}
				else{
					node<T> *aux = temp;
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
void list_circle<T>::print(){
	node<T> *temp = primero;
	do{
		cout << temp->_dato << "  ";
		temp = temp->next;
	}	while(temp != primero);
	cout << endl;
}

template<typename T>
void list_circle<T>::print_r(){
	node<T> *temp = primero;
	do{
		temp = temp->prev;
		cout << temp->_dato << "  ";
	}	while(temp != primero);
	cout << endl;
}

int main(int argc, char const *argv[]){
	list_circle<int> *A = new list_circle<int>();
	for(int i=0; i<10; i++)	A->push(i);
	return 0;
}