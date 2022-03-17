#include <iostream>

using namespace std;

template<class T>
class ArvoreNo{
 	public:
 		T el;
 		int sucessor;
 		ArvoreNo<T> *left, *right;
 		ArvoreNo(){
 			left=right=0;	
 			sucessor = 0;
		}
		ArvoreNo(T e, ArvoreNo<T> *l=0, ArvoreNo<T> *r=0){
			el=e;
			left = l;
			right = r;
			sucessor = 0;
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
		
		/*void morris(){
			ArvoreNo<T> *p = root;
			ArvoreNo<T> *tmp;
			
			while(p!=0){
				if(p->left == 0){
					cout<<p->el<<endl;
					p = p->right;
				}else{
					tmp = p->left;
					while(tmp->right != 0 && tmp->right != p){
						tmp = tmp->right;					
					}
					if(tmp->right == 0){
						tmp->right = p;
						p = p->left;
					}else{	
						cout<<p->el<<endl;
						tmp->right = 0;
						p = p->right;
					}
					
				}
			}		
		}*/
		
		//Não consegui implementar o percurso
		void preOrdem(){
			ArvoreNo<T> *p = root;
			ArvoreNo<T> *tmp = root;
			
			if(p!=0){ 
				while(p->left != 0){
					cout<<p->el<<endl;
					p = p->left;
				}
				cout<<p->el<<endl;	
				while(p!=0){
					tmp = p;
					p = p->right;
					if(p!=0 && tmp->sucessor == 0){	
						cout<<p->el<<endl;	
						while(p->left != 0){
							p = p->left;
							cout<<p->el<<endl;	
						}
					}
				}
			}
		}
		
		void inserir(T el){ 
			ArvoreNo<T> *p=root;
			ArvoreNo<T> *prev=0;
			
			if(root==0){
				root = new ArvoreNo<T>(el); 
				return;
			}
		
			while(p!=0){
				prev=p;
				if(p->el > el){
					p=p->left;
				}else if(p->sucessor == 0){
					p=p->right;
				}else{
					break;
				}
			}
			
			ArvoreNo<int> *novo = new ArvoreNo<int>(el);
			if(prev->el > el){
				prev->left = novo;
				novo->sucessor = 1;
				novo->right = prev;
			}
			else if(prev->sucessor==1){
				novo->sucessor = 1;
				prev->sucessor = 0;
				novo->right = prev->right;
				prev->right = novo;
					
			}else{
				prev->right = novo;
			}
		}
 };

int main(){
	Arvore<int> *a = new Arvore<int>();
	
	a->inserir(19);
	a->inserir(8);
 	a->inserir(46);
 	a->inserir(41);
 	a->inserir(67);
 	a->inserir(72);
 	a->inserir(8);
 	a->inserir(7);
 	a->inserir(9);
 	a->inserir(6);
 	
	a->preOrdem();
 	
 	
 	return 0;
}
