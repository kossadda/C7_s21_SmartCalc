val: 
	rm -rf test
	clear
	@gcc -Wall -Wextra s21_main/* tests/testing.c -o test -lm
	valgrind --show-leak-kinds=all --leak-check=full --track-origins=yes ./test
