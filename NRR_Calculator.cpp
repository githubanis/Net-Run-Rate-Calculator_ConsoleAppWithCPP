#include<bits/stdc++.h>
using namespace std;

std::vector<string> teams;
std::vector<float> totalRuns(12), totalRunsOfOpponent(12), totalOvers(12), totalOversOfOpponent(12), netRunRate(12);
std::string temp, t;
int noOfTeams, temp1, temp2;

void ShowOptions(int x) {
    for(int i=0; i<noOfTeams; i++) {
        if(i == x)
            continue;
        cout<<"Press "<<i + 1<<" for team "<<teams[i]<<endl;
    }
}
void TakeInput() {
    cin>>t;
    for(int i=0; i<noOfTeams; i++) {        
        getline(cin, temp);
        teams.push_back(temp);        
    }
    teams[0] = t;
}
void ShowInitialMassege() {
    cout<<"--------> This console app is all about <---------"<<endl;
    cout<<"------------> Net Run Rate Calculator <-----------"<<endl;
    cout<<"How many teams in the group: "<<endl;
}
void InvalidInputMassege(int num) {
    cout<<"Your Input is not right, please try again.."<<endl;
    cout<<"You must choose options between 1 to "<<num<<endl;
}
bool Invalid(int temp) {
    if(temp > noOfTeams || temp < 1) {
        InvalidInputMassege(noOfTeams);
        return true;
    }
    return false;
}
void SaveMatchScores(int x, int y, float rx, float ox, float ry, float oy) {

    totalRuns[x] += rx;
    totalRunsOfOpponent[x] += ry;
    totalRuns[y] += ry;
    totalRunsOfOpponent[y] += rx;
    totalOvers[x] += ox;
    totalOversOfOpponent[x] += oy;
    totalOvers[y] += oy;
    totalOversOfOpponent[y] += ox;
    
    netRunRate[x] = (totalRuns[x] / totalOvers[x]) - (totalRunsOfOpponent[x] / totalOversOfOpponent[x]);
    netRunRate[y] = (totalRuns[y] / totalOvers[y]) - (totalRunsOfOpponent[y] / totalOversOfOpponent[y]);

}
void ShowNetRunRate() {
    for(int i=0; i< noOfTeams; i++) {
        cout<<"Net Run Rate for "<<teams[i]<<" is: "<<netRunRate[i]<<endl;
    }    
}

int main()
{
    ShowInitialMassege();
    cin>>noOfTeams;
    cout<<"There will be exactly "<<((noOfTeams * (noOfTeams - 1)) / 2)<<" match in the group if every team played 1 match with others. \nEnter team names in the group: "<<endl;
    TakeInput();
    ShowOptions(-1);
    cin>>temp1;
    while(Invalid(temp1)) {
        cin>>temp1;
    }      
    for(int i=0; i< ((noOfTeams * (noOfTeams - 1)) / 2); i++) {
        cout<<"\t----> Match no. "<<i + 1<<" <----"<<endl;
        if(i > 0) {
            ShowOptions(-1);
            cin>>temp1;
            while(Invalid(temp1)) {
                cin>>temp1;
            }      
        }
        cout<<"Enter Scores of "<<teams[temp1 - 1]<<": "<<endl;
        float rx, ox, ry, oy;
        cin>>rx;
        cout<<"Enter total over played by "<<teams[temp1 - 1]<<": "<<endl;
        cin>>ox;
        cout<<"\t----> Select opponent <----"<<endl;
        ShowOptions(temp1 - 1);
        cin>>temp2;
        while(Invalid(temp2)) {
            cin>>temp2;
        }   
        cout<<"Enter Scores of "<<teams[temp2 - 1]<<": "<<endl;
        cin>>ry;
        cout<<"Enter total over played by "<<teams[temp2 - 1]<<": "<<endl;
        cin>>oy;
        SaveMatchScores(temp1 - 1, temp2 - 1, rx, ox, ry, oy);
        ShowNetRunRate();
    }
    
	return 0;
}
