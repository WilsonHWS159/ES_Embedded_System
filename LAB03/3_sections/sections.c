int init_global = 0x1111;
int uninit_global;

const int global_const = 0x2222;

char init_global_rw_str[] = "AAA"; // ASCII 'A' : 0x41
char uninit_global_rw_str[3];
char *global_ro_str = "BBB"; // ASCII 'B' : 0x42

static int init_static_global = 0x3333;
static int uninit_static_global;

void mymain(void)
{
	int init_local = 0x4444;
	int uninit_local;

	const int local_const = 0x5555;

	char init_local_rw_str[] = "CCC"; // ASCII 'C' : 0x43
	char uninit_local_rw_str[3];
	char *local_ro_str = "DDD"; // ASCII 'D' : 0x44

	static int init_static_local = 0x6666;
	static int uninit_static_local;

	uninit_local_rw_str[0] = uninit_local_rw_str[1] = uninit_local_rw_str[2] = 'E'; // ASCII 'D' : 0x45

	while (1)
		;
}

void func(void)
{
	static int init_static_local = 0x7777;
	static int uninit_static_local;
}