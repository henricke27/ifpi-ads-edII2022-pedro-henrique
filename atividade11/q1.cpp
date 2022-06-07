#include <iostream>
#include <cmath>

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
		
		void preOrdem(ArvoreNo<T> *no){ 
			if(root==0){
				cout<<"vazio"<<endl;
			}else{
				if(no!=0){
					cout<<"<"<<no->el;
					preOrdem(no->left);
					preOrdem(no->right);
					cout<<">";
				}else{
					cout<<"<>";
				}			
			}	
		}
			
		void insert(ArvoreNo<T> *no, T el){ 
			if(root == 0){
				root = new ArvoreNo<T>(el);	
			}else{
				if(no->left == 0){
					no->left = new ArvoreNo<T>(el);
				}else if(no->right == 0){
					no->right = new ArvoreNo<T>(el);
				}else{
					if(el < no->el){
						insert(no->left,el);
					}else{
						insert(no->right,el);
					}		
				}	
			}		
		}
		
		int altura(ArvoreNo<T> *no){ 
			if(no==0){
				return 0;
			}else{
				int esquerda = altura(no->left);
				int direita = altura(no->right);
				if(esquerda > direita){
					return esquerda + 1;
				}else{
					return direita + 1;
				}
			}	
		}
			
		int quantidadeNos(ArvoreNo<T> *root){
    		if(root == NULL)
        		return 0;
    		else{
    			return 1 + quantidadeNos(root->left) + quantidadeNos(root->right);
			}
        	
        }
        
		bool ehCompleta(){
			return quantidadeNos(root) == pow(2,altura(root)) - 1;
		}
		
		bool ehDesbalanceada(){
			return altura(root->left) + 1 != altura(root->right) + 1;
		}
	
 };

int main(){
 	
 	Arvore<int> *a = new Arvore<int>();
 	a->insert(a->root,8);
 	a->insert(a->root,20);
 	a->insert(a->root,25);
 	a->insert(a->root,14);
 	a->insert(a->root,32);
 	a->insert(a->root,30);
	a->insert(a->root,28);
	a->insert(a->root,31);
	a->insert(a->root,40);
	
	cout<<"Quantidade de nos da arvore: "<<a->quantidadeNos(a->root)<<endl;
	//                                   a->altura(left/right)     + 1(root)
	cout<<"Altura subarvore esquerda: "<<a->altura(a->root->left) + 1 <<endl; 
	cout<<"Altura subarvore direita: " <<a->altura(a->root->right) + 1<<endl;
	
	cout<<"Arvore completa: "<<a->ehCompleta()<<endl;
	cout<<"Arvore desbalanceada: "<<a->ehDesbalanceada();
	
 	return 0;
}
