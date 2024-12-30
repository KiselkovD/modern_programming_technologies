#include "image.h"
#include "fractal.h"

void empty_fractal(image_p picture)
{
}

// Функция для закрашивания линии
void paint_line(unsigned char *img, int width, int height, int x1, int y1, int x2, int y2, int color)
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
			set_pixel(img, x1, y, color);
		}
	}
	// Если различаются по горизонтали (x)
	else if (x1 != x2)
	{
		// Закрашиваем горизонтально
		for (int x = x1; x <= x2; x++)
		{
			set_pixel(img, x, y1, color);
		}
	}
	else
	{
		set_pixel(img, x1, y1, color);
	}
}

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

		paint_line(img, 300, 300, mid, y0 + 1, mid, y0 + l, 255);
		paint_line(img, 300, 300, mid, y0 - l, mid, y0 - 1, 255);

		draw_fractal(img, x1, y0, mid - 1, y0);			 // Левый отрезок
		draw_fractal(img, mid + 1, y0, x2, y0);			 // Правый отрезок
		draw_fractal(img, mid, y0 - l, mid, y0 - 1); // Нижняя линия
		draw_fractal(img, mid, y0 + 1, mid, y0 + l); // Верхняя линия
	}
	// Проверка на вертикальность
	else if (x1 == x2)
	{
		int l = (y2 - y1) / 2;
		int mid = y1 + l;
		int x0 = x1;

		paint_line(img, 300, 300, x0 + 1, mid, x0 + l, mid, 125);
		paint_line(img, 300, 300, x0 - l, mid, x0 - 1, mid, 125);

		draw_fractal(img, x0, y1, x0, mid - 1);			 // Нижний отрезок
		draw_fractal(img, x0, mid + 1, x0, y2);			 // Верхний отрезок
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

// Реализация функции draw_fractal
void draw_fractal_2(unsigned char *img, int x1, int y1, int x2, int y2)
{
	// прекращаем рекурсию
	if ((x1 == x2 && abs(y2 - y1) < 3) || (y1 == y2 && abs(x2 - x1) < 3))
	{
		return;
	}

	// Проверка на горизонт
	if (y1 == y2)
	{
		int l = (x2 - x1) / 3;
		int mid = x1 + l;
		int y0 = y1;

		paint_line(img, 300, 300, x1, y0 + 1, x1, y0 + l, 255);
		paint_line(img, 300, 300, x1, y0 - l, x1, y0 - 1, 255);

		paint_line(img, 300, 300, x2, y0 + 1, x2, y0 + l, 255);
		paint_line(img, 300, 300, x2, y0 - l, x2, y0 - 1, 255);

		// printf("x(%3d) y(%3d) x(%3d) y(%3d) | ", x1, y0 - l, x1, y0 + l);
		draw_fractal_2(img, x1, y0 - l, x1, y0 + l); // Левый отрезок
		// printf("x(%3d) y(%3d) x(%3d) y(%3d) | ", x2, y0 - l, x2, y0 + l);
		draw_fractal_2(img, x2, y0 - l, x2, y0 + l); // Правый отрезок
	}
	// Проверка на вертикальность
	else if (x1 == x2)
	{
		int l = (y2 - y1) / 3;
		int mid = y1 + l;
		int x0 = x1;

		paint_line(img, 300, 300, x0 + 1, y1, x0 + l, y1, 155);
		paint_line(img, 300, 300, x0 - l, y1, x0 - 1, y1, 155);

		paint_line(img, 300, 300, x0 + 1, y2, x0 + l, y2, 155);
		paint_line(img, 300, 300, x0 - l, y2, x0, y2, 155);

		// printf("x(%3d) y(%3d) x(%3d) y(%3d) | ", x0 - l, y1, x0 + l, y1);
		draw_fractal_2(img, x0 - l, y1, x0 + l, y1); // Нижний отрезок
		// printf("x(%3d) y(%3d) x(%3d) y(%3d) | ", x0 - l, y2, x0 + l, y2);
		draw_fractal_2(img, x0 - l, y2, x0 + l, y2); // Верхний отрезок
	}
	else
	{
		fprintf(stderr, "error not hor not vert.\n");
	}
}
