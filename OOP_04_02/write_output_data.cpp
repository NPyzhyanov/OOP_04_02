#include <string>
#include <fstream>

#include "return_codes.h"
#include "address.h"
#include "display_message.h"
#include "form_sorted_data.h"

#include "write_output_data.h"

void write_output_data(int addresses_amount, Address** p_p_addresses)
{
    if (p_p_addresses == nullptr)
    {
        if (addresses_amount != 0)
        {
            display_message(wrong_ptr_transmission_error);
            return;
        }
    }
    
    std::ofstream output_file("../OOP_04_02/out.txt");
    
    output_file << addresses_amount << std::endl;
    
    if (addresses_amount == 0)
    {
        output_file.close();
        return;
    }
    
    std::string output_data = form_sorted_data(addresses_amount, p_p_addresses);
    
    output_file << output_data;
    
    output_file.close();
}
