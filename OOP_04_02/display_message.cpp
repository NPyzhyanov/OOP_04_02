#include <iostream>

#include "return_codes.h"
#include "limits.h"

#include "display_message.h"

void display_message(ReturnCodes return_code)
{
    setlocale (LC_ALL, "Russian");
    
    switch (return_code)
    {
        case file_not_opened:
            std::cout << "Не удалось открыть файл \"in.txt\"" << std::endl;
            break;
        case incomplete_line:
            std::cout << "Одна из строк введена не полностью" << std::endl;
            break;
        case unexpected_eof:
            std::cout << "В файле присутствуют не все данные" << std::endl;
            break;
        case wrong_line_entry:
            std::cout << "В одной из строк присутствуют лишние данные" << std::endl;
            break;
        case excess_data:
            std::cout << "В файле присутствуют лишние данные" << std::endl;
            break;
        case wrong_addresses_amount:
            std::cout << "Некорректное количество адресов. Введите значение от 0 до " << limits::MAX_ADDRESSES_AMOUNT << std::endl;
            break;
        case wrong_ptr_transmission_error:
            std::cerr << "Pointer transmittion error occured!" << std::endl;
        default:
            std::cerr << "Unknown error!" << std::endl;
    }
}
