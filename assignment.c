#define NAME 100					//LENGTH OF NAME OF ANYTHING	
#define GAME_ID 5					//MAXIMUM NUMBER OF GAMES CAN HOLD
#define GROUND_ID 10			//MAXIMUM NUMBER OF GROUND AVAILABLE
#define POSSIBLE_SLOT 5				//MAXIMUM NUMBER OF DATES AVAILABLE
#define TIME  19	
#include<stdio.h>
#include<math.h>
#include<string.h>

struct game
{
	char name[NAME];
	int hourly_rate;
	int time[366][24];	
};
struct ground
{
	char name[NAME];
	char city[NAME];
	char state[NAME];
	struct game game_id[GAME_ID];
}ground_id[GROUND_ID],temp;
//#include"myfunction.h"
//#include"function.h"
//initialization
void initialize()
{	
	int i,j,k,l;
	for(i=0;i<GROUND_ID;i++)
	{	
		strcpy(ground_id[i].name,"\0");
		strcpy(ground_id[i].city,"\0");
		strcpy(ground_id[i].state,"\0");
		for(j=0;j<GAME_ID;j++)
		{			
			for(k=0;k<366;k++)
			{	for(l=0;l<24;l++)
					ground_id[i].game_id[j].time[k][l]=0;
			}
			strcpy(ground_id[i].game_id[j].name,"\0");
			ground_id[i].game_id[j].hourly_rate=0;
		}
	}
}
//swapping:
void swap(int x,int y)
{


    temp=ground_id[x];
    ground_id[x]=ground_id[y];
    ground_id[y]=temp;
}
//groundcity sort:
void groundcitysort()
{
int i,j;

    for(i=0;i<GROUND_ID;i++)
    {
        for(j=0;j<GROUND_ID-i-1;j++)
        {

        if(strcmp(ground_id[j].name,ground_id[j+1].name)>0&&ground_id[j+1].name[0]!='\0')
        {//printf("hh");
            swap(j,j+1);

        }
        else if((strcmp(ground_id[j].name,ground_id[j+1].name)==0&&ground_id[j+1].name[0]!='\0'))
        {
         if((strcmp(ground_id[j].city,ground_id[j+1].city)>0)&&ground_id[j+1].city[0]!='\0')
        {

            swap(j,j+1);

        }
        }
        }
    }
}

//sportssort:
void sportsort()
{
    int i,j,k;
    for(i=0;i<GROUND_ID;i++)
    {
        for(j=0;j<GAME_ID;j++)
        {
            for(k=0;k<GAME_ID-j-1;k++)
            {
                if(strcmp(ground_id[i].game_id[k].name,ground_id[i].game_id[k+1].name)>0&&ground_id[i].game_id[k+1].name[0]!='\0')
                {
                     temp.game_id[0]=ground_id[i].game_id[k];
                    ground_id[i].game_id[k]=ground_id[i].game_id[k+1];
                    ground_id[i].game_id[k+1]=temp.game_id[0];
                }
            }
        }
    }
}

