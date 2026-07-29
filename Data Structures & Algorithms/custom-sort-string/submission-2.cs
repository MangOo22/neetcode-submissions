public class Solution
{
    public string CustomSortString(string order, string s)
    {
        StringBuilder ans = new StringBuilder();
        int[] frq = new int[26];

        for (int i = 0; i < s.Length; i++)
        {
            frq[s[i] - 'a']++;
        }

        for (int i = 0; i < order.Length; i++)
        {
            while (frq[order[i] - 'a'] > 0)
            {
                ans.Append(order[i]);
                frq[order[i] - 'a']--;
            }
        }

        for (int i = 0; i < 26; i++)
        {
            while (frq[i] > 0)
            {
                char ch = (char)(i + 'a');
                ans.Append(ch);
                frq[i]--;
            }
        }

        return ans.ToString();
    }
}