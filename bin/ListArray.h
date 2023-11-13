#include <ostream>
#include "List.h"
template <typename T>
class ListArray : public List<T>{
	private:
	       	T* arr;
		int max=0;
		int n;
		static const int MINSIZE = 2;
		void resize(int new_size){
       			T aux[new_size];
        		for (int i = 0; i<=new_size;i++){
               		 aux[i]=arr[i];
          		}
        		delete[] arr;
       			arr = new T[new_size];
        		for (int i = 0; i<=new_size;i++){
                		arr[i]=aux[i];
          		}
       			max = new_size;
       		 }

	public:
		ListArray(){
		arr = new T[MINSIZE];
		max = MINSIZE;
		n=0;
		}
		~ListArray(){
		delete[] arr;
		}

		T operator[](int pos){
		if (pos <= max && pos >= 0){
			return  arr[pos];
		   }
		else{
			throw std::out_of_range("la posición es inválida");
		   }
		}
		 
	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
	
	out << "[";	
	for (int i=0;i<list.n;i++){
	out<< list.arr[i];
	
	if(i < list.n -1){
	out << ", ";
	}
	}
	out << "]";
	return out;
 	}
	
//OVERRIDE DE LAS FUNCIONES DE List.h------------------------------------------

	void insert (int pos,T e){
		if (pos < 0 || pos > max){
		throw std::out_of_range("posición inválida");
		}
		else {
		resize(max+1);
		for(int i = max; i > pos; i--){
			arr[i]=arr[i-1];
		}
		arr[pos] = e;
		n++;
		}
	 }
	 void append(T e) override{
resize(max + 1);
		arr[max] = e;
		n++;
		}

	 void prepend(T e) override{
		resize(max + 1);
		for(int i=0; i<=max; i++){
		arr[i+1]=arr[i];
		}
                arr[0] = e;
                n++;
		}

	T remove (int pos) override {
		if (pos < 0 || pos > max){
                       throw std::out_of_range("posición inválida");
                    }
		else {
       		 T aux;
		 aux = arr[pos];		 
		 for (int i = pos; i<=max;i++){
                	arr[i]=arr[i+1];
          	 }
		  resize(max-1);
                  return aux;
               	}
	 }

	 T get(int pos)override{
		if (pos < 0 || pos > max){
                        throw std::out_of_range("posición inválida");
                     }
                     else {
                       return arr[pos];
		     }

		 }
	int search(T e)override{
		for(int i =0; i < max; i++){
			if (e == arr[i]){
			return i;
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
