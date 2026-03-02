#include <iostream>
#include <cstddef>

template<class T>
struct BiList
{
    T val;
    BiList<T>* next;
    BiList<T>* prev;
};

template<class T>
BiList<T>* convert(const T* data, const size_t s)
{
  if (s == 0){return nullptr;}
  
  BiList<T>* head = new BiList<T>{ data[0], nullptr, nullptr };
  BiList<T>* current = head;

  try{
    for (size_t i = 1; i < s; ++i){
      BiList<T>* newNode = new BiList<T>{ data[i], nullptr, current };
      current->next = newNode;
      current = newNode;
    }
  }
  catch (...){
    while (head != nullptr){
      BiList<T>* temp = head;
      head = head->next;
      delete temp;
    }
  throw;
  }
  
  return head;
}

template<class T>
void clear(BiList<T>* head)
{
  while (head != nullptr){
    BiList<T>* temp = head;
    head = head->next;
    delete temp;
  }
}

int main()
{
  const int data[] = { 1, 2, 3 };
  const size_t size = 3;
  BiList<int>* list = convert(data, size);
  clear(list);
  return 0;
}
