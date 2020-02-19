#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    /*
    unordered_map<string, int> player;
    for( string name : participant){
        ++player[name];
    }
    
    unordered_map<string, int>::iterator itr;
    for(itr=player.begin(); itr != player.end(); itr++){
        
        cout << itr->first << "," << itr->second << endl;
    }
    
    for( string name : completion)
    {
        --player[name];
    }
    printf("\n");
    for(itr=player.begin(); itr != player.end(); itr++){
        
        cout << itr->first << "," << itr->second << endl;
    }
    */
    
    
    unordered_map<string, int> player;
    unordered_map<string, int>::iterator itr;
    for(int i = 0; i < participant.size(); i++){
        //player.insert(make_pair(participant[i], 10));
        string name = participant[i];
        player[name] = player[name] + 1;
        
        }
    

    
    for(int i = 0; i < completion.size(); i++){
        unordered_map<string, int>::iterator itr = 
            player.find(completion[i]);
        if( itr != player.end()){
           // cout << "itr : " << itr->first << endl;
            itr->second = itr->second - 1;
        }
    }


    for(itr=player.begin(); itr != player.end(); itr++){
        if( itr->second > 0 ) answer = itr->first;
            //cout << itr->first << endl;
        //cout << itr->first << "," << itr->second << endl;
    }

    
    
    /*
    int i = 0, j = 0, k = 0;
    
    for(i = 0; i < participant.size(); i++){
       for(j = 0; j < completion.size(); j++){
         if( participant[i] == completion[j]){
             cout << participant[i] << endl;
             //cout << completion[j] << endl;
                participant.erase(participant.begin()+i);
                completion.erase(completion.begin()+j);
             //break;
          
             printf("what is the problem?\n");
            }
        }
    }
   // printf("%d\n", participant.size());
    for(k = 0; k < participant.size(); k++){
            //cout << participant[k] << endl;
            }
            
            */
    
    
    
    return answer;
}
