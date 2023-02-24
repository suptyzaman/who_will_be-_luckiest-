#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
char FirstName[30],LastName[30], UserName[30];
int score = 0, earn =0, fifty=1, dip=1, flip =1,level =1;;
char Q[30] ,option[4][30],ans[2];


COORD coord = {0, 0};
void gotoxy (int x, int y)
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



// to choose random option to give 50/50 chance
unsigned int randRange( int ans)
{   unsigned int res = 1 + (rand() % 4);
    if(res == ans){
        randRange(ans);
    }
    else  return (res);
}


//welcome screen
void welcome(){
    system("cls");

    gotoxy(28,3);
    printf("Welcome to the game");
    gotoxy(17,4);
    printf("*************************************************\n");
    gotoxy(26,6);
    printf("Who will be the luckiest");
    gotoxy(24,28);
    printf("Print Any Key to continue....");
    getch();
    login();//call the login function
    return;


}

//login system
void login(){
    system("cls");

    gotoxy(25,7);
    printf("Enter Firstname: ");
    gets(FirstName);
    gotoxy(25,8);
    printf("Enter lastname: ");
    gets(LastName);
    gotoxy(25,9);
    menu();//call the menu function
    return;
}

//menu
void menu(){
    system("cls");

    gotoxy(22,3);
    printf("Who will be the luckiest?");

    gotoxy(22,6);
    printf("Hey %s %s lets play ",FirstName,LastName);
    gotoxy(23,8);
    printf("1. Start Game");
    gotoxy(23,10);
    printf("2. Exit game");


    gotoxy(22, 25);
    printf("Enter menu number: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        level1();
    }
    else if(choice==2){
        exit(0);
    }
    else{
        gotoxy(22,28);
        printf("You have entered wrong key, try again");
        getch();
        menu();
        return;
    }
    return;


}

//to remove _ underscore from txt
void filter(){
    for(int i = 0; i < strlen(Q); i++){
            if(Q[i] == '_')
                Q[i] = ' ';
    }
    for (int j = 0; j<4; j++){
        for(int i = 0; i < strlen(option[j]); i++){
                if(option[j][i] == '_')
                    option[j][i] = ' ';
        }
    }


    return ;

}


//game playing section
void level1(){

    int solved = 0;
    FILE *qlist = fopen("test.txt","r+");
    for(int i=0; i<5;i++){
        system("cls");

        gotoxy(20,6);
        printf("You are in level 1, solve 3 out of 5 for next level");
        gotoxy(22,8);
        printf("You have solved %d",solved);
        gotoxy(22,32);
        printf("%d Flip %d Doubledip %d 50/50 chance remaining",flip,dip,fifty);

        fscanf(qlist,"%s %s %s %s %s %s",Q,option[0],option[1],option[2],option[3],ans);
        filter();
        gotoxy(22,12);
        printf("Q%d. %s",i+1,Q);
        gotoxy(22,13);
        printf("%s \t \t %s",option[0],option[1]);
        gotoxy(22,14);
        printf("%s \t \t %s",option[2],option[3]);
        if (flip!=0){
            gotoxy(22,33);
            printf("Enter f to flip the question.");
        }
        if (fifty!=0){
            gotoxy(22,34);
            printf("Enter 50 to get a 50/50 chance.");
        }
        gotoxy(22,16);
        printf("Enter ans: ");
        char c[2];
        scanf("%s",c);
        if (strcmp(c,ans)==0){
            solved++;
            score+=3000;
            gotoxy(22,18);
            printf("Congratulation you have solved");
            getch();
        }
        else if(strcmp(c,"f")==0){
            if(flip!=0){
                i--;
                flip--;
                gotoxy(22,19);
                printf("You have skipped this question");
                getch();
            }
            else {
                gotoxy(22,18);
                printf("Try hard");
                getch();
            }
        }
        else if(strcmp(c,"50")==0){
            if(fifty!=0){
                solved= solved+fiftyfifty(i,3000);
            }
            else {
                gotoxy(22,18);
                printf("you have already used this chance. Try hard");
                getch();
            }
        }
        else{
            gotoxy(22,18);
            printf("Try hard");
            if(dip!=0){
                gotoxy(22,19);
                printf("Do you want to use double dip life line (y/n)? ");
                char a[2];
                scanf("%s",a);
                if (strcmp(a,"y")==0 || strcmp(a,"Y")==0){
                    doubledip(&solved,i,3000);
                }
            }
            getch();
        }

    }
    // earn+=3000*score;
    fclose(qlist);
    if(solved >=3){
        level2();
        return;
    }
    else{
        system("cls");

        gotoxy(22,6);
        printf("Game Over");
        gotoxy(22,10);
        printf("your score is  %d ", score);



    }
}

