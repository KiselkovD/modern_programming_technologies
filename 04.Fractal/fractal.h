#ifndef _FRACTAL_H_
#define _FRACTAL_H_

#include "image.h"

/**
 * @brief Draws empty fractal, assuming image is clean
 *
 * @param picture
 */
void empty_fractal(image_p picture);

// Функция для закрашивания линии
void paint_line(unsigned char *img, int width, int height, int x1, int y1, int x2, int y2, int color);

void line_mid_fractal(unsigned char *img, int x1, int y1, int x2, int y2);
void line_end_fractal(unsigned char *img, int x1, int y1, int x2, int y2);
// void line_mid_fractal(image_p picture,,,);

#endif // _FRACTAL_H_
