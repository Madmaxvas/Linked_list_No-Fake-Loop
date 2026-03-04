#include "BiList.hpp"
#include <iostream>

int main() {
    const int initial_data[] = {1, 2, 4, 5};
    BiList<int>* list_head = nullptr;

    try {
        list_head = convert_array_to_list(initial_data, 4);
        print_list(list_head);

        BiList<int>* node_two = list_head->next; 
        insert_after(node_two, 3);
        print_list(list_head);

        list_head = erase_node(list_head);
        print_list(list_head);

        erase_after(list_head->next); 
        print_list(list_head);

    } catch (const std::exception& e) {
        std::cerr << "Internal error: " << "\n";
    }

    clear(list_head);

    return 0;
}
