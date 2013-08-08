#include "string.h"
#include "Interpreter.h"
#include "ByteCode.h"
#include "Stack.h"

void interpret(char* buffer, size_t size) {
        char* head = buffer;
        while(head - buffer < size) {
                bytecode_t instruction;
                memcpy(&instruction, head, sizeof(bytecode_t));
                head += sizeof(bytecode_t);
                switch(instruction) {
                        case ADD:
                                {
                                        double v1 = popValue();
                                        double v2 = popValue();
                                        pushValue(v1 + v2);
                                        break;
                                }
                        case SUB:
                                {
                                        double v1 = popValue();
                                        double v2 = popValue();
                                        pushValue(v2 - v1);
                                        break;
                                }
                        case MULT:
                                {
                                        double v1 = popValue();
                                        double v2 = popValue();
                                        pushValue(v2 * v1);
                                        break;
                                }
                        case DIV:
                                {
                                        double v1 = popValue();
                                        double v2 = popValue();
                                        pushValue(v2 / v1);
                                        break;
                                }
                        case PUSH:
                                {
                                        char* start;
                                        double value;
                                        memcpy(&value, head, sizeof(double));
                                        pushValue(value);
                                        head += sizeof(double);
                                        break;
                                }
                        default:
                                {
                                        // Shouldn't happen
                                        break;
                                }
                }
        }

}
