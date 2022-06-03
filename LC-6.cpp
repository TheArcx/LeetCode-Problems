class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        string t;
        vector<string> vec(numRows, "");
        int i = 0, j = 0;
        while (i < s.length())
        {
            while (j < numRows - 1 && i < s.length())
            {
                vec[j++] += s[i++];
            }
            while (j > 0 && i < s.length())
            {
                vec[j--] += s[i++];
            }
        }
        for (auto i = vec.begin(); i != vec.end(); i++)
        {
            t += *i;
        }
        return t;
    }
};