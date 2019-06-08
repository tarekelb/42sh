/*
** EPITECH PROJECT, 2018
** my_sort_int_array.c
** File description:
** sort number in array
*/

void my_sort_int_array(int *array, int size)
{
    int i = size - 1;
    int j = size - 1;
    int swap;

    while (--i > -1) {
        if (array[j] < array[i]) {
            swap = array[i];
        array[i] = array[j];
        array[j] = swap;
    }
    }
    if (--size > 0)
        my_sort_int_array(array, size);
}