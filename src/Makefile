CC=-Wall -Werror -Wextra -std=c11
EXE=test
GCOV=gcov_report
COVER=-fprofile-arcs -ftest-coverage
LCOV=-lcheck -lsubunit -lgcov
LINK=calculations/functions/*.c
TESTS=calculations/tests
VAL=--trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all
PROG=build/s21_smartcalc
MAIN_FOLD=s21_smartcalc

# Моя временная цель
build:
	@gcc ${CC} ${LINK} calculations/functions/cpp_addition/*.c ${TESTS}/testing.c -lm -o ${EXE}
	clear
	@./${EXE}

all: install run

install: uninstall
	mkdir build
	cd ${MAIN_FOLD} && qmake-qt5 && make
	mv ${MAIN_FOLD}/s21_smartcalc build
	rm -rf ${MAIN_FOLD}/Makefile

uninstall:
	@rm -rf test build build-* calculations/*.o ${MAIN_FOLD}/*.o ${MAIN_FOLD}/ui_* ${MAIN_FOLD}/moc_* ${MAIN_FOLD}/*.user

run:
	./$(PROG)

test: clean
	gcc $(CC) ${LINK} ${TESTS}/main_test.c -lm -o ${EXE} ${LCOV}
	@./${EXE}

gcov_report: clean
	gcc $(CC) ${COVER} ${LINK} ${TESTS}/main_test.c -lm -o ${EXE} ${LCOV}
	@mkdir -p ${GCOV}
	@./${EXE}
	gcovr -r . --html --html-details -o ${GCOV}/coverage.html
	@rm -rf ${EXE} *.gc*
	xdg-open ${GCOV}/coverage.html

clean:
	@rm -rf ${GCOV} *.gc* ${EXE} 

valgrind: test
	@valgrind ${VAL} ./${EXE}
	@rm ${EXE}

# dist:

# dvi:
