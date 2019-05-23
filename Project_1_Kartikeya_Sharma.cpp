#include <stdio.h>
#include <stdlib.h>
// Name: Kartikeya Sharma
// Class: Algorithms 22000

void merge_sort(int *a, int *aux, int length) {

    int i;
    int j1;
    int j2;
    int j3;
    int temp;

    // Null case. If array size is 1 or less
    if(length < 2) {
        return;
    }

    // Base case
    if(length == 2) {
        if(a[1] < a[0]) {
            temp = a[1];
            a[1] = a[0];
            a[0] = temp;
        }
        return;
    }
    // Everything else (3-way mergesort)
    else {
        merge_sort( a, aux, (length/3) );
        merge_sort( a + (length/3), aux, (length/3) );
        merge_sort( a + 2*(length/3), aux, length - 2*(length/3) );

        int j1_END = (length/3);
        int j2_END = 2*(length/3);
        int j3_END = (length);

        for ( i = 0, j1 = 0, j2 = j1_END, j3 = j2_END; i < j3_END; )

            // Case 1: Where non of the arrays are exhaused. Here we find the smallest item
            if( j1 < j1_END && j2 < j2_END && j3 < j3_END && a[j1] <= a[j2] && a[j1] <= a[j3] ) {
                aux[i++] = a[j1++];
            }
            else if( j1 < j1_END && j2 < j2_END && j3 < j3_END && a[j2] <= a[j1] && a[j2] <= a[j3] ) {
                aux[i++] = a[j2++];
            }
            else if(j1 < j1_END && j2 < j2_END && j3 < j3_END && a[j3] <= a[j1] && a[j3] <= a[j2] ) {
                aux[i++] = a[j3++];
            }

            // Case 2: Where one array (j1, j2, or j3) is ehaused and we find smallest accordingly
            else if( j1 == j1_END && j3 < j3_END && j2 < j2_END ) {
                if (a[j2] <= a[j3]) {
                    aux[i++] = a[j2++];
                } else {
                    aux[i++] = a[j3++];
                }
            }
            else if( j2 == j2_END && j1 < j1_END && j3 < j3_END ) {
                if (a[j1] <= a[j3]) {
                    aux[i++] = a[j1++];
                } else {
                    aux[i++] = a[j3++];
                }
            }
            else if( j3 == j3_END && j2 < j2_END && j1 < j1_END ) {
                if (a[j1] <= a[j2]) {
                    aux[i++] = a[j1++];
                } else {
                    aux[i++] = a[j2++];
                }
            }

            // Case 3: Where 2 arrays are exhaused and we copy remaining
            // elements from last arry into a[]
            else if( j1 < j1_END && j2 == j2_END && j3 == j3_END ) {
                aux[i++] = a[j1++];
            }
            else if( j2 < j2_END && j3 == j3_END && j1 == j1_END ) {
                aux[i++] = a[j2++];
            }
            else if( j3 < j3_END && j1 == j1_END && j2 == j2_END ) {
                aux[i++] = a[j3++];
            }

    }
    for( i = 0; i < length; i++) {
        a[i] = aux[i];
    }

}

int main() {

    int *r;
    int *s;
    long i;

    printf("Allocating Array. ");
    fflush(stdout);
    r = (int *) malloc(3000000 * sizeof(int));
    s = (int *) malloc(3000000 * sizeof(int));
    printf("Filling array. ");
    fflush(stdout);

    for( i = 0; i< 3000000; i++)
        r[i] = 3 * ((137 * i)%3000000);
    printf("Sorting. ");
    fflush(stdout);
    merge_sort( r, s, 3000000 );
    printf("Checking. \n");
    fflush(stdout);
    for(i=0; i< 3000000; i++)
        if( r[i] != 3*i )
        {  printf("Error at %d; is %d, should be %d\n", i, r[i], 3*i );
            fflush(stdout); exit(-1);
        }
    printf("Passed Test.\n");
}