CFLAGS = -c -Wall -Werror -Wextra -std=c11
LDFLAGS = -Wall -Werror -Wextra -std=c11
HEADERS = $(wildcard s21_*.h)
SOURCE = $(wildcard s21_*.c )
TESTS_SOURCE = $(wildcard tests/*.c)
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
  	OPEN_CMD = xdg-open
	ADD_LIB = -lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURCE
endif
ifeq ($(UNAME_S),Darwin)
	OPEN_CMD = open
	ADD_LIB =
endif

all: s21_matrix.a

s21_matrix.a: ${SOURCE}
	gcc $(CFLAGS) $(ADD_LIB) $(SOURCE)
	ar rc s21_matrix.a *.o
	ranlib s21_matrix.a
	-rm -rf *.o

s21_matrix.o: ${SOURCE} $(HEADERS)
	gcc $(CFLAGS)

test: clean s21_matrix.a
	gcc $(LDFLAGS) $(TESTS_SOURCE)   s21_matrix.a $(ADD_LIB) -o test -lcheck
	./test 
	# >> logs_test/bank_w.txt

gcov_report:
	gcc --coverage $(SOURCE) $(TESTS_SOURCE)   -o gcov_test $(ADD_LIB) -lcheck
	chmod +x *
	# rm -rf test-test*
	# rm -rf test-test*
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info
	$(OPEN_CMD) ./report/index.html

valg:
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./main

leaks:
	leaks -atExit -- ./test

clean_lib:
	rm -rf s21_matrix.a

clean:
	-rm -rf *.o *.gcda *.gcno *.gcov *result coverage.info s21_test.info *.a test gcov_test gcov_test.info report test.dSYM

style_test:
	clang-format --style=Google -n *.h *.c $(TESTS_SOURCE)

style:
	clang-format --style=Google -i *.h *.c $(TESTS_SOURCE)


rebuild: clean all


