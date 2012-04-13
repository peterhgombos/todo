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
    return TEST_SUCCESS;
}
int test_add_todo(){return 0;}
int test_remove_todo(){return 0;}
int test_list_all(){return 0;}
int test_list_id(){return 0;}
int test_print_line_colored(){return 0;}
int test_open_list(){return 0;}
int test_search(){return 0;}

