#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
	FILE* fp;
	char name[16];
	int n, a[8] = {0}, k, c, num, tmp, repeat, arr_write[5] = {1, 2, 3, 4, 5}, arr_count[5];
 	printf("歡迎光臨長庚樂透彩購買機台\n");
	printf("請問你要買幾組樂透彩：");
	scanf("%d", &num);
	srand(time(0));
	time_t curtime;
	time(&curtime);
	for (int i = 1; i <= 4; i++) {
		sprintf(name, "lotto[%04d].txt", i);
		fp = fopen(name, "w+");
		fprintf(fp, "======== lotto649 =========\n");
		fprintf(fp, "======== NO.%05d =========\n", i);
		fprintf(fp, "= ");
		for (int g = 0; g <= 23; g++) {
		    fprintf(fp, "%c", ctime(&curtime)[g]);
		}
		fprintf(fp, " =\n");
		for (k = 1; k <= num; k++) {
			fprintf(fp, "[%d]: ", k);
			for (n = 0; n <= 5; n++) {
				do {
					a[n] = (rand() % 69) +1;
					repeat = 0;
					for (int b = 1; b <= n; b++) {
						if (a[n] == a[b-1]) {
							repeat = 1;
						}
					}
				} while (repeat == 1);
			}
			for (n = 0; n <= 5; n++) {
				for (int i=0; i<6; i++) {
            		for (int j=0; j<6; j++) {
                		if (a[i] < a[j]) {
                			tmp = a[i];
                    		a[i] = a[j];
                   			a[j] = tmp;
						}
    	        	}
	        	}
				fprintf(fp, "%02d ", a[n]);
			}
			a[7] = (rand() % 10) +1;
			fprintf(fp, "%02d", a[7]);
			fprintf(fp, "\n");
			if (k >= num) {
		    	k += 1;
		   	 for (; k <= 5; k++) {
		    	    fprintf(fp, "[%d]: -- -- -- -- -- -- --\n", k);
		   	 }
			}
		}
		fprintf(fp, "======== csie@CGU =========\n");
	}
	fclose(fp);
	return 0;
}
