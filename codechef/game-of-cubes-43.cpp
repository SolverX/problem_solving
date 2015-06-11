    # include <iostream>
    # include <cstdio>
    # include <cstdlib>
    # include <cstring>
    # include <algorithm>
    # include <map>
    # include <vector>
    using namespace std;
    typedef long long ull;
    typedef pair<int,int> ii;
    int R,C;
    char S[108][108];
    vector<ii> List1;
    bool visited[101][101];
    int dx[]={-1,0,0,1},dy[]={0,-1,1,0};
    void generateClusterList(int x,int y){
        if(x>=R || y>=C ||x<0 || y<0) return;
        if(visited[x][y] || S[x][y]!='x')return;
        visited[x][y]=true;
        List1.push_back(ii(x,y));
        for(int i=0;i<4;i++){
            generateClusterList(x+dx[i],y+dy[i]);
        }

    }
    int cmp(ii a,ii b){
        if( a.first < b.first){
            return true;
        }else if(a.first==b.first){
            return a.second<b.second;
        }
        return false;
    }
    int DropPoint(int x,int y){
        if(x==0){
            return -3;
        }
        x--;
        if( x>=0 && S[x][y]=='x'){
            return -2;
        }
        // cout<<y<<endl;
        for(;x>=0;x--){
            if(S[x][y]=='x'){
                // cout<<"came"<<x<<endl;
                return x;
            }
        }
        return -1;
    }
    void pullDown(int height){
        
        height--;
        // cout<<height<<endl;
        // cout<<"----"<<endl;
        for(int i=0;i<List1.size();i++){
            int x= List1[i].first , y = List1[i].second;
            S[x][y]='.';
            // cout<<x<<" "<<y<<endl;
            if(x-height>=0){
                
                S[x-height][y]='x';
            }
        }
    }
    void updateCluster(){
        if(List1.size()<=0)
            return;
        sort(List1.begin(),List1.end(),cmp);
        int firstX=-1,firstY=-1,secondX=C+1,secondY=C+1;
        int height = R+1;
        for(int i=0;i<List1.size();i++){
                int tmp =DropPoint(List1[i].first,List1[i].second);
                // cout<<"DROPPOINT"<<endl;
                // cout<<firstX<<" "<<tmp<<" "<<List1[i].first<<" "<<List1[i].second<<endl;
                // cout<<"---"<<endl;
                if(tmp==-3){
                    return;
                }
                if(tmp>=-1){
                    //  if(firstX==tmp){
                    //     
                    // }
                    if( height > (List1[i].first-tmp) ){
                        // cout<<(firstX-tmp)<<endl;
                        height = List1[i].first-tmp;
                        firstX=tmp;
                        firstY=List1[i].second;
                        secondX=List1[i].first;
                        secondY=List1[i].second;
                    }

                }
        }
        // cout<<firstX<<" "<<firstY<<endl;
        // cout<<secondX<<" "<<secondY<<endl;
        pullDown(secondX - firstX );
    }

    int main(){
        freopen("in.txt","r",stdin);
        scanf("%d %d\n",&R,&C);
        for(int i=R-1;i>=0;i--){
            scanf("%s\n",S[i]);
        }
        int Q;
        cin>>Q;
        int move = 0;
        while(Q--){
            int x,y=-1;
            cin>>x;
            x--;
            if(move%2==0){
                for(int i=0;i<C;i++){
                    if(S[x][i]=='x'){
                        y=i;
                        break;
                    }
                }
            }else{
                y=-1;
                for(int i=C-1;i>=0;i--){
                    if(S[x][i]=='x'){
                        y=i;
                        break;
                    }
                }
            }
            if(y!=-1){
                // cout<<x<<" "<<y<<endl;
                S[x][y]='.';
                memset(visited,0,sizeof(visited));
                List1.clear();
                generateClusterList(x-1,y);
                // cout<<List1.size()<<endl;
                // for(int i=0;i<List1.size();i++){
                //     cout<<(List1[i].first)<<" "<< (List1[i].second)<<endl;
                // }
                // cout<<"Fgddfg";
                updateCluster();
                List1.clear();
                if(move%2==0){
                    generateClusterList(x,y+1);
                }else{
                    generateClusterList(x,y-1);
                }
                // cout<<List1.size()<<endl;
                // for(int i=0;i<List1.size();i++){
                //     cout<<(List1[i].first)<<" "<< (List1[i].second)<<endl;
                // }
                // cout<<"Fgddfg";
                updateCluster();
                List1.clear();
                generateClusterList(x+1,y);
                // for(int i=0;i<List1.size();i++){
                //     cout<<(List1[i].first)<<" "<< (List1[i].second)<<endl;
                // }
                // cout<<"Fgddfg";
                updateCluster();
                
            }
            move++;
        }
        for(int i=R-1;i>=0;i--){
            cout<<S[i]<<endl;
        }

        return 0;
    }