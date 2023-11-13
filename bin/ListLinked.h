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
	  first = new Node(0);
    	n = 0;
    	}

    	~ListLinked(){
    	Node<T>* aux = first;
    	for(int i = 0; i <= n; i++){
    	aux = first;
    	first = first->next;
    	delete[] aux;
     	}
    	}

    	T operator[](int pos){
    	if(pos < 0 || pos > n){
            	throw std::out_of_range("posición no válida");
     	}
    	else{
            	Node<T>* aux;
            	for(int i = 0; aux != nullptr && i != pos; i++){
		  aux = aux->next;
		  }
            	return aux->data;
     	}
	}

 friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
    	Node<T>* aux = list.first;
     	out << "[";
     	while(aux != nullptr){
            	out << aux;
            	aux = aux->next;
            	if(aux != nullptr){
            	out<<", ";
            	}
            	out<<"]";
     	}
     	return out;
 }
//OVERRIDE DE LAS FUNCIONES DE List.h------------------------------------------

    	void insert (int pos,T e){
            	if (pos < 0 || pos > n){
            	throw std::out_of_range("posición inválida");
            	}
            	else {
            	Node<T>* aux;
            	aux = first;
            	for(int i = 0; i < pos - 1; i++){
                   	aux = aux->next;
            	}
            	Node<T>* ele = new Node(e,aux->next);
            	aux->next = ele;
            	n++;
            	}
     	}
     	void append(T e) override{
            	Node<T>* aux;
            	aux = first;
            	while(first->next != nullptr){
            	aux = aux->next;
            	}
		Node<T>* ele = new Node(e);
            	aux->next = ele;//ahora la última apunta a e, e ya apunta a nullptr ya que es el último
            	n++;
	}

     	void prepend(T e) override{
            	Node<T>* aux;
            	aux = first;
		Node<T>* ele = new Node(e,aux);
            	first = ele;
            	n++;
            	}
     	T remove (int pos) override {
            	if (pos < 0 || pos > n){
                   	throw std::out_of_range("posición inválida");
                	}
            	else {
            	Node<T>* aux;
            	Node<T>* aux1;
		Node<T>* val;
            	aux = first;
            	for(int i = 0; i <= pos-1; i++){
		  aux = aux->next;
            	}
		val = aux->next;
            	aux1=aux->next;
            	aux->next = aux1->next;
            	n--;
		return val->data;
            	}
		
	}
        T get(int pos)override{
            	if (pos < 0 || pos > n){
                    	throw std::out_of_range("posición inválida");
              	}
            	else {
            	Node<T>* aux;
              	for(int i = 0; first != nullptr && i != pos; i++){
                    	aux = aux->next;
              	}
                     	return aux->data;
            	}

	}


    	int search(T e)override{
            	int pos = 0;
		Node<T>* aux;
		aux = first;
            	while(aux->next != nullptr){
                    	pos++;
                    	aux =  aux->next;
                    	if (e == aux->data){
                    	return pos;
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
