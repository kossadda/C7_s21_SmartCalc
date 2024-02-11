################################################################################
#   _____                      _    _____      _                  __     ___   #
#  / ____|                    | |  / ____|    | |                /_ |   / _ \  #
# | (___  _ __ ___   __ _ _ __| |_| |     __ _| | ___     __   __ | |  | | | | #
#  \___ \| '_ ` _ \ / _` | '__| __| |    / _` | |/ __|    \ \ / / | |  | | | | #
#  ____) | | | | | | (_| | |  | |_| |___| (_| | | (__      \ V /  | | _| |_| | #
# |_____/|_| |_| |_|\__,_|_|   \__|\_____\__,_|_|\___| ____ \_/   |_|(_)\___/  #
#                                                     |____|                   #
#                                                                              #
################################################################################


################################################################################
#                                 _       _     _                              #
#                                (_)     | |   | |                             #
#                __   ____ _ _ __ _  __ _| |__ | | ___  ___                    #
#                \ \ / / _` | '__| |/ _` | '_ \| |/ _ \/ __|                   #
#                 \ V / (_| | |  | | (_| | |_) | |  __/\__ \                   #
#                  \_/ \__,_|_|  |_|\__,_|_.__/|_|\___||___/                   #
#                                                                              #
#                                                                              #
################################################################################

#================================== COMPILER ==================================#
PROJECT_NAME = smartcalc
CC = gcc
#==============================================================================#


#=============================== DIRECTORY NAMES ==============================#
OBJ_DIR = ./obj
GCOV_OBJ_DIR = ./obj/gcov
TEST_OBJ_DIR = ./obj/tests
MODULES_DIR = ./modules
GUI_MODULES_DIR = ./gui_modules
TEST_DIR = ./tests
REPORT_DIR = ./report
DVI_DIR = ./../docs
DIST_DIR = ./../dist
BUILD = ./../bin
#==============================================================================#

#==================================== FLAGS ===================================#
# MAIN FLAGS FOR COMPILER
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c11 -g

# CHECK LIBRARIES FOR LINKING
LDFLAGS = -lcheck -lsubunit -lm

# CHECK & GCOV LIBRARIES FOR LINKING GCOV
LDGCOV = $(LDFLAGS) -lgcov

# FLAGS FOR COVERING MODULES
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

# FLAGS FOR VALGRING TEST
VAL = --trace-children=yes --track-fds=yes --track-origins=yes \
	--leak-check=full --show-leak-kinds=all -s

# FLAGS FOR CPPCHECK TEST
CPPCHECK = --enable=all --suppress=missingIncludeSystem
#==============================================================================#


#================================ TARGET NAMES ================================#
LIBRARY = $(PROJECT_NAME).a
TARGET = test
GCOV = gcov_report
#==============================================================================#


#================================ MAIN HEADER =================================#
MAIN_H = $(shell find ./ -maxdepth 1 -name "*.h")
#==============================================================================#


#====================== LIST OF FILE AND DIRS IN MODULES ======================#
MODULES_DIRS = $(shell find $(MODULES_DIR) -type d)
MODULES_C = $(shell find $(MODULES_DIR) -type f -name "*.c")
MODULES_H = $(shell find $(MODULES_DIR) -type f -name "*.h")
MODULES_O = $(MODULES_C:%.c=%.o)
#==============================================================================#


#==================== LIST OF FILE AND DIRS IN TEST MODULES ===================#
TEST_DIRS = $(shell find $(TEST_DIR) -type d)
TEST_C = $(shell find $(TEST_DIR) -type f -name "*.c")
TEST_H = $(shell find $(TEST_DIR) -type f -name "*.h")
TEST_O = $(TEST_C:%.c=%.o)
EXCLUDE = ./modules/calculator/unar_operation.c
#==============================================================================#

#================= LIST OF FILES TO CLANG-FORMAT AND CPPCHECK =================#
C_FILES = $(MODULES_C) $(TEST_C)
H_FILES = $(MODULES_H) $(MAIN_H) $(TEST_H)
ALL_FILES = $(C_FILES) $(H_FILES)
#==============================================================================#


#=============== CONFIGURING PATH TO SEARH FOR UNPREFIXED PATHS ===============#
vpath %.c $(MODULES_DIRS) : $(TEST_DIRS)
vpath %.o $(OBJ_DIR)
#==============================================================================#


################################################################################
#                      _                       _                               #
#                     | |                     | |                              #
#                    _| |_ __ _ _ __ __ _  ___| |_ ___                         #
#                   |_  __/ _` | '__/ _` |/ _ \ __/ __|                        #
#                     | || (_| | | | (_| |  __/ |_\__ \                        #
#                      \__\__,_|_|  \__, |\___|\__|___/                        #
#                                    __/ |                                     #
#                                   |___/                                      #
################################################################################

