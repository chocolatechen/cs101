#include <stdio.h>

typedef struct my_mm {
	int num_of_allocated_space[10];
	int g_mem_usage[10];
} my_mm_t;

int g_mem[10];
my_mm_t mms;

int *my_calloc(int n, int size) {
	int start_address = -1;
	for (int i = 0; i < 10; i++) {
		int j = i, num_of_non_allocated_space = 0;
		while (mms.g_mem_usage[j] == 0 && num_of_non_allocated_space < n*size && j < 10) {
			num_of_non_allocated_space++;
			j++;
		}
		if (num_of_non_allocated_space == n*size) {
			start_address = i;
			break;
		}
		i = j;
	}
	if (start_address == -1) {
		print_g_mem_usage();
		return NULL;
	} else {
		for (int i = 0; i < n*size; i++) {
			mms.g_mem_usage[start_address + i] = 1;
		}
		mms.num_of_allocated_space[start_address] = n*size;
		print_g_mem_usage();
		return &g_mem[start_address];
	}
}

void my_free(int *p) {
	if (p == NULL) {
		print_g_mem_usage();
		return;
	}
	int start_address = p - g_mem;
	for (int i = 0; i < mms.num_of_allocated_space[start_address]; i++) {
		mms.g_mem_usage[start_address + i] = 0;
	}
	mms.num_of_allocated_space[start_address] = 0;
	print_g_mem_usage();
}

void print_g_mem_usage() {
	for (int i = 0; i < 10; i++) {
		printf("%d", mms.g_mem_usage[i]);
	}
	printf("\n");
}

int main() {
	int *np1 = my_calloc(1, 1);
	int *np2 = my_calloc(1, 2);
	int *np3 = my_calloc(1, 3);
	int *np4 = my_calloc(1, 4);
	my_free(np1);
	my_free(np4);
	int *np5 = my_calloc(1, 5);
	return 0;
}