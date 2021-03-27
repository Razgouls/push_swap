#include <stdio.h>

    void afficher(int tab[], int n)
    {
        for (int i = 0; i < n; i++)
            printf("%d ", tab[i]);
        printf("\n");
    }

    void fusion(int tab[], int debut, int milieu, int fin)
    {
        //printf("10  4  8  5  12  2  6  11  3  9  7  1\n");
        int n1 = milieu - debut + 1;
        int n2 = fin - milieu;
        //printf("debut : [ %d ] --> milieu : [ %d ] --> fin : [ %d ]\n", debut, milieu, fin);
        //printf("n1 : [ %d ] --> n2 : [ %d ]\n", n1, n2);
        int G[n1], D[n2];
     
        for (int i = 0; i < n1; i++)
            G[i] = tab[debut + i];
        for (int j = 0; j < n2; j++)
            D[j] = tab[milieu + 1 + j];
     
        //printf("------------------GGG-------------------\n");
        //afficher(G, n1);
       // printf("------------------DDD-------------------\n");
        //afficher(D, n2);
        //printf("\n");
        // maintient trois pointeurs, un pour chacun des deux tableaux et un pour
        // maintenir l'index actuel du tableau trié final
        int i, j, k;
        i = 0;
        j = 0;
        k = debut;
     
        while (i < n1 && j < n2)
        {
            if (G[i] <= D[j])
            {
                tab[k] = G[i];
                i++;
            }
            else
            {
                tab[k] = D[j];
                j++;
            }
            k++;
        }
     
        // Copiez tous les éléments restants du tableau non vide
        while (i < n1)
        {
            tab[k] = G[i];
            i++;
            k++;
        }
     
        while (j < n2)
        {
            tab[k] = D[j];
            j++;
            k++;
        }
    }
     
    // Tri par fusion
    void triFusion(int tab[], int debut, int fin)
    {
        if (debut < fin)
        {
     
            // Trouvez le point milieu pour diviser le tableau en deux moitiés
            int m = (debut + fin) / 2;
     
            //triFusion(tab, debut, m);
            triFusion(tab, m + 1, fin);
            printf("debut : [ %d ] --> milieu : [ %d ] --> fin ; [ %d ]\n", debut, m + 1, fin);
            // Fusionnez les deux moitiés triées
            fusion(tab, debut, m, fin);
        }
    }
     
    int main()
    {
        int tab[] = {10, 4, 8, 5, 12, 2, 6, 11};
        int n = 8;
     
        triFusion(tab, 0, n - 1);
     
        printf("Tableau trié: \n");
        afficher(tab, n);
    }