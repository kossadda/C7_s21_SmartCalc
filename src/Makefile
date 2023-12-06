# FLAGS
VAL=--trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all
CLANG=-n -style="{BasedOnStyle: Google, IndentWidth: 4}"
CC=-Wall -Werror -Wextra -g -std=c11
COVER=-fprofile-arcs -ftest-coverage
LCOV=-lcheck -lsubunit -lgcov
GCOVR=-r . --html --html-details
# FUNCS PATHS
MAIN_FOLD=s21_smartcalc
CALC=s21_smartcalc/s21_main
DEPOSIT=s21_smartcalc/s21_deposit
CREDIT=s21_smartcalc/s21_credit
OTHER=s21_smartcalc/s21_additional
CMAIN=calculations/s21_main/*
CDEPOSIT=calculations/s21_deposit/*
CCREDIT=calculations/s21_credit/*
# TESTS PATHS
TESTS=calculations/tests/main_test.c
# OTHER PATHS
TRASH=$(MAIN_FOLD)/*.o $(MAIN_FOLD)/ui_* $(MAIN_FOLD)/moc_* $(MAIN_FOLD)/*.user $(MAIN_FOLD)/Makefile
GCOV=calculations/gcov_report
BUILD=build
# EXECUTE
EXE=test
PROG=s21_smartcalc

all: install run

install: uninstall
	@read -p "Выберите способ установки (qmake/cmake): " choice; \
	if [ "$$choice" = "qmake" ]; then \
		$(MAKE) install_by_qmake; \
	elif [ "$$choice" = "cmake" ]; then \
		$(MAKE) install_by_cmake; \
	else \
		echo "Неверный выбор. Установка отменена."; \
	fi 
	@rm -rf $(TRASH)

install_by_qmake:
	$(MAKE) install_qmake
	@mkdir -p $(BUILD)
	@cd $(MAIN_FOLD) && qmake-qt5 && make -s
	@mv $(MAIN_FOLD)/$(PROG) $(BUILD)/$(PROG)

install_by_cmake:
	$(MAKE) install_cmake
	@mkdir -p $(BUILD)
	@cd $(BUILD) && cmake .. && make

install_cmake:
	@if [ -e /etc/debian_version ]; then \
        sudo apt install cmake; \
    else \
        if [ -e /etc/fedora-release ]; then \
            sudo dnf install cmake; \
        fi; \
    fi

install_qmake:
	@if [ -e /etc/debian_version ]; then \
        sudo apt install qt5-qmake; \
    else \
        if [ -e /etc/fedora-release ]; then \
            sudo dnf install qt5-qtbase-devel; \
        fi; \
    fi

uninstall:
	@rm -rf $(GCOV) $(TRASH) $(EXE) $(BUILD) $(BUILD)-* *.gc* 

run:
	./$(BUILD)/$(PROG)

test: clean
	gcc $(CC) $(CMAIN) $(TESTS) -lm -o $(EXE) $(LCOV)
	@./$(EXE)

gcov_report: clean
	gcc $(CC) $(COVER) $(CMAIN) $(TESTS) -lm -o $(EXE) $(LCOV)
	@mkdir -p $(GCOV)
	@./$(EXE)
	gcovr $(GCOVR) -o $(GCOV)/coverage.html
	@rm -rf $(EXE) *.gc*
	xdg-open $(GCOV)/coverage.html

valgrind: test
	@valgrind $(VAL) ./$(EXE)
	@rm $(EXE)

clang-format:
	clang-format $(CLANG) $(CMAIN)

# dist:

# dvi:

# Моя временная цель
build: uninstall
	@gcc $(CC) $(LINK) calculations/functions/cpp_addition/*.c $(TESTS)/testing.c -lm -o $(EXE)
	clear
	@./$(EXE)

