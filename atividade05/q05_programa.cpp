#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

template<class T>
class ArvoreNo{
 	public:
 		T el;
 		ArvoreNo<T> *left, *right;
 		ArvoreNo(){
 			left=right=0;	
		}
		ArvoreNo(T e, ArvoreNo<T> *l=0, ArvoreNo<T> *r=0){
			el=e;
			left = l;
			right = r;
		}
 };

template<class T>
class Arvore {
	public:
 		ArvoreNo<T> *root;
 	public: 
 		Arvore(){
 			root = 0;
		}
		~Arvore(){
			clear();
		}	
 		void clear(){
 			clear(root);
 			root=0;
		}
		
		int nivelMax(ArvoreNo<T> *no){ 
			if(no==0){
				return 0;
			}else{
				int esquerda = nivelMax(no->left);
				int direita = nivelMax(no->right);
				if(esquerda > direita){
					return esquerda + 1;
				}else{
					return direita + 1;
				}
			}	
		}
		
		void remove(ArvoreNo<T> *no){
			ArvoreNo<T> *tmp = new ArvoreNo<T>();
			
			int c = root->el == no->el;

			if(no!=0){
				if(!no->right){
					no = no->left;
				}else if(no->left==0){
					no = no->right;
				}else{
					tmp = no->left;
					while(tmp->right!=0){
						tmp = tmp->right;
					}
					tmp->right=no->right;
					tmp = no;
					no = no->left;
					if(c){
						root = no;
					}
				}	
			}
			*tmp = 0;
		}
		
		void findAndRemove(T el){ 
			cout<<"altura antes da remocao: "<<nivelMax(this->root)<<endl;
			ArvoreNo<T> *no = root;
			ArvoreNo<T> *prev=0;
			while(no!=0){
				if(no->el == el)
					break;
				prev = no;
				if(el < no->el){
					no = no->left;
				}else{
					no = no->right;		
				}
			}
			if(no!=0 && no->el==el){
				if(no==root){
					remove(root);
				}else if(prev->left==no){
					remove(prev->left);
				}else{
					remove(prev->right);
				}
			}else if(root!=0){
				cout<<el<<" nao esta na arvore"<<endl;
			}else{
				cout<<"arvore vazia"<<endl;
			}
			
			cout<<"Altura depois da remocao: "<<nivelMax(this->root)<<endl;
		}
		
		void insert(T el){ 
			ArvoreNo<T> *p=root, *prev=0;
			while(p!=0){
				prev=p;
				if(el<p->el){
					p=p->left;
				}else{
					p=p->right;
				}
			}
			if(root==0){
				root = new ArvoreNo<T>(el); 
			}else if(el < prev->el){
				prev->left=new ArvoreNo<T>(el);
			}else{
				prev->right=new ArvoreNo<T>(el);
			}
		}
	
 };

int main(){
 	int el = 0;
 	cout<<"Valor do no a ser removido: ";
 	cin>>el;
 	
 	Arvore<int> *a = new Arvore<int>();
 	a->insert(13);
 	a->insert(10);
 	a->insert(25);
 	a->insert(2);
 	a->insert(12);
 	a->insert(20);
 	a->insert(31);
 	a->insert(29);
 	
 	a->findAndRemove(el); 	
 	
 	/* q05. Podemos verificar o aumento da altura da árvore ao
 	remover o nó 13. E caso tivessemos mais elementos maiores que
 	13, a árvore poderia entrar num estado desbalanceado. */
 							
 	return 0;
}

