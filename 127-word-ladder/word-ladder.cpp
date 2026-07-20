class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        
        queue<pair<string,int>>q;
        q.push({beginWord,1});

        while(!q.empty()){
            auto [word, length] = q.front();
            q.pop();

            if(word == endWord) return length;

            for(int i = 0; i< word.size(); i++){
                char original = word[i];
                for(char c='a'; c<='z';c++){
                    word[i] = c;
                    if(dict.find(word) != dict.end()){
                        dict.erase(word);
                        q.push({word, length+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};