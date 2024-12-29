#include <stdio.h>
#include "image.h"
#include "fractal.h"

int findLargestN(int x)
{
    int n = 1;
    int result = -1; // Инициализируем результат значением -1

    while (1)
    {
        int current = 2;
        for (int i = 0; i < n; i++)
            current *= 2;
        current--;
        // printf("cur %d\n", current);
        if (current >= x)
        {
            break; // Прерываем цикл, если текущее значение больше или равно x
        }
        result = current; // Сохраняем текущее значение
        n++;              // Увеличиваем n
    }

    return result; // Возвращаем найденное значение
}

// Функция для закрашивания линии
void paint_line(unsigned char *img, int width, int height, int x1, int y1, int x2, int y2)
{
    // Проверка на выход за пределы изображения
    if (x1 < 0 || x1 >= width || y1 < 0 || y1 >= height ||
        x2 < 0 || x2 >= width || y2 < 0 || y2 >= height)
    {
        // fprintf(stderr, "Ошибка: координаты выходят за пределы изображения.\n");
        return;
    }

    // Если различаются по вертикали (y)
    if (y1 != y2)
    {
        // Закрашиваем вертикально
        for (int y = y1; y <= y2; y++)
        {
            set_pixel(img, x1, y, 255);
        }
    }
    // Если различаются по горизонтали (x)
    else if (x1 != x2)
    {
        // Закрашиваем горизонтально
        for (int x = x1; x <= x2; x++)
        {
            set_pixel(img, x, y1, 255);
        }
    }
    else
    {
        // Ошибка: координаты совпадают
        fprintf(stderr, "Ошибка: координаты (x1, y1) и (x2, y2) совпадают.\n");
    }
}

// Реализация функции draw_fractal
void draw_fractal(unsigned char *img, int x1, int y1, int x2, int y2)
{
    // прекращаем рекурсию
    if ((x1 == x2 && abs(y2 - y1) < 2) || (y1 == y2 && abs(x2 - x1) < 2))
    {
        return;
    }

    // Проверка на горизонт
    if (y1 == y2)
    {
        int l = (x2 - x1) / 2;
        int mid = x1 + l;
        int y0 = y1;

        paint_line(img, 300, 300, mid, y0 - l, mid, y0 + l);

        draw_fractal(img, x1, y0, mid - 1, y0);      // Левый отрезок
        draw_fractal(img, mid + 1, y0, x2, y0);      // Правый отрезок
        draw_fractal(img, mid, y0 - l, mid, y0 - 1); // Нижняя линия
        draw_fractal(img, mid, y0 + 1, mid, y0 + l); // Верхняя линия
    }
    // Проверка на вертикальность
    else if (x1 == x2)
    {
        int l = (y2 - y1) / 2;
        int mid = y1 + l;
        int x0 = x1;

        paint_line(img, 300, 300, x0 - l, mid, x0 + l, mid);

        draw_fractal(img, x0, y1, x0, mid - 1);      // Нижний отрезок
        draw_fractal(img, x0, mid + 1, x0, y2);      // Верхний отрезок
        draw_fractal(img, x0 - l, mid, x0 - 1, mid); // Левая линия
        draw_fractal(img, x0 + 1, mid, x0 + l, mid); // Правая линия

        // printf("x%1d y%1d x%1d y%1d | ", x1 - l, y1 + l, x1, y1 + l);
        // draw_fractal(img, x1 - l, y1 + l, x1, y1 + l); // Левая линия
    }
    else
    {
        fprintf(stderr, "error not hor not vert.\n");
    }
}

int main()
{
    image_p img = create_image(300, 300);

    pixel_coord x1 = 1;
    pixel_coord x2 = findLargestN(300);

    pixel_coord y1 = 150;
    pixel_coord y2 = 150;

    printf("so ");
    for (pixel_coord p = 0; p < 300; ++p)
        for (pixel_coord p2 = 0; p2 < 300; ++p2)
            set_pixel(img, p, p2, (pixel_data)0);
    printf("go\n");

    printf("%d\n", findLargestN(300));

    paint_line(img, 300, 300, x1, y1, x2, y2);
    draw_fractal(img, x1, y1, x2, y2);

    // empty_fractal(img);

    save_pgm(img, "test.pgm");
    return 0;
}
