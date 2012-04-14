#include <stdio.h>
#include <stdlib.h>
#include "todo.h"
#include "tests.h"

char* S[] = {"\e[32mOK!\e[0m","\e[31mFAILED!\e[0m"};

int main(int argc,char**argv){
    test(test_help);
    test(test_add_todo);
    test(test_remove_todo);
    test(test_list_all);
    test(test_list_id);
    test(test_print_line_colored);
    test(test_open_list);
    test(test_search);
    return 0;
}

void test(int (*fn)(void)){
    printf("Testing... ");
    printf("%s\n",S[(*fn)()]);
}

int test_help(){
    printf("Help");
    return TEST_SUCCESS;
}

int test_add_todo(){
    printf("add todo");
    return TEST_SUCCESS;
}

int test_remove_todo(){
    printf("remove_todo");
    return TEST_SUCCESS;
}

int test_list_all(){
    printf("list all");
    return TEST_SUCCESS;
}

int test_list_id(){
    printf("list_id");
    return TEST_SUCCESS;
}

int test_print_line_colored(){
    printf("print_line_colored");
    return TEST_SUCCESS;
}

int test_open_list(){
    printf("open_list");
    return TEST_SUCCESS;
}

int test_search(){
    printf("search");
    return TEST_SUCCESS;
}

