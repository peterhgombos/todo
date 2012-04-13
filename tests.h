#define TEST_SUCCESS 0
#define TEST_FAILED  1
void help();
int test_help();
int test_add_todo();
int test_remove_todo();
int test_list_all();
int test_list_id();
int test_print_line_colored();
int test_open_list();
int test_search();

void test(int (*fn)(void));
