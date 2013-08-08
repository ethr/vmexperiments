#include "string.h"
#include "stdio.h"
#include "ByteCode.h"
#include "Interpreter.h"

static char* addInstruction(bytecode_t instruction, char* buffer) {
        memcpy(buffer, &instruction, sizeof(bytecode_t));
        return buffer + sizeof(bytecode_t);
}

static char* addDouble(double value, char* buffer) {
        memcpy(buffer, &value, sizeof(double));
        return buffer + sizeof(double);
}


static char* addSizet(size_t value, char* buffer) {
        memcpy(buffer, &value, sizeof(size_t));
        return buffer + sizeof(size_t);
}


int main() {
        char buffer[1024];
        char* nxt;
        double result;
        nxt = buffer;
        nxt = addInstruction(SET, nxt);
        nxt = addSizet(0, nxt);
        nxt = addDouble(50.0, nxt);
        nxt = addInstruction(SET, nxt);
        nxt = addSizet(1, nxt);
        nxt = addDouble(20.0, nxt);
        nxt = addInstruction(ADD, nxt);
        nxt = addSizet(0, nxt);
        nxt = addSizet(1, nxt);
        nxt = addSizet(2, nxt);
        interpret(buffer, nxt - buffer);
        memcpy(&result, getRegisterValue(2), sizeof(double));
        printf("Result %g\n", result);
        return 0;
}
