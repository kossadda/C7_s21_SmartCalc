CC=-Wall -Werror -Wextra -std=c11
TEST=test
GCOV=gcov_report
COVER=-fprofile-arcs -ftest-coverage
LCOV=-lcheck -lsubunit -lgcov
LINK=functions/*.c tests/main_test.c
VAL=--trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all

build:
	@gcc ${CC} functions/*.c tests/testing.c -lm -o ${TEST}
	clear
	@./${TEST}

test: clean
	clear
	gcc $(CC) ${LINK} -lm -o ${TEST} ${LCOV}
	@./${TEST}

clean:
	@rm -rf ${GCOV} *.gc* ${TEST} 

gcov_report: clean
	@clear
	gcc $(CC) ${COVER} ${LINK} -lm -o ${TEST} ${LCOV}
	@mkdir -p ${GCOV}
	@./${TEST}
	gcovr -r . --html --html-details -o ${GCOV}/coverage.html
	@rm -rf ${TEST} *.gc*
	xdg-open ${GCOV}/coverage.html

valgrind: test
	@valgrind ${VAL} ./${TEST}
	@rm ${TEST}