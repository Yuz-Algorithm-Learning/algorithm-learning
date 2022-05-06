#include <string>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int n;
    Node* prev;
    Node* next;
    Node(int n, Node* prev, Node* next) : n(n), prev(prev), next(next) {}
};

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'O');
    
    Node* curr = new Node(0, NULL, NULL);
    for(int i = 1; i < n; i++) {
        curr->next = new Node(i, curr, NULL);
        curr = curr->next;
    }
    
    for(int i = 0; i < n - k - 1; i++)
        curr = curr->prev;
    
    stack<Node*> del;
    for(string str : cmd) {
        if(str[0] == 'U' || str[0] == 'D') {
            int x = stoi(str.substr(2));
            
            if(str[0] == 'U') {
                while(x--)
                    curr = curr->prev;
            } else {
                while(x--)
                    curr = curr->next;
            }
        } else if(str[0] == 'C') {
            del.push(curr);
            if(curr->prev != NULL) curr->prev->next = curr->next;
            if(curr->next != NULL) curr->next->prev = curr->prev;
            
            if(curr->next == NULL) curr = curr->prev;
            else curr = curr->next;
        } else {
            Node *re = del.top();
            del.pop();
            
            if(re->prev != NULL) re->prev->next = re;
            if(re->next != NULL) re->next->prev = re;
        }
    }
    
    while(!del.empty()) {
        int num = del.top()->n;
        del.pop();
        answer[num] = 'X';
    }
    
    return answer;
}