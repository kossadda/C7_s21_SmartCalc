# FLAGS
VAL = --trace-children=yes --track-origins=yes --leak-check=full
CLANG = -n -style="{BasedOnStyle: Google, IndentWidth: 4}"
# CC = -Wall -Werror -Wextra -g -std=c11
COVER = -fprofile-arcs -ftest-coverage
LCOV = -lcheck -lsubunit -lgcov
GCOVR = -r . --html --html-details
# FUNCS PATHS
MAIN_FOLD=s21_frontend
CALC = $(shell find s21_backend/s21_calculator -name '*.c')
CREDIT = $(shell find s21_backend/s21_credit -name '*.c')
DEPOSIT = $(shell find s21_backend/s21_deposit -name '*.c')
SUPPORT = $(shell find s21_backend/s21_common -name '*.c')
SOURCES = $(CALC) $(CREDIT) $(DEPOSIT) $(SUPPORT)
OBJECTS = $(SOURCES:.c=.o)
# TESTS PATHS
TESTS = s21_backend/s21_tests/*.c
# OTHER PATHS
TRASH = $(MAIN_FOLD)/*.o $(MAIN_FOLD)/ui_* $(MAIN_FOLD)/moc_* $(MAIN_FOLD)/*.user $(MAIN_FOLD)/Makefile
GCOV = gcov_report
BUILD = build
# EXECUTE
EXE = test
PROG = s21_smartcalc






all: install run

# install: uninstall
# 	@read -p "Выберите способ установки (qmake/cmake): " choice; \
# 	if [ "$$choice" = "qmake" ]; then \
# 		$(MAKE) install_by_qmake; \
# 	elif [ "$$choice" = "cmake" ]; then \
# 		$(MAKE) install_by_cmake; \
# 	else \
# 		echo "Неверный выбор. Установка отменена."; \
# 	fi
# 	@rm -rf $(TRASH)

install_by_qmake:
# 	$(MAKE) install_qmake
	@mkdir -p $(BUILD)
	@cd $(MAIN_FOLD) && qmake && make -s
	@mv $(MAIN_FOLD)/$(PROG) $(BUILD)/$(PROG)

install: s21_smartcalc.a
# 	$(MAKE) install_cmake
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

s21_smartcalc.a: $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $(PROG).a
	@rm $(OBJECTS)

test: ggwp
	clear
	@gcc $(CC) $(CALC) $(CREDIT) $(DEPOSIT) $(SUPPORT) $(TESTS) -lm -o $(EXE) $(LCOV)
	@./$(EXE)

gcov_report: uninstall
	gcc $(CC) $(COVER) $(CALC) $(CREDIT) $(DEPOSIT) $(SUPPORT) $(TESTS) -lm -o $(EXE) $(LCOV)
	@mkdir -p $(GCOV)
	@./$(EXE)
	gcovr $(GCOVR) -o $(GCOV)/coverage.html
	@rm -rf $(EXE) *.gc*
	xdg-open $(GCOV)/coverage.html

valgrind: test
	@valgrind $(VAL) ./$(EXE) > val.txt 2>&1
	@code val.txt
	@rm $(EXE)

valgrind_prog: install
	@valgrind $(VAL) ./$(BUILD)/$(PROG)

clang-format:
	clang-format $(CLANG) $(CALC)


# Моя временная цель
build: uninstall
	@gcc $(CC) $(CALC) $(CREDIT) $(DEPOSIT) $(SUPPORT) s21_backend/s21_debug.c -lm -o $(EXE)
	clear
	@./$(EXE)

ggwp:
	rm -rf test