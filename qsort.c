#include <stdio.h>
#include <stdlib.h>

#define  SWAP(a, b)	( (a) = (b) + (a) - ((b) = (a)) )

#define  MASK_SIGNBIT	0x80000000L
int median(int arr[], int a, int b, int c)  {
    if ( MASK_SIGNBIT & ( (arr[b] - arr[a] ) ^ (arr[b]-arr[c]) ) )
	return b;
    if ( arr[a] < arr[c] )
	return a;
    else
	return c;
}

void quicksort0(int arr[], int left, int right)  {
  int  pivot, small, large, midx;
  int  ii ;

  //printf("%s(%d) l[%d]=%d r[%d]=%d\n", __func__, __LINE__, left, arr[left], right, arr[right] ) ;
    if ( left >= right )
	return;
    /*
    if ( (1 + left) == right )  {
	if ( arr[left] > arr[right] )
	    SWAP( arr[left], arr[right] ) ;
	return;
    }
    */
  midx = median( arr, left, left + (right-left) >> 1, right ) ; SWAP( arr[left], arr[midx] ) ;
    pivot = arr[left] ;
    //printf("%s(%d) l[%d]=%d r[%d]=%d\n", __func__, __LINE__, left, arr[left], right, arr[right] ) ;

    for ( small = left+1, large = right ; small < large; )  {
	while (arr[large] > pivot)
	    large--;
	while ( (arr[small] <= pivot) && (small < large) )
	    small++;
	if (small < large)
	    SWAP( arr[small], arr[large] ) ;
	/*
	for ( ii = left; ii <= right; ii++)
	    printf("%d ", arr[ii] ) ;
	printf("  p=%d [s=%d l=%d] (l=%d r=%d)\n", pivot, small, large, left, right) ;
	*/
    }
    SWAP( arr[left], arr[large] ) ;	// arr[large] = pivot ;
    /*
	for ( ii = left; ii <= right; ii++)
	    printf("%d ", arr[ii] ) ;
	printf("  p=%d [s=%d l=%d] (lf=%d rt=%d)\n", pivot, small, large, left, right) ;
    */
    //getchar() ;

    quicksort0( arr, left, large-1 ) ;
    quicksort0( arr, large+1, right ) ;
}

void quicksort(int arr[], int len)  {
  int pivot, small, large, ii;

  //printf("%s(%d) l=%d r=%d\n", __func__, __LINE__, left, right ) ;
    if ( 2  > len )
	return;
    /*
    if ( 2 == len )  {
	if ( arr[0] > arr[1] )
	    SWAP( arr[0], arr[1]) ;
	return;
    }
    */
    small = 1 ;		large = len - 1 ;
    pivot = arr[0] ;
    do  {
	while (arr[large] > pivot)
	    large--;
	while ( (arr[small] <= pivot) && (small < large) )
	    small++;
	if (small < large)
	    SWAP( arr[small], arr[large] ) ;
	/*
	for ( ii = left; ii <= right; ii++)
	    printf("%d ", arr[ii] ) ;
	printf("  p=%d [s=%d l=%d] (l=%d r=%d)\n", pivot, small, large, left, right) ;
	*/
    } while ( small < large ) ;

    arr[0] = arr[large] ;	arr[large] = pivot ;
    /*
	for ( ii = 0; ii < len; ii++)
	    printf("%d ", arr[ii] ) ;
	printf("  p=%d [s=%d l=%d] (len=%d)\n", pivot, small, large, len) ;
    */
    //getchar() ;

    quicksort( arr, large ) ;
    quicksort( &arr[large+1], len-(large+1) ) ;
}


int  findkth( int kth, int arr[], int len )  {
  int pivot, small, large, ii;

  //printf("%s(%d) l=%d r=%d\n", __func__, __LINE__, left, right ) ;
    if ( 2  > len )
	return arr[0] ;
    /*
    if ( 2 == len )  {
	if ( arr[0] > arr[1] )
	    SWAP( arr[0], arr[1]) ;
	return;
    }
    */
    small = 1 ;		large = len - 1 ;
    pivot = arr[0] ;
    do  {
	while (arr[large] > pivot)
	    large--;
	while ( (arr[small] <= pivot) && (small < large) )
	    small++;
	if (small < large)
	    SWAP( arr[small], arr[large] ) ;
    } while ( small < large ) ;

    arr[0] = arr[large] ;	arr[large] = pivot ;
    for ( ii = 0; ii < len; ii++)
	    printf("%d ", arr[ii] ) ;
    printf("  p=%d [s=%d l=%d] (len=%d)\n", pivot, small, large, len) ;
    //getchar() ;
    //if ( kth == large )		return  arr[kth] ;
    if ( kth <= large )
	return  findkth( kth, arr, large ) ;
    else
	return  findkth( kth-(large+1), &arr[large+1], len-(large+1) ) ;
}



#define  MAX   40

void main(int argc, char *argv[])  {
    int  ii, arr[MAX], kth ;
    (ii) = (MAX + argc) ;

    if ( argc > 1 )
	srand( atoi(argv[2]) ) ;
    for ( ii = 0; ii < MAX; ii++)  {
	arr[ii] = rand() % 100 ;
	printf("%d ", arr[ii] ) ;
    }
    printf("\n") ;

    kth = atoi(argv[1]) ;
    printf("%dth = %d\n", kth, findkth( kth-1, arr, MAX) ) ;
    for ( ii = 0; ii < MAX; ii++)  printf("%d ", arr[ii] ) ;	    printf("\n") ;
    quicksort0(arr, 0, MAX-1);
    for ( ii = 0; ii < MAX; ii++)  printf("%d ", arr[ii] ) ;	    printf("\n") ;
    arr[0] = 7; arr[1]=6; arr[2]=5;
    quicksort(arr, MAX);
    for ( ii = 0; ii < MAX; ii++)  printf("%d ", arr[ii] ) ;	    printf("\n") ;

}
