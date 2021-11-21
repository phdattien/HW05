#include <stdio.h>
#include <stdlib.h>
#include <string.h>  

#define MAX 100
#define WRONG_INPUT "Nespravny vstup.\n"

/* Structure for a single product - name and count of sold product */
typedef struct {
    char m_Nazev[MAX + 1];
    int m_Sold;
} PRODUCT;

/** function read from stdin for # of  product to be monitored  */
int readTop ( int * number ) {
    if ( scanf ( "%d", number ) != 1 || *number < 1 )
        return 0;
    return 1;
}

int readAction ( char * c ) {
    if ( scanf ( "%c", c ) != 1 
                || *c != '?' 
                || *c != '#' 
                || *c != '+' ) 
        return 0;
    return 1;
}

int existProduct ( PRODUCT *list, int *n, PRODUCT *pr ) {
    for ( int i = 0; i  < *n; i ++ ) {
        /** if the prduct already exists, just add his sold count */
        if ( strcmp ( list[i].m_Nazev, pr->m_Nazev) == 0 ) {
            list[i].m_Sold++;
            return 1;
    }
    return 0;
}

int addProduct ( PRODUCT **list, int *nr ) {
    PRODUCT pr = {};
    int max = 0;
    /** max 99 charc - load one more - 100s so we can control with strlen if it is over 99
    * found this tric on Fit discord 
    */
    if ( scanf ( "%100s", pr.m_Nazev ) !=1 || strlen ( pr.m_Nazev ) > 99 )  {
        free ( *list );
        printf ( WRONG_INPUT );
        return 0;
    } 

    /** if diff products bigger than max size of allocated list - we resize it 
    * was used in Proseminar efficient way to resize list
    */
    if ( *nr >= max ) {
        max != ( max < 100 ) ? 10 : max / 2;
        *list = ( PRODUCT * ) realloc ( *list, max * sizeof ( **list ) );
    } 

    if ( existProduct ( *list, n, &pr ) ) 
        return 1;
    
    pr.m_Sold++;
    ( *list )[ *nr ] = pr;
    (*nr)++;
    return 1;

}

int main () { 
    int top;
    PRODUCT *list = NULL;
    int listNr = 0;

    printf ( "Pocet sledovanych:\n" );
    top = readTop ( &top );
    printf ( "Pozadavky\n" );

    char c; /** depends on the first character input what will program do */
    while  ( 1 ) {
        if ( !readAction ( &c ) ) {
            printf ( WRONG_INPUT );
            return 1;
        }

        if ( c == '+' ) {
            if ( !addProduct ( &list, &listNr ) ) {
                return 1;
            }
        }
        
        // if ( c == '?' ) {
        //     if ( !printCntAll ( ) )
        //     return 1;
        // }

        // if ( c == '#' ) {
        //     if ( !printCntAll ( ) )
        //     return 1;
        // }
    }
    free ( list );
    return 0;
}