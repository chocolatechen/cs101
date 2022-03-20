#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE* fp;
FILE* fp1;

void writeback(int counter) {
	int write_back[1];
	write_back[0] = counter;
	FILE* tmpfp;
	tmpfp = fopen("counter.bin", "wb");
	fwrite(write_back, sizeof(int), 1, tmpfp);
	fclose(tmpfp);
}

void file_name(int counter, char filename[128]) {
	snprintf(filename, 128, "lotto[%04d].txt", counter);
}

int counter_file(int counter) {
	int read_array[1];
	FILE* tmpfp;
	tmpfp = fopen("counter.bin", "rb");
	fread(read_array, sizeof(int), 1, tmpfp);
	fclose(tmpfp);
	return read_array[0];
}

void open_file2(int counter) {
	int write_array[1] = {0};
	write_array[0] = counter;
	FILE* tmpfp;
	//打開一個不一定存在的counter.bin檔並讀他
	fp1 = fopen("counter.bin", "r");
	//若這個檔不存在則再次打開這個不一定存在的檔並寫一個值進去使這個檔存在，反之則關檔 
	if (fp1 == NULL) {
		tmpfp = fopen("counter.bin", "wb+");
		fwrite(write_array, sizeof(int), 1, tmpfp);
		fclose(tmpfp);
	} else {
		fclose(fp);
	}
}
 
void open_file1(char filename[128], int counter) {
	fp = fopen(filename, "w+");
	fprintf(fp, "======== lotto649 =========\n");
	fprintf(fp, "=======+ NO.%05d +========\n", counter);
	srand(time(0));
	time_t curtime;
	time(&curtime);
	fprintf(fp, "= %.*s =\n", 24, ctime(&curtime));
}

void sorting_lotto(int a[8]) {
    for (int i = 0; i < 6; i++) {
    	for (int j = 0; j < 6; j++) {
    	   	if (a[i] < a[j]) {
    	   	    int tmp = a[i];
                a[i] = a[j];
               	a[j] = tmp;
			}
    	}
	}
}

void create_one_group_lotto(int lotto[8]) {
    int repeat;
    for (int i = 0; i < 7; i++) {
        do {
            lotto[i] = (rand() % 69) + 1;
            repeat = 0;
            for (int j = 1; j <= 5; j++) {
                if (lotto[i] == lotto[j-1]) {
                    repeat = 1;
                }
            }
            i++;
        } while (repeat == 1);
    }
    lotto[6] = (rand() % 10) +1;
    sorting_lotto(lotto);
}

void print_lotto_file(int i, int num, int lotto[8]) {
	fprintf(fp, "[%d]: ", i);
	if (i <= num) {
		for(int j = 0; j < 7; j++) {
			fprintf(fp, "%02d ", lotto[j]);
		}
		fprintf(fp, "\n");
	} else {
		fprintf(fp, "-- -- -- -- -- -- --\n");
	}
}

int main () {
	int counter = 0;
	open_file2(counter);//開bin檔
	counter = counter_file(++counter);
	char filename[128];
	file_name(counter, filename);
	open_file1(filename, counter);
	int lotto[8], num;
	printf("歡迎光臨長庚樂透彩購買機台\n");
	printf("請問你要買幾組樂透彩(最多5組)：");
	scanf("%d", &num);
	for (int i= 1; i < 6; i++) {
		create_one_group_lotto(lotto);
		print_lotto_file(i, num, lotto);
	}
	fprintf(fp, "======== csie@CGU =========\n");
	writeback(counter);
	return 0;
	fclose(fp);
}