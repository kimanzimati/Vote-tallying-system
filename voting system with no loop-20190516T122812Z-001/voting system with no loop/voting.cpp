#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[50];
	int votes;
} candidates_t;

void showBallot(candidates_t cand[], int size) {
	int i;
	printf("\n");
	printf("\t\t\t\t OFFICIAL BALLOT\n");
	printf("\t\t OFFICIAL LIST OF STUDENT COUNCIL CANDIDATES 2010\n");
	printf("\t\t\tDE LA SALLE UNIVERSITY-MANILA\n\n\n");

	for(i=0; i<size; i++) {
		printf("%d. %s\n", (i+1), cand[i].name);
	}

	// system("pause"); system("cls"); BAD

	printf("INSTRUCTION:\n");
	printf("TO VOTE FOR A CANDIDATE,INPUT THE NUMBER CORRESPONDING TO YOUR\n");
	printf("CHOSEN STUDENCT COUNCIL CANDIDATE.\n\n");
	printf("Enter Candidate Number (1-%d) you want to Vote: \n\n\n", (size+1));
	
}

int getVoteFromUser(int size) {
	int vote;

	for(;;)/> {
		printf("Vote: ");
		scanf("%d",&vote);
		vote--;
		if(vote>=0 && vote<20) { break; }
		printf("Invalid Vote! Please Try Again\n");
	}
	return vote;
}

void showResults(candidates_t cand[], int size) {
	int i;
	for(i=0; i<size; i++) {
		printf("%s got %d votes\n", cand[i].name, cand[i].votes);
	}
}

int main() {
	candidates_t cand[] = { 
		{ "AQUINO, Juan Gabriel", 0}, { "ASUNCION, Beal", 0}, { "CHONG, Jessica", 0},
		{ "DACANAY, Therese", 0}, { "DE LEON, Alveene Joyce", 0}, { "ESPELETA, Paola", 0},
		{ "GABALDON, Neil", 0}, { "HADAP, Krista", 0}, { "JUANO, Jeffrey", 0},
		{ "KIONG, Jennifer", 0}, { "LIM, Jeremy", 0}, { "LO, Jimmy", 0},
		{ "NG, Robbie", 0}, { "ORMOC, Regan", 0}, { "PANULAYA, Leonila", 0},
		{ "RECENO, Roy Justin", 0}, { "SEVILLA, Nigel", 0}, { "TAN, Donald", 0},
		{ "UY, Jocelle", 0}, { "VELASCO, Anton", 0},
	};
	int candSize = sizeof(cand)/sizeof(candidates_t);
	
	showBallot(cand, candSize);
	
	cand[getVoteFromUser(candSize)].votes++;
	cand[getVoteFromUser(candSize)].votes++;
	showResults(cand, candSize);
	
	return 0;
}

