class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q; //{word,dis};
        set<string> s(wordList.begin(),wordList.end());
        if(s.find(endWord)==s.end()) return 0;
        q.push({beginWord,1});
        s.erase(beginWord);
        while(!q.empty()){
            string topWord=q.front().first;
            int level=q.front().second;
            q.pop();
            for(int i=0;i<topWord.length();i++){
                char orichar=topWord[i];
                for(int j=0;j<26;j++){
                    char ch='a'+j;
                    topWord[i]=ch;
                    if(topWord==endWord) return level+1;
                    if(s.find(topWord)!=s.end()){
                        q.push({topWord,level+1});
                        s.erase(topWord);
                    }

                }
                topWord[i]=orichar;
            }
        }
        return 0;
    }
};