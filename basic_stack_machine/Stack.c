#include "string.h"
#include "Stack.h"

static char stack[1024];
static char* head = stack;

void pushValue(double value) {
        memcpy(head, &value, sizeof(double));
        head += sizeof(double);
}

double popValue() {
        double result;
        result = peekValue();
        head -= sizeof(double);
        return result;
}

double peekValue() {
        double result;
        char* start;
        result = 0.0;
        start = head - sizeof(double);
        memcpy(&result, start, sizeof(double));
        return result;

}
