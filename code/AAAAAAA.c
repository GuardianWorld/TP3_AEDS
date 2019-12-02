void ordenaPalavraEncadeada(TListaTexto* texto)
{
    apontadorTexto pAux;
    apontadorTexto pTexto;
    apontadorTexto pCorre;
    apontadorTexto pScorro;
    apontadorTexto paa;
    pAux = texto->pPrimeiro;
    pTexto = texto->pPrimeiro;
    pScorro = pTexto;
    paa = texto->pPrimeiro;
    int i, j, h,k, min_idx;
    int n = texto->numeroPalavras;
    //int ver1,ver2

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        pTexto = pTexto->ProxPalavra;
        // Find the minimum element in unsorted array
        min_idx = i;
        for(k = 0; k < i; k++)
        {
            pAux = texto->pPrimeiro->ProxPalavra;
        }
        for (j = i+1; j < n; j++)
        {
            if(i != 0){
            pAux = pAux->ProxPalavra;
            }
            //ver1 = arrj[j];
            //ver2 = arr[min_idx];
                //J                         //I
            if (pAux->ProxPalavra->palavra.letra < pTexto->palavra.letra) //2 < 1
            {
                min_idx = j;
            }

        }

        for(h = 0; h < min_idx-1; h++)
        {
            paa = paa->ProxPalavra;
        }
        pCorre = paa->ProxPalavra;
        paa->ProxPalavra = pTexto;
        //pTexto->ProxPalavra = pCorre;
        pScorro->ProxPalavra = pCorre;
        pScorro = pTexto;
    }
    return;
}
