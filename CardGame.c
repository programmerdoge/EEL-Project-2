#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CARDS 52
#define FACES 13
#define HAND 13

struct card {
    
    const char *face;
    const char *suit;
    int value;
};

typedef struct card Card;

//prototypes
void fillDeck( Card * const aDeck, const char *aFace[], const char *aSuit[], int fValue[], int sValue[]);
void shuffle(Card *const aDeck);
void deal(const Card *const aDeck, Card *const aHand1, Card *const aHand2, Card *const aHand3, Card *const aHand4);

int main(void)
{
    
    Card deck[CARDS];
    Card hand1[HAND];
    Card hand2[HAND];
    Card hand3[HAND];
    Card hand4[HAND];
    
   
    
    const char *face[] = {"Deuce", "Three", "Four", "Fives", "Six",
                          "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    
    const char *suit[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    
    int faceValue[] = { 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13, 14};
    
    int suitValue[] = { 1 , 2 , 3 , 4};
    
    srand(time(NULL)); //randomize
    
    fillDeck(deck, face, suit, faceValue, suitValue);
    shuffle(deck);
    deal(deck, hand1, hand2, hand3, hand4);
}//end main

void fillDeck( Card * const aDeck, const char *aFace[], const char *aSuit[], int fVal[], int sVal[])
{
    
    size_t i;
    
    for(i = 0; i < CARDS; i++)
    {
        
        aDeck[i].face = aFace[i % FACES];
        aDeck[i].suit = aSuit[i / FACES];
        aDeck[i].value = fVal[i % FACES] + sVal[i / FACES];
        
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

void deal(const Card *const aDeck, Card *const aHand1, Card *const aHand2, Card *const aHand3, Card *const aHand4)
{
    
    int handValue1 = 0;
    int handValue2 = 0;
    int handValue3 = 0;
    int handValue4 = 0;
    
    size_t i = 0;
    size_t j;
    size_t k;
    size_t l;
    size_t m;

        while(i < CARDS)
        {
            
            //hand 1
            printf("Player 1:\n");
            for(j = 0; j < HAND; j++)
            {
                
                aHand1[j].face = aDeck[i].face;
                aHand1[j].suit = aDeck[i].suit;
                aHand1[j].value = aDeck[i].value;
                handValue1 += aHand1[j].value;
                printf("%5s of %-8s value: %d\n", aHand1[j].face, aHand1[j].suit, aHand1[j].value);
                i++;
                
            }
            
            printf("value of hand = %d\n", handValue1);
            puts("");
            
            //hand 2
            printf("Player 2:\n");
            for(k = 0; k < HAND; k++)
            {
                
                aHand2[k].face = aDeck[i].face;
                aHand2[k].suit = aDeck[i].suit;
                aHand2[k].value = aDeck[i].value;
                handValue2 += aHand2[k].value;
                printf("%5s of %-8s value: %d\n", aHand2[k].face, aHand2[k].suit, aHand2[k].value);
                i++;
            }
            
            printf("value of hand = %d\n", handValue2);
            puts("");
            
            //hand 3
            printf("Player 3:\n");
            for(l = 0; l < HAND; l++)
            {
                
                aHand3[l].face = aDeck[i].face;
                aHand3[l].suit = aDeck[i].suit;
                aHand3[l].value = aDeck[i].value;
                handValue3 += aHand3[l].value;
                printf("%5s of %-8s value: %d\n", aHand3[l].face, aHand3[l].suit, aHand3[l].value);
                
                i++;
            }
            
            printf("value of hand = %d\n", handValue3);
            puts("");
            
            //hand 4
            printf("Player 4:\n");
            for(m = 0; m < HAND; m++)
            {
                
                aHand4[m].face = aDeck[i].face;
                aHand4[m].suit = aDeck[i].suit;
                aHand4[m].value = aDeck[i].value;
                handValue4 += aHand4[m].value;
                printf("%5s of %-8s value: %d\n", aHand4[m].face, aHand4[m].suit, aHand4[m].value);
                i++;
            }
            
            printf("value of hand = %d\n", handValue4);
            puts("");
        }
    
}//end deal function


