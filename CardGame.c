/*
 Joussef Abdul Salam, PID: 6130916, Code: 31
 
 Ch. 10: Deck Program with 104 cards and a deal of 26 cards
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CARDS 104
#define FACES 13

struct card {
    
    const char *face;
    const char *suit;
};

typedef struct card Card;

//prototypes
void fillDeck( Card * const aDeck, const char *aFace[], const char *aSuit[]);
void shuffle(Card *const aDeck);
void deal(const Card *const aDeck);

int main(void)
{
    
    Card deck[CARDS];
    
    const char *face[] = {"Ace", "Deuce", "Three", "Four", "Fives", "Six",
                          "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    
    const char *suit[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    
    srand(time(NULL)); //randomize
    
    fillDeck(deck, face, suit);
    shuffle(deck);
    deal(deck);
}//end main

void fillDeck( Card * const aDeck, const char *aFace[], const char *aSuit[])
{
    
    size_t i;
    
    for(i = 0; i < (CARDS / 2); i++)
    {
        
        aDeck[i].face = aFace[i % FACES];
        aDeck[i].suit = aSuit[i / FACES];
        
        aDeck[52 + i] = aDeck[i];
    }

    
}//end fill deck function

void shuffle(Card *const aDeck)
{
    
    size_t i;
    size_t j;
    Card temp;
    
    for(i = 0; i < CARDS; i++)
    {
        
        j = rand() % CARDS;
        temp = aDeck[i];
        aDeck[i] = aDeck[j];
        aDeck[j] = temp;
    }
}//end shuffle function

void deal(const Card *const aDeck)
{
    
    size_t i;

        for(i = 0; i < CARDS; i++)
        {
        
            printf("%5s of %-8s%s", aDeck[i].face, aDeck[i].suit, (i + 1) % 26 ? " \n" : "\n––––––––––––––––––––––––\n");
        }
    
}//end deal function