//dAY of the year:
int DayoftheYear(int x,int y)
{
    int a[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};

            return a[y-1]+x-1;


}
//day and month:
int DayandMonth(int x)
{
    int i,flag=0,j;
     int a[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};

        for(i=0;i<13&&flag==0;i++)
        {
            if((x-a[i])<0)
            {
                flag=1;
            }
        }
         i=i-2;
        j=x-a[i];

         return (j*100+i+1);
}
//cityground sort:
void citygroundsort()
{
int i,j;
    for(i=0;i<GROUND_ID;i++)
    {
        for(j=0;j<GROUND_ID-i-1;j++)
        {

        if(strcmp(ground_id[j].city,ground_id[j+1].city)>0&&ground_id[j+1].city[0]!='\0')
        {
            swap(j,j+1);

        }
        else if(strcmp(ground_id[j].city,ground_id[j+1].city)==0&&ground_id[j+1].city[0]!='\0')
        {


        if((strcmp(ground_id[j].name,ground_id[j+1].name)>0)&&ground_id[j+1].name[0]!='\0')
        {

            swap(j,j+1);

        }
        }
        }
    }
}
//statecity sort:
void statecitysort()
{
int i,j;
    for(i=0;i<GROUND_ID;i++)
    {
        for(j=0;j<GROUND_ID-i-1;j++)
        {

        if(strcmp(ground_id[j].state,ground_id[j+1].state)>0&&ground_id[j+1].state[0]!='\0')
        {
            swap(j,j+1);

        }
        else if(strcmp(ground_id[j].state,ground_id[j+1].state)==0&&ground_id[j+1].state[0]!='\0')
        {
         if((strcmp(ground_id[j].city,ground_id[j+1].city)>0)&&ground_id[j+1].city[0]!='\0')
        {

            swap(j,j+1);

        }
        }
        }
    }
}
//scan
void scan(int k)
    {	int m=0,n=0;
        int i,j,a=1,b=1;char option;
        for(i=0;i<k;i++)
        {
            a=0,b=0;
		
            scanf("%s",ground_id[i].name);
		            
	scanf("%s",ground_id[i].city);
		
            scanf("%s",ground_id[i].state);
            for(j=0;j<4;j++)
            {
             scanf("%s",ground_id[i].game_id[j].name);
             scanf("%d",&ground_id[i].game_id[j].hourly_rate);
          
		for(m=0;m<20;m++)
		{	for(n=0;n<20;n++)
			  ground_id[i].game_id[j].time[m][n]=1;
		}
            }
        }
//printf("%d",ground_id[1].game_id[2].time[10][15]);
//scanf("%c",&option);    
}

//function 1:
void getGroundInfo()
{
	int i,k=0;
	char city[NAME];
	printf("please enter the city you want to search in.. \n");
	scanf("%s",city);
	for(i=0;i<GROUND_ID;i++)
	{
		if(strcmp(city,ground_id[i].city)==0)
		{
			k++;
			printf("%d: %s\n",k,ground_id[i].name);
		}
	}
}
//function 2:
void addSport()
{
	int i,j,found=0;
	printf("Enter the ground name ,city	\n ");
	char ground[NAME],city[NAME],game[NAME];;
	scanf("%s%s",ground,city);
	for(i=0;i<GROUND_ID&&found==0;i++)
	{
		if((strcmp(ground,ground_id[i].name)==0)&&(strcmp(city,ground_id[i].name)==0))
		{
			found=1;i--;
		}
	}
	j=i;
	if(found==0)
	{
		printf("FAILURE...NO SUCH GROUND EXITS\n");
	}
	else
	{	
		printf("Enter the sports name");
		scanf("%s",game);
		found=0;
		for(i=0;i<GAME_ID&&found==0;i++)
		{
			if(strcmp("\0",ground_id[j].game_id[i].name)==0)
			{
				found=1;
				strcpy(ground_id[j].game_id[i].name,game);
				printf("SUCCESS....please decide the hourly rate and time slot for game and update soon\n");
			}
		}
		if(found==0)
		{
			printf("FAILURE ..ground capacity is already reached");
		}
	}
}
//function 3:
void deleteSport()
{
	printf("Enter the ground name,city and sport to be deleted\n");
	char ground[NAME],city[NAME],sport[NAME];
	scanf("%s%s",ground,city);
	int i,j,k,found=0;
		for(i=0;i<GROUND_ID&&found==0;i++)
	{
		if(strcmp(ground,ground_id[i].name)==0&&strcmp(city,ground_id[i].city)==0)
		{
			found=1;i--;
		}
	}j=i;
	if(found==0)
	{
		printf("FAILURE...NO SUCH GROUND EXITS\n");
	}
	else
	{	
		printf("Enter the sports name\n");
		scanf("%s",sport);
		found=0;
		for(i=0;i<(	GAME_ID-1)&&found==0;i++)
		{int k,l;
			if(strcmp(sport,ground_id[j].game_id[i].name)==0)
			{
				found=1;
				strcpy(ground_id[j].game_id[i].name,ground_id[i].game_id[j+1].name);
				ground_id[i].game_id[j].hourly_rate=ground_id[i].game_id[j+1].hourly_rate;
				printf("SUCCESS....the entry of the game in given gground is deleted\n");
				for(k=0;k<366;k++)
			{	for(l=0;l<24;l++)
					ground_id[i].game_id[j].time[k][l]=ground_id[i].game_id[j+1].time[k][l];
			}
				strcpy(sport,ground_id[i].game_id[j+1].name);
			}
		}
	//	printf("%d",i);
		if(found==0)
		{
			printf("FAILURE ..\n");
		}
	}
	
}
//function 4:
void addGround()
{	
	int i,j,found=0;
	for(i=0;i<GROUND_ID&&found==0;i++)
	{	
		if(ground_id[i].name[0]=='\0')
		{
			found=1;
			i--;
		}		
	}
	if(found==1)
	{
		char a[NAME],b[NAME],c[NAME];
		printf("name\n");
		scanf("%s",a);
		strcpy(ground_id[i].name,a);

		printf("city\n");
		scanf("%s",b);
		strcpy(ground_id[i].city,b);

		printf("state\n");
		scanf("%s",c);
		
		strcpy(ground_id[i].state,c);
		for(j=0;j<GAME_ID;j++)
		{	
			ground_id[i].game_id[j].name[0]='\0';
			ground_id[i].game_id[j].hourly_rate=0;
			int l,k;
			for(k=0;k<365;k++)
			{
				for(l=0;l<24;l++)
				{
					ground_id[i].game_id[j].time[k][l]=0;
				}
			}
		}
		printf("to add sport in the ground refer to that fnction\n");
	}
	else
	{
		printf("Failure..sorry we cant accomodate new grounds now\n");
	}
}
//function 5:
void deleteGround()
    {
        char ground[NAME],city[NAME];
	printf("ground name");
        scanf("%s",ground);
	printf("enter city name");
        scanf("%s",city);
        int flag=0,i;
        for(i=0;i<GROUND_ID&&flag==0;i++)
        {
            if(strcmp(ground_id[i].name,ground)==0)
            {
                if(strcmp(ground_id[i].city,city)==0)
                {
                    flag=1;

                }
            }
        }
        i--;
        for(;i<GROUND_ID-1;i++)
        {
            ground_id[i]=ground_id[i+1];
        }
        if(flag==1)
        {
            printf("SUCCESS\n");
        }
        else
        {
            printf("FAILURE\n");
        }
	printf("%s",ground_id[0].game_id[2].name);
    }


