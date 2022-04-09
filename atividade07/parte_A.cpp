#include <iostream>
#include <stdlib.h>
#include "arv.h"

using namespace std;

int main(){
 		
 	Arvore<int> *a = new Arvore<int>();
 	a->insert(13);
 	a->insert(10);
 	a->insert(25);
 	a->insert(2);
 	a->insert(12);
 	a->insert(20);
 	a->insert(31);
 	a->insert(29);
 	
 	Arvore<int> *b = new Arvore<int>();
	b->insert(20);
 	b->insert(22);
 	b->insert(27);
 
	cout<<a->nos(a->root)<<endl; // 13.2
	cout<<a->folhas(a->root)<<endl; // 13.3; 
	cout<<a->tem(a->root, 25)<<endl; // 13.5; 
	cout<<a->eb(a->root)<<endl; // 13.6; 
	cout<<a->igual(a->root, b->root)<<endl; // 13.7
	
	//Não consegui responder as duas últimas questões (13.8 e 13.9);
	
 	return 0;
}
