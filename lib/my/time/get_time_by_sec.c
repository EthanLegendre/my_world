/*
** EPITECH PROJECT, 2025
** get_time_by_sec
** File description:
** get_time_by_sec
*/

#include "../../../include/biglib.h"

int *get_time_by_sec(long n)
{
    int hour = 0;
    int min = 0;
    int *time = malloc(sizeof(int) * 3);

    while (n >= 3600){
        hour += 1;
        n -= 3600;
    }
    while (n >= 60){
        min += 1;
        n -= 60;
    }
    time[0] = hour;
    time[1] = min;
    time[2] = 0;
    return time;
}
