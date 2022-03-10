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
		
		void inOrdem(){
			stack<No*> pilha;
			No *p = raiz;
			
			while(p!=0){
				while(p!=0){
					if(p->right!=0){
						pilha.push(p->right);
					}
					pilha.push(p);
					p = p->left;
				}
				p = pilha.top();
				pilha.pop();
				
				while(!pilha.empty() && p->right==0){
					cout<<p->nome<<endl;
					p = pilha.top();
					pilha.pop();
				}
				cout<<p->nome<<endl;
				if(!pilha.empty()){
					p = pilha.top();
					pilha.pop();					
				}else{
					p = 0;
				}
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
	
	arv->inOrdem();
	return 0;
}
