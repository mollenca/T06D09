#include <stdio.h>

#define Size 10

int input(int *a);
void output(int *a);
void swap(int *a, int i);
void sort(int *a);

int main() {
    int mas[Size];
    if (input(mas)) {
        sort(mas);
        output(mas);
    } else {
        printf("n/a");
    }
    return 0;
}


int input(int *a) {
    char c = 0;
    int check = 1;
    for (int *p = a; p - a < Size; p++)
        if (scanf("%d%c", p, &c)); 
             else {
            check =  0;
        }
    return check;
}

void output(int *a) {
    for (int *p = a; p - a < Size - 1; p++)
        printf("%d ", *p);
    printf("%d\n", *(a + Size - 1));
}


void swap(int *a, int i) {
    int temp = *(a + i);
    *(a + i) = *(a + i + 1);
    *(a + i + 1) = temp;
}

void sort(int *a) {
    for (int i = 0; i < Size; i++)
        for (int j = 0; j < Size - 1 ; j++)
            if (*(a + j) > *(a + j + 1))
                swap(a, j);
}