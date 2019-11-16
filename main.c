//Francisco Bolanos
//EEL2880
//Dealing 26 cards with two decks to four players

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define CARDS 52
#define FACES 13
#define SUITS 4

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
int sum(const Card *const wDeck);

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
deal( deck );
sum( deck );
} // deal all 52 Cards


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

int sum( const Card * const Deck ){

  size_t i;
  size_t j;
  int value = 0;



  for(i=0; i<CARDS; ++i ){
    int hearts =  strcmp( Deck[i].suit, "Hearts" );
  int diamonds = strcmp( Deck[i].suit, "Diamonds" );
  int spades = strcmp( Deck[i].suit, "Spades" );

    if (spades ==0)
        value+=4;
    else if (hearts ==0)
        value +=3;
    else if(diamonds ==0)
        value +=2;
        else
        value +=1;
          }

   for(j=0; j<CARDS; ++j){
    int deuce = strcmp(Deck[j].face, "Deuce");
    int three = strcmp(Deck[j].face, "Three");
    int four = strcmp(Deck[j].face, "Four");
    int five = strcmp(Deck[j].face, "Five");
    int six = strcmp(Deck[j].face, "Six");
    int seven = strcmp(Deck[j].face, "Seven");
    int eight = strcmp(Deck[j].face, "Eight");
    int nine = strcmp(Deck[j].face, "Nine");
    int ten = strcmp(Deck[j].face, "Ten");
    int jack = strcmp(Deck[j].face, "Jack");
    int queen = strcmp(Deck[j].face, "Queen");
    int king = strcmp(Deck[j].face, "King");


    if (deuce == 0)
        value +=1;
    else if(three == 0)
        value+=2;
    else if(four ==0)
        value+=3;
    else if(five ==0 )
        value +=4;
    else if(six ==0 )
        value +=5;
    else if(seven ==0)
        value +=6;
    else if(eight ==0 )
        value +=7;
    else if(nine ==0 )
        value +=8;
    else if(ten ==0)
        value +=9;
    else if(jack ==0)
        value+=10;
    else if(queen ==0)
        value +=11;
    else if(king ==0 )
        value +=12;
    else
        value+=13;
   }

  printf("\n Total of hand is %d \n", value);
  return value;
}



