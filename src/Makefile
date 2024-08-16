CFLAGS = -c -Wall -Werror -Wextra -std=c11
LDFLAGS = -Wall -Werror -Wextra -std=c11
HEADERS = $(wildcard */*.h)
SOURCE = $(wildcard s21_*.c ari*.c)
ARITHMETIC_TEST = all_tests/a_tests/arithmetic_test/*/*.c
# BANK = all_tests/a_tests/bank/test_bank.c
OBJECTS = $(patsubst %.c,%.o, ${SOURCE})
TESTS_SOURCE = $(wildcard  all_tests/*/*.c all_tests/*.c  all_tests/*/*/*/*.c)
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
  	OPEN_CMD = xdg-open
	ADD_LIB = -lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURCE
endif
ifeq ($(UNAME_S),Darwin)
	OPEN_CMD = open
	ADD_LIB =
endif

all: s21_decimal.a 

s21_decimal.a: ${SOURCE}
	gcc $(CFLAGS) $(ADD_LIB) $(SOURCE)
	# ar rcs $@ $(OBJECTS)
	ar rc s21_decimal.a *.o
	ranlib s21_decimal.a
	-rm -rf *.o

s21_decimal.o: ${SOURCE} $(HEADERS)
	gcc $(CFLAGS)

test: clean  s21_decimal.a
	gcc $(LDFLAGS) -o test $(TESTS_SOURCE)   s21_decimal.a $(ADD_LIB) -lcheck #$(ARITHMETIC_TEST)
	./test 
	# >> logs_test/bank_w.txt

gcov_report:
	gcc --coverage $(SOURCE) $(TESTS_SOURCE)   -o gcov_test $(ADD_LIB) -lcheck #$(ARITHMETIC_TEST)
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

clean:
	-rm -rf *.o *.gcda *.gcno *.gcov *result coverage.info s21_test.info *.a test gcov_test gcov_test.info report test.dSYM

style_test:
	clang-format --style=Google -n *.c $(TESTS_SOURCE) $(ARITHMETIC_TEST) $(SOURCE) $(HEADERS) all_tests/tests/*.h

style:
	clang-format --style=Google -i *.c $(TESTS_SOURCE) $(ARITHMETIC_TEST) $(SOURCE) $(HEADERS) all_tests/tests/*.h


rebuild: clean all

.PHONY: clean all s21_decimal.a test gcov_report style style_test

test-ro:
	gcc $(FLAGS) s21_*.c other/*.c -o test -lcheck

# Собираем docker image с тегом 'v1' на основании dockerfile и создаем контейнер
docker_build:
	cp ../materials/linters/.clang-format ./
	docker build -t vault:v1 .
	docker create -it --name matrix vault:v1

# Запускаем контейнер
docker_start:
	docker start -i matrix

docker_delete:
	docker rm matrix
	docker image rm vault:v1


mini_verter:
	cd ../materials/build/ && chmod +x run.sh && sh run.sh
	cd ../src
