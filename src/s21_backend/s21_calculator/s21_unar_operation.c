/// \file
#include "s21_calculator.h"

/*!
 * @brief Function for adding/removing a unary minus from the last number in a line.
 * 
 * @param[out] str processed string.
 * 
 * @return Modified string.
*/
char *unar_operation(char *str)
{
    char ptr[256] = {0};
    int len = strlen(str) - 1;
    if(str[len] == CHAR_CL_BRCK && check(str[len-1], NUMBERS)) {
        int num = number_position(str, len - 1);
        int pos_minus = minus_position(str, len);
        if(num == pos_minus && !check(str[num - 2], END_TIGONTRC_CHARS)) {
            clean_unar(str, ptr, len, pos_minus);
            strcpy(str, ptr);
        }
    } else if(check(str[len], NUMBERS)) {
        int pos_number = number_position(str, len);
        make_unar(str, ptr, len, pos_number);
        strcpy(str, ptr);
    }
    return str;
}

/*!
 * @brief Function to determine the position of the last number in a string.
 * 
 * @param[out] str processed string.
 * @param[in] len String length.
 * 
 * @return Index of the character from which the number begins.
*/
int number_position(char *str, int len)
{
    int pos_number = 0;
    for(int i = len; i >= 0; i--) {
        if(!check(str[i], NUMBERS DOT)) {
           pos_number = i;
           i = -1; 
        }
    }
    return pos_number;
}

/*!
 * @brief Function to determine the position of the last minus sign in a string.
 * 
 * @param[out] str processed string.
 * @param[in] len string length.
 * 
 * @return Index of the last character containing a minus value.
*/
int minus_position(char *str, int len)
{
    int pos_minus = 0;
    for (int i = len; i >= 0; i--) {
        if(str[i] == CHAR_MINUS && str[i-1] == CHAR_OP_BRCK && str[len] == CHAR_CL_BRCK) {
            pos_minus = i;
            i = -1;
        }
    }
    return pos_minus;
}

/*!
 * @brief Function to add a unary minus to a string.
 * 
 * @param[out] str processed string.
 * @param[out] ptr buffer string.
 * @param[in] len string length.
 * @param[in] pos_number index of the character from which the number begins.
*/
void make_unar(char *str, char *ptr, int len, int pos_number)
{
    int count = 0;
    if(pos_number == 0) {
        pos_number = -1;
    }
    for(int i = 0; i < len + 1; i++) {
        if(i == pos_number + 1) {
            strcat(ptr, OP_BRCK MINUS);
            count += 2;
        }
        ptr[count++] = str[i];
        if(i == len) {
            ptr[count++] = CHAR_CL_BRCK;
        }
    }
}

/*!
 * @brief Function to remove unary minus.
 * 
 * @param[out] str processed string.
 * @param[out] ptr buffer string.
 * @param[in] len string length.
 * @param[in] pos_minus index of the last character containing a minus value.
*/
void clean_unar(char *str, char *ptr, int len, int pos_minus)
{
    int count = 0;
    for(int i = 0; i < len; i++) {
        if(i != pos_minus - 1 && i != pos_minus) {
            ptr[count++] = str[i];
        }
    }
}
