#include "../main.h"

int prior_comparison(char first, char second) {
    int decision = 0;
    int priority_1 = determine_priority(first);
    int priority_2 = determine_priority(second);
    if(priority_1 < priority_2) {
        decision = 1;
    } else if(priority_1 == priority_2 && !check(first, "^m")) {
        decision = 2;
    } 
    if(check(first, "()") || check(second, "()")) {
        decision = 0;
    }
    return decision;
}

int determine_priority(char operation) {
    int priority = 0;
    if(check(operation, "+-")) {
        priority = 1;
    } else if(check(operation, "*/")) {
        priority = 2;
    } else if(check(operation, "m")) {
        priority = 3;
    } else if(check(operation, "^")) {
        priority = 3;
    } else if(check(operation, "sctSCTQLl")) {
        priority = 4;
    } else if(check(operation, "()")) {
        priority = 5;
    }
    return priority;
}