#include <iostream>
#include <string>

using namespace std;

bool smaller(char *a, char *b){
	int aux, i=0;
	while(true){
		aux = *(a+i) - *(b+i);
		if(aux<0) return true;
		else if(aux>0) return false;
		if(*(a+i+1)=='\0' and *(b+i+1)!='\0') return true;
		i++;
	}
}

int main(int argc, char const *argv[]){
	/*char a = 'a';
	int aux = a;
	cout << a << endl;
	cout << aux << endl;*/

	char a[10], b[10];
	cin >> a;
	cin >> b;
	cout << smaller(a,b) << endl;

	return 0;
}
