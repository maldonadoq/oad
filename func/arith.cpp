#include <iostream>
#include <stdio.h>

using namespace std;

template<class T>
class point{
public:
	T x, y;
	point<T> *next;
	point(T _x, T _y){
		this->x = _x;
		this->y = _y;
		this->next = NULL;
	}
	~point(){	}
};

template<class T, typename R>
class list{
public:
	point<R> *primero;
	point<R> *ultimo;
	list(){
		this->primero = NULL;
		this->ultimo = NULL;
	}
	void push(T *p){
		if(!primero){
			this->primero = p;
			this->ultimo = this->primero;
		}
		else{
			this->ultimo->next = p;
			this->ultimo = this->ultimo->next;
			this->ultimo->next = this->primero;
		}
	}
	void print(){
		point<R> *temp = this->primero;
		do{
			cout << "(" << temp->x << "," << temp->y << ")" << endl;
			temp = temp->next;
		}	while(temp!=primero);
		cout << endl;
	}
};

template<class R, class T>
double area(R v){
	double area = 0;
	T temp = v->primero;
	do{
		//cout << (temp->x*temp->next->y) - (temp->y*temp->next->x) << endl;
		area += (temp->x*temp->next->y) - (temp->y*temp->next->x);
		temp = temp->next;
	}	while(temp->next!=v->primero->next);
	return area/2;
}
