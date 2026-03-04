#ifndef BILIST_HPP
#define BILIST_HPP

#include <iostream>
#include <cstddef>

template<class T>
struct BiList {
  T val;
  BiList<T>* next;
  BiList<T>* prev;
};

template<class T>
BiList<T>* create_node(const T& value, BiList<T>* prev_node = nullptr, BiList<T>* next_node = nullptr) {
  return new BiList<T>{ value, next_node, prev_node };
}

template<class T>
BiList<T>* insert_after(BiList<T>* node, const T& value) {
  if (!node) return nullptr;

  BiList<T>* new_node = create_node(value, node, node->next);
    
  if (node->next != nullptr) {
        node->next->prev = new_node;
  }
  node->next = new_node;
    
  return new_node;
}

template<class T>
BiList<T>* erase_node(BiList<T>* node) noexcept {
  if (!node) return nullptr;

  BiList<T>* prev_node = node->prev;
  BiList<T>* next_node = node->next;

  if (prev_node != nullptr) {
    prev_node->next = next_node;
  }
  if (next_node != nullptr) {
    next_node->prev = prev_node;
  }

  delete node;
  return next_node;
}


template<class T>
BiList<T>* erase_after(BiList<T>* node) noexcept {
  if (!node || !node->next) return nullptr;
    
  node->next = erase_node(node->next);
  return node->next;
}

template<class T>
void clear(BiList<T>*& head) noexcept {
  while (head != nullptr) {
    head = erase_node(head);
  }
}

template<class T>
BiList<T>* convert_array_to_list(const T* data, size_t size) {
  if (size == 0 || !data) return nullptr;

  BiList<T>* head = nullptr;
  try {
    head = create_node(data[0]);
    BiList<T>* current = head;

    for (size_t i = 1; i < size; ++i) {
      current = insert_after(current, data[i]);
    }
  }
  catch (...) {
    clear(head); 
      throw;
  }
  return head;
}

template<class T>
void print_list(const BiList<T>* head) {
  const BiList<T>* curr = head;
  while (curr) {
    std::cout << curr->val << "\n";
    curr = curr->next;
  }
  std::cout << "\n";
}

#endif
