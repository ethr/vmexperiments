#include "string.h"
#include "stdio.h"
#include "ByteCode.h"
#include "Interpreter.h"
#include "Stack.h"

static char* addInstruction(bytecode_t instruction, char* buffer) {
        memcpy(buffer, &instruction, sizeof(bytecode_t));
        return buffer + sizeof(bytecode_t);
}

static char* addDouble(double value, char* buffer) {
        memcpy(buffer, &value, sizeof(double));
        return buffer + sizeof(double);
}


int main() {
        char buffer[1024];
        char* nxt;
        nxt = buffer;
        nxt = addInstruction(PUSH, nxt);
        nxt = addDouble(10.0, nxt);
        nxt = addInstruction(PUSH, nxt);
        nxt = addDouble(20.0, nxt);
        nxt = addInstruction(ADD, nxt);
        interpret(buffer, nxt - buffer);
        printf("Result %g\n", popValue());
        return 0;
}
