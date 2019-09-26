#include <stdio.h>
#include <stdlib.h>

int inputCheck(char charChoose,int intChoose,int intNum);
int ConditionSelect(int intvalue);

int main()
{
    int intvalue; //catch the returning value of function <inputCheck>
    int intVerify; //catch the returning value of function <conditionSelect>
    int intReplay;

    char charChoose;
    int intChoose=0;
    int intNum; //validity limitation of inputCheck function

    printf("------------------------GUESSING GAME------------------------\n\n");

    printf("Here we have 8 hints !\n You have only 3 chances to answer...\n Choose a number between 1 - 8 to play : ");
    scanf("%s",&charChoose);

    intChoose = charChoose - '0';  //convert char to int
    intNum = 8; //there are 8 clues (So the limit is 8)


    intvalue = inputCheck(charChoose,intChoose,intNum);
    intVerify = ConditionSelect(intvalue);

    /* ---------------- Play again or exit ----------------*/

    while(intVerify == 1){

        printf("\nWanna play again !\n\t -----ENTER 1 FOR PLAY AGAIN | ENTER 2 FOR EXIT-----\n : ");
        scanf("%s",&charChoose);

        intChoose = charChoose - '0';
        intNum = 2; //only can input 1 or 2 (So the limit is 2)
        intvalue = inputCheck(charChoose,intChoose,intNum);

        if(intvalue==1){
            printf("Here we have 8 hints !\n You have only 3 chances to answer...\n Choose a number between 1 - 8 to play : ");
            scanf("%s",&charChoose);

            intChoose = charChoose - '0'; //convert char to int
            intNum = 8; //there are 8 clues (So the limit is 8)

            intvalue = inputCheck(charChoose,intChoose,intNum);
            intVerify = ConditionSelect(intvalue);

            }else{
                intVerify = 0; //stop the loop and end the game
            } //end if

    } //end while

    return 0;
}



int inputCheck(char charChoose,int intChoose,int intNum){

    int intLoop =0;


    while(intLoop==0){

        //check weather the input is character or in between the corresponding values
        if(isdigit(charChoose) && intChoose>0 && intChoose<(intNum+=1)){
            intLoop=1;

        }else{
            printf("----Invalid input!---- \n Please input number between 1 - %d \n\n",intNum);

            printf("Choose a number between 1 - %d to play : ",intNum);
            scanf("%s",&charChoose);

            intChoose = charChoose - '0';
        } //end if

    } //end while



    return intChoose; //return the int value of input(1 - 8)
}




