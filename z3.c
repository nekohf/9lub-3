//#define M_PI 3.14159265358979323846
//#define _USE_MATH_DEFINES
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include<locale.h>
//
//int main() 
//{
//    setlocale(LC_CTYPE, "RUS");
//    char sy;
//    int h, b, a; //h-высота b-основание g-угол hv-верх основ s-смещение w - ширина sy - картинка a - сначала
//    double g; 
//
//    do {
//        printf("Введите символ: ");
//        scanf("%c", &sy);
//        printf("Введите высоту (h): ");
//        scanf("%d", &h);
//        printf("Введите нижнее основание (b): ");
//        scanf("%d", &b);
//        printf("Введите угол (a, в градусах): ");
//        scanf("%lf", &g);
//        int s = (int)(h / tan(g * M_PI / 180.0));
//        int hv = b - s;
//        printf("Прямоугольная трапеция:\n");
//        for (int i = 0; i < h; i++) { 
//            int w = hv + (h > 1 ? (i * s) / (h - 1) : 0);
//
//            for (int j = 0; j < w; j++) {
//                if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
//                    printf("%c", sy);
//                }
//                else {
//                    printf(" ");
//                }
//            }
//            printf("\n");
//        }
//        printf("Продолжить? (0 - нет, другое - да): ");
//        scanf("%d", &a);
//    } while (a != 0);
//    return 0;
//}

#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "RUS");
    char sy;
    int h, b, a;
    double g;

    do {
        printf("Введите символ для рисования: ");
        scanf("%c", &sy);
        printf("Введите высоту (h): ");
        scanf("%d", &h);
        printf("Введите нижнее основание (b): ");
        scanf("%d", &b);
        printf("Введите угол (a, в градусах): ");
        scanf("%lf", &g);
        int s = (int)(h / tan(g * M_PI / 180.0));
        int hv = b - s;
        if (hv <= 0 || h <= 0) {
            printf("Ошибка: размеры слишком малы для заданного угла!\n");
        }
        else {
            printf("Прямоугольная трапеция (h=%d, b=%d, a=%.0f):\n", h, b, g);

            for (int i = 0; i < h; i++) {
                int current_len = hv + (h > 1 ? (i * s) / (h - 1) : 0);
                if (i == h - 1) current_len = b;
                for (int j = 0; j < b; j++) {
                    if (j == 0 ||
                        (i == 0 && j < hv) ||
                        (i == h - 1) ||
                        (j == current_len - 1)) {
                        printf("%c", sy);
                    }
                    else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }
        printf("Продолжить? (0 - нет, другое число - да): ");
        scanf("%d", &a);
    } while (a != 0);

    return 0;
}