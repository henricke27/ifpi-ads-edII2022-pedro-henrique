#include <iostream>
#include <stdlib.h>
#include "arv.h"

int main(){
 		
 	Arvore<int> *a = new Arvore<int>();
 	a->insert(13);
 	a->insert(10);
 	a->insert(25);
 	a->insert(2);
 	a->insert(11);
 	a->insert(20);
 	a->insert(26);
 	a->insert(18);
 	a->insert(24);
 	
/*	a->remocaoSimples(25); 
	a->preOrdem(a->root);	*/
 	
/* 	a->findAndDeleteByMerging(25); 
 	a->percursoExtensao();	*/
 	
/* 	a->findAndDeleteByCopying(a->root->right); 
 	a->preOrdem(a->root);	*/
 	
 	
//  1 - Remoção simples: 
//		<13<10<2<><>><11<><>>><>>;

//	2 - Remoção por fusão: 
//  	13 - 10 - lixo - 2 - 11 - lixo - 26 - lixo - lixo - lixo; (percurso em extesão)

//  3 - Remoção por cópia: 
//		<13<10<2<><>><11<><>>><24<20<18<><>><>><26<><>>>>;

 	return 0;
}


