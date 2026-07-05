#ifndef FILE_H
#define FILE_H

// Khai báo extern để hệ thống nhận diện biến điểm cao toàn cục
extern int highScore;

// Đọc điểm cao nhất từ file
int loadHighScore();

// Lưu điểm cao nhất xuống file
void saveHighScore(int score);

// Cập nhật High Score
void updateHighScore(int score);

#endif