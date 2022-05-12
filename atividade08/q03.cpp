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
			
		void algoritmoMorris(){ 
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
 	a->insert(15);
	a->insert(4);
 	a->insert(20);
 	a->insert(17);
 	a->insert(19);
 	
 	a->algoritmoMorris();
 	
 	return 0;
}
