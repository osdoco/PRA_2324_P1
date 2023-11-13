#include <ostream>

template <typename T>
class Node {
	public:
		T data;
		Node<T>* next;
	Node(T dat = nullptr, Node<T>* net = nullptr ){
		data = dat;
		next = net;
	}
	friend std::ostream&operator<<(std::ostream &out, const Node<T> &node){
		out << node.Data;
		return out;
	}
};