//function 6:
void updateGround()
{
	char ground[NAME],city[NAME];
	printf("enter ground and city name\n");
	scanf("%s%s",ground,city);
	int i,j,found=0;
	for(i=0;i<GROUND_ID&&found==0;i++)
	{
		if(strcmp(city,ground_id[i].city)==0&&strcmp(ground,ground_id[i].name)==0)
		{
			found=1;
			i--;
		}
	}
	if(found==0)
	{
		printf("failure..");
	}
	else
	{	
		printf("now enter the updated data\n");
		char a[NAME];
		printf("name");
		scanf("%s",a);
		strcpy(ground_id[i].name,a);
		printf("city");
		scanf("%s",a);
		strcpy(ground_id[i].city,a);
		printf("state");
		scanf("%s",a);
		strcpy(ground_id[i].state,a);
		printf("to update info related to sports use add or delete sports function\n");
	}

}
//function 7:
void getFixturesinCity()
{	groundcitysort();
	sportsort();
    char city[NAME];
    int day_start;
    int month_start;
    int day_stop;
    int month_stop;
    int i,j,k,z,flag=0;
    printf("Enter the name of the City\n");
    scanf("%s",city);
    printf("Enter the initial day and month\n");
    scanf("%d%d",&day_start,&month_start);
    printf("Enter the final day and month\n");
    scanf("%d%d",&day_stop,&month_stop);
    int start=DayoftheYear(day_start,month_start);
    int stop=DayoftheYear(day_stop,month_stop);

    for(i=0;i<GROUND_ID;i++)
    {
        if(strcmp(ground_id[i].city,city)==0)
        {
                for(j=0;j<GAME_ID;j++)
                {
                    flag=0;
                    for(k=start;k<=stop&&flag==0;k++)
                    {
                        for(z=0;z<24;z++)
                        {
                        	if(ground_id[i].game_id[j].time[k][z]==1)
                        	{
                        	   flag=1;
                        	   printf("\t %s \t %s \n",ground_id[i].name,ground_id[i].game_id[j].name);
                        	}
                        }
                    }


                }

        }
    }
}
//Function 8:
void getFixturesinState()
{
	citygroundsort();
	sportsort();
	char a[NAME];
	printf("enter the state\n");
	scanf("%s",a);
	int i,j;
	for(i=0;i<GROUND_ID;i++)
	{
	
			if(strcmp(ground_id[i].state,a)==0)
		{
			printf("%s\t%s\t",ground_id[i].city,ground_id[i].name);
			for(j=0;j<GAME_ID;j++)
			{	
				printf("\t\t%s\n",ground_id[i].game_id[j].name);
			}
		}
	}

} 
//function 9:
void getFixturesSortedonDate()
{
    int i,j,k,z;
    int tempo;
    for(j=1;j<366;j++)
    {
        for(z=0;z<24;z++)
        {

        for(i=0;i<GROUND_ID;i++)
        {
        for(k=0;k<GAME_ID;k++)
        {




                if(ground_id[i].game_id[k].time[j][z]==1)
                {
                    tempo=DayandMonth(j);

                    printf("ground:%s day:%d month:%d time:%d sport:%s\n",ground_id[i].name,(tempo/100),tempo%100,z,ground_id[i].game_id[k].name);
                }

        }
    }
    }
    }
}
//function 10:
void getFixturesSortedonState()
{
	int i;
	statecitysort();
	for(i=0;i<GROUND_ID;i++)
	{
		printf("%s(%s)\n",ground_id[i].name,ground_id[i].state);
	}
}
//function 11:
void isAvailable()
{
	statecitysort();
	char game[NAME];
	int date,time,month;
	printf("enter game ,date ,month and time hr\n");
	scanf("%s%d%d%d",game,&date,&month,&time);
	int i,j,k,l;
	l=DayoftheYear(date,month);
	for(i=0;i<GROUND_ID;i++)
	{//printf("56");
		for(j=0;j<GAME_ID;j++)
		{
			if(strcmp(game,ground_id[i].game_id[j].name)==0)
			{
				if(ground_id[i].game_id[j].time[l][time]==0)
				{
					printf("yes the ground %s is available(%s)\n",ground_id[i].name,ground_id[i].city);
				}
			}
		}
	}
}
//function 12:
void UniqueSports()
    {
	int i,j;
        char ground[NAME],city[NAME];
        char char_arr[GROUND_ID*GAME_ID][NAME];
        char main_arr[GAME_ID][NAME];
        int count1=0,count2=0;
        printf("Enter the name of the ground\n");
        scanf("%s",ground);
        printf("Enter the name of the city\n");
        scanf("%s",city);
        for(i=0;i<GROUND_ID;i++)
        {

                if(strcmp(ground_id[i].city,city)==0)
            {


                    if(strcmp(ground_id[i].name,ground)==0)

                    {
                        for(j=0;j<GAME_ID;j++)
                        {
                            strcpy(main_arr[count1],ground_id[i].game_id[j].name);
                            count1++;
			
                        }
	

                    }
                    else
                    {
	
                       for(j=0;j<GAME_ID;j++)
                       {
                           strcpy(char_arr[count2],ground_id[i].game_id[j].name);
                           count2++;
			//printf("%s\n",char_arr[count2-1]);
                       }
                    }

            }
        }
        int flag;
        for(i=0;i<count1;i++)
        {
            flag=0;
            for(j=0;j<count2;j++)
            {//printf("%s:%s",char_arr[j],main_arr[i]);
                if(strcmp(char_arr[j],main_arr[i])==0)
                {//printf("ll");
                    main_arr[i][0]='\0';
                }
            }
           
                printf("%s\n",main_arr[i]);
            
        }


    }

