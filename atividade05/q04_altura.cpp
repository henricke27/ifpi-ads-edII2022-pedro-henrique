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
		
		void remover(T el){
			ArvoreNo<T> *no = root;
			ArvoreNo<T> *pai=0;
			while(no!=0){
				if(no->el == el){
					if(el == pai->right->el){
						pai->right = 0;
					}else{
						pai->left = 0;
					}
					break;
				}		
				pai = no;
				if(el < no->el){
					no = no->left;
				}else{
					no = no->right;		
				}		
			}
		}
		
		void percursoExtensao(){ 
			queue<ArvoreNo<T>*> f;
			ArvoreNo<T> *p=root;
			if(p!=NULL){
				f.push(p);
				while(!f.empty()){
					p=f.front();
					cout<<p->el<<endl;
					f.pop();
					if(p->left!=0){
						f.push(p->left);
					}
					if(p->right!=0){
						f.push(p->right);
					}
				}
			}			
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
 		
 	Arvore<int> *a = new Arvore<int>();
 	a->insert(13);
 	a->insert(10);
 	a->insert(25);
 	a->insert(2);
 	a->insert(12);
 	a->insert(20);
 	a->insert(31);
 	a->insert(29);

	cout<<a->nivelMax(a->root);
 	
 	return 0;
}
