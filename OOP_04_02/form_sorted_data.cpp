#include <string>

#include "address.h"

#include "form_sorted_data.h"

std::string form_sorted_data(int addresses_amount, Address** p_p_addresses)
{
    std::string* addresses_array = new std::string[addresses_amount]();
    
    for (int address = 0; address < addresses_amount; address++)
    {
        std::string new_address = p_p_addresses[address]->form_output_address();
        
        // Сортировка вставками
        int sort_index = address;
        while (sort_index > 0 && new_address < addresses_array[sort_index - 1])
        {
            addresses_array[sort_index] = addresses_array[sort_index - 1];
            sort_index--;
        }
        addresses_array[sort_index] = new_address;
    }
    
    std::string sorted_addresses = "";
    
    for (int address = 0; address < addresses_amount; address++)
    {
        sorted_addresses += (addresses_array[address] + "\n");
    }
    
    delete[] addresses_array;

    return sorted_addresses;
}