void level2(){
    int solved = 0;
    FILE *qlist = fopen("test.txt","r+");
    for(int i=0; i<7;i++){
        system("cls");

        gotoxy(20,6);
        printf("You are in level 2, solve 5 out of 7 for next level");
        gotoxy(22,8);
        printf("You have solved %d",solved);
        gotoxy(22,32);
        printf("%d Flip %d Doubledip %d 50/50 chance remaining",flip,dip,fifty);

        fscanf(qlist,"%s %s %s %s %s %s",Q,option[0],option[1],option[2],option[3],ans);
        filter();
        gotoxy(22,12);
        printf("Q%d. %s",i+1,Q);
        gotoxy(22,13);
        printf("%s \t \t %s",option[0],option[1]);
        gotoxy(22,14);
        printf("%s \t \t %s",option[2],option[3]);
        if (flip!=0){
            gotoxy(22,33);
            printf("Enter f to flip the question.");
        }
        if (fifty!=0){
            gotoxy(22,34);
            printf("Enter 50 to get a 50/50 chance.");
        }
        gotoxy(22,16);
        printf("Enter ans: ");
        char c[2];
        scanf("%s",c);
        if (strcmp(c,ans)==0){
            solved++;
            score+=5000;
            gotoxy(22,18);
            printf("Congratulation you have solved");
            getch();
        }
        else if(strcmp(c,"f")==0){
            if(flip!=0){
                i--;
                flip--;
                gotoxy(22,19);
                printf("You have skipped this question");
                getch();
            }
            else {
                gotoxy(22,18);
                printf("you have already used this chance. Try hard");
                getch();
            }
        }
        else if(strcmp(c,"50")==0){
            if(fifty!=0){
                solved= solved+fiftyfifty(i,5000);
            }
            else {
                gotoxy(22,18);
                printf("you have already used this chance. Try hard");
                getch();
            }

        }
        else{
            gotoxy(22,18);
            printf("Try hard");
            if(dip!=0){
                gotoxy(22,19);
                printf("Do you want to use double dip life line (y/n)? ");
                char a[2];
                scanf("%s",a);
                if (strcmp(a,"y")==0 || strcmp(a,"Y")==0){
                    doubledip(&solved,i,5000);
                }
            }
            getch();
        }

    }
    fclose(qlist);
    if(solved >=5){
        level3();
        return;
    }
    else{
        system("cls");
        gotoxy(22,6);
        printf("Game Over");
        gotoxy(22,10);
        printf("your score is  %d ", score);

    }
    return;
}


void level3(){
    int solved = 0;
    FILE *qlist = fopen("test.txt","r+");
    for(int i=0; i<8;i++){
        system("cls");

        gotoxy(20,6);
        printf("You are in final level");
        gotoxy(22,8);
        printf("You have solved %d",solved);
        gotoxy(22,32);
        printf("%d Flip %d Doubledip %d 50/50 chance remaining",flip,dip,fifty);

        fscanf(qlist,"%s %s %s %s %s %s",Q,option[0],option[1],option[2],option[3],ans);
        filter();
        gotoxy(22,12);
        printf("Q%d. %s",i+1,Q);
        gotoxy(22,13);
        printf("%s \t \t %s",option[0],option[1]);
        gotoxy(22,14);
        printf("%s \t \t %s",option[2],option[3]);
        if (flip!=0){
            gotoxy(22,33);
            printf("Enter f to flip the question.");
        }
        if (fifty!=0){
            gotoxy(22,34);
            printf("Enter 50 to get a 50/50 chance.");
        }
        gotoxy(22,16);
        printf("Enter ans: ");
        char c[2];
        scanf("%s",c);
        if (strcmp(c,ans)==0){
            solved++;
            score+=10000;
            gotoxy(22,18);
            printf("Congratulation you have solved");
            getch();
        }
        else if(strcmp(c,"f")==0){
            if(flip!=0){
                i--;
                flip--;
                gotoxy(22,19);
                printf("You have skipped this question");
                getch();
            }
            else {
                gotoxy(22,18);
                printf("Try hard");
                getch();
            }
        }
        else if(strcmp(c,"50")==0){
            if(fifty!=0){
                solved= solved+fiftyfifty(i,10000);
            }
            else {
                gotoxy(22,18);
                printf("you have already used this chance. Try hard");
                getch();
            }
        }
        else{
            gotoxy(22,18);
            printf("Try hard");
            if(dip!=0){
                gotoxy(22,19);
                printf("Do you want to use double dip life line (y/n)? ");
                char a[2];
                scanf("%s",a);
                if (strcmp(a,"y")==0 || strcmp(a,"Y")==0){
                    doubledip(&solved,i,10000);
                }
            }
            getch();
        }

    }
    fclose(qlist);
    if(score >=100000){
        winner();

        return;
    }
    else{
        system("cls");

        gotoxy(22,6);
        printf("Game Over");
        gotoxy(22,10);
        printf("your score is  %d ",score);



    }
    return;
}

