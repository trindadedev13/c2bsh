/**
 * Licensed under Apache 2.0.
 * Developed by Aquiles Trindade (trindadedev).
 * in 2025-04-08
 */

#ifndef CB_CONVERTER_H
#define CB_CONVERTER_H

#include "cb_bool.h"
#include "cb_string.h"

typedef struct {
  cb_string code;       // the beanshell converted code
  cb_string* includes;  // list with all includes
  int includes_count;   // the size of list with all includes
} c2bsh_converter_result;

// Converts the C lang code to Bean shell code
// @param c_code The CLang Code
// @returns the result
// @see c2bsh_converter_result struct
c2bsh_converter_result* c2bsh_converter_convert(const cb_string c_code);

// Checks if line starts with #include
// if true its a include
cb_bool c2bsh_converter_check_include(c2bsh_converter_result* result,
                                      cb_string line);

// Add includes into includes list.
void c2bsh_converter_add_includes(c2bsh_converter_result* result,
                                  cb_string line);

// Replace C Types with BeanShell/Java Types in ptr
// Example: cb_string -> String
void c2bsh_converter_replace_ctypes(cb_string code_buffer, cb_string ptr);

// Converts C Array declaration to BeanShell/Java Array Decalaration
void c2bsh_converter_resolve_array_syntax(cb_string input, cb_string output);

// free result allocated memory.
void c2bsh_converter_close(c2bsh_converter_result* result);

#endif
