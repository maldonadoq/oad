#include <iostream>
#include <stdio.h>

using namespace std;

void _print(char *t){
	while(*t != '\0'){
		cout << *t;
		t++;
	}
	cout << endl;
}

int str_size(char *a){
	char *b = a;
	for(;*b!='\0';b++);
	return b-a;
}

void str_copy(char *a, char *b){
	while(*b!='\0')	*a++ = *b++;
	*a = '\0';
}

void str_cat(char *a, char *b){
	while(*++a!='\0');
	while(*b!='\0')	*a++ = *b++;
	*a = '\0';
}

int str_cmp(char *a, char *b){
	int aux = *a++ - *b++;
	if(aux>0) return -1;
	else if(aux<0) return 1;
	else return 0;
}

void str_rs(char *a){
	while(*a++ != '\0');
	while(*a-- == ' ');
	*a = '\0';
}

void str_ls(char *a){
	char *b = a;
	while(*++b == ' ');
	while(*b!='\0'){
		*a = *b++;
		a++;
	}	
	*a = '\0';
}
 
void str_s(char *a){
	str_rs(a);
	str_ls(a);
}

void str_rls(char *a){
	char *b = a;
	while(*b != '\0'){
		if(*b != ' '){
			*a = *b;
			a++;
		}
		b++;
	}
	*a = '\0';
}