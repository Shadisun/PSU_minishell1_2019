##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

TEST_NAME	= unit_test

LIB_NAME	= libmy.a

BIN_NAME	= mysh

IDIR		= include/

LIB_DIR		= lib/

SRC_DIR 	= src/

LIB_FILES	=	my_getnbr.c\
				my_puterror.c\
				my_putstr.c\
				my_strcat.c\
				my_strdup.c\
				my_strlen.c\
				my_str_to_double_point.c\
				my_str_to_word_array.c

SRC_FILES	=	main.c\
				add_del_env.c\
				banned_functions.c\
				delete_oldpwd.c\
				error_not_found.c\
				env_check.c\
				exit_line.c\
				get_path.c\
				my_cd.c\
				my_dup_env.c\
				my_env.c\
				my_setenv.c\
				my_unsetenv.c\
				path_finder.c\
				run_prog.c\
				set_pwd.c\
				signal_handler.c\
				special_path_cases.c\

TEST_FILES	=

LDFLAGS	= -lcriterion -lgcov --coverage

CFLAGS	+= -I ./$(IDIR) -W -Wall -Wextra -lm

RM		= rm -f

LIB		= $(addprefix $(LIB_DIR), $(LIB_FILES))

SRC		= $(addprefix $(SRC_DIR), $(SRC_FILES))

TEST		= $(addprefix $(SRC_DIR), $(TEST_FILES))

SRC_TEST	= test/test.c

OBJS_LIB	= 	$(LIB:.c=.o)

OBJS_SRC	=	$(SRC:.c=.o)

all: $(LIB_NAME) $(BIN_NAME)

$(LIB_NAME): $(OBJS_LIB)
	ar -rcs $(LIB_NAME) $(OBJS_LIB)

$(BIN_NAME): $(OBJS_SRC)
		gcc -o $(BIN_NAME) $(SRC) $(LIB_NAME) $(CFLAGS)

tests_run: 	all
			$(OBJS_TEST)
			gcc -o $(TEST_NAME) $(LDFLAGS) $(SRC_TEST) $(TEST) $(LIB_NAME) $(CFLAGS)
			./$(TEST_NAME)
			gcov *.gcna
			gcov *.gcno

clean:
	$(RM) $(OBJS_LIB)
	$(RM) $(OBJS_SRC)
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.gcov

fclean: clean
	$(RM) $(LIB_NAME)
	$(RM) $(BIN_NAME)
	$(RM) $(TEST_NAME)

re:	fclean all

debug: CFLAGS += -g3
debug: fclean all

.PHONY: all clean fclean re
