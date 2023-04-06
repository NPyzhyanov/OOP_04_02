#include <fstream>
#include <string>

#include "address.h"
#include "return_codes.h"
#include "limits.h"
#include "display_message.h"
#include "read_line.h"

#include "read_input_data.h"

bool read_input_data(int* &p_addresses_amount, Address** &p_p_addresses)
{
    std::ifstream input_file("../OOP_04_02/in.txt");
    if(! input_file.is_open())
    {
        display_message(file_not_opened);
        return false;
    }
    
    std::ifstream* p_file = &input_file;
    
    std::string str_addresses_amount = "";
    
    ReturnCodes return_code = read_line(p_file, &str_addresses_amount, false);
    if (return_code != ok)
    {
        if (return_code == unexpected_eof && str_addresses_amount == "0")
        {
            p_addresses_amount = new int(0);
            return true;
        }
        display_message(return_code);
        if (return_code != wrong_line_entry)
        {
            return false;
        }
    }
    
    int local_addresses_amount = std::stoi(str_addresses_amount);
    
    if (local_addresses_amount < 0 || local_addresses_amount > limits::MAX_ADDRESSES_AMOUNT)
    {
        display_message(wrong_addresses_amount);
        return false;
    }
    
    p_addresses_amount = new int(local_addresses_amount);
    
    if (local_addresses_amount == 0)
    {
        if (!input_file.eof())
        {
            display_message(excess_data);
        }
        return true;
    }
    
    p_p_addresses = new Address*[local_addresses_amount]();
    
    std::string city;
    std::string street;
    std::string str_house_number;
    int house_number;
    std::string str_apartment_number;
    int apartment_number;
    
    bool eof_expected = false;
    
    for (int address = 0; address < local_addresses_amount; address++)
    {
        city = "";
        street = "";
        str_house_number = "";
        str_apartment_number = "";
        
        return_code = read_line(p_file, &city, false);
        if (return_code != ok)
        {
            display_message(return_code);
            if (return_code != wrong_line_entry)
            {
                return false;
            }
        }
        
        return_code = read_line(p_file, &street, false);
        if (return_code != ok)
        {
            display_message(return_code);
            if (return_code != wrong_line_entry)
            {
                return false;
            }
        }
        
        return_code = read_line(p_file, &str_house_number, false);
        if (return_code != ok)
        {
            display_message(return_code);
            if (return_code != wrong_line_entry)
            {
                return false;
            }
        }
        house_number = stoi(str_house_number);
        
        eof_expected = (address == local_addresses_amount - 1);
        return_code = read_line(p_file, &str_apartment_number, eof_expected);
        if (return_code != ok)
        {
            display_message(return_code);
            if (return_code != wrong_line_entry)
            {
                return false;
            }
        }
        apartment_number = stoi(str_apartment_number);
        
        p_p_addresses[address] = new Address(city, street, house_number, apartment_number);
    }
    
    if (!input_file.eof())
    {
        display_message(excess_data);
    }
    
    p_file = nullptr;
    input_file.close();
    
    return true;
}
