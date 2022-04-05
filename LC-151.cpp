class Solution
{
public:
    string reverseWords(string s)
    {

        // reverse string
        reverse(s.begin(), s.end());

        int size = s.size();
        int index = 0;
        for (int start = 0; start < size; ++start)
        {
            if (s[start] != ' ')
            {

                // Beginning of word
                if (index != 0)
                    s[index++] = ' ';

                // EoW
                int end = start;

                while (end < size && s[end] != ' ')
                    s[index++] = s[end++];

                // Reverse word back to normal
                reverse(s.begin() + index - (end - start), s.begin() + index);

                start = end;
            }
        }
        s.erase(s.begin() + index, s.end());
        return s;
    }
};