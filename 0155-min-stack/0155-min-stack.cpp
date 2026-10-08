class MinStack {
public:
    vector<int> st;
    vector<int> minSt;
    int min;

    MinStack() {
    }   
    
    void push(int value) {
        st.push_back(value);

        if(st.size() == 1) {
            minSt.push_back(value);
            min = value;
        }
        else if(value <= min) {
            minSt.push_back(value);
            min = value;
        }
        else {
            minSt.push_back(min);
        }
    }
    
    void pop() {
        st.pop_back();
        minSt.pop_back();

        if(!minSt.empty()) {
            min = minSt.back();
        }
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minSt.back();
    }
};