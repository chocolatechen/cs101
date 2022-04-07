#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE* fp;
    
void rec_dec(char* s) {
    for(char* t = s; *t; t++) {
		fprintf(fp, "%c,", *s);
		return rec_dec(s+1);
	}
}

void hanoi_tower(int n, char A, char B, char C) {
    if(n > 0) {
    	hanoi_tower(n-1, A, C, B);
        fprintf(fp, "Move disk %d from %c to %c\n", n, A, C);
        hanoi_tower(n-1, B, A, C);
    }
}

int multiplication(int i, int j) {
    if (i == 10) {
        return 0;
    } else if (j == 9) {
        fprintf(fp, "%d*%d=%d \n", i, j, i*j);
        multiplication(i+1, 1);
    } else {
        fprintf(fp, "%d*%d=%d ", i, j, i*j);
        multiplication(i, j+1);
    }
}

int main() {
    fp = fopen("hanoi.txt", "w+");
    char s[] = "1234567890";
    rec_dec(s);
    fprintf(fp, "\nfunc#1-----------------------\n");
    hanoi_tower(16, 'A', 'B', 'C');
    fprintf(fp, "func#2-----------------------\n");
    multiplication(1,1);
    fprintf(fp, "func#3-----------------------\n");
    return 0;
    fclise(fp);
}