#include "main.h"


/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/

void assign_value_to_memory_address_given (uint8_t *msg, response_struct *response_struct_ptr) {
    // (response_struct_ptr->dataAddress) = (uint32_t) msg;
	(response_struct_ptr->dataAddress) =  msg;
}
