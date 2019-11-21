#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define CARDS 52
#define FACES 13
#define HAND 6

//card structure definition
struct card {

    const char *face; //pointer to face
    const char *suit; //pointer to suit
    int value;   //int to store value for cards
};

typedef struct card Card;  //new typename for struct card

//prototypes
void fillDeck( Card * const aDeck, const char *aFace[], const char *aSuit[], int fValue[], int sValue[]);
void shuffle(Card *const aDeck);
void deal(const Card *const aDeck, Card *const aHand1, Card *const aHand2, Card *const aHand3, Card *const aHand4, Card *const aHand5, Card *const aHand6, Card *const aHand7, Card *const aHand8, Card *const aleftover);


    Card deck[CARDS];  //define array of Cards and for each Hand
    Card hand1[HAND];
    Card hand2[HAND];
    Card hand3[HAND];
    Card hand4[HAND];
    Card hand5[HAND];
    Card hand6[HAND];
    Card hand7[HAND];
    Card hand8[HAND];
    Card leftover[HAND];
    Card temp[HAND];   //array to hold temp variable for swapping


int main(void)
{


    //initialize array of pointer
    const char *face[] = {"Deuce", "Three", "Four", "Fives", "Six",
                          "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    //initialize array of pointers
    const char *suit[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

    //integer array for face values
    int faceValue[] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12, 13};
    //integer array for suit values
    int suitValue[] = { 1 , 2 , 3 , 4};

    srand(time(NULL)); //randomize
    fillDeck(deck, face, suit, faceValue, suitValue);  //fill the main deck
    char newline = '\n'; //to use for repeating in while loop

    while('\n' == newline){

    shuffle(deck); //shuffle the decks
    deal(deck, hand1, hand2, hand3, hand4, hand5, hand6, hand7, hand8, leftover);  //deal the 8 hands

    printf("\n Press \"Enter\" to play again and any other key to stop");
    newline = getchar();   //read single character from input and if \n then repeat while
    }
}//end main

//place strings into Card structures
void fillDeck( Card * const aDeck, const char *aFace[], const char *aSuit[], int fVal[], int sVal[])
{

    size_t i; //counter

    for(i = 0; i < CARDS; i++)  //loop through aDeck
    {

        aDeck[i].face = aFace[i % FACES];
        aDeck[i].suit = aSuit[i / FACES];
        aDeck[i].value = fVal[i % FACES] + sVal[i / FACES];

    } //end for


}//end fill deck function

void shuffle(Card *const aDeck) //random shuffle of cards
{

    size_t i; //counter
    size_t j; //variable to hold random variable
    Card temp;  //define a temporary structure for swapping cards

    for(i = 0; i < CARDS; i++)  //loop through aDeck randomly swapping cards
    {

        j = rand() % CARDS;
        temp = aDeck[i];
        aDeck[i] = aDeck[j];
        aDeck[j] = temp;
    }
}//end shuffle function

void deal(const Card *const aDeck, Card *const aHand1, Card *const aHand2, Card *const aHand3, Card *const aHand4, Card *const aHand5, Card *const aHand6, Card *const aHand7, Card *const aHand8, Card *const aleftover)  //deal cards and determine winner
{

    int handValue1 = 0;  //declare variable to hold the value of the hand
    int handValue2 = 0;
    int handValue3 = 0;
    int handValue4 = 0;
    int handValue5 = 0;
    int handValue6 = 0;
    int handValue7 = 0;
    int handValue8 = 0;

    size_t i = 0;  // counters to loop through the cards and for each deck for each hand
    size_t j;
    size_t k;
    size_t l;
    size_t m;
    size_t n;
    size_t o;
    size_t p;
    size_t q;
    size_t t;


        while(i < CARDS)  //go through amount of CARDS
        {
            for(j = 0; j < HAND; j++) //loop through aDeck and assign to aHand1
            {
                aHand1[j].face = aDeck[i].face;
                aHand1[j].suit = aDeck[i].suit;
                aHand1[j].value = aDeck[i].value;
                handValue1 += aHand1[j].value;
                i++;
            }

            puts(""); //output line to screen

            for(k = 0; k < HAND; k++) //loop through aDeck assign to aHand2
            {
                aHand2[k].face = aDeck[i].face;
                aHand2[k].suit = aDeck[i].suit;
                aHand2[k].value = aDeck[i].value;
                handValue2 += aHand2[k].value;
                i++;
            }

            for(l = 0; l < HAND; l++) //loop through aDeck and assign values to aHand3
            {
                aHand3[l].face = aDeck[i].face;
                aHand3[l].suit = aDeck[i].suit;
                aHand3[l].value = aDeck[i].value;
                handValue3 += aHand3[l].value;
                i++;
            }

            for(m = 0; m < HAND; m++)  //loop through aDeck and assign values to aHand4
            {
                aHand4[m].face = aDeck[i].face;
                aHand4[m].suit = aDeck[i].suit;
                aHand4[m].value = aDeck[i].value;
                handValue4 += aHand4[m].value;
                i++;
            }

             for(n = 0; n < HAND; n++) //loop through aDeck and assign to aHand5
            {
                aHand5[n].face = aDeck[i].face;
                aHand5[n].suit = aDeck[i].suit;
                aHand5[n].value = aDeck[i].value;
                handValue5 += aHand5[n].value;
                i++;
            }

             for(o = 0; o < HAND; o++) //loop through aDeck and assign to aHand6
            {
                aHand1[o].face = aDeck[i].face;
                aHand1[o].suit = aDeck[i].suit;
                aHand1[o].value = aDeck[i].value;
                handValue6 += aHand6[j].value;
                i++;
            }

             for(p = 0; p < HAND; p++) //loop through aDeck and assign to aHand1
            {
                aHand7[p].face = aDeck[i].face;
                aHand7[p].suit = aDeck[i].suit;
                aHand7[p].value = aDeck[i].value;
                handValue7 += aHand7[p].value;
                i++;
            }

             for(q = 0; q < HAND; q++) //loop through aDeck and assign to aHand1
            {
                aHand8[q].face = aDeck[i].face;
                aHand8[q].suit = aDeck[i].suit;
                aHand8[q].value = aDeck[i].value;
                handValue8 += aHand8[q].value;
                i++;
            }
            for(t=0; t<4; t++)
            {
                aleftover[t].face = aDeck[i].face;
                aleftover[t].suit = aDeck[i].face;
                i++;
            }

        }
            //assign variable to identify a maxvalue of two hands at a time
        int *PtrhandValue1 = &handValue1;
        int *PtrhandValue2 = &handValue2;
        int *PtrhandValue3 = &handValue3;
        int *PtrhandValue4 = &handValue4;
        int *PtrhandValue5 = &handValue5;
        int *PtrhandValue6 = &handValue6;
        int *PtrhandValue7 = &handValue7;
        int *PtrhandValue8 = &handValue8;
        int values[] ={*PtrhandValue1,*PtrhandValue2, *PtrhandValue3, *PtrhandValue4, *PtrhandValue5, *PtrhandValue6, *PtrhandValue7, *PtrhandValue8};

 size_t s;
 int totalwinner = handValue1;

 for(s=0; s<8; ++s){
  if(totalwinner < values[i]){
    totalwinner = values[i];

  }
 }  //assign variable to determine overall winner of two maxvalues

    int randnum = 1+rand()%8;  //generate a random number between 1-4
    if (randnum % 8 != 0 && randnum % 8 != 7 && randnum % 8 != 6)  // determine if randnum is divisible by 4 to give 75% chance
    {
        if( totalwinner == handValue2){                 //determine what the winning hand is then swap that value to the value of hand1
                memcpy(temp , hand2,  sizeof(hand2));
                memcpy(hand2, hand1, sizeof(hand1));
                memcpy(hand1, temp, sizeof(temp));

        } else if (totalwinner == handValue3 ) {
                memcpy(temp , hand3,  sizeof(hand3));
                memcpy(hand3, hand1, sizeof(hand1));
                memcpy(hand1, temp, sizeof(temp));
        } else if(totalwinner == handValue3 ){
                memcpy(temp , hand3,  sizeof(hand3));
                memcpy(hand3, hand1, sizeof(hand1));
                memcpy(hand1, temp, sizeof(temp));
        } else if (totalwinner == handValue4){
                memcpy(temp , hand4,  sizeof(hand4));
                memcpy(hand4, hand1, sizeof(hand1));
                memcpy(hand1, temp, sizeof(temp));
        } else if (totalwinner == handValue5){
                memcpy(temp , hand5,  sizeof(hand5));
                memcpy(hand5, hand1, sizeof(hand1));
                memcpy(hand1, temp, sizeof(temp));
        } else if (totalwinner == handValue6){
                memcpy(temp , hand6,  sizeof(hand6));
                memcpy(hand6, hand1, sizeof(hand1));
                memcpy(hand1, temp, sizeof(temp));
        } else if (totalwinner == handValue7){
                memcpy(temp , hand7,  sizeof(hand7));
                memcpy(hand7, hand1, sizeof(hand1));
                memcpy(hand1, temp, sizeof(temp));
        } else if (totalwinner == handValue8){
                memcpy(temp , hand8,  sizeof(hand8));
                memcpy(hand8, hand1, sizeof(hand1));
                memcpy(hand1, temp, sizeof(temp));
        } else(printf(" "));
    }
            //if divisible by 4, leave hand values the same

            printf("Dealing cards to players");


        //loop through hands and print each hand
            printf("Player P(DEALER): \n");
                for(j=0; j< HAND; j++)
                {
                    printf("%5s of %-8s value: %d\n", aHand1[j].face, aHand1[j].suit, aHand1[j].value);
                    i++;
                }

            puts("");
            printf("Player Q: \n");
                for(k=0; k < HAND; k++ )
                {
                    printf("%5s of %-8s value: %d\n", aHand2[k].face, aHand2[k].suit, aHand2[k].value);
                    i++;
                }

             puts("");
             printf("Player R: \n");
                for(l = 0; l< HAND; l++)
                {
                    printf("%5s of %-8s value: %d\n", aHand3[l].face, aHand3[l].suit, aHand3[l].value);
                    i++;
                }
            puts("");
            printf("Players S: \n");
                for(m=0; m< HAND; m++)
                {
                    printf("%5s of %-8s value: %d \n", aHand4[m].face, aHand4[m].suit, aHand4[m].value);
                    i++;
                }
             puts("");
             printf("Player T: \n");
                for(n = 0; n< HAND; n++)
                {
                    printf("%5s of %-8s value: %d\n", aHand5[n].face, aHand5[n].suit, aHand5[n].value);
                    i++;
                }
            puts("");
            printf("Players U: \n");
                for(o=0; o< HAND; o++)
                {
                    printf("%5s of %-8s value: %d \n", aHand6[o].face, aHand6[o].suit, aHand6[o].value);
                    i++;
                }
            puts("");
            printf("Players V: \n");
                for(p=0; p< HAND; p++)
                {
                    printf("%5s of %-8s value: %d \n", aHand7[p].face, aHand7[p].suit, aHand7[p].value);
                    i++;
                }
            puts("");
            printf("Players W: \n");
                for(q=0; q< HAND; q++)
                {
                    printf("%5s of %-8s value: %d \n", aHand8[q].face, aHand8[q].suit, aHand8[q].value);
                    i++;
                }
            puts("");
            printf("Cards leftover: \n");
                for(t=0; t<4; ++t)
                {
                    printf("%5s of %-8s \n", aleftover[t].face, aleftover[t].suit);
                    i++;
                }



    printf("Winning value: %d ", totalwinner);  //print the value of the winning hand

}//end deal function
