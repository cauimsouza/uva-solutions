#include <bits/stdc++.h>
using namespace std;

set<string> dic;

bool solve(string s){
    if(s.empty())
        return 1;
    if(dic.find(s) != dic.end())
        return 0;

    dic.insert(s);

    int posLast, posFirst = 0;
    bool isA = s.front() == 'a';
    bool can = false;
    while(!can){
        if(isA){
            posLast = s.find("b", posFirst);
            if(posLast < 0){ // no more groups
                if(s.length() - posFirst > 1)
                    can = can || solve(s.substr(0, posFirst));
                break;
            }
            else if(posLast  - posFirst > 1){
                can = can || solve(s.substr(0, posFirst) + s.substr(posLast));
            }
            posFirst = posLast;
            isA = false;
        }
        else{
            posLast = s.find("a", posFirst);
            if(posLast < 0){ // no more groups
                if(s.length() - posFirst > 1)
                    can = can || solve(s.substr(0, posFirst));
                break;
            }
            else if(posLast  - posFirst > 1){
                can = can || solve(s.substr(0, posFirst) + s.substr(posLast));
            }
            posFirst = posLast;
            isA = true;
        }
    }
    return can;
}

int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
        dic.clear();
        string inp;
        cin >> inp;
        printf("%d\n", solve(inp));
    }
}
