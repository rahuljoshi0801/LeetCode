
class Solution 
{
    public:
        string mapWordWeights(vector<string>& words, vector<int>& weights) 
        {
            unordered_map<int,char> mpp;
            for(int i=0;i<26;i++)
            {
                mpp[i]='z'-i;
            }    

            int n=words.size();
            string ans="";
            for(int i=0;i<n;i++)
            {
                int sum=0;
                string word=words[i];
                int size=word.length();
                for(int j=0;j<size;j++)
                {
                    sum+=weights[word[j]-'a'];
                }

                ans+=mpp[sum%26];
            }

            return ans;
        }
};