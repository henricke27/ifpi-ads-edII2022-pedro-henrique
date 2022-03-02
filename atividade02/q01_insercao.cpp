#include <iostream>

using namespace std;

class No{
	public:
		char nome;
		No *left;
		No *right;
		
		No(char n){
			nome = n;
			left = 0;
			right = 0;
		}
};

class Arvore{
	public:
		No *raiz;
	
		Arvore(){
			raiz=0;
		}
	
		void insere(No *arv, No *pai, No *novo, int lado){
			if(this->raiz == 0){
				raiz = novo;
			}
			
			if(arv!=0){
				if(arv->nome==pai->nome){
					if(lado==1 && arv->left==0){
						arv->left = novo;
					}else if(lado==2 && arv->right==0){
						arv->right = novo;
					}else{
						cout<<"Ja existe um no ocupando esta posicao"<<endl;
					}
				}else{
					insere(arv->left, pai, novo, lado);
					insere(arv->right, pai, novo, lado);
				}	
			}
			
			
		}
	
};

int main(){ //testando
	Arvore *arv = new Arvore();
	
	No *noa = new No('a');
	No *noe = new No('e');
	No *noi = new No('i');
	No *noo = new No('o');
	No *nou = new No('u');
	
	arv->insere(arv->raiz, noa, noe, 1); 
	arv->insere(arv->raiz, noe, noi, 2); 
	arv->insere(arv->raiz, noe, noi, 2); // Não insere; mensagem;
	arv->insere(arv->raiz, noe, noo, 1); //insere;
	arv->insere(arv->raiz, noo, nou, 1);
	
	cout<<arv->raiz->nome;
	cout<<arv->raiz->right->nome;
	cout<<arv->raiz->left->nome;
	cout<<arv->raiz->left->left->nome;
	
	return 0;
}

