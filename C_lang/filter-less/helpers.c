#include "helpers.h"
#include <math.h>
#include <stdlib.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int average = 0; // stored average, completed and outputed as int

            average  = (int) round(((((float)image[i][j].rgbtBlue) + ((float)image[i][j].rgbtGreen) + ((float)image[i][j].rgbtRed)) / 3.0));


            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;

        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // for each pixel
        // calculate each new color value, using the sepia formula
        // ensure the result is an integer between 0 and 255

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaBlue = 0; // sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
            int sepiaGreen = 0; // sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
            int sepiaRed = 0; //  sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue

            // operations

            sepiaBlue = (int) round(((float)image[i][j].rgbtBlue * 0.131) + ((float)image[i][j].rgbtGreen * 0.534) + ((float)image[i][j].rgbtRed * 0.272));

            sepiaGreen = (int) round(((float)image[i][j].rgbtBlue * 0.168) + ((float)image[i][j].rgbtGreen * 0.686) + ((float)image[i][j].rgbtRed * 0.349));

            sepiaRed = (int) round(((float)image[i][j].rgbtBlue * 0.189) + ((float)image[i][j].rgbtGreen * 0.769) + ((float)image[i][j].rgbtRed * 0.393));

            // conditionals
            //blue
            if(sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if(sepiaBlue < 0)
            {
                sepiaBlue = 0;
            }
            // green
            if(sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if(sepiaGreen < 0)
            {
                sepiaGreen = 0;
            }
            //red
            if(sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if(sepiaRed < 0)
            {
                sepiaRed = 0;
            }

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //For each row
        //swap pixels on horizontally opposite sides
        //we wil need a swap temporary holder

    // first we define a temporary holder array

    //RGBTRIPLE (*temp)[height][width]; // this will make all set to 0 and allow us to change them
    RGBTRIPLE(*temp)[width] = calloc(height, width * sizeof(RGBTRIPLE));

    for (int i = 0; i < height; i++) //starting the itineration vertically
    {
        for (int j = 0; j < width; j++) // itineration vertically
        {
            // this loop will make the copies in reverse order into a temporary array
            temp[i][(width) - 1 -j].rgbtBlue = image[i][j].rgbtBlue ;
            temp[i][(width) - 1 -j].rgbtGreen = image[i][j].rgbtGreen;
            temp[i][(width) - 1 -j].rgbtRed = image[i][j].rgbtRed;
        }

        for (int k = 0; k < width; k++)
        {
            image[i][k].rgbtBlue = temp[i][k].rgbtBlue;
            image[i][k].rgbtGreen = temp[i][k].rgbtGreen;
            image[i][k].rgbtRed = temp[i][k].rgbtRed;
        }
    }

    free(temp);
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //copy imaage into  a new array
    //
    int average_matrix = 0;

    RGBTRIPLE (*tempi)[width] = calloc(height, width * sizeof(RGBTRIPLE)); // storing data

    for (int i = 0; i < height; i++) // first we have to copy with operations and store it. the passing values has to come in another function
    {
        for (int j = 0; j < width; j++)
        {
            tempi[i][j].rgbtBlue = image[i][j].rgbtBlue;
            tempi[i][j].rgbtGreen = image[i][j].rgbtGreen;
            tempi[i][j].rgbtRed = image[i][j].rgbtRed;
        }
    }


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumBlue = 0;
            int sumGreen = 0;
            int sumRed = 0;
            // this could be better implemented:
            // int sumBlue, sumGreen, sumRed;
            // avgBlue = sumGreen = sumRed = 0;
            // i'm not sure if its better.

            float count = 0.0; // counter for the valid arrays

            // we have to create a loop that will iterate inside for the next array

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    int posci = 0;
                    int poscj = 0;

                    posci = i + k;
                    poscj = j + l;

                    // if conditional

                    if (posci < 0 || posci > (height - 1) || poscj < 0 || poscj > (width - 1))
                    {
                        continue;
                    }

                        sumBlue += image[posci][poscj].rgbtBlue;
                        sumGreen += image[posci][poscj].rgbtGreen;
                        sumRed += image[posci][poscj].rgbtRed;

                        count ++;
                }


                tempi[i][j].rgbtBlue = round(sumBlue / count);
                tempi[i][j].rgbtGreen = round(sumGreen / count);
                tempi[i][j].rgbtRed = round(sumRed / count);

            }

        }
    }


    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            //

            image[k][l].rgbtBlue = tempi[k][l].rgbtBlue;
            image[k][l].rgbtGreen = tempi[k][l].rgbtGreen;
            image[k][l].rgbtRed = tempi[k][l].rgbtRed;

        }
    }

    free(tempi);

    return;
}


/*

            float avg_blue = 0.0;
            float avg_green = 0.0;
            float avg_red = 0.0;

            //Blue
            avg_blue = (image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i + 1][j].rgbtBlue +
            image[i - 1][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue) / 9.0;

            tempi[i][j].rgbtBlue = (int)avg_blue;

            // Green
            avg_green = abs(image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i + 1][j].rgbtGreen +
            image[i - 1][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen) / 9.0;

            tempi[i][j].rgbtGreen = (int)avg_green;

            //Red
            avg_red = abs(image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i + 1][j].rgbtRed +
            image[i - 1][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed) / 9.0;

            tempi[i][j].rgbtRed = (int)avg_red;



*/