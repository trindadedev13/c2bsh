#ifndef CB_FORMATTER_H
#define CB_FORMATTER_H

#include <stdio.h>

#include "cb_bool.h"
#include "cb_string.h"

// Adds indentation to the buffer based on the indentation level
void formatter_append_intent(cb_string buffer, int* pos, int indent_level);

// Formatts the code and returns it
cb_string formatter_format(cb_string code,
                           size_t buffer_size,
                           cb_bool indent_multiline_comments);

#endif