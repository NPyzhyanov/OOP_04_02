#include <string>
#include <fstream>

#include "return_codes.h"
#include "read_line.h"

ReturnCodes read_line(std::ifstream* p_file, std::string* p_word, bool eof_expected)
{
    ReturnCodes warning_status = ok;
    
    *p_file >> *p_word;
    if (p_word->length() == 0)
    {
        return incomplete_line;
    }
    if (p_file->eof())
    { 
        return eof_expected ? ok : unexpected_eof;
    }
    
    while(p_file->get() != '\n' && !p_file->eof())
    {
        warning_status = wrong_line_entry;
        if (p_file->eof())
        {
            return eof_expected ? ok : unexpected_eof;
        }
    }
    
    return warning_status;
}
