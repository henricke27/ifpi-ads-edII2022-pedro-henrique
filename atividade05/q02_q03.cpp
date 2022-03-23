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
		
		void percursoExtensao(){ //q02.percuso em extensão
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
		
		void remove(ArvoreNo<T> *no){
			ArvoreNo<T> *tmp;
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
				}
				delete tmp;
			}	
		}
		
		void findAndRemove(T el){ //q03.remoção por fusão
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
 	
 	a->findAndRemove(10);
	a->percursoExtensao();
 	
 	return 0;
}
