class Solution {
public:
    
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, unordered_set<int>> mp;
        for( auto rev : reservedSeats){
            mp[rev[0]].insert(rev[1]);
        }
        
       int  result = (n - mp.size())*2;
       for(auto& [row ,bookedSeats ] : mp ){
        auto isAvailable =[&](int seat){
            return bookedSeats.find(seat) == bookedSeats.end();
        };
        bool GroupA = isAvailable(2) && isAvailable(3) && isAvailable(4) && isAvailable(5);
        bool GroupB = isAvailable(4) && isAvailable(5) && isAvailable(6) && isAvailable(7);
        bool GroupC = isAvailable(6) && isAvailable(7) && isAvailable(8) && isAvailable(9);
        if(GroupA && GroupC)
            result += 2;
            else if(GroupA|| GroupB || GroupC) result +=1;
       }
       return result;
        



    }
};