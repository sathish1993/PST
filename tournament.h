#ifndef tournament_H
#define tournament_H

typedef struct player{
int offensive;
int defensive;
} Player;

typedef struct team{
char* name;
Player players[10];
} Team;


Team* initializeteam(int,char*);
Team* game(Team*,Team *);
Team* tournament(Team **,int);
void deleteTeam(Team*);
#endif
