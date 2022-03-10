#include <stack>
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
	
		void insert(char el){ 
			No *p=raiz, *prev=0;
			while(p!=0){
				prev=p;
				if(el<p->nome){
					p=p->left;
				}else{
					p=p->right;
				}
			}
			if(raiz==0){
				raiz = new No(el); 
			}else if(el < prev->nome){
				prev->left=new No(el);
			}else{
				prev->right=new No(el);
			}
		}
		
		void posOrdem(){
			stack<No*> pilha;
			No *p = raiz;
			No *q = raiz;
			while(p!=0){
				while(p->left!=0){
					pilha.push(p);
					p=p->left;
				}
				while(p->right == 0 || p->right == q){
					cout<<p->nome<<endl;
					q=p;
					if(pilha.empty()){
						return;
					}
					p = pilha.top();
					pilha.pop();
				}
				pilha.push(p);
				p = p->right;
			}
				
		}
			
		
};


int main(){

	Arvore *arv = new Arvore();
	
	arv->insert('q');
	arv->insert('a');
	arv->insert('z');
	arv->insert('w');
	arv->insert('s');
	arv->insert('x');
	arv->insert('e');
	arv->insert('d');	 			
	arv->insert('c');
	
	arv->posOrdem();
	
	return 0;
}
