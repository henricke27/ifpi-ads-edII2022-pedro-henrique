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
 			//clear(root);
 			root=0;
		}
		

		void inserir(ArvoreNo<T> *no, T el){ 
			if(root == 0){
				root = new ArvoreNo<T>(el);	
			}else{
				if(no->left == 0){
					no->left = new ArvoreNo<T>(el);
				}else if(no->right == 0){
					no->right = new ArvoreNo<T>(el);
				}else{
					if(el < no->el){
						inserir(no->left,el);
					}else{
						inserir(no->right,el);
					}		
				}	
			}		
		}
		
		void balancear(T vetor[], int first, int last){	
			if(first <= last){
				int middle = (first + last) / 2;
				inserir(this->root,vetor[middle]);
				balancear(vetor,first,middle-1);
				balancear(vetor,middle+1,last);
			}
		}
		
		void bolha (int n,int* v) {
			int i,j;
			bool trade;
			for(i=n-1; i>0; i--){
				trade = false;
				for(j=0; j<i; j++){
					if(v[j] > v[j+1]){
						int temp = v[j];
						v[j] = v[j+1];
						v[j+1] = temp;
						trade = true;
					}
				}
				if(!trade){
					break;
				}
			}
		}
 };

int main(){
 	Arvore<int> *a = new Arvore<int>();
 	int vetor[] = {6,7,14,40,63};
 	
 	/*a->inserir(a->root,7);
 	a->inserir(a->root,6);
 	a->inserir(a->root,22);
 	a->inserir(a->root,14);
 	a->inserir(a->root,40);
 	a->inserir(a->root,63);*/
	
	a->balancear(vetor,0,4);
	
 	return 0;
}
