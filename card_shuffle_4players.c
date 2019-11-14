//Francisco Bolanos
//EEL2880
//Dealing 26 cards with two decks to four players

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CARDS 52
#define FACES 13

//card structure definition
struct card {
const char *face; // define pointer face
const char *suit; // define pointer suit
};
typedef struct card Card; // new type name for struct card
// prototypes  All functions defined
void fillDeck( Card * const wDeck, const char * wFace[],
const char * wSuit[] );
void shuffle( Card * const wDeck );
void deal( const Card *const wDeck );



int main( void )
{
Card deck [ CARDS ]; //define array of Cards
//initialize array of pointers
const char * face[] = { "Ace" , "Deuce" , "Three" , "Four" , "Five" , "Six" , "Seven" , "Eight" , "Nine" , "Ten" , "Jack" , "Queen" , "King"};


// initialize array of pointers
const char *suit[] = { "Hearts" , "Diamonds" , "Clubs" , "Spades"};
srand( time( NULL) ); //randomize

char newline ='\n';

while('\n' == newline){
size_t i;
for(i=0; i<4; i++){
 printf("\n Dealing to player: %lu \n ", i+1);
fillDeck( deck, face, suit ); //load the deck with Cards
shuffle( deck ); // put Cards in random order
deal( deck );} // deal all 52 Cards
printf("Press \"Enter\" to play again and any other key to stop");
newline = getchar();

}
} // end main
// place strings into Card Structures
void fillDeck( Card * const wDeck, const char * wFace [],
const char * wSuit[] )
{
size_t i; // counter
// loop through wDeck
for (i = 0; i < CARDS; ++i ) {
wDeck [ i ] . face = wFace[ i % FACES];
wDeck [ i ] . suit = wSuit[ i / FACES];
} // end for
} // end function fillDeck




// random shuffle of cards
// shuffle cards
void shuffle( Card * const wDeck )
{
size_t i; // counter
size_t j; // variable to hold random variable between 0-51
Card temp; // define temporary structure for swapping Cards
// loop through wDeck randomly swapping Cards
for ( i = 0; i < CARDS; ++i) {
j = rand () % CARDS;
temp = wDeck[ i ];
wDeck[ i ] = wDeck [ j ];
wDeck[ j ] = temp;
} // end for
}// end function shuffle
// deal cards


void deal( const Card * const Deck)
{
size_t i; // counter
// loop through wDeck
for ( i = 0; i < CARDS; ++i ) {
printf ("%5s of %-8s%s", Deck[ i  ].face, Deck[ i  ].suit,
(i + 1 ) % 4 ? " " : "\n" );
} // end for
} // end function deal

