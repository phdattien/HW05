#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5
#define WRONG_INPUT "Nespravny vstup\n"

/* Structure for a single product - name and count of sold product */
typedef struct {
    char m_Nazev[MAX + 1];
    int m_Sold;
} PRODUCT;

/** function read from stdin for product to be monitored  */
int readTop ( int * number ) {
    if ( scanf ( "%d", number ) != 1 || *number < 1 )
        return 0;
    return 1;
}

int main ( ) { 
/*    if ( scanf ( "%5s", pr.m_Nazev ) != 1 || strln (pr.m_Nazev ) > 4  ) {
        printf ( "Nespravny vstup.\n");
        return 1;
    }
*/
    int top;
    PRODUCT *list = NULL;
    int listNr;

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
            if ( !addProduct ( ) )
            return 1;
        }
        
        if ( c == '?' ) {
            if ( !printCntAll ( ) )
            return 1;
        }

        if ( c == '#' ) {
            if ( !printCntAll ( ) )
            return 1;
        }
    }
}




