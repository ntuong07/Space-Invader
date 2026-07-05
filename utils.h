
#ifndef UTILS_H
#define UTILS_H

// Sinh số ngẫu nhiên
int randomNumber(int min, int max);

// Kiểm tra va chạm
bool checkOverlap(int x1, int y1, int w1, int h1,
                  int x2, int y2, int w2, int h2);

// Giới hạn tọa độ
int limitValue(int value, int min, int max);

#endif