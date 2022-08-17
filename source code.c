#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

int CalcGCD(int alpha)
{
 int x;
   int temp1=alpha;
   int temp2=26;

     while(temp2!=0)
      {
        x=temp2;
        temp2=temp1%temp2;
        temp1=x;
      }
     return(temp1);
}
int GetMultiplicativeInverse(int alpha)
{
    int i,MI;
 for(i=1;i<=alpha;i++)
 {
  MI=((i*26)+1);
  if(MI%alpha==0)
  {
   break;
  }
 }
 MI=MI/alpha;
 return(MI);
}

main()
{
    system("color 8f");
    int x, e,d;
    menu:
    printf("Enter your choice : \n\n1.Encryption\n\n2.Decryption\n\n3. Exit the Program\n");
    scanf("%d",&x);

    if(x==1)
    {
        printf("Enter your choice : \n\n1.Affine Cypher\n2.Pollybius Algorithm\n3.Scytale Cipher\n4.File encryption\n5.One time pad cipher\n");
        scanf("%d",&e);
        getchar();
        switch(e)
        {
        case 1:
            {
                int i,j,k,gcd,alpha,beta,numstr[100],numcipher[100];
 char str[100],cipher[100];
 printf("\nEnter a string\n");
 gets(str);
 //converting entered string to Capital letters
 for(i=0,j=0;i<strlen(str);i++)
 {
  if(str[i]!=' ')
  {
   str[j]=toupper(str[i]);
   j++;
  }
  else
  {
   str[j]=' ';
   j++;
  }
 }
 str[j]='\0';
 printf("Entered string is : %s \n",str);
 printf("Enter Alpha value and must be between 1 and 25 both included\n");
 scanf("%d",&alpha);
 getchar();
 //Checking consitions
 if(alpha<1 || alpha>25)
 {
  printf("Alpha should lie in between 1 and 25\nSorry Try again !\n");
  exit(0);
 }
 gcd=CalcGCD(alpha);
 if(gcd!=1)
 {
  printf("gcd(alpha,26)=1 but \n gcd(%d,26)=%d\nSorry Try again !\n",alpha,gcd);
  exit(0);
 }
 printf("Enter Beta value and must be between 0 and 25 both included\n");
 scanf("%d",&beta);
 if(beta<0 || beta>25)
 {
  printf("Beta value should lie between 0 and 25\nSorry Try again !\n");
  exit(0);
 }
 //Conditions Over
 //Program Starts
 //Storing string in terms of ascii and to restore spaces I used -20
 for(i=0;i<strlen(str);i++)
 {
  if(str[i]!=' ')
  numstr[i]=str[i]-'A';
  else
  numstr[i]=-20;
 }
 //Ciphering Process
    //If numcipher is more than 25 .We need to convert and ensure that lie in between 0 and 25.(indicating Alphabets)
    //A-0,B-1,C-2,.....Y-24,Z-25
    printf("Affine Cipher text is\n");
    for(i=0;i<strlen(str);i++)
    {
     if(numstr[i]!=-20)
     {
     numcipher[i]=((alpha*numstr[i])+beta)%26;
          printf("%c",(numcipher[i]+'A'));
     }
     else
     {
          printf(" ");
     }
    }
printf("\n");

goto menu;
        }

        case 2:
            {
                int i,j,poly[26],x,k;
 char str[1000];
 printf("Enter a sentence\n");
 gets(str);
i=0;
 while(str[i]!='\0')
 {
  if((str[i]>=0&&str[i]<=31)||(str[i]>=33&&str[i]<65)||(str[i]>90&&str[i]<97)||(str[i]>122&&str[i]<=127))
  {
   printf("Enter only alphabets and space\n");
   exit(0);
  }
  i++;
 }
 x=0;
 k=11;
 //Assigning Polybius Square numbers to alphabets

for(i=0;i<=25;i++)
{
 if(i<=8)
 {
      if(i%5==0&&i!=0)
   {
  k+=5;
  poly[x]=k++;

    }
   else{
  poly[x]=k++;

      }
 }
 if(i>=10)
 {
      if(i%5==0&&i!=0)
   {

  poly[x]=k++;
   k+=5;

    }
   else{
  poly[x]=k++;

      }
 }
 if(i==9)
 {
  poly[x]=24;
 }


  x++;
}
i=0;
printf("Encrypted Code using Polybius Square Cipher \n");
while(str[i]!='\0')
  {
 if(!((str[i]>=0&&str[i]<=31)||(str[i]>=33&&str[i]<65)||(str[i]>90&&str[i]<97)||(str[i]>122&&str[i]<=127)))
 {
   if(str[i]>='A'&&str[i]<='Z')
   {
    printf("%d ",poly[str[i]-'A']);
   }
     if(str[i]>='a'&&str[i]<='z')
     {
      printf("%d ",poly[str[i]-'a']);
     }

 }

    if(str[i]==' ')
    {
      printf("%c",str[i]);
    }

   i++;
  }
  printf("\n");
goto menu;

}
    case 3:
        {
            int i,j,k,len,turns,code[100][1000],col;
    char str[1000];
    printf("Enter a Secret Message\n");
    gets(str);
    len=strlen(str);
 printf("Enter number of turns on band\n");
 scanf("%d",&turns);
 k=0;
 //initializing code to zero
 for(i=0;i<len;)
 {
  for(j=0;j<turns;j++)
  {
   code[k][j]=0;
   i++;
  }
  k++;
 }
 k=0;
 //storing messages in code according to turns on band
for(i=0;i<len;)
{
  if(str[i]!=' ')
  {
 for(j=0;j<turns;)
 {
  if(i<=len)
  {
    if(str[i]!=' ')//to avoid spaces in between words
    {
            code[k][j]=(int)str[i];
      i++;
   j++;
      }
      else
      {
       i++;
      }

  }
  else
  {
   break;
  }

 }
 k++;
  }
  else
  {
   i++;
  }
}
printf("The encrypted message is\n");
//printing encrypted message which is column wise
col=k;
for(i=0;i<turns;i++)
{
 for(j=0;j<col;j++)
 {
     if(code[j][i]!=0)
  printf("%c",code[j][i]);

 }
}
printf("\n");
goto menu;
}
    case 4:
        {
            char fname[20], ch, choice;
	FILE *fps, *fpt;
	printf("Enter file name (with extension like file.txt) to encrypt : ");
	gets(fname);
	fps=fopen(fname, "r");
	if(fps==NULL)
	{
		printf("Error in opening file..!!");
		printf("\nPress any key to exit...");
		////getch();
		exit(1);
	}
	fpt=fopen("temp.txt", "w");
	if(fpt==NULL)
	{
		printf("Error in creating temp.txt file..!!");
		fclose(fps);
		printf("\nPress any key to exit...");
		////getch();
		exit(2);
	}
	while(1)
	{
		ch=fgetc(fps);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			ch=ch+100;
			fputc(ch, fpt);
		}
	}
	fclose(fps);
	fclose(fpt);
	fps=fopen(fname, "w");
	if(fps==NULL)
	{
		printf("Error in opening source file..!!");
		printf("\nPress any key to exit...");
		//getch();
		exit(3);
	}
	fpt=fopen("temp.txt", "r");
	if(fpt==NULL)
	{
		printf("Error in opening temp.txt file...!!");
		fclose(fps);
		printf("\nPress any key to exit...");
		//getch();
		exit(4);
	}
	while(1)
	{
		ch=fgetc(fpt);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			fputc(ch, fps);
		}
	}
	printf("File %s encrypted successfully..!!", fname);
	printf("\nPress any key to exit...");
	fclose(fps);
	fclose(fpt);
	//getch();
	goto menu;
        }
    case 5:
        {
            int i,j,len1,len2,numstr[100],numkey[100],numcipher[100];
 char str[100],key[100],cipher[100];
 printf("Enter a string text to encrypt\n");
 gets(str);
 for(i=0,j=0;i<strlen(str);i++)
 {
  if(str[i]!=' ')
  {
   str[j]=toupper(str[i]);
   j++;
  }
 }
 str[j]='\0';
 //obtaining numerical plain text ex A-0,B-1,C-2
    for(i=0;i<strlen(str);i++)
    {
     numstr[i]=str[i]-'A';
    }
    printf("Enter key string of random text\n");
    gets(key);
 for(i=0,j=0;i<strlen(key);i++)
 {
  if(key[i]!=' ')
  {
   key[j]=toupper(key[i]);
   j++;
  }
 }
 key[j]='\0';
 //obtaining numerical one time pad(OTP) or key
    for(i=0;i<strlen(key);i++)
    {
     numkey[i]=key[i]-'A';
    }

    for(i=0;i<strlen(str);i++)
    {
     numcipher[i]=numstr[i]+numkey[i];
    }
    //To loop the number within 25 i.e if addition of numstr and numkey is 27 then numcipher should be 1
    for(i=0;i<strlen(str);i++)
    {
     if(numcipher[i]>25)
     {
      numcipher[i]=numcipher[i]-26;
     }
    }
    printf("One Time Pad Cipher text is\n");
    for(i=0;i<strlen(str);i++)
    {
      printf("%c",(numcipher[i]+'A'));
    }
    printf("\n");
    goto menu;

        }
        }
        }
    else if(x==2)
    {
        printf("Enter your choice : \n\n1.Affine Cypher\n2.Pollybius Algorithm\n3.Scytale Cipher\n4.File encryption\n5.One time pad cipher\n");
        scanf("%d",&d);
        getchar();
        switch(d)
        {
        case 1:
            {
               int i,j,k,gcd,alpha,beta,numstr[100],numcipher[100],alphaInverse;
 char str[100],cipher[100];
 printf("Enter a string\n");
 gets(str);
 //converting entered string to Capital letters
 for(i=0,j=0;i<strlen(str);i++)
 {
  if(str[i]!=' ')
  {
   str[j]=toupper(str[i]);
   j++;
  }
  else
  {
   str[j]=' ';
   j++;
  }
 }
 str[j]='\0';
 printf("Entered string is : %s \n",str);
 printf("Enter Alpha value and must be between 1 and 25 both included\n");
 scanf("%d",&alpha);
 //Checking conditions
 if(alpha<1 || alpha>25)
 {
  printf("Alpha should lie in between 1 and 25\nSorry Try again !\n");
  exit(0);
 }
 gcd=CalcGCD(alpha);
 if(gcd!=1)
 {
  printf("gcd(alpha,26)=1 but \n gcd(%d,26)=%d\nSorry Try again !\n",alpha,gcd);
  exit(0);
 }
 printf("Enter Beta value and must be between 0 and 25 both included\n");
 scanf("%d",&beta);
 if(beta<0 || beta>25)
 {
  printf("Beta value should lie between 0 and 25\nSorry Try again !\n");
  exit(0);
 }
 //Conditions Over
 //Program Starts
 //Storing string in terms of ascii and to restore spaces I used -20
 for(i=0;i<strlen(str);i++)
 {
  if(str[i]!=' ')
  numstr[i]=str[i]-'A';
  else
  numstr[i]=-20;
 }
 //For Decryption we need to find multiplicative inverse of  Alpha
 alphaInverse=GetMultiplicativeInverse(alpha);
 printf("MI=%d\n",alphaInverse);
     //Deciphering Process
    //If numcipher is more than 25 .We need to convert and ensure that lie in between 0 and 25.(indicating Alphabets)
   //A-0,B-1,C-2,.....Y-24,Z-25
    printf("Affine Cipher text is\n");
    for(i=0;i<strlen(str);i++)
    {
     if(numstr[i]!=-20)
     {
     numcipher[i]=(alphaInverse*(numstr[i]-beta))%26;
     if(numcipher[i]<0)
     {
      numcipher[i]=numcipher[i]+26;//To avoid negative numbers
     }
          printf("%c",(numcipher[i]+'A'));
     }
     else
     {
          printf(" ");
     }
    }
printf("\n");
goto menu;

}
        case 2:
            {
                 int i,j,poly[26],x,k,num;
 printf("Enter how many numbers are there?\n");
 scanf("%d",&num);
 int numcipher[num];
 printf("Enter numbers separated by space\n");
 for(i=0;i<num;i++)
 {
  scanf("%d",&numcipher[i]);
 }

 x=0;
 k=11;
 //Assigning Polybius Square numbers to alphabets

for(i=0;i<=25;i++)
{
 if(i<=8)
 {
      if(i%5==0&&i!=0)
   {
  k+=5;
  poly[k]=x;
  k++;

    }
   else{
   poly[k]=x;
  k++;

      }
 }
 if(i>=10)
 {
      if(i%5==0&&i!=0)
   {

   poly[k]=x;
  k++;
   k+=5;

    }
   else{
 poly[k]=x;
  k++;

      }
 }
 if(i==9)
 {
  poly[24]=8;//taking 'i' instead of 'j'
 }


  x++;
}
printf("Decrypted Code using Polybius Square Cipher \n");
for(i=0;i<num;i++)
{
 printf("%c",(poly[numcipher[i]]+65));
}
  printf("\n");
 return 0;
 goto menu;
            }
        case 3:
            {
                int i,j,k,len,turns,code[100][1000],col,rows;
    char str[1000];
    printf("Enter an Encrypted Message\n");
    gets(str);
    len=strlen(str);
 printf("Enter number of turns on band\n");
 scanf("%d",&turns);
 k=0;
 rows=ceil((float)len/turns);//for storing the entered sentence column wise instead of row wise
 //initializing code to zero
 for(i=0;i<len;)
 {
  for(j=0;j<rows;j++)
  {
   code[j][k]=0;
   i++;
  }
  k++;
 }
 k=0;
 //storing messages in code according to turns on band
for(i=0;i<len;)
{
  if(str[i]!=' ')
  {
 for(j=0;j<rows;)
 {
  if(i<=len)
  {
    if(str[i]!=' ')//to avoid spaces in between words
    {
            code[j][k]=(int)str[i];
      i++;
      j++;
      }
      else
      {
       i++;
      }

  }
  else
  {
   break;
  }

 }
 k++;
  }
  else
  {
   i++;
  }
}


printf("The Decrypted message using Scytale Cipher is\n");
//printing encrypted message which is column wise
col=k;
for(i=0;i<rows;i++)
{
 for(j=0;j<turns;j++)
 {
     if(code[i][j]!=0)
     printf("%c",code[i][j]);

 }
}
printf("\n");
goto menu;
            }
        case 4:
            {
                char ch, choice, fname[20];
	FILE *fps, *fpt;
	printf("Enter file name (with extension like file.txt) which you have encrypted earlier to decrypt : ");
	gets(fname);
	fps=fopen(fname, "w");
	if(fps==NULL)
	{
		printf("Error in opening source file..!!");
		printf("\nPress any key to exit...");
		//getch();
		exit(7);
	}
	fpt=fopen("temp.txt", "r");
	if(fpt==NULL)
	{
		printf("Error in opening temp.txt file..!!");
		fclose(fps);
		printf("\nPress any key to exit...");
		//getch();
		exit(9);
	}
	while(1)
	{
		ch=fgetc(fpt);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			ch=ch-100;
			fputc(ch, fps);
		}
	}
	printf("File %s decrypted successfully..!!",fname);
	printf("\nPress any key to exit...");
	fclose(fps);
	fclose(fpt);
	////getch();
	goto menu;
            }
        case 5:
            {
                int i,j,len1,len2,numstr[100],numkey[100],numcipher[100];
 char str[100],key[100],cipher[100];
 printf("Enter an Encrypted string text to Decrypt\n");
 gets(str);
 for(i=0,j=0;i<strlen(str);i++)
 {
  if(str[i]!=' ')
  {
   str[j]=toupper(str[i]);
   j++;
  }
 }
 str[j]='\0';
 //obtaining numerical plain text ex A-0,B-1,C-2
    for(i=0;i<strlen(str);i++)
    {
     numstr[i]=str[i]-'A';
    }
    printf("Enter key string of random text\n");
    gets(key);
 for(i=0,j=0;i<strlen(key);i++)
 {
  if(key[i]!=' ')
  {
   key[j]=toupper(key[i]);
   j++;
  }
 }
 key[j]='\0';
 //obtaining numerical one time pad(OTP) or key
    for(i=0;i<strlen(key);i++)
    {
     numkey[i]=key[i]-'A';
    }

    for(i=0;i<strlen(str);i++)
    {
     numcipher[i]=numstr[i]-numkey[i];//changed from + to - for decryption
     if(numcipher[i]<0)
     {
      numcipher[i]=numcipher[i]+26;//If cipher is negative we have to add 26
     }
     numcipher[i]=numcipher[i]%26;//To loop within 1 to 26 for alphabets from A-Z
    }

    printf("Decrypted One Time Pad Cipher text is\n");
    for(i=0;i<strlen(str);i++)
    {
      printf("%c",(numcipher[i]+'A'));
    }
    printf("\n");
    goto menu;

{

}            }
        }
    }
    else
       {
       int y;
       printf("Are you sure?\n1.YES\n2.NO\n");
       scanf("%d",&y);
       getchar();
       if(y==2)
        {
            goto menu;
        }
       else if(y==1)
        {
            exit(0);
        }
       else
       {
           printf("Invalid input.");
           goto menu;
       }
       //goto menu;
       }

}
