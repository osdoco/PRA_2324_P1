#include <ostream>
#include "List.h"
template <typename T>
class ListArray : public List<T>{
	private:
	       	T* arr;
		int max;
		int n;
		static const int MINSIZE = 2;
		void resize(int new_size);
	public:
		ListArray() override{
		cosas = new T[MINSIZE]
		max = MINSIZE;
		n=0;
		arr = cosas[0];
		}
		~ListArray(){
		delete[] cosas;
		}

		T operator[](int pos){
		if (pos <= size - 1 && pos > 0){
			return  cosas[pos];
		   }
		else{
			throw std::out_of_range("la posición es inválida");
		   }
		}
		 
	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
	for (int i=0;i<n;i++){
		out<< cosas[i] << " ";
		}
	return out;
 	}

	void resize(int new_size){
	T aux[new_size];
	for (int i = 0; i<=new_size;i++){
		aux[i]=cosas[i];
	  }
	delete[] cosas;
	cosas = new T[new_size]
	 for (int i = 0; i<=new_size;i++){
                cosas[i]=aux[i];
          }

	max = new_size;
	arr = cosas[0];
	 
	}
	
//OVERRIDE DE LAS FUNCIONES DE List.h------------------------------------------

	void insert override (int pos,T e){
		if (pos < 0 || pos > max){
		throw std::out_of_range("posición inválida");
		}
		else {
		resize(max+1);
		for(int i = max; i > pos; i--){
			cosas[i]=cosas[i-1];
		}
		cosas[pos] = e;
		n++;
		}
	 }
	 void apped override (T e){
		resize(max + 1);
		cosas[max] = e;
		n++;
		}

	 void prepend override(T e){
		resize(max + 1);
		for(int i=0; i<=max; i++){
		cosas[i+1]=cosas[i];
		}
                cosas[0] = e;
                n++;
		}

	T remove override (int pos){
		if (pos < 0 || pos > max){
                       throw std::out_of_range("posición inválida");
                    }
		else {
                  T aux= cosas[pos];
                  cosas[pos]='NULL';
                  return aux;
		  n--;
               	}
	 }

	 T get override (int pos){
		if (pos < 0 || pos > max){
                        throw std::out_of_range("posición inválida");
                     }
                     else {
                       return cosas[pos];
		     }

		 }
	int search override(T e){
		for(int i =0; i < max; i++){
			if (e = cosas[i]){
			return i;
			}
		}
			return -1;
	 }

	bool empty override(){
			 T aux;
		for (int i = 0; i < max; i++){
			aux = cosas[i];
			if(aux =! 'NULL'){
			return false;
			}
		   }
		return true;
		}

	int size override (){
		return n;
		}
		
};
