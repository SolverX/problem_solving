# include <iostream>
# include <cstdio>
# include <cstdlib>
# include <algorithm>
# include <map>
# include <vector>
using namespace std;
#define VOTED TRUE
#define YET_TO_VOTE FALSE;
int voteCount[51];
int voted[51];
int votes[51];
vector<int> vote_distribution;
int N,cnt=0;
bool found;
bool isPossible(int chef,int friendChef){
    if( chef == friendChef){
        return false;
    }
    return voteCount[chef]<votes[chef] &&  voted[friendChef]==-1;
}
void backtrack(int chef){
    if(found) return;
    if(chef >=N || cnt>N) return;

    if (voteCount[chef]>=votes[chef]){
        cout<<chef<<endl;
        backtrack(chef+1);
        return;
    }
    for(int i=0;i<N;i++){
            if(i!=0){
                cout<<" ";
            }
            cout<<(voted[i]+1);
        }
        cout<<endl;
    if(cnt==N){
        for(int i=0;i<N;i++){
            if(i!=0){
                cout<<" ";
            }
            cout<<(voted[i]+1);
        }
        cout<<endl;
        found=true;
    }
    
    // cout<<vote_distribution.size()<<endl;
    for(int i=0;i<N;i++){
        if(isPossible(chef,i)){
            voteCount[chef]++;
            voted[i] = chef;
            cnt++;
            backtrack(chef);
            voteCount[chef]--;
            voted[i]=-1;
            cnt--;

        }else{
            backtrack()
        }

    }
    
}
int main(){
    freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        cin>>N;
        bool correct = true;
        int sum = 0;
        for(int i=0;i<N;i++){
            voteCount[i]=0;
            voted[i] = -1;
            int tmp;
            cin>>tmp;
            votes[i]=tmp;
            if (tmp > N-1 && correct){
                correct = false;
                break;
            }
            sum += tmp;
        }
        if(!correct || sum!=N){
            cout<<-1<<endl;
            continue;
        }
        cnt=0;
        found=false;
        backtrack(0);
        if(!found){
            cout<<-1<<endl;
        }
    }
    return 0;
}