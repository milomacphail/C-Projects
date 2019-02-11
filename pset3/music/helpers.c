// Helper functions for music

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    //put x/y into intergers
    int x = fraction[0] - '0';
    int y = fraction[2] - '0';
    // return ((8/denominator) * numerator);
    int duration = ((8/y) * x);
    return duration;

}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{

     double freq =  0.0;

// Switch operator is much faster for multi-way branching
    int oct = note[strlen(note) -1] -'0';
    switch (note[0])
    {
        case 'C':
                freq = 440.0 / (pow(2.0, (9.0 / 12.0)));
            break;
        case 'D':
                freq = 440.0 / (pow(2.0, (7.0 / 12.0)));
            break;
        case 'E':
                freq = 440.0 / (pow(2.0, (5.0 / 12.0)));
            break;
        case'F':
                freq = 440.0 / (pow(2.0,(4.0 / 12.0)));
            break;
        case 'G':
                freq = 440.0 / (pow(2.0, (2.0 / 12.0)));
            break;
        case 'A':
                freq = 440.0;
            break;
        case 'B':
                freq = 440.0 * (pow(2.0, (2.0 / 12.0)));
            break;

    }
            // Loop to shift oct
            if (oct > 4)
            {
                for (int i = 0; i < oct - 4; i++)
            {
                freq *= 2.0;
            }
        }
            else if (oct < 4)
            {
                for (int i = 0; i < 4 - oct; i++)
            {
                freq /= 2.0;
            }
        }

            // adjust to accidental (flat or sharp)
            if (note[1] == 'b')
            {
            freq /= (pow(2.0, (1.0 / 12.0)));
            }
            else if (note[1] == '#')
            {
            freq *= (pow(2.0, (1.0 / 12.0)));
            }

    return round(freq);

}
// Is a string a rest
bool is_rest(string s)
{

    if (s[0] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }

}
