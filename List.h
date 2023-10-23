#ifndef LIST_H
#define LIST_H

template <typename T> 
class List {
    public:
       virtual  void append(T e);
       virtual  void prepend(T e);

       virtual T remove(int pos);
       virtual T get(int pos);
       virtual  int search(T e);
       virtual bool empty();
       virtual int size();

};
#endif 

