#ifndef AED_H
#define AED_H

namespace AED{
	template <typename T>
	class list{
	public:
		// La clase iterador se inicializa aca pero solo porq despues
		// es utilizada en la clase cell de lo contrario cuando lo usemos en
		// esa clase no reconocera el termino iterator;
		// Luego de la clase cell retornamos al public y la definimos!
		class iterator;
		
	private:
		//Se implementa la clase(struct) cell que es una anidada tambien
		//A diferencia del iterador es privada y no puede ser accedida desde afuera
		
		struct cell{
			
			friend class iterator;
			friend class list;
			
			T data;
			cell *prev;
			cell *next;
			
			cell() : prev(0), next(0){}
			cell(const cell &c) : data (c.data), prev(c.prev), next(c.next){}
			cell (const T &x,cell *p, cell *n): data(x),prev(p),next(n){}
			
		};
		cell header;
		
	public:
		/*! ******************************** */
		/*! ***        ITERADORES        *** */
		/*! ******************************** */
		class iterator{
		private:
			friend class list;
			cell *ptr; // Celda a la que el iterador apunta;
			iterator (cell *c) : ptr(c){};
		public:
			iterator():ptr(0){};
			iterator (const iterator &p): ptr( p.ptr ) {}
			
			/*! ******************************** */
			/*! ***SOBRE CARGA DE OPERADORES!*** */
			/*! ******************************** */
			iterator operator= (const iterator &p){
				this->ptr=p.ptr;
				return *this;
			}
			
			bool operator== (const iterator &p){
				return this->ptr != p.ptr;
			}
			
			bool operator!= (const iterator &p ){
				return this->ptr != p.ptr;
			}
			T& operator* (){
				return this->ptr->data; //*p Para datos primitivos
			}
			
			T* operator->(){
				return this->ptr->data; // p->DNI (Para estructuras)
			}
			
			// Avanza el iterador
			// Y devuelve el avanzado.
			iterator & operator++(){
				ptr = ptr->next;
				return ptr;
			} // prefix ++p;
			
			// Avanza el iterador pero
			// Devuelve el anterior.
			iterator operator ++(int) {
				iterator tmp(this->ptr); // iterator tmp = *this;
				this->ptr = this->ptr->next;
				return tmp;
			}
			
			iterator & operator --() {
				this->ptr = this->ptr->prev;
				return *this;
			}
			
			iterator operator --(int){
				iterator tmp(this->ptr);
				this->ptr = this->ptr->prev;
				return tmp;
			}
		};
		
	
	/*! ******************************** */
	/*! ***CLASE Dlist CONSTRUCTORES!*** */
	/*! ******************************** */
	list(){
		this->header.prev = this->header.next = &this->header;
	}
	
	~list(){
		this->clear();
	}
	
	/*! ******************************** */
	/*! ***  CLASE Dlist FUNCIONES!  *** */
	/*! ******************************** */
	
	iterator begin(){
		return iterator (header.next);
	}
	
	iterator end(){
		return iterator (&this->header);
	}
	
	bool empty(){
		return (this->begin() == this->end());
	}
	
	void clear (){
		this->erase(this->begin(), this->end());
	
	};
	
	iterator insert ( iterator q, const T &x){
		cell *p = q.ptr->prev;
		cell *n = q.ptr;
		cell *c = new cell (x , p, n );
		p->next = c;
		n->prev = c;
		return iterator(c);
	}
	
	iterator erase ( iterator q ){
		
		cell *p = q.ptr->prev; //p es el anterior a q
		cell *n = q.ptr->next; // n es el siguiente a q
		delete q.ptr;          // Elimino q
		
		p->next = n;           // ahora el que le sigue a "p" es "n" q era el q le seguia a "q"
		n->prev = p;           // El previo a "n" ahora es "p" que era el anterior a "q"
		
		return iterator (n);   // Desp del erase devuelve el que le seguia!
		
		
	}
	
	iterator erase ( iterator q, iterator r ){
		
		cell *p = q.ptr->prev;
		cell *n = r.ptr;
		cell *s = q.ptr;
		
		while ( s != n ){
			cell *c = s->next;
			delete s;
			s=c;
		}
		p->next = n;
		n->prev = p;
		
		return r;
	}
	
	void push_back (const T &x );
	}
;
}

#endif
