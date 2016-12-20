#include "tournament.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#define DEBUG 0

#define NUM_TEAMS 16
#define NUM_PLAYERS 10

//Method to initialize struct members
Team *initializeTeam(int num_of_players,char* teamname){
int i=0;
Team* team_n =(Team*)malloc(sizeof (Team));
team_n->name=teamname;
for(;i<num_of_players;i++){
	team_n->players[i].offensive = rand()%10 + 1;
	team_n->players[i].defensive = rand()%10 + 1;
}
return team_n; 
}

//Method to conduct Game between 2 teams
Team *game(Team* t1,Team* t2){
int i=0,t1_offensive_sum=0,t1_defensive_sum=0;
int t2_offensive_sum=0,t2_defensive_sum=0;
int j=0,t2_count=0,t1_count=0;
if(t1==NULL || t2 ==NULL){
	return NULL;
}
for(;i<NUM_PLAYERS;i++){
	t1_offensive_sum = t1_offensive_sum + t1->players[i].offensive;
	t1_defensive_sum = t1_defensive_sum + t1->players[i].defensive;
	t2_offensive_sum = t2_offensive_sum + t2->players[i].offensive;
	t2_defensive_sum = t2_defensive_sum + t2->players[i].defensive;
}

//Implementing Handicap Method, Adding random value upto '5' to Team 2 
// Start
t2_offensive_sum = t2_offensive_sum + rand()%5;
t2_defensive_sum = t2_defensive_sum + rand()%5;
// End

for(;j<10;j++){
	if(t1_defensive_sum<(rand()%t2_offensive_sum)){
		t2_count = t2_count+1;	
	}
	if(t2_defensive_sum<(rand()%t1_offensive_sum)){
		t1_count = t1_count+1;
	}
}
printf("\tTeam Names Team1:%s\t Team2:%s\n", t1->name,t2->name);
printf("\tTeam Scores: \n");
printf("\tTeam1 Offensive score:%d\t Team1 Defensive score:%d\n",t1_offensive_sum,t1_defensive_sum);
printf("\tTeam2 Offensive score:%d\t Team2 Defensive score:%d\n",t2_offensive_sum,t2_defensive_sum);
if(t2_count>t1_count){
	printf("\tTeam1 %s : %d\tTeam2 %s : %d\n",t1->name,t1_count,t2->name,t2_count);
	return t2;
}
else if(t1_count>t2_count){
	printf("\tTeam1 %s : %d\tTeam2 %s : %d\n",t1->name,t1_count,t2->name,t2_count);
	return t1;
}else{//If there is a tie adding random value
	t1_count = t1_count + rand()%100;
	t2_count = t2_count + rand()%100;
	if(t1_count<t2_count){
	printf("\tTeam1 %s : %d\tTeam2 %s : %d\n",t1->name,t1_count,t2->name,t2_count);
	return t2;
	}else{
	printf("\tTeam1 %s : %d\tTeam2 %s : %d\n",t1->name,t1_count,t2->name,t2_count);
	return t1;
	}
}
}

Team * tournament(Team ** league,int noofteams){
int i=0,r=0,j=0,k=0;
int flagteam = 0;
Team * roundwinner[noofteams-1];
for(;i<10;i++){
	if(noofteams==(int)pow((int)2.0,(int)i)){
		flagteam=1;
		int rounds=(int)(log(noofteams)/log(2));
		if(r==0){
			printf("\n\t*******************ROUND 0*******************\n");
			while(k<noofteams){
				printf("\n");
				roundwinner[j]=game(league[k],league[k+1]);
				j++;
				k+=2;
			}
		}
		int teamcount = noofteams/2;
		for(r=1;r<rounds;r++){
		k=0;
		if(r!=1){
			teamcount = teamcount/2;
		}
		printf("\n\t*******************ROUND %d**************************\n",r);
		j=0;
		while(k<teamcount){
			printf("\n");
			roundwinner[j]=game(roundwinner[k],roundwinner[k+1]);
			j+=1;
			k+=2;
		}
		}
	return roundwinner[0];
	}
}
if(flagteam==0){
	printf("\tPlease Enter Number of Teams in the powers of 2, Given Number is invalid\n");
	return NULL;
}
}

void deleteTeam(Team * t){
	free(t);
}

