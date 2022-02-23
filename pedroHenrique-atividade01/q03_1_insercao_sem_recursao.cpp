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
		
		void imprime(ArvoreNo<T> *no){
			if(root==0){
				cout<<"vazio"<<endl;
			}else{
				if(no!=0){
					cout<<"<"<<no->el;
					imprime(no->left);
					imprime(no->right);
					cout<<">";
				}else{
					cout<<"<>";
				}				
			}			
		}
		
		void insert(T el){ // 3.1 Insercao sem recursao
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
 	
 	int b = 13;
 	int c = 10;
 	int d = 25;
 	int e = 2;
 	int f = 12;
 	int g = 20;
 	int h = 31;
 	int i = 29;
 	
 	Arvore<int> *a = new Arvore<int>();
 	a->insert(b);
 	a->insert(c);
 	a->insert(d);
 	a->insert(e);
 	a->insert(f);
 	a->insert(g);
 	a->insert(h);
 	a->insert(i);
 	
	a->imprime(a->root);
 	
 	return 0;
}
