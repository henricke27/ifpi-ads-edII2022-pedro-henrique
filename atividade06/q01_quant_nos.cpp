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
			
		void quantidadeDeNos(){ //q01
			queue<ArvoreNo<T>*> f;
			ArvoreNo<T> *p=root;
			
			int quant_nos = 0;
			if(p!=NULL){
				f.push(p);
				quant_nos++;
				while(!f.empty()){
					p=f.front();
					f.pop();
					if(p->left!=0){
						f.push(p->left);
						quant_nos++;
					}
					if(p->right!=0){
						f.push(p->right);
						quant_nos++;
					}
				}
			}
			cout<<"Quantidade de nos da arvore: "<<quant_nos<<endl;
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
	a->insert(1);
 	
	a->quantidadeDeNos();
 	
 	return 0;
}
