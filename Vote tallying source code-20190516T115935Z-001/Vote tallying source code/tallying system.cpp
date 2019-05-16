
#include <iostream>
#include <iomanip>
using namespace::std;

#define N 5
char names[N][20];
int votes[N];
float percent[N];
int totalVotes;
int winnerPos; 
int winnerVotes;

void get_input(){
int i;
totalVotes = 0;
for (i=0;i<N;i++)
{
cout << "Enter Last Name of Candidate" << endl;
cin >> names[i]; 
cout << "Enter Number of Votes received " << endl;
cin >> votes[i]; 
totalVotes += votes[i]; 
}

}
void calculate_winner()
{
int i;
winnerPos = 0;
winnerVotes = votes[0];

for (i=1;i<N;i++)
if ( winnerVotes < votes[i] )
{
winnerPos = i;
winnerVotes = votes[i];
}
}
void show_output(){
int i;
cout<<setiosflags(ios::left)<<setw(20)<<"Candidate"
<<"Votes Rec"<<setiosflags(ios::left)<<setw(12)<<"% Of Total Votes"<<endl;
for ( i = 0; i < N; i++ )
cout<<setiosflags(ios::left)<<setw(20)<<names[i]
<<setw(12)<<votes[i]
<<setw(10)<<((float)votes[i]/(float)totalVotes)*100.0<<"%"
<<endl;
cout<<endl;
cout<<"Winner of the election "<<names[winnerPos];
}
int main(){
get_input();
calculate_winner();
show_output();
return 0;
}
