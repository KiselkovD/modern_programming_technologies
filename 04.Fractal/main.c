#include <stdio.h>
#include "image.h"
#include "fractal.h"

int findLargestN(int x);

int main()
{
    image_p img = create_image(300, 300);
    clear_image(img);

    pixel_coord x1 = 1;
    pixel_coord x2 = findLargestN(300);

    pixel_coord y1 = 150;
    pixel_coord y2 = 150;

    printf("%d\n", findLargestN(100));

    paint_line(img, 300, 300, 1 + 120, 100, 63 + 120, 100, 200);
    line_mid_fractal(img, 1 + 120, 100, findLargestN(100) + 120, 100);

    line_end_fractal(img, 1 + 120, 200, 63 + 120, 200);

    empty_fractal(img);

    save_pgm(img, "test.pgm");
    return 0;
}

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
