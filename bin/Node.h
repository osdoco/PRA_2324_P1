#include <ostream>

template <typename T>
class Node {
	public:
		T data;
		Node<T>* next;
	Node(T dat, Node<T>* net ){
		data=dat;
		if(net!=nullptr){
		next = net;
		 }
		else{
			next = nullptr;
		}
	}
	friend std::ostream&operator<<(std::ostream &out, const Node<T> &node){
		out << node.Data;
		return out;
	}
};
