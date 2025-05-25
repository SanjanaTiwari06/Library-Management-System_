#include<stdio.h>
#include<stdlib.h>                                                                                                               
#include<time.h>                                                    
struct books                   
{
    int id; 
    char bookname[50];      
    char authorname[50];
    char date[12];

}b;                                                                              
struct student       
{                                                               
                                              
    int id;                
    char sName[50];                                                                                                                          
    char sClass[50];
    char sRoll[50];
    char bookname[50];   
    char date[12];                         
}s;
  
                  
FILE  *fp;                                                                      

int main()
{                          
    int ch;
    //main menu 
    while(1)
  {  
                                                                                                         
        system("cls");
    printf("<====LIBRARY MANAGEMENT SYSTEM====>\n\n");
    printf("1.add book\n");
    printf("2.book list\n");
    printf("3.remove book\n");
    printf("4.issue book\n");
    printf("5.issue book list\n");
    printf("0.exit\n\n");
    printf("enter your choice: ");
    scanf("%d",&ch);


    switch(ch)
    {
        case 0:
        exit (0);
        break;
        
        case 1:
        addbook();
        break;

        case 2:
        booklist();  
        break;

        case 3:
        removebook();
        break;
        
        case 4:
        issuebook();
        break;

        case 5:
        issuebooklist();
        
        default:
        printf("invalid choice\n\n");
        break;

    }
    printf("press any key to continue.....");                         

   getch();   
  }
    return 0;
    
 }
  void addbook() 
  {
    char mydate[12];
    time_t t=time (NULL);                                                 
    struct tm tm=*localtime(&t);
    sprintf(mydate,"%2d%02d%d",tm .tm_mday, tm.tm_mon+1, tm.tm_year+ 1900);
    strcpy (b.date,mydate);

    fp=open("book.txt","ab");
 
    printf("enter book id: ");
    scanf("%d",&b.id);

    printf("Enter book name: ");

    fflush(stdin);
    gets(b.bookname);

    printf("Enter author name: ");

    fflush(stdin);
    gets(b.authorname);

    printf("book added succesfully\n\n");

    fwrite(&b,sizeof(b),1,fp);
    fclose(fp);
      

  } 
  void booklist()
  {
    system("cls");
    printf("<===available book===>\n\n");
    printf("%-10s %-30s %-20s %s","Id", "bookname","authoname","date\n\n"); 

    fp=fopen("booK.txt","rb");
    while(fread(&b,sizeof(b),1,fp)==1)       
    {
       printf("%-10d %-30s %-20s %s\n",b.id,b.bookname,b.authorname,b.date);
      
    }
    fclose(fp);
  }
 void removebook()
 {
  int id, f=0;
  system("cls");
  printf("<===Remove books===>\n\n");
  printf("enter book id to remove:  ");
  scanf("%d", &id);

  FILE *ft;

  fp = fopen("Books.txt", "cb");
  ft = fopen("temp.txt" , "wb");
  while(fread(&b, sizeof(b),  1, fp) == 1){
    if(id == b.id)
    {
      f=1; 
    } else 
    {
      fwrite(&b, sizeof(b), 1, ft);
    }
  }

  if(f ==1)
  {
    printf("\n\nBook Deleted Successfully");
  }else
 {
  printf("\n\nNo Book Found");
 }

 fclose(fp);
 fclose(ft);

 remove("books.txt");
 rename("tmp.txt", "books.txt");  

 } 

 void issuebook()
 {
  char mydate [12];
      time_t t = time(NULL);
      struct tm tm = *localtime(&t); 
      sprintf(mydate, "%02d/%02d/%d" , tm . tm_mday, tm.tm_mon+1, tm .tm_year + 1900);  
      strcpy(s.date, mydate);

      
      int  f = 0;

      system("cls");
      printf("<===Issue Books===>\n\n");
      printf("Enter Book id to issue: ");
      scanf("%$d", &s.id);

      //check if we have book of given id 
      fp = open("books.txt",  "rb");

      while(fread(&b, sizeof(b),  1, fp) == 1)
      {
        if (b.id == s. id ) 
        { 
          strcpy (s.bookname,b.bookname );
          f = 1;
          break;

        }
      }

      if (f==0)
       {
        printf("No Book found with this id\n");
        printf("pls try again ...\n\n");
        return ;
      }

      fp = fopen ("issue.txt", "ab");
      printf("Enter Student Name:  ");
      fflush(stdin);
      gets(s.sName);

     printf("Enter Student Class:  ");
     fflush(stdin);
     gets(s.sClass);

     printf("Enter Student Roll:  ");
     scanf("%d", &s.sRoll);

    fwrite(&b, sizeof(b),  1,  fp);
    fclose(fp);
 }  
 void issuebooklist()
  {
  system("cls");  
  printf("<===Issue Book List===> ");
  }                                                    
    