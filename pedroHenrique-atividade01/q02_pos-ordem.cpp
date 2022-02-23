#include <iostream>

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
		
		void posOrdem(ArvoreNo<T> *no){ //2 - Percurso em Pós Ordem;
			if(root == 0){
				cout<<"vazio"<<endl;
			}else{
				if(no != 0){
					posOrdem(no->left);	
					posOrdem(no->right);	
					cout<<"<"<<no->el;
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
	
 };

int main(){
 	
 	int b = 13;
 	int c = 10;
 	int d = 25;
 	int e = 2;
 	int f = 12;
 	int g = 20;
 	int h = 31;
 	int i = 29;
 	
 	Arvore<int> *a = new Arvore<int>();
 	a->insert(a->root,b);
 	a->insert(a->root,c);
 	a->insert(a->root,d);
 	a->insert(a->root,e);
 	a->insert(a->root,f);
 	a->insert(a->root,g);
 	a->insert(a->root,h);
 	a->insert(a->root,i);
 	
	a->posOrdem(a->root);
 	
 	return 0;
}
