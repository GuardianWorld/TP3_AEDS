int partitionbib (TTexto* arr, int low, int high);
void swapbib(TTexto* a, TTexto* b);

void quickSortbib(TTexto* arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partitionbib(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSortbib(arr, low, pi - 1);
        quickSortbib(arr, pi + 1, high);
    }
}

int partitionbib (TTexto* arr, int low, int high)
{
    int pivot = arr[high].numeroPalavras;
    //printf("=%d=",arr[high].numeroPalavras);    // pivot
    int i = (low - 1);  // Index of smaller element
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j].numeroPalavras < pivot)
        {
            i++;    // increment index of smaller element
            swapbib(&arr[i], &arr[j]);
        }
    }
    swapbib(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void swapbib(TTexto* a, TTexto* b)
{
    TTexto t = *a;
    *a = *b;
    *b = t;
}
//usar no main
//n = bib.tamBiblioteca;
//quickSortbib(&bib.textos, 0 , n-1);
