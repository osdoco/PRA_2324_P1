#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
 
        Node<T>* first;
	int n;

    public:

        ListLinked(){
	first = nullptr;
	n = 0;
	}

	~ListLinked(){
	Node<T>* aux = first;
	for(int i = 0; i <= n; i++){
	aux = first->next;
	delete[] first;
	first = aux;
	 }
	}

	T operator[](int pos){
	if(pos < 0 || pos > n){
		throw std::out_of_range("posición no válida");
	 }
	else{
		
	 	for(int i = 0; first != nullptr && i != pos; i++){
		first = first->next;
		}
		return first;
	 }
	}

 friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){

	 out << "[";
	 while(list.first != nullptr){
		out << list.first;
		list.first = list.first->next;
		if(list.first != nullptr){
		out<<", ";
		}
	 }
	 return out;
 }
//OVERRIDE DE LAS FUNCIONES DE List.h------------------------------------------

        void insert (int pos,T e) override{
                if (pos < 0 || pos > n){
                throw std::out_of_range("posición inválida");
                }
                else {
                
                for(int i = 0; i < pos - 1; i++){
                        first = first->next;
                }
		Node<T>* aux;
		aux = first->next;
                first->next = e;
		first = first->next;//aqui estamos en e
		first->next = aux;
                n++;
                }
         }
         void append(T e) override{
                while(first->next != nullptr){
		first = first->next;
		}
		first->next = e;//ahora la última apunta a e;
		first = first->next;
		first->next = nullptr;//ahora el puntero e->next apunta a null ya que es el ultimo
                n++;
                }

         void prepend(T e) override{
                Node<T>* aux;
		aux = first;
		first = e;
		first->next = aux;
                n++;
                }
	 T remove (int pos) override {
                if (pos < 0 || pos > n){
                       throw std::out_of_range("posición inválida");
                    }
                else {
                for(int i = 0; i < pos-1; i++){
			first = first->next;
		}
		first->next = nullptr;	
		n--;
                }
         }

         T get(int pos)override{
                if (pos < 0 || pos > n){
                        throw std::out_of_range("posición inválida");
                  }
                else {
                  for(int i = 0; first != nullptr && i != pos; i++){
                	first = first->next;
               	  }
                 	 return first;
         	}

              }

                 
        int search(T e)override{
		int aux = 0;
                while(first->next != nullptr){
			aux++;
			first = first->next;
                        if (e == first){
                        return aux;
                        }
                }
                        return -1;
         }

        bool empty()override{
                return n == 0;
                }

        int size()override{
                return n;
                }


};
