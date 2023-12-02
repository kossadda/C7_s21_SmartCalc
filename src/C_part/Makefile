CC=-Wall -Werror -Wextra -std=c11

all: build
	@./test
	@rm test

build:
	@clear
	@gcc parser.c -lm -o test

valgrind: build
	@valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test
	@rm test

test:
	gcc $(CC) *.c -lm -o check -lcheck -lsubunit -lgcov
	@./check


gcov_report: 
	gcc $(CC) -fprofile-arcs -ftest-coverage *.c -lm -o check -lcheck -lsubunit -lgcov
	@mkdir -p gcov_report
	@./check
	gcovr -r . --html --html-details -o gcov_report/coverage.html
	@rm -rf check *.gc* test_gcov/*.gc*