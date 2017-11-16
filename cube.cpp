/*
 0 for white
 1 for orange
 2 for yellow
 3 for red
 4 for green
 5 for blue
 
 solved state: 731796345686735
*/

#include <iostream>
#include <set>
#include <queue>

using namespace std;
int curside[6][4];
string curs;

set<long long> used;
queue<long long> config;
queue<string> step;

void tonum(int side[6][4], string s)
{
    long long n=0;
    int i, j;
    for(i=0;i<5;i++)
        for(j=0;j<4;j++)
            n+=side[i][j], n*=6;
    for(j=0;j<3;j++)
        n+=side[5][j], n*=6;
    n+=side[5][3];
    if(used.find(n)==used.end())
        used.insert(n), config.push(n), step.push(s);
}

void toside(long long c)
{
    int i, j;
    for(i=5;i>=0;i--)
        for(j=3;j>=0;j--)
            curside[i][j]=c%6, c/=6;
}


void coma()
{
    int side[6][4];
    int i, j;
    for(i=0;i<6;i++)
        for(j=0;j<4;j++)
            side[i][j]=curside[i][j];
    
    side[0][1]=side[5][1], side[0][3]=side[5][3];
    side[5][1]=side[2][2], side[5][3]=side[2][0];
    side[2][2]=side[4][1], side[2][0]=side[4][3];
    side[4][1]=curside[0][1], side[4][3]=curside[0][3];
    
    side[1][0]=curside[1][2];
    side[1][1]=curside[1][0];
    side[1][2]=curside[1][3];
    side[1][3]=curside[1][1];
    
    tonum(side, curs+'A');
}

void comb()
{
    int side[6][4];
    int i, j;
    for(i=0;i<6;i++)
        for(j=0;j<4;j++)
            side[i][j]=curside[i][j];
    
    side[0][0]=side[3][0], side[0][1]=side[3][1];
    side[3][0]=side[2][0], side[3][1]=side[2][1];
    side[2][0]=side[1][0], side[2][1]=side[1][1];
    side[1][0]=curside[0][0], side[1][1]=curside[0][1];
    
    side[4][0]=curside[4][1];
    side[4][1]=curside[4][3];
    side[4][2]=curside[4][0];
    side[4][3]=curside[4][2];
    
    tonum(side, curs+'B');
}

void comc()
{
    int side[6][4];
    int i, j;
    for(i=0;i<6;i++)
        for(j=0;j<4;j++)
            side[i][j]=curside[i][j];
    
    side[4][0]=side[3][2], side[4][1]=side[3][0];
    side[3][2]=side[5][3], side[3][0]=side[5][2];
    side[5][3]=side[1][1], side[5][2]=side[1][3];
    side[1][1]=curside[4][0], side[1][3]=curside[4][1];
    
    side[2][0]=curside[2][1];
    side[2][1]=curside[2][3];
    side[2][2]=curside[2][0];
    side[2][3]=curside[2][2];
    
    tonum(side, curs+'C');
}


int main()
{
    int side[6][4];
    int i, j;
    
    cout << "please enter your cube" << endl;
    for(i=0;i<6;i++)
        for(j=0;j<4;j++){
            char input;
            cin >> input;
            if(input=='W')
                side[i][j]=0;
            if(input=='O')
                side[i][j]=1;
            if(input=='Y')
                side[i][j]=2;
            if(input=='R')
                side[i][j]=3;
            if(input=='G')
                side[i][j]=4;
            if(input=='B')
                side[i][j]=5;
        }
    
    tonum(side, "");
    while(!config.empty()){
        long long curc=config.front();
        curs=step.front();
        config.pop(), step.pop();
        
        if(curc==731796345686735){
            cout << curs << endl;
            break;
        }
        
        toside(curc);
        coma(), comb(), comc();
    }
    
    return 0;
}