#================================= MAIN TARGETS ===============================#
all: install dvi

install: $(LIBRARY)
	@printf "\033[33m                     _             _      _           _ _     _ _                     \n";
	@printf "                    | |           | |    | |         (_) |   | (_)                    \n";
	@printf "                 ___| |_ __ _ _ __| |_   | |__  _   _ _| | __| |_ _ __   __ _         \n";
	@printf "                / __| __/ _\` | '__| __|  | '_ \| | | | | |/ _\` | | '_ \ / _\` |        \n";
	@printf "                \__ \ || (_| | |  | |_   | |_) | |_| | | | (_| | | | | | (_| |  _ _ _ \n";
	@printf "                |___/\__\__,_|_|   \__|  |_.__/ \__,_|_|_|\__,_|_|_| |_|\__, | (_|_|_)\n";
	@printf "                                                                         __/ |        \n";
	@printf "                                                                        |___/         \033[0m\n";
	mkdir -p $(BUILD)
	cd $(BUILD) && cmake ./../src && make	
	@printf "\033[33m  _           _        _ _       _   _                                           _      _           _ \n";
	@printf " (_)         | |      | | |     | | (_)                                         | |    | |         | |\n";
	@printf "  _ _ __  ___| |_ __ _| | | __ _| |_ _  ___  _ __       ___ ___  _ __ ___  _ __ | | ___| |_ ___  __| |\n";
	@printf " | | '_ \/ __| __/ _\` | | |/ _\` | __| |/ _ \| '_ \     / __/ _ \| '_ \` _ \| '_ \| |/ _ \ __/ _ \/ _\` |\n";
	@printf " | | | | \__ \ || (_| | | | (_| | |_| | (_) | | | |   | (_| (_) | | | | | | |_) | |  __/ ||  __/ (_| |\n";
	@printf " |_|_| |_|___/\__\__,_|_|_|\__,_|\__|_|\___/|_| |_|    \___\___/|_|_|_| |_| .__/|_|\___|\__\___|\__,_|\n";
	@printf "                                                       / _|     | | |     | |                         \n";
	@printf "                       ___ _   _  ___ ___ ___  ___ ___| |_ _   _| | |_   _|_|                         \n";
	@printf "                      / __| | | |/ __/ __/ _ \/ __/ __|  _| | | | | | | | |                           \n";
	@printf "                      \__ \ |_| | (_| (_|  __/\__ \__ \ | | |_| | | | |_| |                           \n";
	@printf "                      |___/\__,_|\___\___\___||___/___/_|  \__,_|_|_|\__, |                           \n";
	@printf "                                                                      __/ |                           \n";
	@printf "                                                                     |___/                            \033[0m\n";

uninstall: clean
	rm -rf $(BUILD)
	rm -rf build*

$(LIBRARY): $(OBJ_DIR) $(MODULES_O) $(MODULES_H) $(MAIN_H)
	ar rcs $@ $(addprefix $(OBJ_DIR)/, $(notdir $(MODULES_O)))
	ranlib $@

$(TARGET): $(LIBRARY) $(TEST_OBJ_DIR) $(TEST_O)
	$(CC) $(addprefix $(OBJ_DIR)/, $(notdir $(TEST_O))) $(LIBRARY) $(LDFLAGS) -o $@
	./$@

$(GCOV): $(REPORT_DIR) $(TEST_OBJ_DIR) $(TEST_O)
	$(CC) $(addprefix $(OBJ_DIR)/, $(notdir $(TEST_O))) $(filter-out $(EXCLUDE),$(MODULES_C)) $(LDFLAGS)	$(GCOV_FLAGS) -o $(TARGET)
	./$(TARGET)
	gcovr -r . --html --html-details -o $(REPORT_DIR)/coverage.html
	xdg-open $(REPORT_DIR)/coverage.html

dvi:
	rm -rf $(DVI_DIR)
	doxygen Doxyfile
	xdg-open $(DVI_DIR)/html/index.html

