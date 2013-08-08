#include "string.h"
#include "Interpreter.h"
#include "ByteCode.h"

static char registers[8*16];

char* getRegisterValue(size_t number) {
        char* reg;
        reg = registers + sizeof(double)*number;
        return reg;
}

static void setRegister(size_t number, double value) {
        char* reg;
        reg = registers + sizeof(double)*number;
        memcpy(reg, &value, sizeof(double));
}

void interpret(char* buffer, size_t size) {
        char* head = buffer;
        while(head - buffer < size) {
                bytecode_t instruction;
                memcpy(&instruction, head, sizeof(bytecode_t));
                head += sizeof(bytecode_t);
                switch(instruction) {
                        case ADD:
                                {
                                        size_t regNum_a;
                                        size_t regNum_b;
                                        size_t regNum_output;
                                        double value_a;
                                        double value_b;
                                        double value_output;
                                        char* regData;

                                        memcpy(&regNum_a, head, sizeof(size_t));
                                        head += sizeof(size_t);
                                        memcpy(&regNum_b, head, sizeof(size_t));
                                        head += sizeof(size_t);
                                        memcpy(&regNum_output, head, sizeof(size_t));
                                        head += sizeof(size_t);

                                        regData = getRegisterValue(regNum_a);
                                        memcpy(&value_a, regData, sizeof(double));

                                        regData = getRegisterValue(regNum_b);
                                        memcpy(&value_b, regData, sizeof(double));

                                        setRegister(regNum_output,
                                                        value_a + value_b);
                                        break;
                                }
                        case SUB:
                                {
                                        // TODO
                                        break;
                                }
                        case MULT:
                                {
                                        // TODO
                                        break;
                                }
                        case DIV:
                                {
                                        // TODO
                                        break;
                                }
                        case SET:
                                {
                                        size_t regNum;
                                        double value;
                                        memcpy(&regNum, head, sizeof(size_t));
                                        head += sizeof(size_t);
                                        memcpy(&value, head, sizeof(double));
                                        head += sizeof(double);
                                        setRegister(regNum, value);
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
