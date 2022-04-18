#include <queue>
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
		
		// ########## Parte A ##########
		
		void insert(T el){ //13.1
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
		
		void preOrdem(ArvoreNo<T> *no){ //13.1
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
		
		void ordemSimetrica(ArvoreNo<T> *no){ //13.1
			if(root == 0){
				cout<<"vazio"<<endl;
			}else{
				if(no != 0){
					ordemSimetrica(no->left);	
					cout<<no->el<<endl;
					ordemSimetrica(no->right);		
				}
			}
		}
		
		void posOrdem(ArvoreNo<T> *no){ //13.1
			if(root == 0){
				cout<<"vazio"<<endl;
			}else{
				if(no != 0){
					posOrdem(no->left);	
					posOrdem(no->right);	
					cout<<no->el<<endl;
				}
			}
		}
		
		void percursoExtensao(){ //13.1
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
		
		int nos(ArvoreNo<T> *no){ // 13.2
			if(no==NULL){
				return 0;
			}else{
				return 1 + nos(no->left) + nos(no->right); 
			}
		}
		
		int folhas(ArvoreNo<T> *no){  //13.3
			if(no == NULL){
				return 0;
			}else if(no->left == NULL and no->right == NULL){
				return 1;
			}else{
				return folhas(no->left) + folhas(no->right);
			}
		}
		
		int tem(ArvoreNo<T> *a, T x){ // 13.1 e 13.5;
			if(a==NULL){
				return 0;
			}	
			if(x == a->el) {
				return 1;	
			}
			if(x <= a->el){
				return tem(a->left, x);
			}else {
				return tem(a->right, x);
			}		
		}
		
		int eb(ArvoreNo<T> *a){ // 13.6
			if (a != NULL){
				if((a->left == 0 && a->right != 0) || (a->left != 0 && a->right == 0)){
					return 0;
				}else{
					return eb(a->left) && eb(a->right); 
				}
			}else{
				return 1;
			}
		}
		
		int igual(ArvoreNo<T> *a, ArvoreNo<T> *b){ // 13.7
			if ((a == NULL) != (b == NULL)) return 0;
   			if (a == b) return 1;

   			if (a->el != b->el) return 0;
   			if (!igual(a->left, b->left)) return 0;
   			if (!igual(b->right, b->right)) return 0;
   			return 1;
		}
		
		// ########## Parte B ##########
		
		void remocaoSimples(T el){ // 1
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
		
		void deleteByMerging(ArvoreNo<T> *prev, ArvoreNo<T> *no){ // 2
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
					//cout<<"aqui:"<<tmp->el<<endl;
					tmp->right=no->right;
					if(prev->el < no->el){
						prev->right = no->left;
					}else{
						prev->left = no->left;
					}
					tmp = no;
				}
				delete tmp;
			}	
		}
		
		void findAndDeleteByMerging(T el){ //2
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
					deleteByMerging(prev,root);
				}else {
					if(prev->left==no){
						deleteByMerging(prev,prev->left);
					}else{
						deleteByMerging(prev,prev->right);
					}
				}
			}
		}
		
		void findAndDeleteByCopying(ArvoreNo<T> *a){ // 3
			ArvoreNo<T> *no = a;
			ArvoreNo<T> *prev=no;
			ArvoreNo<T> *tmp=no;
			
			if(no->right == 0){
				no = no->left;
			}else if(no->left==0){
				no = no->right;
			}else{
				tmp = no->left;
				prev = no;
				while(tmp->right!=0){
					prev = tmp;
					tmp= tmp->right;
				}
				no->el = tmp->el;
				if(prev==no){
					prev->left = tmp->left;
				}else{
					prev->right = tmp->left;
				}
			}
			delete tmp;	
		}
				
 };
