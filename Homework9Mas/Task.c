#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

int draw_trapezoid(char symbol, int h, int b, int a);
int ask_continue();

int main() {
    setlocale(LC_ALL, "RUS");
    char symbol;
    int h, b, a;
    int repeat;
    do {
        printf("\nВведите символ из которого будет строиться фигура: ");
        scanf(" %c", &symbol);
        printf("Введите высоту (h): ");
        scanf("%d", &h);
        printf("Введите ширину верхнего основания (b): ");
        scanf("%d", &b);
        printf("Введите угол наклона (a) (например, 1 или 2): ");
        scanf("%d", &a);
        draw_trapezoid(symbol, h, b, a);
        repeat = ask_continue();
    } while (repeat != 0);

    return 0;
}
int draw_trapezoid(char symbol, int h, int b, int a) {
    printf("\nТрапеция:\n");
    if (h <= 0 || b <= 0 || a < 0) {
        printf("Ошибка: некорректные размеры.\n");
        return;
    }
    for (int row = 0; row < h; row++) {
        int current_width = b + row * a;
        if (row == 0) {
            for (int col = 0; col < b; col++) {
                printf("%c", symbol);
            }
        }
        else {
            printf("%c", symbol);
            if (row == h - 1) {
                for (int col = 1; col < current_width; col++) {
                    printf("%c", symbol);
                }
            }
            else {
                for (int col = 1; col < current_width - 1; col++) {
                    printf(" ");
                }
                printf("%c", symbol);
            }
        }
        printf("\n");
    }
}
int ask_continue() {
    int choice;
    printf("\nПродолжить? <Да - введите любое число, Нет - введите 0>: ");
    scanf("%d", &choice);
    return choice; 
}