//function 13:
void SportswithGround()
{	
	groundcitysort();
	int i,j;
	char a[NAME];
	printf("Enter the sports\n");
	scanf("%s",a);
	for(i=0;i<GROUND_ID;i++)
	{
		for(j=0;j<GAME_ID;j++)
		{
			if(strcmp(a,ground_id[i].game_id[j].name)==0)
			{
				printf("%s\n",ground_id[i].name);
			}
		}
	}
}
//function 14:
void FindLocationsForGameEvents()
{	//groundcitysort();
	int i,j,k,z;
	printf("Enter game name\n");
	char game[NAME];
	scanf("%s",game);
	printf("enter date month and hours range\n");
	int date1,date2,month2,month1,hr1,hr2,l1,l2;
	printf("enter date month time of start");
	scanf("%d%d%d",&date1,&month1,&hr1);
	printf("enter date month time of end");
	scanf("%d%d%d",&date2,&month2,&hr2);
l2=DayoftheYear(date2,month2);	
l1=DayoftheYear(date1,month1);
	for(i=0;i<GROUND_ID;i++)
	{
		int count=0;
		for(j=0;j<GAME_ID;j++)
		{
			if(strcmp(game,ground_id[i].game_id[j].name)==0)
			{for(z=l1;z<l2;z++)
				{for(k=hr1;k<=hr2&&count==0;k++)
				{
					if(ground_id[i].game_id[j].time[z][k]==1)
					{
						count++;
						printf("%s\n",ground_id[i].name);
					}
				}}
			}
		}
	}
}
//function 15:
void FindLocationForGame()
{
	//groundcitysort();
	isAvailable();
}
//function 16:
void FindLocationForGameInTimeRange()
{	//groundcitysort();
	int i,j,k,z;
	char game[NAME];
	printf("Enter the name of the sports\n");
	scanf("%s",game);
	int date1,date,month2,month,hr1,hr2,l;
	printf("enter date month time interval");
	scanf("%d%d%d%d",&date,&month,&hr1,&hr2);
//	printf("enter date month time of end");
//	scanf("%d%d%d",&date2,&month2,&hr2);
l=DayoftheYear(date,month);	
//l1=DayoftheYear(date1,month1);
	
	for(i=0;i<GROUND_ID;i++)
	{
		int count=0;
		for(j=0;j<GAME_ID;j++)
		{
			if(strcmp(game,ground_id[i].game_id[j].name)==0)
			{
				for(k=hr1;k<=hr2;k++)
				{
					if(ground_id[i].game_id[j].time[l][k]==0)
					{
						count++;
					}
				}
			}
		}count--;
	//	printf("%d",count);
		if(count==(hr2-hr1))
		{
			printf("%s(%s)\n",ground_id[i].name,ground_id[i].city);
		}
	}
}
//function 17:
void ClashOfMatches()
{ int day,month,n,i,j,k,z;
    printf("Give the Date\n");
    scanf("%d%d",&day,&month);
    printf("Enter the number of grounds\n");
    scanf("%d",&n);
    printf("Enter the grounds\n");
    char arr[GROUND_ID][NAME];
    for(i=0;i<n;i++)
    scanf("%s",arr[i]);
    char game[20];
    printf("Enter name of the game\n");
    scanf("%s",game);
    day=DayoftheYear(day,month);
int found=10;
    for(k=0;k<n;k++)
    {

    for(i=0;i<GROUND_ID;i++)
    {

            if(strcmp(ground_id[i].name,arr[k])==0)
               {
                for(j=0;j<GAME_ID;j++)
                {
                    if(strcmp(ground_id[i].game_id[j].name,game)==0)
                    {
                        for(z=0;z<24;z++)
                        {
                            if(ground_id[i].game_id[j].time[day][z]==1)
                            {
                                printf("ground:%s game: %s time(hr.) %d\n",ground_id[i].name,ground_id[i].game_id[j].name,z);
                            }
                        }
                    }

                }
               }
    }
    }

}
//function 18:
void GiveListOfGroundsHavingMinOneMatch()
{	groundcitysort();
	char city[NAME];
	printf("entr the city name\n");
	scanf("%s",city);
	char list[GAME_ID][NAME];
	int i,j,k,l;
	printf("enter the list of sports (max 5)\n");	
	for(i=0;i<GAME_ID;i++)
	{
		scanf("%s",list[i]);
	}
	int date,month;
	printf("Enter the day and month\n");
	scanf("%d%d",&date,&month);
	l=DayoftheYear(date,month);		
	for(i=0;i<GROUND_ID;i++)
	{int found=0;	
		if(strcmp(city,ground_id[i].city)==0)
		{
			for(j=0;j<GAME_ID&&found==0;j++)
			{
				for(k=0;k<GAME_ID&&found==0;k++)
				{
					if(strcmp(list[k],ground_id[i].game_id[j].name)==0)
					{
						int m;
						for(m=0;m<24&&found==0;m++)
						{
							if(ground_id[i].game_id[j].time[l][m]==1)
							{	found=1;
								printf("yes  %s ground will have match\n",ground_id[i].name);
							}
						}
					}
				}
			}
		}
	}
}
//function 19:
void GiveListOfGroundsHavingAtleastKMatches()
{	groundcitysort();
	char city[NAME];
	printf("entr the city name\n");
	scanf("%s",city);
	char list[GAME_ID][NAME];
	int i,j,k,l;
	printf("Enter the list of games (maximum 5)\n");
	for(i=0;i<GAME_ID;i++)
	{
		scanf("%s",list[i]);
	}
	int date,month;
	printf("enter day amd the month\n");
	scanf("%d%d",&date,&month);

	printf("enter k\t");
	scanf("%d",&k);
	l=DayoftheYear(date,month);
	for(i=0;i<GROUND_ID;i++)
	{
		if(strcmp(city,ground_id[i].city)==0)
		{	int count=0;
			for(j=0;j<GAME_ID;j++)
			{
				for(k=0;k<20;k++)
				{
					if(strcmp(list[k],ground_id[i].game_id[j].name)==0)//if(strcmp(game,ground_id[i].game_id[j].name)==0)
					{	//printf("sd");
						int m;
						for(m=0;m<24;m++)
						{
							if(ground_id[i].game_id[j].time[l][m]==1)
							{
								count++;
							}
						}
					}
				}
			}
			if(count>=k)
			{
				printf("%s\n",ground_id[i].name);
			}
		}
	}
}
//function 20:
void SortOnPriceForAGame()
    {
        int i,day,month,count=0,time,j;
        char game[NAME];
        printf("Enter the name of the game\n");
        scanf("%s",game);
        printf("Enter the date\n");
        scanf("%d%d",&day,&month);
        printf("Enter the time\n");
        scanf("%d",&time);
        time=time-1;
        day=DayoftheYear(day,month);
        char temp[GROUND_ID][NAME];
        int temp2[GROUND_ID];
        char tem[20];
        int tem2;
        for(i=0;i<GROUND_ID;i++)
        {
            for(j=0;j<GAME_ID;j++)
            {
                if(strcmp(game,ground_id[i].game_id[j].name)==0)
                {
                   if(ground_id[i].game_id[j].time[day][time]==0)
                    {

                    strcpy(temp[count],ground_id[i].name);
                    temp2[count]=ground_id[i].game_id[j].hourly_rate;
                    count++;
                    }
                }
            }

        }
        for(i=0;i<count;i++)
        {
            for(j=0;j<count-i-1;j++)
            {
                if(temp2[j]>temp2[j+1])
                {
                    tem2=temp2[j];
                    temp2[j]=temp2[j+1];
                    temp2[j+1]=tem2;
                    strcpy(tem,temp[j]);
                    strcpy(temp[j],temp[j+1]);
                    strcpy(temp[j+1],tem);
                }
            }
        }

        for(i=0;i<count;i++)
        {
            printf("%d  %s ",temp2[i],temp[i]);
        }
    }
