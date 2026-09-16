public class Solution {
    public List<string> GetNextValidWords(string word, HashSet<string> wordList) {
        var children = new List<string>();
        char[] chars = word.ToCharArray();
        
        for (int i = 0; i < chars.Length; i++) {
            char mainChar = chars[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (ch == mainChar) continue;
                chars[i] = ch;
                string transformedWord = new string(chars);
                if (wordList.Remove(transformedWord))
                {
                    children.Add(transformedWord);
                }
            }
            chars[i] = mainChar;
        }
        return children;
    }
    public int BFS(string beginWord, string endWord, HashSet<string> wordList) {

        if (beginWord == endWord || !wordList.Contains(endWord)) {
            return 0;
        }

        int ans = 0;
        var q = new Queue<string>();
        q.Enqueue(beginWord);
        
        while(q.Count > 0) {
            ans++;
            int len = q.Count;
            for (int i = 0; i < len; i++) {
                string curWord = q.Dequeue();
                if (curWord == endWord) {
                    return ans;
                }
                List<string> nextValidWords = GetNextValidWords(curWord, wordList);
                
                foreach(var word in nextValidWords) {
                    q.Enqueue(word);
                }

            }
        }
        return 0;
    }
    public int LadderLength(string beginWord, string endWord, IList<string> wordList) {
        HashSet<string> setOfWordList = new HashSet<string>(wordList);
        return BFS(beginWord, endWord, setOfWordList);
    }
}
