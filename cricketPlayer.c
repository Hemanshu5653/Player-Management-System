
#include<stdio.h>
#include<string.h>

int ctr=0;

typedef struct Player
{
	int jsno;
	char name[20];
	int runs;
	int wickets;
	int matches;	
}Player;


void hardcode(Player*p);
void addPlayer(Player*,int);
void displayPlayer(Player*);
void update(Player*, int);
void searchPlayer(Player*, int);
void deletePlayer(Player*, int);
void sortPlayer(Player*, int);


void main()
{
	
    int size=10;
	struct Player p[size];
	hardcode(p);
	displayPlayer(p);
	int choice;
	
	do
	{
	printf("\n*****Player Management System******\n");

    printf("1. Add Player\n");
    printf("2. Display Players\n");
    printf("3. Update Players\n");
    printf("4. Search Players\n");
    printf("5. Delete Players\n");
    printf("6. Sort Players\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
	
	switch(choice)
	{   

		case 1:
			addPlayer(p, size);
			break;
			
		case 2:
			displayPlayer(p);
			break;	
	    		
		case 3:
		    update(p, size);
		    break;
		    
		case 4:
		    searchPlayer(p, size);
		    break;
		    
		case 5:
		    deletePlayer(p, size);
		    displayPlayer(p);
		    break;
			
		case 6:
		    sortPlayer(p, size);
		    break;
		
		  case 7:
            printf("End of the program. Thank you!\n");
            break;
				
		default:
		printf("Invalid Choice");	    
			
	}
}
    while(choice!=7);	
		
}



void hardcode(Player*p)
{
	p[0].jsno=7;
	strcpy(p[0].name,"MSD");
	p[0].runs=5125;
	p[0].wickets=252;
	p[0].matches=63;
	ctr++;
	
	p[1].jsno=15;
	strcpy(p[1].name,"Maxwell");
	p[1].runs=515;
	p[1].wickets=102;
	p[1].matches=73;
	ctr++;
	
    p[2].jsno=2;
	strcpy(p[2].name,"Kohli");
	p[2].runs=5585;
	p[2].wickets=282;
	p[2].matches=33;
	ctr++;
		
}



void addPlayer(Player* p, int size)
{
	
	
	printf("Adding Player:\n");
	printf("_______________");
	
	if(ctr<size)
	{
	printf("\nEnter the jsno:");
	scanf("%d",&p[ctr].jsno);	
		
	printf("\nEnter the name:");
	scanf("%s",&p[ctr].name);	
		
	printf("\nEnter the runs:");
	scanf("%d",&p[ctr].runs);	
		
	printf("\nEnter the wickets:");
	scanf("%d",&p[ctr].wickets);	
	
	printf("\nEnter the matches:");
	scanf("%d",&p[ctr].matches);
	
	printf("Information added sucessfully..!!!");		
	
	ctr++;
	}
	
	else
	{
		printf("\nInsufficient memory!");
	}
}


void displayPlayer(Player* p)
{

	printf("\nPlayer information");
	printf("\n---------------------\n");

    int i;	
	for(i=0;i<ctr;i++)
	{
		printf("\njsno:%d\t Name:%s\t Runs:%d\t Wickets:%d\t Matches:%d\t\n",p[i].jsno,p[i].name,p[i].runs,p[i].wickets,p[i].matches);
		
	}	
		
}

void update(Player*p, int size)
   {   
    printf("\nUpdating Player Information:"); 
    printf("\n__________________________________");
	
	int jsNo;
	
	printf("\nEnter the jersey number to update:");
	scanf("%d",&jsNo);

    int i;
	
   for(i=0;i<ctr;i++)
   {
   	
    	if(p[i].jsno==jsNo)
    	{
     	printf("\nEnter the updated runs:");
     	scanf("%d",&p[i].runs);	
		
    	printf("\nEnter the updated number of matches:");
    	scanf("%d",&p[i].matches);
		
	    printf("\nEnter the updated number of wickets:");
    	scanf("%d",&p[i].wickets);
	
     	printf("\nInformation updated Sucessfully....!!!\n.");
	
    	printf("\nDisplaying Updated Information:\n");
        printf("_________________________________");

        printf("\njsno:%d\t Name:%s\t Runs:%d\t Wickets:%d\t Matches:%d\t\n",p[i].jsno,p[i].name,p[i].runs,p[i].wickets,p[i].matches);	
        break;
        }   
        else
        {
        	printf("Jersey No not found");
        	break;
		}
   }
}


//searching player by jersey Name ,number and runs

void searchPlayer(Player*p, int size)
{
    printf("\nSearching Player\n");
    
    int choice;
    int i, flag = 0; 
    
    printf("\nSearch Menu:\n");
    printf("1. Search by Jersey Number\n");
    printf("2. Search by Runs\n");
    printf("3. Search by Name\n");
    
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    	
    	case 1:
    		
    	printf("\nSearching player:");
		printf("\n_");
		int js;
		printf("\nEnter a player jersey number to search:");
		scanf("%d",&js);
	

		for(i=0;i<ctr;i++)
		{
			if(p[i].jsno==js)
			{
			flag=1;
			break;
			
			}
	
		}
		if(flag==1)
		{
		 printf("\nplayer found at index %d having name %s.\n\n ",i,p[i].name);	
		}	
		else
		{
		 printf("\nPlayer not found. Invalid jersey number.\n\n");	
		}	
    		
    case 2:
    	
    	
    	printf("\nSearching player by runs:");
		printf("\n_");
	
		int runs;
		printf("\nEnter a player runs:");
		scanf("%d",&runs);
		
		int i;
		int flag=0;
	
		for(i=0;i<ctr;i++)
		{
			if(p[i].runs==runs)
			{
			flag=1;
			break;
			
			}
	
		}
		if(flag==1)
		{
		 printf("\nplayer found at index %d having name %s.\n\n ",i,p[i].name);	
		}	
		else
		{
		 printf("\nPlayer not found. Invalid name.\n\n");	
		}
	
		case 3:
    	//searching by name
    	printf("\n\nSearching player by names:");
    
		char name[20];	
    	printf("\n\nEnter a player name to search :");
    	scanf("%s",&name);
		 
		for(i=0;i<ctr;i++)
		 {
			int result=strcasecmp(name,p[i].name);
		
			if(result==0)
			{   
		    flag=1; 
		    break;
	   		 }
   	 	}
	
	   if(flag==1)
	   {
	   	printf("Player found at index=%d\n", i);
		printf("Jersey No: %d\n", p[i].jsno);
        printf("Innings: %d\n", p[i].matches);
        printf("Runs: %d\n", p[i].runs);
        printf("Wickets: %d\n", p[i].wickets);
        
	   }
	   
	   else
	   {
	   	printf("\nplayer not found");
	   }	
					
   }
	

}

