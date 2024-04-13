/*Preparation:
for example, nums={1, 3, 5, 4, 7}
For every index i of nums, we will consider the longest increasing subsequence(LIS) up to nums[i].
We will capture (1) number of these LISs up to nums[i], and (2) there length. Let 
    acc[i] = largest accumulated length of an increasing sequence up to nums[i]
    ways[i] = number of ways getting a LIS up to nums[i]

In the above case, 
    {1(acc=1, ways=1), 3(acc=2, ways=1), 5(acc=3, ways=1), 4(acc=3, ways=1), 7(acc=4, ways=2)}
Finding number of LIS in this problem would mean finding the maximal "acc", 
and then return its total "ways" as answer
*/

/*Using segment tree to solve for acc's and ways's
e.g. nums={1, 3, 5, 2 ,4, 7}
sort nums in ascending order => v={1, 2, 3, 4, 5, 7}
the new index of nums[i] is given by indexMap={0, 2, 4, 1, 3, 5}

create a segment tree (sgTree) of vector v.
A leaf node of sgTree captures the pair (acc, ways) of the number v[j].
An interior node tree[x] has two children, tree[2*x] and tree[2*x+1].
    if the acc's of tree[2*x] and tree[2*x+1] differ from the other, 
    tree[x]= (larger acc, the corresponding ways) between tree[2*x] & tree[2*x+1],
    since only the longest LIS's concern us.

    if (tree[2*x].first==tree[2*x+1]), we get to tree[x]=(acc[2*x], ways[2*x]+ways[2*x+1])
    since number of ways would add up in this case

(i=0) sgTree is of nodes written in (acc/ways) as in the following diagram.
From left to right, each leaf node represents an entry v[i] of vector v.

                  (0/0)
               /         \
            (0/0)        (0/0)
             /  \         /  \
         (0/0)  (0/0)  (0/0)  (0/0)
         /   \         /   \
     (0/0)   (0/0)  (0/0)  (0/0)

x=nums[0]=1=v[0] => acc/ways=1/1. We update the first leaf node (j=0):

                  (1/1)
               /         \
            (1/1)        (0/0)
             /  \         /  \
         (1/1)  (0/0)  (0/0)  (0/0)
         /   \         /   \
     (1/1)   (0/0)  (0/0)  (0/0)

--------------------------------------------------------------------------------
(i=1) x=nums[1]=3=v[2]
To find acc/ways of nums[1], we consider all visited previous leaf nodes of value<x.
So, acc = maximum acc[j] of these leaf nodes,
ways = sum of ways[j]'s of leaf nodes having the maximal acc[j] (as above).
In practice, we trace from the root of sgTree following these principles:

(1) when tree[x] represents the range [left, right] of v,
if v[right]<x, then every leaf node in [left, right] is of value<x
=> take tree[x]=(acc[x], ways[x]) into consideration directly

(2) the children of tree[x] are tree[2*x] and tree[2*x+1], 
representing the ranges [left,mid] and [mid+1,right] respectively.
If (x<=v[mid]), we pass to tree[2*x] directly
if (x>v[mid]), every leaf node under tree[2*x] is of value<x
    so we have to look at tree[2*x]=(acc[2*x], ways[2*x])
    and then compare it with what we get from query at tree[2*x+1].

in this case, x=3 means that we look at ...
    the range [0,1]: tree[x] = (1, 1)
=> acc=1+1, ways=1 (i.e. {1,3})=> update the 3rd leaf node (j=2) by 2/1:

                  (2/1)
               /         \
            (2/1)        (0/0)
             /  \         /  \
         (1/1)  (2/1)  (0/0)  (0/0)
         /   \         /   \
     (1/1)   (0/0)  (0/0)  (0/0)

 v={1, 2, 3, 4, 5, 7}
--------------------------------------------------------------------------------
(i=2) x=5=nums[2]=v[4]
query: v[2]=3<x => range [0,2]: tree[x]=(2, 1)
       v[3]=4<x => range [3]: tree[x]=(0, 0) 
=> acc=3, ways=1, i.e. {1,3,5}
update:
                  (3/1)
               /         \
            (2/1)        (3/1)
             /  \         /  \
         (1/1)  (2/1)  (3/1)  (0/0)
         /   \         /   \
     (1/1)   (0/0)  (0/0)  (3/1)

 v={1, 2, 3, 4, 5, 7}
--------------------------------------------------------------------------------
(i=3) x=2=nums[3]=v[1]
query: v[0]=1<x => range [0]: tree[x]=(1,1)
=> acc=2, ways=1, i.e. {1,2}
update:
                  (3/1)
               /         \
            (2/2)        (3/1)
             /  \         /  \
         (2/1)  (2/1)  (3/1)  (0/0)
         /   \         /   \
     (1/1)   (2/1)  (0/0)  (3/1)

 v={1, 2, 3, 4, 5, 7}
--------------------------------------------------------------------------------

(i=4) x=4=nums[4]=v[3]
query: v[2]=3<4 => range [0,2]: tree[x]=(2, 2)
=> acc=3, ways=2, i.e. {1,2,4} and {1,3,4}
update:
                  (3/3)
               /         \
            (2/2)        (3/3)
             /  \         /  \
         (2/1)  (2/1)  (3/3)  (0/0)
         /   \         /   \
     (1/1)   (2/1)  (3/2)  (3/1)

 v={1, 2, 3, 4, 5, 7}
--------------------------------------------------------------------------------

(i=5) x=7=nums[5]=v[5]
query: v[2]=3<7 => range [0,2]: tree[x]=(2,2)
query: v[4]=5<7 => range [3,4]: tree[x]=(3,3)
=> acc=4, ways=3, i.e. {1,3,4,7}, {1,2,4,7}, {1,3,5,7}
update: 
                  (4/3)
               /         \
            (2/2)        (4/3)
             /  \         /  \
         (2/1)  (2/1)  (3/3)  (4/3)
         /   \         /   \
     (1/1)   (2/1)  (3/2)  (3/1)
--------------------------------------------------------------------------------

return the information of tree[1] as result
*/

