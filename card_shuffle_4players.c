#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#define CARDS 52
#define FACES 13
#define SUITS 4

//card structure definition
struct card {
    char *face; // define pointer face
    char *suit; // define pointer suit
    int value;
};

typedef struct card Card; // new type name for struct card

// prototypes  All functions defined
void fillDeck( Card *wDeck,   char *wFace[], char *wSuit[], int fValue[], int sValue[]);
void shuffle( Card *wDeck );
void deal(   Card *wDeck );
int sum( Card *wDeck );

int main(void)
{
    Card deck[CARDS]; //define array of Cards
    
    //initialize array of pointers
    char * face[] = { "Deuce" , "Three" , "Four" , "Five" , "Six" , "Seven" , "Eight" , "Nine" , "Ten" , "Jack" , "Queen", "King", "Ace"};

    //initialize array of pointers
    char *suit[] = { "Clubs" , "Diamonds" , "Hearts" , "Spades"};
    
    int faceValue[] = { 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13, 14};
    int suitValue[] = { 1 , 2 , 3 , 4};
    
    srand( time(NULL) ); //randomize
    
    fillDeck(deck, face, suit, faceValue, suitValue);
    
    char newline ='\n';

    while('\n' == newline)
    {
        size_t i;
        
        for(i = 0; i < 4; i++)
        {
            printf("\n Dealing to player: %lu \n ", i + 1);
            shuffle(deck);
            deal(deck);
            
        } // deal all 52 Cards


        printf("Press \"Enter\" to play again and any other key to stop");
        newline = getchar();

    }
} // end main

// place strings into Card Structures
void fillDeck( Card *wDeck, char *wFace [], char *wSuit[], int fValue[], int sValue[])
{
    
    size_t i; // counter
    
    // loop through wDeck
    for (i = 0;i < CARDS; ++i)
    {
        wDeck[i].face = wFace[i % FACES];
        wDeck[i].suit = wSuit[i / FACES];
        wDeck[i].value = fValue[i % FACES] + sValue[i / FACES];
    } // end for
} // end function fillDeck

// random shuffle of cards
void shuffle( Card *wDeck )
{
    size_t i; // counter
    size_t j; // variable to hold random variable between 0-51
    Card temp; // define temporary structure for swapping Cards
    
    // loop through wDeck randomly swapping Cards
    for (i = 0; i < CARDS; ++i)
    {
        j = rand () % CARDS;
        temp = wDeck[i];
        wDeck[i] = wDeck [j];
        wDeck[j] = temp;
    } // end for
}// end function shuffle

// deal cards
void deal(Card *wDeck)
{

    size_t i; // counter
    
    // loop through wDeck
    for (i = 0;i < CARDS; ++i )
    {
        printf ("%5s of %-8s value: %d %s\n", wDeck[i].face, wDeck[i].suit, wDeck[i].value, (i + 1) % 13 ? " " : "\n" );

    } // end for
} // end function deal