void deletePlayer(Player*p, int size)
{
    
    int deletebyjsno;
    
    printf("Enter a jersey number to delete: ");
    scanf("%d", &deletebyjsno);

    int i, flag = 0;
    for (i = 0; i < size; i++)
    {
        if (p[i].jsno == deletebyjsno)
        {
            flag = 1;
            
            printf("Player found at index=%d\n", i);
            printf("Name: %s\n", p[i].name);
            printf("Jersey No: %d\n", p[i].jsno);
            printf("Innings: %d\n", p[i].matches);
            printf("Runs: %d\n", p[i].runs);
            printf("Wickets: %d\n", p[i].wickets);
 
            int j;
            for (j = i; j < size - 1; j++)
            {
                p[j] = p[j + 1];
            }

            
            ctr--;

            printf("Player deleted successfully.\n");
            displayPlayer(p);
            break;
        }
    }

    if (flag == 0)
    {
        printf("Player not found\n");
    }  
 
}




void sortPlayer(Player*p,int size)
{
  
    int i,j,temp;
    int choice;
    
    printf("Sort menu\n");
    printf("1.Sort by runs\n");  
    printf("2.Sort by matches\n");
    printf("3.Sort by wickets\n");
    printf("4.Back to main menu\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    
    switch(choice)
    {
    	case 1:
    		for(i=0;i<ctr;i++)
    		{
              for(j=i+1;j<ctr;j++)
              {
              	if(p[i].runs<p[j].runs)
              	{
				  
              	Player temp=p[i]; 
              	p[i]=p[j];
              	p[j]=temp;
                }
			  }
			}
			displayPlayer(p);
			break;
			
		case 2:
    		for(i=0;i<ctr;i++)
    		{
              for(j=i+1;j<ctr;j++)
              {
              	if(p[i].wickets<p[j].wickets)
              	{
				  
              	Player temp=p[i];
              	p[i]=p[j];
              	p[j]=temp;
                }
			  }
			}
			displayPlayer(p);
			break;	
			
		case 3:
    		for(i=0;i<ctr;i++)
    		{
              for(j=i+1;j<ctr;j++)
              {
              	if(p[i].matches<p[j].matches)
              	{
				  
              	Player temp=p[i];
              	p[i]=p[j];
              	p[j]=temp;
                }
			  }
			}
			displayPlayer(p);
			break;	
			
		case 4:
        printf("Returning to Main Menu.\n");
        return;
        
        default:
        printf("Invalid choice. Returning to Main Menu.\n");
    }
}
	
	
    
    
    
    
    
    
    
    
    
    
    

        
    
        
    







