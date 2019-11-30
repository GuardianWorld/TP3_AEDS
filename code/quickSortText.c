int partition (TPalavra* arr, int low, int high);
void swap(TPalavra* a, TPalavra* b);

void quickSort(TPalavra* arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition (TPalavra* arr, int low, int high)
{
    int pivot = arr[high].palavra[0];    // pivot
    int i = (low - 1);  // Index of smaller element
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j].palavra[0] < pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void swap(TPalavra* a, TPalavra* b)
{
    TPalavra t = *a;
    *a = *b;
    *b = t;
}
//usar no MAIN
//n = text.numeroPalavras;
//quickSort(&text.texto, 0 , n-1);
