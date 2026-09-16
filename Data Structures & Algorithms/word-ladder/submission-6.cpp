class Solution {

    vector<string> GetChilds(string word, unordered_set<string>& words) {
        int n = word.size();
        vector<string> childs;
        for (int i = 0 ; i < n; i++) {
            char mainChar = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (mainChar == ch) { continue; }
                
                word[i] = ch;
                if (words.find(word) != words.end()) {
                    childs.push_back(word);
                    words.erase(word);
                }
            }
            word[i] = mainChar;
        }
        return childs;
    }


public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        
        if (beginWord == endWord or words.find(endWord) == words.end()) { 
            return 0;
        }
       
        int depth = 0;
        queue<string> q;
        q.push(beginWord);
        
        while(!q.empty()) {
            depth++;
            int len = q.size();
            for (int i = 0; i < len; i++) {
                string curNode = q.front(); q.pop();
                if (curNode == endWord) { return depth; }
                vector<string> childs = GetChilds(curNode, words);
                for (auto& child: childs) {
                    q.push(child);
                }
            }
        }

        return 0;
    }
};


/* 
    1) end words must be in the word list 
    2) List<string> GetNextTransforWords(string currentWord) => return nextTransforWord
       cat => bat 
       bat => bag
       etc..
    3) BFS


*/
