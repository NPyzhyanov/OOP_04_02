#ifndef RETURN_CODES_H
#define RETURN_CODES_H

enum ReturnCodes
{
    ok = 0,
    file_not_opened,
    incomplete_line,
    unexpected_eof,
    wrong_line_entry,
    excess_data,
    wrong_addresses_amount,
    wrong_ptr_transmission_error
};

#endif // RETURN_CODES_H