//function 21:
void FindGamesSchedule()
{
    int dur[20],range[20],str[20],stp[20];
    char names[20][20];
    int day,month;
    int n,i;

 	 printf("Enter the no. of games\n");

    scanf("%d",&n);
    printf("Enter the names of the games\n");
    for(i=0;i<n;i++)
    scanf("%s",names[i]);
    printf("Enter time duration for each match\n");
    for(i=0;i<n;i++)
    scanf("%d",&dur[i]);

    printf("Enter  time range of matches\n");
  for(i=0;i<n;i++)    
scanf("%d%d",&str[i],&stp[i]);
    printf("Enter the date\n");
    scanf("%d%d",&day,&month);
    day=DayoftheYear(day,month);

    int z,flag1,count,temp2[20],j,k;
    char temp[20][20];
    char tem[20];
	int tem2,y;
   for(z=0;z<n;z++)
    {
        count=0;
        for(i=0;i<GROUND_ID;i++)
        {
            for(j=0;j<GAME_ID;j++)
            {
                if(strcmp(names[z],ground_id[i].game_id[j].name)==0)
                {
                    flag1=0;
                    for(y=str[z];y<stp[z];y++)
                    {
                   if(ground_id[i].game_id[j].time[day][y]!=0)
                    flag1=1;
                    }
                    if(flag1==0)
                    {
                    strcpy(temp[count],ground_id[i].name);
                    temp2[count]=ground_id[i].game_id[j].hourly_rate;
                    count++;
                    }
                }
            }

       }
       for(j=0;j<count-1;j++)
        {

                if(temp2[j]>temp2[j+1])
                {
                    tem2=temp2[j];
                    temp2[j]=temp2[j+1];
                    temp2[j+1]=tem2;
                    strcpy(tem,temp[j]);
                    strcpy(temp[j],temp[j+1]);
                    strcpy(temp[j+1],tem);
                }

        }
        printf("Most probable slot for %s game is on %s ground for %d\n",names[z],temp[0],temp2[0]);

}
  }





