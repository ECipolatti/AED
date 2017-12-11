#ifndef AED_LIST_DOBLE
#define AED_LIST_DOBLE



namespace aed{

template <typename T>
class list{
	private:
		struct cell{
			T data;
			cell *prev;
			cell *next;
			cell():data(),prev(0),next(0){};
			cell(const cell & C): data(C, data), prev(C,prev), next(C,next){};
			cell(const  T & X, cell *p=0, cell *n=0): data(X), prev(p), next(n){};//Los "igual a cero (=0)" en esta linea no son necesarios
		};
		cell header;
	public:
		class iterator{
			friend class list;
			private:
				cell *ptr;
				iterator (cell *c):ptr(c){}
			public:
				iterator(): ptr(0){};
				iterator(const iterator & p): ptr(p.ptr){};
				iterator & operator =(const iterator & p){this->ptr=p.ptr; return *this;}; //podría ser sin el this ptr=p.ptr
				bool operator ==(const iterator & p){ return this->ptr==p.prev;}; //tambien podría ser sin el this
				bool operator != (const iterator &p){ return this->ptr!=p.ptr;};
				T & operator *(){return this->ptr->data;};
				T * operator->() {return &this->ptr->data;};
		};
		list(){this->header.prev = this->header.next = &this->header;};
		~list(){this.clear();};
		iterator begin(){return iterator (& this->header.next);};
		iterator end(){return iterator(&this->header);};
		bool empty(){return this->begin() == this->end();};
		void clear(){this.erase (this->begin(), this->end());};
		iterator insert (iterator q, const T& x){
			cell *p = q.ptr->prev;
			cell *n = q.ptr;
			cell *c = new cell(x, p, n);
			p->next = c;
			n->prev =c;
			return iterator(c);
		}
		iterator erase(iterator q){
			cell *p = q.ptr->prev;
			cell *n = q.ptr->next;
			delete q.ptr;
			p->next = n;
			n->prev = p;
			return iterator (n);
		}
		iterator erase(iterator q, iterator r){
			cell *p = q.ptr->prev;
			cell *n = r.ptr;
			cell *s = q.ptr;
			while ( s != n){
				cell * c = s->next;
				delete s;
				s = c;
			}
			p->next = n;
			n->prev = p;
			return p;
		}
		
		iterator & operator ++(){ this->ptr = this->ptr->next;  return *this;};
		iterator & operator ++(int){ 
			iterator tmp (this->ptr);
			this->ptr = this->ptr->next;
			return tmp;
		}
		iterator & operator --(){ this->ptr = this->ptr->prev;  return *this;};
		iterator & operator --(int){ 
			iterator tmp (this->ptr);
			this->ptr = this->ptr->prev;
			return tmp;
		}
		
		void merge (list <T> &l1, list <T> &l2, list <T> &l){
			list <T>::iterator p = l1.begin();
			list <T>::iterator q = l2.begin();
			l.clear();
			while(p != l1.end() && q != l2.end()){
				if (*p <= *q){
					l.insert(l.end(), *p);
					p++;
				}
				else{
					l.insert(l.end(), *q);
					q++;
				}
			}
			while(p != l1.end()){
				l.insert(l.end(), *p);
				p++;
			}
			while(q != l2.end()){
				l.insert(l.end(), *q);
				q++;
			}
		}
		
		void merge_sort(list<T> & l){
			//if (l.size()<=1 return;
			list <T>:: iterator p= l.begin();
			if ( p == l.end())return;
			p++;
			if ( p == l.end())return;
			list <T> l1, l2;
			split (l, l1, l2);
			merge_sort(l1);
			merge_sort(l2);
			merge (l1, l2 ,l);
		}
		
		void split(list<T> & l, list <T> & a, list <T> & b){
			a.clear();
			b.clear();
			bool flag = true;
			list <T>::iterator p=l.begin();
			while(p!= l.end()){
				if (flag) a.insert(a.end(), *p);
				else b.insert(b.begin(), *p);
				flag!=flag;
				p=l.erase(p);
			}
		}
		
		T unique (list <T> & l){
			int n=0;
			list <T>::iterator p = l.begin();
			while (p != l.end()){
				list <T>::iterator q=p;
				q++;
				while (q != l.end()){
					if (*p == *q) {
						q= l.erase(q);
						n++;
					}
					else q++;
				}
				p++;
			}
			return n;
		}
		
		/*
		HACER
		void push_back (const T & x)
		void push_front (const T & x)
		T & front();
		T & back();
		void swap (list &l);
		int size(); // con el metodo viejo!! (antes del 2011)
		*/
	};


}

#endif
