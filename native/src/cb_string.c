/**
 * Licensed under Apache 2.0.
 * Developed by Aquiles Trindade (trindadedev).
 * in 2025-04-08
 */

#include "cb_string.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

cb_bool str_starts_with(cb_string str, cb_string prefix) {
  return strncmp(prefix, str, strlen(prefix)) == 0;
}

// Replaces an text in String (cb_string) by moving memory
void str_replace(cb_string str,
                 const cb_string target,
                 const cb_string replacement) {
  char buffer[1024];  // Temporary buffer
  cb_string pos = strstr(str, target);
  if (!pos)
    return;  // Target not found

  size_t before_len = pos - str;
  size_t target_len = strlen(target);
  size_t replacement_len = strlen(replacement);

  strncpy(buffer, str, before_len);          // Copy part before the target
  strcpy(buffer + before_len, replacement);  // Add the replacement
  strcpy(buffer + before_len + replacement_len,
         pos + target_len);  // Add the rest of the string after the target
  strcpy(str, buffer);       // Copy result back into original string
}

// trim string
cb_string str_trim(cb_string str) {
  while (isspace((unsigned char)*str))
    str++;
  return str;
}