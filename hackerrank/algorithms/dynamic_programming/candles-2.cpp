#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <bitset>
using namespace std;
#define VISITED 2
#define EXPLORED 1
#define UN_VISISTED 0

typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

class Candle{
public:
    int height;
    int color_code;
    Candle(int _height,int _color){height=_height,color_code=_color;}
};

class Series{
private:
    int maxColor;
    int color[8];
    int colorCount;
public:
    Series(int colorLimit){
        memset(color,0,sizeof(color));
        colorCount=0;
        maxColor=colorLimit;
    }
    Series(){}
    void addColor(int colorCode){
        color[colorCode]++;
        if(color[colorCode]==1){
            colorCount++;
        }
        
    }

    void removeColor(int colorCode){
        color[colorCode]--;
        if(color[colorCode]==0){
            colorCount--;
        }
        
    }

    bool isPerfectSeries(){
        return colorCount==maxColor;
    }

};

vector<Candle> candles;

int candleCount,colorCount;
Series colorSeries;
long long DP[50001];
int maxPossibleSeries(int pos){
    if(DP[pos]!=0) return DP[pos];
    colorSeries.addColor(candles[pos].color_code);
    int current = candles[pos].height;
    if(colorSeries.isPerfectSeries()){
        colorSeries.removeColor(candles[pos].color_code);
        return 1;
    }
    int sum=0;
    for(int i=pos-1;i>=0;i--){
        int val = candles[i].height;
        if(current>val){
            sum += maxPossibleSeries(i);
            sum%=1000000007;
        }
    }
    colorSeries.removeColor(candles[pos].color_code);
    return DP[pos]=sum;
}
int main(){
    freopen("in.txt","rt",stdin);
    cin>>candleCount>>colorCount;
    colorSeries = Series(colorCount);
    for(int i=0;i<candleCount;i++){
        DP[i]=0;
        int height,color;
        cin>>height>>color;
        candles.push_back(Candle(height,color));
    }
    int maxValue=0;
    for(int i=candleCount-1;i>=0;i--){
        maxValue = max (maxValue,maxPossibleSeries(i));
    }
    cout<<maxValue<<endl;
    // cout<<candles.size()<<endl;
    return 0;
}