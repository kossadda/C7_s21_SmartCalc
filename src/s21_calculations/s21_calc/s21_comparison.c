#include "s21_calc.h"

/// @brief A function designed to compare the priorities of two operations (current and at the top of the stack)
/// @param current Current operation
/// @param top_stack Operation on top of stack
/// @return Returns if the current operation prevails over the operation at the top of the stack - HIGH_PRIORITY. In case of priority equivalence - EQUAL_PRIORITY. In case of low priority - LOW_PRIORITY.
int prior_comparison(const char current, const char top_stack)
{
    int decision = LOW_PRIORITY;

    int priority_1 = determine_priority(current);
    int priority_2 = determine_priority(top_stack);

    if(priority_1 < priority_2) {
        decision = EQUAL_PRIORITY;
    } else if(priority_1 == priority_2 && !check(current, RIGHT_ASSOCIATIVE)) {
        decision = HIGH_PRIORITY;
    }

    if(check(current, OP_BRCK CL_BRCK) || check(top_stack, OP_BRCK CL_BRCK)) {
        decision = LOW_PRIORITY;
    }

    return decision;
}

/// @brief The function determines the priority of the input operation
/// @param operation Operation
/// @return Returns the integer value of the function priority ("+-":1, "*/mod":2, "^":3, "sin,cos,tan,asin,acos,atan,log,ln":4, "()":5)
int determine_priority(const char operation)
{
    int priority = 0;

    if(check(operation, ADD MIN)) {
        priority = 1;
    } else if(check(operation, MUL DIV MOD)) {
        priority = 2;
    } else if(check(operation, EXP)) {
        priority = 3;
    } else if(check(operation, TRIGONOMETRIC_CHARS)) {
        priority = 4;
    } else if(check(operation, OP_BRCK CL_BRCK)) {
        priority = 5;
    }
    
    return priority;
}
