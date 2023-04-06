#include "address.h"

#include <string>

Address::Address(std::string city_, std::string street_, int house_number_, int apartment_number_)
{
    city = city_;
    street = street_;
    house_number = house_number_;
    apartment_number = apartment_number_;
}

std::string Address::form_output_address()
{
    std::string converted_house_number = std::to_string(house_number);
    std::string converted_apartment_number = std::to_string(apartment_number);
    
    std::string output_address = city + ", " + street + ", " + converted_house_number + ", " + converted_apartment_number;
    
    return output_address;
}
