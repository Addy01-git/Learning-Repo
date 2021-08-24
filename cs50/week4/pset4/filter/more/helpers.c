#include "helpers.h"
#include "math.h"
#include "stdio.h"

// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment
// comment

int getg(int height, int width, int pi, int pj, RGBTRIPLE image[height][width], int color);

int min(int a, int b);

int min(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    return a;
}


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int rgbGray = round((image[i][j].rgbtBlue  +  image[i][j].rgbtGreen  +  image[i][j].rgbtRed) / 3.00);
            image[i][j].rgbtBlue = rgbGray;
            image[i][j].rgbtGreen = rgbGray;
            image[i][j].rgbtRed = rgbGray;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int blue1 = image[i][j].rgbtBlue;
            int green1 = image[i][j].rgbtGreen;
            int red1 = image[i][j].rgbtRed;

            int bluetemp = image[i][width - j - 1].rgbtBlue;
            int greentemp = image[i][width - j - 1].rgbtGreen;
            int redtemp = image[i][width - j - 1].rgbtRed;

            image[i][j].rgbtRed = redtemp;
            image[i][j].rgbtBlue = bluetemp;
            image[i][j].rgbtGreen = greentemp;

            image[i][width - j - 1].rgbtBlue = blue1;
            image[i][width - j - 1].rgbtGreen = green1;
            image[i][width - j - 1].rgbtRed = red1;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if ((i != 0) && (j != 0) && (i != height - 1) && (j != width - 1))
            {
                image[i][j].rgbtBlue = round((copy[i - 1][j - 1].rgbtBlue  +  copy[i - 1][j].rgbtBlue  +  copy[i][j - 1].rgbtBlue  +  copy[i +
                                              1][j].rgbtBlue  +  copy[i][j + 1].rgbtBlue  +  copy[i + 1][j + 1].rgbtBlue  +  copy[i - 1][j + 1].rgbtBlue  +  copy[i + 1][j -
                                                      1].rgbtBlue  +  copy[i][j].rgbtBlue) / 9.0);
                image[i][j].rgbtGreen = round((copy[i - 1][j - 1].rgbtGreen  +  copy[i - 1][j].rgbtGreen  +  copy[i][j - 1].rgbtGreen  +  copy[i +
                                               1][j].rgbtGreen  +  copy[i][j + 1].rgbtGreen  +  copy[i + 1][j + 1].rgbtGreen  +  copy[i - 1][j + 1].rgbtGreen  +  copy[i + 1][j -
                                                       1].rgbtGreen  +  copy[i][j].rgbtGreen) / 9.0);
                image[i][j].rgbtRed = round((copy[i - 1][j - 1].rgbtRed  +  copy[i - 1][j].rgbtRed  +  copy[i][j - 1].rgbtRed  +  copy[i +
                                             1][j].rgbtRed  +  copy[i][j + 1].rgbtRed  +  copy[i + 1][j + 1].rgbtRed  +  copy[i - 1][j + 1].rgbtRed  +  copy[i + 1][j -
                                                     1].rgbtRed  +  copy[i][j].rgbtRed) / 9.0);
            }

            else if (i == 0 && (j != 0 && j != width - 1))
            {
                image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue  +  copy[i][j - 1].rgbtBlue  +  copy[i][j + 1].rgbtBlue  +  copy[i +
                                              1][j].rgbtBlue  +  copy[i + 1][j + 1].rgbtBlue  +  copy[i + 1][j - 1].rgbtBlue) / 6.0);
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed  +  copy[i][j - 1].rgbtRed  +  copy[i][j + 1].rgbtRed  +  copy[i + 1][j].rgbtRed  +
                                             copy[i + 1][j + 1].rgbtRed  +  copy[i + 1][j - 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen  +  copy[i][j - 1].rgbtGreen  +  copy[i][j + 1].rgbtGreen  +  copy[i +
                                               1][j].rgbtGreen  +  copy[i + 1][j + 1].rgbtGreen  +  copy[i + 1][j - 1].rgbtGreen) / 6.0);
            }

            else if (i == height - 1 && (j != 0 && j != width - 1))
            {
                image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue  +  copy[i][j - 1].rgbtBlue  +  copy[i][j + 1].rgbtBlue  +  copy[i -
                                              1][j].rgbtBlue  +  copy[i - 1][j + 1].rgbtBlue  +  copy[i - 1][j - 1].rgbtBlue) / 6.0);
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed  +  copy[i][j - 1].rgbtRed  +  copy[i][j + 1].rgbtRed  +  copy[i - 1][j].rgbtRed  +
                                             copy[i - 1][j + 1].rgbtRed  +  copy[i - 1][j - 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen  +  copy[i][j - 1].rgbtGreen  +  copy[i][j + 1].rgbtGreen  +  copy[i -
                                               1][j].rgbtGreen  +  copy[i - 1][j + 1].rgbtGreen  +  copy[i - 1][j - 1].rgbtGreen) / 6.0);
            }

            else if (j == 0 && (i != 0 && i != height - 1))
            {
                image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue  +  copy[i][j + 1].rgbtBlue  +  copy[i - 1][j].rgbtBlue  +  copy[i +
                                              1][j].rgbtBlue  +  copy[i + 1][j + 1].rgbtBlue  +  copy[i - 1][j + 1].rgbtBlue) / 6.0);
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed  +  copy[i][j + 1].rgbtRed  +  copy[i - 1][j].rgbtRed  +  copy[i + 1][j].rgbtRed  +
                                             copy[i + 1][j + 1].rgbtRed  +  copy[i - 1][j + 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen  +  copy[i][j + 1].rgbtGreen  +  copy[i - 1][j].rgbtGreen  +  copy[i +
                                               1][j].rgbtGreen  +  copy[i + 1][j + 1].rgbtGreen  +  copy[i - 1][j + 1].rgbtGreen) / 6.0);
            }

            else if (j == width - 1 && (i != 0 && i != height - 1))
            {
                image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue  +  copy[i][j - 1].rgbtBlue  +  copy[i - 1][j].rgbtBlue  +  copy[i +
                                              1][j].rgbtBlue  +  copy[i - 1][j - 1].rgbtBlue  +  copy[i + 1][j - 1].rgbtBlue) / 6.0);
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed  +  copy[i][j - 1].rgbtRed  +  copy[i - 1][j].rgbtRed  +  copy[i + 1][j].rgbtRed  +
                                             copy[i - 1][j - 1].rgbtRed  +  copy[i + 1][j - 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen  +  copy[i][j - 1].rgbtGreen  +  copy[i - 1][j].rgbtGreen  +  copy[i +
                                               1][j].rgbtGreen  +  copy[i - 1][j - 1].rgbtGreen  +  copy[i + 1][j - 1].rgbtGreen) / 6.0);
            }

            else if (i == 0 && j == 0)
            {
                image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue  +  copy[i + 1][j].rgbtBlue  +  copy[i][j + 1].rgbtBlue  +  copy[i + 1][j +
                                              1].rgbtBlue) / 4.0);
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed  +  copy[i + 1][j].rgbtRed  +  copy[i][j + 1].rgbtRed  +  copy[i + 1][j +
                                             1].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen  +  copy[i + 1][j].rgbtGreen  +  copy[i][j + 1].rgbtGreen  +  copy[i + 1][j +
                                               1].rgbtGreen) / 4.0);
            }

            else if (i == 0 && j == width - 1)
            {
                image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue  +  copy[i + 1][j].rgbtBlue  +  copy[i][j - 1].rgbtBlue  +  copy[i + 1][j -
                                              1].rgbtBlue) / 4.0);
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed  +  copy[i + 1][j].rgbtRed  +  copy[i][j - 1].rgbtRed  +  copy[i + 1][j -
                                             1].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen  +  copy[i + 1][j].rgbtGreen  +  copy[i][j - 1].rgbtGreen  +  copy[i + 1][j -
                                               1].rgbtGreen) / 4.0);
            }

            else if (i == height - 1 && j == 0)
            {
                image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue  +  copy[i - 1][j].rgbtBlue  +  copy[i - 1][j + 1].rgbtBlue  +  copy[i][j +
                                              1].rgbtBlue) / 4.0);
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed  +  copy[i - 1][j].rgbtRed  +  copy[i - 1][j + 1].rgbtRed  +  copy[i][j +
                                             1].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen  +  copy[i - 1][j].rgbtGreen  +  copy[i - 1][j + 1].rgbtGreen  +  copy[i][j +
                                               1].rgbtGreen) / 4.0);
            }

            else if (i == height - 1 && j == width - 1)
            {
                image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue  +  copy[i - 1][j].rgbtBlue  +  copy[i][j - 1].rgbtBlue  +  copy[i - 1][j -
                                              1].rgbtBlue) / 4.0);
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed  +  copy[i - 1][j].rgbtRed  +  copy[i][j - 1].rgbtRed  +  copy[i - 1][j -
                                             1].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen  +  copy[i - 1][j].rgbtGreen  +  copy[i][j - 1].rgbtGreen  +  copy[i - 1][j -
                                               1].rgbtGreen) / 4.0);
            }

        }
    }

    return;
}

