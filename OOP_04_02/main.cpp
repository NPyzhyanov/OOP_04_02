#include <iostream>

#include "address.h"
#include "read_input_data.h"
#include "write_output_data.h"

int main()
{
    int* p_addresses_amount = nullptr;
    Address** p_p_addresses = nullptr;
    
    bool data_read = read_input_data(p_addresses_amount, p_p_addresses);
    
    if (data_read)
    {
        write_output_data(*p_addresses_amount, p_p_addresses);
    }
    
    if (p_addresses_amount != nullptr)
    {
        if (*p_addresses_amount != 0)
        {
            for (int address = 0; address < *p_addresses_amount; address++)
            {
                delete p_p_addresses[address];
            }
        }
    }
    delete[] p_p_addresses;
    delete p_addresses_amount;
    p_p_addresses = nullptr;
    p_addresses_amount = nullptr;
    
    return data_read ? 0 : 1;
}
