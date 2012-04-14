/*
 *   To test with stdout, open another stream as follows:
 *  
 *   freopen("testout", "w", stdout);
 *
 *   Remember to close it afterwards
 *
 *   freopen("/dev/stdout", "w", stdout);
 */
#include <stdio.h>
#include <stdlib.h>
#include "todo.h"
#include "tests.h"

char* S[] = {"\e[32mOK!\e[0m","\e[31mFAILED!\e[0m"};

char id[4];

int main(int argc,char**argv){
    test(test_open_list);
    test(test_add_todo);
    test(test_remove_todo);
    test(test_list_all);
    test(test_list_id);
    test(test_search);
    return 0;
}

void test(int (*fn)(void)){
    printf("Testing ");
    printf("%s\n",S[(*fn)()]);
}

int test_add_todo(){
    printf("add todo... \t");

    return TEST_SUCCESS;
}

int test_remove_todo(){
    printf("remove_todo... \t");
    return TEST_SUCCESS;
}

int test_list_all(){
    printf("list all... \t");
    return TEST_SUCCESS;
}

int test_list_id(){
    printf("list_id... \t");
    return TEST_SUCCESS;
}


int test_open_list(){
    printf("open_list... \t");
    return TEST_SUCCESS;
}

int test_search(){
    printf("search... \t");
    return TEST_SUCCESS;
}

