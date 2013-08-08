#ifndef INTERPRETER_H_
#define INTERPRETER_H_

#include "string.h"

void interpret(char* buffer, size_t size);

char* getRegisterValue(size_t number);

#endif
