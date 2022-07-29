class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
         unordered_map<int,int> candies;
        for(int candy : candyType) candies[candy]++;
        int candies_you_can_eat = candyType.size()/2;
        return candies.size() > candies_you_can_eat ? candies_you_can_eat : candies.size();
    }
};