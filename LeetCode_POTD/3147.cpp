// LC POTD
// #approach - 1
// used queues, to keep track of the next jump , much of a brute way 
// TC - O(N)
// SC - O(N)
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        if(n == 1)return energy[0];

        queue<pair<int,int>>q;
        q.push({k,energy[0]});

        for(int i = 1; i<n; i++){
            if(q.front().first == i){
                auto it = q.front();
                q.pop();
                it.first = i+k;
                it.second = max(energy[i], it.second+energy[i]);
                q.push(it);
            }else{
                q.push({i+k,energy[i]});
            }
        }
        int ans = INT_MIN;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            ans = max(ans,it.second);
        }
        return ans;
        
    }
};

// #Approach - 2
// #used kadane's algorithm
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = INT_MIN;
        int n = energy.size();
        for(int i = 0; i<k; i++){
            int temp = 0;
            for(int j = i; j<n; j+=k){
                temp = max(energy[j],energy[j]+temp);
            }
            ans = max(ans,temp);
        }   
        return ans;
    }
};

// TC - O(N)
// sc - o(1)

// #approach - 3
// when traversed in reverse order , and update the values accordingly , then the max element in the array is answer
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        for (int i = n-k-1;i >=0; i--) {
            energy[i] += energy[i+k];
        }
        return *max_element(energy.begin(), energy.end());
    }
};
// tc - o(n)
// sc - o(1)