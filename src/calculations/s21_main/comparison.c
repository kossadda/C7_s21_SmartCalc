#include "../main.h"

int prior_comparison(char current, char top_stack) {
    int decision = LOW_PRIORITY;
    int priority_1 = determine_priority(current);
    int priority_2 = determine_priority(top_stack);
    if(priority_1 < priority_2) {
        decision = EQUAL_PRIORITY;
    } else if(priority_1 == priority_2 && !check(current, RIGHT_ASSOCIATIVE)) {
        decision = HIGH_PRIORITY;
    } 
    if(check(current, BRACKETS) || check(top_stack, BRACKETS)) {
        decision = LOW_PRIORITY;
    }
    return decision;
}

int determine_priority(char operation) {
    int priority = 0;
    if(check(operation, "+<")) {
        priority = 1;
    } else if(check(operation, "*/m")) {
        priority = 2;
    } else if(check(operation, "^")) {
        priority = 3;
    } else if(check(operation, TRIGONOMETRIC_CHARS)) {
        priority = 4;
    } else if(check(operation, BRACKETS)) {
        priority = 5;
    }
    return priority;
}
