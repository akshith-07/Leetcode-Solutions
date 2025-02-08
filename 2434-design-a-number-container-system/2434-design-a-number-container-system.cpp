class NumberContainers {
public:
    unordered_map<int, int> mp;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> idx;
    NumberContainers() {
        mp.reserve(100000);
    }
    
    void change(int index, int number) {
        mp[index]=number;
        idx[number].push(index);
    }
    
    int find(int number) {
        if (idx.count(number)==0) 
            return -1;
        while(!idx[number].empty()){
            int i=idx[number].top();
            if (mp[i]==number) return i;
            idx[number].pop();
        }
        return -1;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();