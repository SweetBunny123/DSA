class Solution {
public:
     void update(vector<vector<int>>& segmentTree, int index, char ch, string &s) {
        // Update the segment tree with the new character at the specified index
        int j = s.size() + index - 1;
        int parent = (j - 1) / 2;
        int i;
        int parent_zero = 0;
        if(ch != s[index])
        {
            s[index] = ch;
            // Update the segment tree upwards until the root
            while (parent >=0) {
                if(parent==0 && parent_zero==1)
                {
                    break;
                }
                else if(parent==0 && parent_zero == 0)
                {
                    parent_zero++;
                }
                i = parent;
                int left = 2 * i + 1;
                int right = 2 * i + 2;
            // return{segmentTree[left][2]};
                if (s[segmentTree[left][2]] == s[segmentTree[right][1]]) { 
                // Fixed syntax
                segmentTree[i][4] = segmentTree[left][3] + segmentTree[right][0];

                segmentTree[i][4] = max(max(segmentTree[left][4], segmentTree[right][4]), segmentTree[i][4]);
                segmentTree[i][0] = segmentTree[left][0];
                segmentTree[i][3] = segmentTree[right][3];//since i found them equal 
                //aaa abd  then what i do is
                //if first of last equal and length = first then update first
                if(s[segmentTree[right][1]]== s[segmentTree[right][2]]&& segmentTree[right][0]== segmentTree[right][2]-segmentTree[right][1]+1)
                {
                    segmentTree[i][3] = segmentTree[right][0]+segmentTree[left][3];
                }
                if(s[segmentTree[left][1]]== s[segmentTree[left][2]]&& segmentTree[left][0]== segmentTree[left][2]-segmentTree[left][1]+1)
                {
                    segmentTree[i][0] = segmentTree[left][3]+segmentTree[right][0];
                }
                // if last of first equal and length = first then update last
            }
            else{
                segmentTree[i][4] = max(segmentTree[left][4], segmentTree[right][4]);
                segmentTree[i][0] = segmentTree[left][0];
                segmentTree[i][3] = segmentTree[right][3];
            }
            segmentTree[i][2] = segmentTree[right][2]; // Fixed assignment
            segmentTree[i][1] = segmentTree[left][1]; // Fixed assignment
            parent = (i - 1) / 2;
            }
        }
    }

    int maxlength(vector<vector<int>>&tree)
    {
        return tree[0][4];
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = 1;
        while (n <=s.size()) {
            n = n * 2;
        }

        vector<vector<int>> segmentTree(2*n-1, vector<int>{0, 0, 0, 0, 0}); // Fixed syntax
        int c = 0;
        while(s.size()<n)
        {
            s += c;
            c++;
        }
        int j = 0;
        for (int i = n-1; i < 2*n-1; i++, j++) {
            //prefix length , prefix index ,suffffixindex, suffix length, maxlength
            segmentTree[i][1] = j;
            segmentTree[i][2] = j;
            segmentTree[i][0] = 1;
            segmentTree[i][3] = 1;
            segmentTree[i][4] = 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            // return{segmentTree[left][2]};
            if (s[segmentTree[left][2]] == s[segmentTree[right][1]]) { 
                // Fixed syntax
                segmentTree[i][4] = max(max(segmentTree[left][4], segmentTree[right][4]),  segmentTree[left][3] + segmentTree[right][0]);
                segmentTree[i][0] = segmentTree[left][0];
                segmentTree[i][3] = segmentTree[right][3];//since i found them equal 
                //aaa abd  then what i do is
                //if first of last equal and length = first then update first
                if(s[segmentTree[right][1]]== s[segmentTree[right][2]]&& segmentTree[right][0]== segmentTree[right][2]-segmentTree[right][1]+1)
                {
                    segmentTree[i][3] = segmentTree[right][0]+segmentTree[left][3];
                }
                if(s[segmentTree[left][1]]== s[segmentTree[left][2]]&& segmentTree[left][0]== segmentTree[left][2]-segmentTree[left][1]+1)
                {
                    segmentTree[i][0] = segmentTree[left][3]+segmentTree[right][0];
                }
                // if last of first equal and length = first then update last
            }
            else{
                segmentTree[i][4] = max(segmentTree[left][4], segmentTree[right][4]);
                segmentTree[i][0] = segmentTree[left][0];
                segmentTree[i][3] = segmentTree[right][3];
            }
            segmentTree[i][2] = segmentTree[right][2]; // Fixed assignment
            segmentTree[i][1] = segmentTree[left][1]; // Fixed assignment
        }

        // Add the logic for further processing, like handling queries and returning results.
        vector<int>ans;
        for(int i = 0; i<queryIndices.size();i++)
        {
            update(segmentTree, queryIndices[i], queryCharacters[i], s);
            ans.push_back(maxlength(segmentTree));
        }
        return ans;
    }
};
