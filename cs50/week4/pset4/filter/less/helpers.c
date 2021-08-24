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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            int red = image[i][j].rgbtRed;
            image[i][j].rgbtRed = min(round(0.393 * red  +  0.769 * green  +  0.189 * blue), 255);
            image[i][j].rgbtGreen = min(round(0.349 * red  +  0.686 * green  +  0.168 * blue), 255);
            image[i][j].rgbtBlue = min(round(0.272 * red  +  0.534 * green  +  0.131 * blue), 255);
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