void winner(){
    system("cls");


    gotoxy(3,5);
    printf("   _____                            _         _       _   _              ");
    gotoxy(3,6);
    printf("  / ____|                          | |       | |     | | (_)             ");
    gotoxy(3,7);
    printf(" | |     ___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_ _  ___  _ __   ");
    gotoxy(3,8);
    printf(" | |    / _ \\| '_ \\ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \\| '_ \\  ");
    gotoxy(3,9);
    printf(" | |___| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | | ");
    gotoxy(3,10);
    printf("  \\_____\\___/|_| |_|\\__, |_|  \\__,_|\\__|\\__,_|_|\\__,_|\\__|_|\\___/|_| |_| ");
    gotoxy(3,11);
    printf("                     __/ |                                               ");
    gotoxy(3,12);
    printf("                    |___/                                                ");


    //https://patorjk.com/software/taag/#p=display&h=0&f=Ogre&t=Winner
    gotoxy(20,15);
    printf(" __    __  _                           ");
    gotoxy(20,16);
    printf("/ / /\\ \\ \\(_) _ __   _ __    ___  _ __ ");
    gotoxy(20,17);
    printf("\\ \\/  \\/ /| || '_ \\ | '_ \\  / _ \\| '__|");
    gotoxy(20,18);
    printf(" \\  /\\  / | || | | || | | ||  __/| |   ");
    gotoxy(20,19);
    printf("  \\/  \\/  |_||_| |_||_| |_| \\___||_|   ");

    gotoxy(22,22);
    printf("Your score is %d",score);
    return;


}

// lifelines
int fiftyfifty(int i,int point){
        int slv =0;
        int randomOptn,n=0;

        for (int j=0;j<4;j++){
            //to chose currect ans number

            if (option[j][0] == ans[0]){ // i have used == becuse option[j][0] returns only ascii integer
                n=j+1;
                break;
            }

        }
        randomOptn = randRange(n);


        for (int j=0;j<4;j++){
            //to remove options except random and currect

            if(j!=n-1 &&j!= randomOptn-1){
                strcpy(option[j],"");
            }
        }

        system("cls");

        gotoxy(20,6);
        printf("Fifty Fifty chance for you. Don't miss.");
        // gotoxy(22,8);
        // printf("You have solved %d",*sd);

        gotoxy(22,9);
        printf("%d Flip %d Doubledip %d 50/50 chance remaining",flip,dip,fifty);
        gotoxy(22,12);
        printf("Q%d. %s",i+1,Q);
        gotoxy(22,13);
        printf("%s \t \t %s",option[0],option[1]);
        gotoxy(22,14);
        printf("%s \t \t %s",option[2],option[3]);
        gotoxy(22,16);
        printf("Enter ans: ");
        char c[2];
        scanf("%s",c);
        if (strcmp(c,ans)==0){
            slv++;
            score+=point;
            gotoxy(22,18);
            printf("Congratulation you have solved");
            getch();
        }
        else{
            gotoxy(22,18);
            printf("Try hard, you have missed the chance");
            getch();
        }
        fifty--;
        return slv;



}

void doubledip(int *slv,int i,int point)
{
        system("cls");

        gotoxy(20,6);
        printf("Double dip chance");
        gotoxy(22,8);
        printf("You have solved %d",*slv);
        gotoxy(22,9);
        printf("%d Flip %d Doubledip %d 50/50 chance remaining",flip,dip,fifty);
        gotoxy(22,12);
        printf("Q%d. %s",i+1,Q);
        gotoxy(22,13);
        printf("%s \t \t %s",option[0],option[1]);
        gotoxy(22,14);
        printf("%s \t \t %s",option[2],option[3]);
        gotoxy(22,16);
        printf("Enter ans: ");
        char c[2];
        scanf("%s",c);
        if (strcmp(c,ans)==0){
            ++*slv;
            score+=point;
            gotoxy(22,18);
            printf("Congratulation you have solved");
            getch();
        }
        else{
            gotoxy(22,18);
            printf("Try hard, you have missed the chance");
            getch();
        }
        dip--;
}


int main()
{
    welcome();
    getch();
    return 0;
}
