void ordenaTexto(TBiblioteca* Biblioteca){

    int i, j, min_idx;
    TTexto temp;
    int n = Biblioteca->tamBiblioteca;
    //int ver1,ver2

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++){
            //ver1 = arrj[j];
            //ver2 = arr[min_idx];
          if (Biblioteca->textos[j].numeroPalavras < Biblioteca->textos[min_idx].numeroPalavras){
            min_idx = j;
          }
        }

        temp = Biblioteca->textos[min_idx];
        Biblioteca->textos[min_idx] = Biblioteca->textos[i];
        Biblioteca->textos[i] = temp;
    }
}



void ordenaPalavra(TTexto* texto){

    int i, j, min_idx;
    TPalavra temp;
    int n = texto->numeroPalavras;
    //int ver1,ver2

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++){
            //ver1 = arrj[j];
            //ver2 = arr[min_idx];
          if (texto->texto[j].palavra[0] < texto->texto[min_idx].palavra[0]){
            min_idx = j;
          }
        }

        temp = texto->texto[min_idx];
        texto->texto[min_idx] = texto->texto[i];
        texto->texto[i] = temp;
    }
}
