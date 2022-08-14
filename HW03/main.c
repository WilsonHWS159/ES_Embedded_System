typedef struct mystruct mystruct;

struct mystruct {
    char *struct_str;
    int struct_int;
};

int init_global_int = 0x1111;
int *init_global_ptr = &init_global_int;
int init_global_int_array[] = {0x2222, 0x3333, 0x4444};
int *init_global_int_array_ptr = &init_global_int_array;

mystruct global_struct = {"AAA", 0x5555};
mystruct *global_struct_ptr = &global_struct;

int plus(int a, int b) {return a + b;};
int *array_plus(int a[], int b[], int *returnSize)
{
    *returnSize = 3;
    for (int i=0; i<3; i++)
        b[i] += a[i];
    return b;
}
mystruct *struct_plus(mystruct *struct_a, mystruct *struct_b)
{
    struct_b->struct_int += struct_a->struct_int;
    return struct_b;
}

void reset_handler(void)
{
    int local_int = 0x6666;
    int *local_int_ptr = &local_int;
    int local_int_array[] = {0x0001, 0x0002, 0x0003};
    int *local_int_array_ptr = &local_int_array;
    mystruct local_struct = {"BBB", 0x7777};
    mystruct *local_struct_ptr = &local_struct;

    local_int = plus(init_global_int, local_int);
    local_int_array_ptr = array_plus(init_global_int_array, local_int_array, &local_int);
    local_struct_ptr = struct_plus(init_global_int_array_ptr, local_struct_ptr);

    for (;;);
}
