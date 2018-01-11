#include <stdio.h>
#include <stdlib.h>
char matrix[3][3];
char smbfua;
char smbfub;

void at_the_first() //To initialize matrix with all Zeors
{
    int r=0,t=0;
    for(r;r<3;r++)
    {
        t=0;
        for(t;t<3;t++)
        {
            matrix[r][t]='0';
        }
    }
} //End of ititializeing matrix with all Zeros

void getusersymbol()   //To Get the symbol for both the users
{
    printf("\nEnter the symbol for first user:");
    scanf(" %c",&smbfua);
    printf("\nEnte the symbol for second user:");
    scanf(" %c",&smbfub);
    if(smbfua==smbfub)
    {
        printf("\nYour both symbols are same please try again");
        getusersymbol();
    }
} //End of getting the symbol 

void getinput(int user)  //To getting the index number at which they wants to insert
{                        //And then insert that.
    int a,b;             //This process will be called each time whenever gamer insert the symbol.
    if(user==1)
    {
         printf("\nUser 'A' [%c] enter the index number:",smbfua);
    }
    else
    {
         printf("\nUser 'B' [%c] enter the index number:",smbfub);
    }
    scanf("%d",&a);
    scanf("%d",&b);
    if(a>2 || b>2)
    {
        printf("\nWrong input..!!! Try again: ");
        getinput(user);
    }
    if(matrix[a][b]==smbfua || matrix[a][b]==smbfub)
    {
        printf("\nWrong index...!!!! Try agrain: ");
        getinput(user);

    }
    else{
         if(user==1)
         {
            matrix[a][b]=smbfua;
         }
         else if(user==2)
         {
            matrix[a][b]=smbfub;
         }
    }
} //End of getting symbol.

int check() //To check each time where either of them is won? or not.
{
    int toreturn;
    if(matrix[0][0]==smbfua && matrix[1][1]==smbfua && matrix[2][2]==smbfua) //case 1
      {
          toreturn=1;
          return(toreturn);
      }
    else if(matrix[0][0]==smbfub && matrix[1][1]==smbfub && matrix[2][2]==smbfub) //case 1
      {
          toreturn=2;
          return(toreturn);
      }
    else if(matrix[0][2]==smbfua && matrix[1][1]==smbfua && matrix[2][0]==smbfua) //case 2
      {
          toreturn=1;
          return(toreturn);
      }
    else if(matrix[0][2]==smbfub && matrix[1][1]==smbfub && matrix[2][0]==smbfub) //case 2
      {
          toreturn=2;
          return(toreturn);
      }
    else if(matrix[0][0]==smbfua && matrix[0][1]==smbfua && matrix[0][2]==smbfua) //case 3
      {
          toreturn=1;
          return(toreturn);
      }
    else if(matrix[0][0]==smbfub && matrix[0][1]==smbfub && matrix[0][2]==smbfub) //case 3
      {
          toreturn=2;
          return(toreturn);
      }
    else if(matrix[0][2]==smbfua && matrix[1][2]==smbfua && matrix[2][2]==smbfua) //case 4
      {
          toreturn=1;
          return(toreturn);
      }
    else if(matrix[0][2]==smbfub && matrix[1][2]==smbfub && matrix[2][2]==smbfub) //case 4
      {
          toreturn=2;
          return(toreturn);
      }
    else if(matrix[2][0]==smbfua && matrix[2][1]==smbfua && matrix[2][2]==smbfua) //case 5
      {
          toreturn=1;
          return(toreturn);
      }
    else if(matrix[2][0]==smbfub && matrix[2][1]==smbfub && matrix[2][2]==smbfub) //case 5
      {
          toreturn=2;
          return(toreturn);
      }
    else if(matrix[0][0]==smbfua && matrix[1][0]==smbfua && matrix[2][0]==smbfua) //case 6
      {
          toreturn=1;
          return(toreturn);
      }
    else if(matrix[0][0]==smbfub && matrix[1][0]==smbfub && matrix[2][0]==smbfub) //case 6
      {
          toreturn=2;
          return(toreturn);
      }
    else if(matrix[0][1]==smbfua && matrix[1][1]==smbfua && matrix[2][1]==smbfua) //case 7
      {
          toreturn=1;
          return(toreturn);
      }
    else if(matrix[0][1]==smbfub && matrix[1][1]==smbfub && matrix[2][1]==smbfub) //case 7
      {
          toreturn=2;
          return(toreturn);
      }
    else
    {
        return(0);
    }
} //End of checking for winner.

void printmatrix()  //To print the matrix each time after they insert their symbol.
{
    printf("\nThe Game condition is:\n");
    int w=0;
    int e=0;
    for(w;w<3;w++)
    {
        e=0;
        for(e;e<3;e++)
        {
            printf(" %c  ",matrix[w][e]);
        }
        printf("\n");
    }
} //End of printing the new matrix.

int main()
{
    int p=0;
    int user=1;
    at_the_first();    //To initialize wole matrix with Zeros.
    getusersymbol();   //To getting the Symbols for users.
    printmatrix();     //To print the initial condition of matrix.
   
    int i;
    
    for(p;p<=9;p++)   //To get the inputs 
    {
        if(p==9)
          {
              printf("\nNither 'A' won nor 'B' won...!!!!");
              break;
          }

        if(user==1)
            {
                getinput(user);
                user=2;
            }
        else
            {
                getinput(user);
                user=1;
            }
        printmatrix();

    i=check();
    if(i)   //To check either of them is won or non, if wins then print and break the loop.
    {
        if(i==1)
           {
               printf("\nGamer 'A' simbol=%c WON..!!!",smbfua);
               break;
           }
        else
           {
               printf("\nGamer 'B' simbol=%c WON..!!!",smbfub);
               break;
           }
    }
    
    }
    return 0;
}