int ConditionSelect(int intvalue){

    char charAnswer[100]; //store the answer
    int intCount = 1;
    int sml = 1; //smile face
    int intVerify = 0; //return the final status of game

    switch(intvalue){
    case 1 :
        printf("\n----Clue No. 01 :\n");
        printf("\t I am a home for royalty. \n\t There are many of me in England.\n\t I am made of stone. \n\t I am protected by a ring of water. \n\t I'm found in many legends. \n\t WHO AM I? ");
        break;
    case 2 :
        printf("\n----Clue No. 02 :\n");
        printf("\t I use a long track. \n\t I transport heavy loads.\n\t Many tourists use me. \n\t Watch for lights to stop for me. \n\t I will show you beautiful scenery \n\t WHO AM I? ");
        break;
    case 3 :
        printf("\n----Clue No. 03 :\n");
        printf("\t Please blow air in me. \n\t I come in many colours. \n\t I'm a symbol of celebration. \n\t Don't touch me with anything sharp. \n\t I only last a day or two \n\t WHO AM I? ");
        break;
    case 4 :
        printf("\n----Clue No. 04 :\n");
        printf("\t I am associated with Spring. \n\t I love to hop in the grass. \n\t I play in your vegetable garden. \n\t My teeth are long and sharp. \n\t I am soft to pet \n\t WHO AM I?");
        break;
    case 5 :
        printf("\n----Clue No. 05 :\n");
        printf("\t I am multi-coloured. \n\t I appear after a storm. \n\t People always point at me. \n\t Everyone takes my picture. \n\t Legend says there is gold at the bottom of me \n\t WHO AM I? ");
        break;
    case 6 :
        printf("\n----Clue No. 06 :\n");
        printf("\t I live in the jungle. \n\t I love to eat bananas. \n\t I'm very similar to a human. \n\t I'm a curious creature. \n\t I have a long curly tail. \n\t WHO AM I?");
        break;
    case 7 :
        printf("\n----Clue No. 07 :\n");
        printf("\t I'll keep your hair dry. \n\t Bring me just in case. \n\t I'm long and light to carry. \n\t Don't open me in the house. \n\t I hope you don't need me today \n\t WHO AM I?");
        break;
    case 8 :
        printf("\n----Clue No. 08 :\n");
        printf("\t I am popular for winter sports. \n\t I can be very dangerous. \n\t You can go up or down me. \n\t I get colder as you go higher. \n\t Don't forget your safety gear \n\t WHO AM I?");
        break;

    }

    scanf("%s",&charAnswer);

    //Loop for  3 chances
    while(intCount < 4){

        switch(intvalue){
        case 1 :
            //Answer check
            if(strcmp(strlwr(charAnswer) , "castle")==0 ){
                printf("\n\tCorrect Answer!%c\n\n",sml);
                intCount = 4;
                intVerify = 1;
            }else{
                //incorrect answer loop
                if((3-intCount) != 0 ){
                    printf("\nYour answer is Incorrect! \n try again ( %d chance(s) remaining ) :",(3-intCount));
                    scanf("%s",&charAnswer);
                }else{
                    printf("\nBad luck! incorrect answer\n Correct answer is CASTLE!\n ");
                    intVerify = 1;
                } //end if

            } //end if
            break;
        case 2 :
            //Answer check
            if(strcmp(strlwr(charAnswer) , "train")==0 ){
                printf("\n\tCorrect Answer!%c\n\n",sml);
                intCount = 4;
                intVerify = 1;
            }else{
                //incorrect answer loop
                if((3-intCount) != 0 ){
                    printf("\nYour answer is Incorrect! \n try again ( %d chance(s) remaining ) :",(3-intCount));
                    scanf("%s",&charAnswer);
                }else{
                    printf("\nBad luck! incorrect answer\n Correct answer is TRAIN!\n ");
                    intVerify = 1;
                } //end if
            } //end if
            break;
        case 3 :
            //Answer check
            if(strcmp(strlwr(charAnswer) , "balloon")==0 ){
                printf("\n\tCorrect Answer!%c\n\n",sml);
                intCount = 4;
                intVerify = 1;
            }else{
                //incorrect answer loop
                if((3-intCount) != 0 ){
                    printf("\nYour answer is Incorrect! \n try again ( %d chance(s) remaining ) :",(3-intCount));
                    scanf("%s",&charAnswer);
                }else{
                    printf("\nBad luck! incorrect answer\n Correct answer is BALLOON!\n ");
                    intVerify = 1;
                } //end if
            } //end if
            break;
        case 4 :
            //Answer check
            if(strcmp(strlwr(charAnswer) , "rabbit")==0 ){
                printf("\n\tCorrect Answer!%c\n\n",sml);
                intCount = 4;
                intVerify = 1;
            }else{
                //incorrect answer loop
                if((3-intCount) != 0 ){
                    printf("\nYour answer is Incorrect! \n try again ( %d chance(s) remaining ) :",(3-intCount));
                    scanf("%s",&charAnswer);
                }else{
                    printf("\nBad luck! incorrect answer\n Correct answer is RABBIT!\n ");
                    intVerify = 1;
                } //end if
            } //end if
            break;
        case 5 :
            //Answer check
            if(strcmp(strlwr(charAnswer) , "rainbow")==0 ){
                printf("\n\tCorrect Answer!%c\n\n",sml);
                intCount = 4;
                intVerify = 1;
            }else{
                //incorrect answer loop
                if((3-intCount) != 0 ){
                    printf("\nYour answer is Incorrect! \n try again ( %d chance(s) remaining ) :",(3-intCount));
                    scanf("%s",&charAnswer);
                }else{
                    printf("\nBad luck! incorrect answer\n Correct answer is RAINBOW!\n ");
                    intVerify = 1;
                } //end if
            } //end if
            break;
        case 6 :
            //Answer check
            if(strcmp(strlwr(charAnswer) , "monkey")==0 ){
                printf("\n\tCorrect Answer!%c\n\n",sml);
                intCount = 4;
                intVerify = 1;
            }else{
                //incorrect answer loop
                if((3-intCount) != 0 ){
                    printf("\nYour answer is Incorrect! \n try again ( %d chance(s) remaining ) :",(3-intCount));
                    scanf("%s",&charAnswer);
                }else{
                    printf("\nBad luck! incorrect answer\n Correct answer is MONKEY!\n ");
                    intVerify = 1;
                } //end if
            } //end if
            break;
        case 7 :
            //Answer check
            if(strcmp(strlwr(charAnswer) , "umbrella")==0 ){
                printf("\n\tCorrect Answer!%c\n\n",sml);
                intCount = 4;
                intVerify = 1;
            }else{
                //incorrect answer loop
                if((3-intCount) != 0 ){
                    printf("\nYour answer is Incorrect! \n try again ( %d chance(s) remaining ) :",(3-intCount));
                    scanf("%s",&charAnswer);
                }else{
                    printf("\nBad luck! incorrect answer\n Correct answer is UMBRELLA!\n ");
                    intVerify = 1;
                } //end if
            } //end if
            break;
        case 8 :
            //Answer check
            if(strcmp(strlwr(charAnswer) , "mountain")==0 ){
                printf("\n\tCorrect Answer!%c\n\n",sml);
                intCount = 4;
                intVerify = 1;
            }else{
                //incorrect answer loop
                if((3-intCount) != 0 ){
                    printf("\nYour answer is Incorrect! \n try again ( %d chance(s) remaining ) :",(3-intCount));
                    scanf("%s",&charAnswer);
                }else{
                    printf("\nBad luck! incorrect answer\n Correct answer is MOUNTAIN!\n ");
                    intVerify = 1;
                } //end if
            } //end if
            break;


        }

        intCount++; //count of chances
    } //end while

    return intVerify; //if the answer is correct then this returns 1 otherwise it returns 0

}





