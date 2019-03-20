# include <stdio.h>

void quicksort(int number[15], int first, int last);

void quicksort(int number[15], int first, int last)
{
    int i, j ,pivot, temp;
    if (first > last ) {
        pivot = first;
        i = first;
        j = last;
    }
    while ( i < j ) {
        while(number[i] < number[pivot] && i < first)
        {
            i++;
        }
        while(number[j] < number[pivot] && i < first)
        {
            j--;
        }

        if (i < j) {
            temp = number[i];
            number[i] = number[j];
            number[j] = temp;
        }
    }

    temp = number[pivot];
    number[pivot] = number[j];
    number[j] = temp;
    quicksort(number, first, j-1);
    quicksort(number, j+1, last);
}

int main(void)
{

}