dist: uninstall
	@rm -rf $(DIST_DIR)
	@echo "Creating a distribution..."
	@mkdir -p $(DIST_DIR)/$(PROJECT_NAME)
	@cp -r ./ $(DIST_DIR)/$(PROJECT_NAME) && rm -rf $(DIST_DIR)/$(PROJECT_NAME)/tests
	@echo "Distribution packaging..."
	@tar -czf $(DIST_DIR)/$(PROJECT_NAME).tar.gz -C $(DIST_DIR) $(PROJECT_NAME)
	@echo "\033[33mDistribution created: $(DIST_DIR)/$(PROJECT_NAME).tar.gz\033[0m"
	@rm -rf $(DIST_DIR)/$(PROJECT_NAME)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(REPORT_DIR)
	rm -rf $(DVI_DIR)
	rm -rf $(DIST_DIR)
	rm -rf $(GCOV)
	rm -f $(TARGET)
	rm -f *.a *.o
	rm -f *.gc*
	rm -f $(GUI_MODULES_DIR)/*.o
	rm -f $(GUI_MODULES_DIR)/*.user
	rm -f $(GUI_MODULES_DIR)/*.cpp
	rm -f $(GUI_MODULES_DIR)/*.h
	rm -f $(GUI_MODULES_DIR)/Makefile
	rm -f $(GUI_MODULES_DIR)/$(PROJECT_NAME)
	rm -f main
	rm -f val.txt

rebuild: uninstall all
#==============================================================================#


#============================== CREATE DIRECTORIES ============================#
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TEST_OBJ_DIR):
	mkdir -p $(TEST_OBJ_DIR)

$(REPORT_DIR):
	mkdir -p $(REPORT_DIR)
#==============================================================================#


#============================== OBJECTIVE TARGETS =============================#
%.o: %.c $(H_FILES)
	$(CC) $(CFLAGS) -c -o $(addprefix $(OBJ_DIR)/, $(notdir $@)) $<

$(TEST_OBJ_DIR)/%.o : %.c $(TEST_H)
	$(CC) $(CFLAGS) -c -o $@ $<
#==============================================================================#


#=============================== CHECKS TARGETS ===============================#
clang_check:
	clang-format -style=Google -n $(ALL_FILES)

clang_fix:
	clang-format -style=Google -i $(ALL_FILES)

cppcheck:
	$@ $(CPPCHECK) $(ALL_FILES)

valgrind: $(TARGET)
	@printf '\033[33m\n                   _            _           _   _            _   _             \n'
	@printf '                  | |          (_)         | | | |          | | (_)            \n'
	@printf '       __   ____ _| | __ _ _ __ _ _ __   __| | | |_ ___  ___| |_ _ _ __   __ _ \n'
	@printf '       \ \ / / _` | |/ _` | '\''__| | '\''_ \ / _` | | __/ _ \/ __| __| | '\''_ \ / _` |\n'
	@printf '        \ V / (_| | | (_| | |  | | | | | (_| | | ||  __/\__ \ |_| | | | | (_| |\n'
	@printf '         \_/ \__,_|_|\__, |_|  |_|_| |_|\__,_|  \__\___||___/\__|_|_| |_|\__, |\n'
	@printf '                      __/ |                                               __/ |\n'
	@printf '                     |___/                                               |___/ \n\033[0m\n'

	@$@ $(VAL) ./$(TARGET) > val.txt 2>&1 && \
	{ \
		printf "\033[33m\n"; \
		printf "########################################################################################\n\n"; \
		printf "                                Valgrind test results:                          \n"; \
		printf "                               Passed tests $$(grep "ERROR SUMMARY: 0" -c val.txt) from $$(grep "ERROR SUMMARY:" -c val.txt)                       \n\n"; \
		printf "########################################################################################\n"; \
		printf "\033[0m\n"; \
	}
#==============================================================================#


#============================= ADDITIONAL TARGETS =============================#
run:
	$(BUILD)/$(PROJECT_NAME)

debug: $(LIBRARY)
	@$(CC) main.c $(LIBRARY) tests/debug/*.c -o main -lm
	@./main
	
qmake_build: $(LIBRARY)
	cd $(GUI_MODULES_DIR) && qmake && make
	rm -rf $(BUILD)
	mkdir $(BUILD)
	mv $(GUI_MODULES_DIR)/$(PROJECT_NAME) $(BUILD)

docker_build:
	docker build -t $(PROJECT_NAME) .
	docker run -d --name $(PROJECT_NAME) $(PROJECT_NAME)
	docker cp $(PROJECT_NAME):/$(PROJECT_NAME)/bin ./..
	docker stop $(PROJECT_NAME)
	docker rm -f $(PROJECT_NAME)
	docker rmi -f $(PROJECT_NAME):latest

dependencies:
	apt install cppcheck
	apt install clang-format
	apt-get install check
	apt install doxygen
	apt-get install graphviz
	apt-get install texlive
	apt install cmake
	apt install qtbase5-dev

#==============================================================================#
