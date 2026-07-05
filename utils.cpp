#include "utils.h"
#include <cstdlib>

// Sinh số ngẫu nhiên
int randomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Kiểm tra va chạm
bool checkOverlap(int x1, int y1, int w1, int h1,
                  int x2, int y2, int w2, int h2)
{
    return !(x1 > x2 + w2 ||
             x2 > x1 + w1 ||
             y1 > y2 + h2 ||
             y2 > y1 + h1);
}

// Giới hạn giá trị
int limitValue(int value, int min, int max)
{
    if(value < min)
        value = min;

    if(value > max)
        value = max;

    return value;
}