// Edges
/*
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }



    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            image[i][j].rgbtRed = getg(height, width, i, j, copy, 1);
            image[i][j].rgbtBlue = getg(height, width, i, j, copy, 3);
            image[i][j].rgbtGreen = getg(height, width, i, j, copy, 2);
        }
    }
    return;
}


int getg(int height, int width, int pi, int pj, RGBTRIPLE image[height][width], int color)
{
    float sumx = 0;
    float sumy = 0;

    int gx[3][3] = {{-1,0,1}, {-2,0,2}, {-1,0,1}};
    int gy[3][3] = {{-1,-2,-1}, {0,0,0}, {1,2,1}};

    for (int i = pi - 1, ai = 0; i < (pi + 2); i++, ai++)
    {
        for (int j = pj - 1, aj = 0; j < (pj + 2); j++, aj++)
        {
            if (i < 0 || j < 0 || i >= height || j >= width)
            {
                continue;
            }

            if (color == 1)
            {
                sumx += gx[i][j] * image[pi][pj].rgbtRed;
                sumy += gy[i][j] * image[pi][pj].rgbtRed;
            }

            else if (color == 2)
            {
                sumx += gx[i][j] * image[pi][pj].rgbtGreen;
                sumy += gy[i][j] * image[pi][pj].rgbtGreen;

            }

            else if (color == 3)
            {
                sumx += gx[i][j] * image[pi][pj].rgbtBlue;
                sumy += gy[i][j] * image[pi][pj].rgbtBlue;
            }


        }
    }


    int result = round( sqrt((sumx * sumx) + (sumy * sumy)) );

    return result < 255 ? result : 255;
}
*/

