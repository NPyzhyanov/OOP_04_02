#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address
{
public:
    Address(std::string city, std::string street, int house_number, int apartment_number);
    
    std::string form_output_address();
    
private:
    std::string city;
    std::string street;
    int house_number;
    int apartment_number;
};

#endif // ADDRESS_H
