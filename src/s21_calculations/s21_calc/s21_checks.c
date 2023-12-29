#include "s21_calc.h"

/**
 * @brief Function for checking an incoming character to match string characters.
 * 
 * @param first_symbol comparing symbol.
 * @param[in] search string characters to compare with.
 * 
 * @return The result of finding a character in a string.
 * @retval NO = 0 - if no matches are found.
 * @retval YES = 1 - if at least one match is found.
*/
int check(const char first_symbol, const char *search)
{
    int check = NO;

    for (size_t i = 0; i < strlen(search); i++) {
        if(first_symbol == search[i]) {
            check = YES;
            i = strlen(search);
        }
    }

    return check;
}

/**
 * @brief When parsing a string, if it encounters ')', it performs all lexems on the top of the stack until it encounters '('.
 * Function have two modes. 
 * Closing parentheses during parsing - PARS_EXPRESSION. Closing brackets after parsing - CLOSE_EXPRESSION.
 * 
 * @param[in] num numeric stack.
 * @param[in] lex lexem stack.
 * @param mode the function mode. 
*/
void bracket_close(num_stack *num, lex_stack *lex, int mode)
{
    while ((mode == PARS_EXPRESSION && lex->stack[lex->count] != CHAR_OP_BRCK) ||
            (mode == CLOSE_EXPRESSION && lex->count != -1)) {

        if(check(lex->stack[lex->count], TRIGONOMETRIC_CHARS OP_BRCK)) {
            math_trigonometry(&num->stack[num->count - 1], lex->stack[lex->count]);
            clean_top_stack(num, NO, lex, YES);
        } else {
            num->stack[num->count - 2] = math_nums(num->stack[num->count - 2], num->stack[num->count - 1], lex->stack[lex->count]);
            clean_top_stack(num, YES, lex, YES);
        }

        if(mode == CLOSE_EXPRESSION) {
            if(lex->count != -1 && lex->stack[lex->count] == CHAR_OP_BRCK) {
                clean_top_stack(num, NO, lex, YES);
            }
        }
    }
}

/**
 * @brief The function is designed to use mathematical lexem if the priority of the current lexem coincides/predominates over the lexem at the top of the stack.
 * Function have two modes.
 * "decision" = EQUAL_PRIORITY - if lexem have the same priority. 
 * "decision" = HIGH_PRIORITY - if the current lexem has a higher priority.
 * 
 * @param[in] num numeric stack.
 * @param[in] lex lexem stack.
 * @param current_lexem current lexem.
 * @param decision calculation mode.
*/
void math_while_parsing(num_stack *num, lex_stack *lex, const char current_lexem, int decision)
{
    while(lex->count && prior_comparison(current_lexem, lex->stack[lex->count-1]) == decision) {
        clean_top_stack(num, YES, lex, YES);
        num->stack[num->count - 1] = math_nums(num->stack[num->count - 1], num->stack[num->count], lex->stack[lex->count]);
    }
}