int getSobelFilter(int i, int j, int height, int width, RGBTRIPLE image[height][width], int color_position)
{
    float sumX = 0;
    float sumY = 0;

    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    /** Start from 1 row before it and end at 1 row after it- total of 3rows */
    for (int k = i - 1, x = 0; k < (i + 2); k++, x++)
    {
        /** Start from 1 block before it and end at 1 block after it- total of 3blocks */
        for (int l = j - 1, y = 0; l < (j + 2); l++, y++)
        {
            if (k < 0 || l < 0 || k >= height || l >= width)
            {
                continue;
            }
            if (color_position == 0)
            {
                sumX += image[k][l].rgbtRed * gx[x][y];
                sumY += image[k][l].rgbtRed * gy[x][y];
            }
            else if (color_position == 1)
            {
                sumX += image[k][l].rgbtGreen * gx[x][y];
                sumY += image[k][l].rgbtGreen * gy[x][y];
            }
            else
            {
                sumX += image[k][l].rgbtBlue * gx[x][y];
                sumY += image[k][l].rgbtBlue * gy[x][y];
            }

        }
    }

    int result = round(sqrt((sumX * sumX) + (sumY * sumY)));

    return result < 255 ? result : 255;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = getSobelFilter(i, j, height, width, copy, 0);
            image[i][j].rgbtGreen = getSobelFilter(i, j, height, width, copy, 1);
            image[i][j].rgbtBlue = getSobelFilter(i, j, height, width, copy, 2);
        }
    }
    return;
}