int main()
{

	initialize();
	scan(5);
	char option[5];

    printf("This a Database for Grounds\n");
    printf("Choose the task to be conducted\n");
    printf("Press a : To Get Ground Info\n");
    printf("Press b : To add Sport\n");
    printf("Press c : To delete Sport\n");
    printf("Press d : To add Ground\n");
    printf("Press e : To delete Ground\n");
    printf("Press f : To update Ground\n");
    printf("Press g : To List games scheduled in the city\n");
    printf("Press h : To get Fixtures in the State\n");
    printf("Press i : To get Fixtures Sorted on date\n");
    printf("Press j : To get Fixtures Sorted on State\n");
    printf("Press k : To check availability\n");
    printf("Press l : To get list of unique sports\n");
    printf("Press m : To get list of ground where a sport can be played\n");
    printf("Press n : To Find location for Game Events\n");
    printf("Press o : To Find Locations for the Game \n ");
    printf("Press p : To Find Locations for the game in given time range\n");
    printf("Press q : To Check if Matches are clashing\n");
    printf("Press r : To get list of grounds with minimum on match\n ");
    printf("Press s : To get list of grounds having at least given number of matches\n");
    printf("Press t : To sort on Price For a Game\n");
    printf("Press u : To get probable assignment of games so as to reduce cost\n\n\n\n\n");
   int i;
for(i=0;i<5;i++)
	{
	printf("Enter new commnad\t");
scanf("%s",&option[i]);
    switch(option[i])
    {


    case('a'):getGroundInfo();
    break;
    case('b'):addSport();
    break;
    case('c'):deleteSport();
    break;
    case('d'):addGround();
    break;
    case('e'):deleteGround();
    break;
    case('f'):updateGround();
    break;
    case('g'):getFixturesinCity();
    break;
    case('h'):getFixturesinState();
    break;
    case('i'):getFixturesSortedonDate();
    break;
    case('j'):getFixturesSortedonState();
    break;
    case('k'):isAvailable();
    break;
    case('l'):UniqueSports();
    break;
    case('m'):SportswithGround();
    break;
    case('n'):FindLocationsForGameEvents();
    break;
    case('o'):FindLocationForGame();
    break;
    case('p'):FindLocationForGameInTimeRange();
    break;
    case('q'):ClashOfMatches();
    break;
    case('r'):GiveListOfGroundsHavingMinOneMatch();
    break;
    case('s'):GiveListOfGroundsHavingAtleastKMatches();
    break;
    case('t'):SortOnPriceForAGame();
    break;
    case('u'):FindGamesSchedule();
    break;
	default:break;
    }
}
	return 0;
}