struct segmentTree{
    std::vector<std::pair<int,int>> tree;
    //tree[x] = {acc[x], ways[x]}
    std::vector<int> u;
    int N;
    segmentTree(std::vector<int>& v){
        N = v.size();
        tree.resize(4*N, std::pair<int,int>(0,0));
        for (int i=0; i<N; i++)
            u.push_back(v[i]);
        return;
    }

    void update(int x, int left, int right, int index, int acc, int ways){
        if (left==right){
            tree[x].first = acc;
            tree[x].second = ways;
            return;
        }
        int mid = (left+right)/2;
        if (index<=mid){
            update(2*x, left, mid, index, acc, ways);
        }else{
            update(2*x+1, mid+1, right, index, acc, ways);
        }
        if (tree[2*x].first>tree[2*x+1].first){
            tree[x] = tree[2*x];
        }else if (tree[2*x+1].first>tree[2*x].first){
            tree[x] = tree[2*x+1];
        }else{
            tree[x].first = tree[2*x].first;
            tree[x].second = tree[2*x].second + tree[2*x+1].second;
        }
        return;
    }

    std::pair<int,int> query(int x, int left, int right, int value){
        if (u[right]<value){
            return tree[x];
        }
        if (value<=u[left]){
            return std::pair<int,int>(0,0);
        }

        int mid = (left+right)/2;
        std::pair<int, int> temp;
        std::pair<int, int> result;

        if (value<=u[mid]){
            result = query(2*x, left, mid, value);

        }else{
            temp = query(2*x+1, mid+1, right, value);
            if (temp.first>tree[2*x].first){
                result.first = temp.first;
                result.second = temp.second;

            }else if (tree[2*x].first>temp.first){
                result.first = tree[2*x].first;
                result.second = tree[2*x].second;

            }else{
                result.first = tree[2*x].first;
                result.second = tree[2*x].second + temp.second;
            }
        }        
        return result;
    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        std::vector<std::pair<int,int>> numsPair;
        std::vector<int> indexMap(n, 0);
        std::vector<int> v(n, 0);
        for (int i=0; i<n; i++){
            numsPair.push_back(std::make_pair(nums[i], i));
        }
        std::sort(numsPair.begin(), numsPair.end());
        for (int j=0; j<n; j++){
            v[j] = numsPair[j].first;
            indexMap[numsPair[j].second] = j;
        }

        segmentTree sgTree = segmentTree(v);
        std::pair<int, int> myPair;
        int acc, ways;
        // i=0
        sgTree.update(1, 0, n-1, indexMap[0], 1, 1);

        for (int i=1; i<n; i++){
            myPair = sgTree.query(1, 0, n-1, nums[i]);
            acc = myPair.first+1;
            ways = std::max(1, myPair.second);
            //std::cout<<"acc="<<acc<<", ways="<<ways<<"\n";
            sgTree.update(1, 0, n-1, indexMap[i], acc, ways);
        }

        //std::cout<<"("<<sgTree.tree[1].first<<", "<<sgTree.tree[1].second<<")\n";
        return sgTree.tree[1].second;

    }
};