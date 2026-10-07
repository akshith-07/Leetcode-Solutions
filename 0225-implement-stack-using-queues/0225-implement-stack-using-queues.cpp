class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int temp;
        while(!q1.empty()){
            q2.push(q1.front());
            temp = q1.front();
            q1.pop();
        }

        while(q2.size()>1){
            q1.push(q2.front());
            q2.pop();
        }
        q2.pop();
        return temp;
    }
    
    int top() {
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int temp = q1.front();
        q2.push(temp);
        q1.pop();
        swap(q1, q2);
        return temp;
    }
    
    bool empty() {

        if(q1.empty()){
            return true;
        }else{
            return false;
        }
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */