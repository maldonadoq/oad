#include <iostream>
#include <stdio.h>
#include "../func/arith.cpp"

using namespace std;

int main(int argc, char const *argv[]){
	list<point<float>, float> *v = new list<point<float>, float>;

	v->push(new point<float>(2.89,4));
	v->push(new point<float>(8.04,5));
	v->push(new point<float>(12,9.3));
	v->push(new point<float>(10,14.1));
	v->push(new point<float>(4,12.1));

	/*int na, cx, cy;
	cout << "numero de aristas del poligono:  "; cin >> na;
	while(na!=0){
		cout << "coordenada x:  "; cin >> cx;
		cout << "coordenada y:  "; cin >> cy;
		v->push(new point<float>(cx,cy));
		na--;
	}*/

	v->print();
	cout << "el area es:  " << area<list<point<float>, float> *, point<float> *>(v) << endl;
	return 0;
}