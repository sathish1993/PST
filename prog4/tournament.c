#include "tournament.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#define DEBUG 0

#define NUM_TEAMS 4
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
Team *game(Team* team1,Team* team2){
int i=0,team1_offensive_sum=0,team1_defensive_sum=0;
int team2_offensive_sum=0,team2_defensive_sum=0;
int j=0,team2_count=0,team1_count=0;
if(team1==NULL || team2 ==NULL){
	return NULL;
}
for(;i<NUM_PLAYERS;i++){
	team1_offensive_sum = team1_offensive_sum + team1->players[i].offensive;
	team1_defensive_sum = team1_defensive_sum + team1->players[i].defensive;
	team2_offensive_sum = team2_offensive_sum + team2->players[i].offensive;
	team2_defensive_sum = team2_defensive_sum + team2->players[i].defensive;
}

//Implementing Handicap Method, Adding random value upto '5' to Team 2 
// Start
team2_offensive_sum = team2_offensive_sum + rand()%5;
team2_defensive_sum = team2_defensive_sum + rand()%5;
// End

for(;j<10;j++){
	if(team1_defensive_sum<(rand()%team2_offensive_sum)){
		team2_count = team2_count+1;	
	}
	if(team2_defensive_sum<(rand()%team1_offensive_sum)){
		team1_count = team1_count+1;
	}
}
printf("\tTeam Names Team1:%s\t Team2:%s\n", team1->name,team2->name);
printf("\tTeam Scores: \n");
printf("\tTeam1 Offensive score:%d\t Team1 Defensive score:%d\n",team1_offensive_sum,team1_defensive_sum);
printf("\tTeam2 Offensive score:%d\t Team2 Defensive score:%d\n",team2_offensive_sum,team2_defensive_sum);
if(team2_count>team1_count){
	printf("\tTeam1 %s : %d\tTeam2 %s : %d\n",team1->name,team1_count,team2->name,team2_count);
	return team2;
}
else if(team1_count>team2_count){
	printf("\tTeam1 %s : %d\tTeam2 %s : %d\n",team1->name,team1_count,team2->name,team2_count);
	return team1;
}else{//If there is a tie adding random value
	team1_count = team1_count + rand()%100;
	team2_count = team2_count + rand()%100;
	if(team1_count<team2_count){
		printf("\tTeam1 %s : %d\tTeam2 %s : %d\n",team1->name,team1_count,team2->name,team2_count);
	return team2;
	}else{
		printf("\tTeam1 %s : %d\tTeam2 %s : %d\n",team1->name,team1_count,team2->name,team2_count);
	return team1;
	}
}
}
//Method to do tournament
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
//method to free memory
void deleteTeam(Team * teamvalue){
	free(teamvalue);
}

