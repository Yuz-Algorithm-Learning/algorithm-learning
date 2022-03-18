#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Node {
    int x;
    int y;
    int idx;
    Node *left;
    Node *right;
};

bool comp(Node &a, Node &b) {
    if(a.y == b.y)
        return a.x < b.x;
    else
        return a.y > b.y;
}

void addNode(Node *parent, Node *child) {
    if(child->x < parent->x) {
        if(parent->left == NULL)
            parent->left = child;
        else
            addNode(parent->left, child);
    } else {
        if(parent->right == NULL)
            parent->right = child;
        else
            addNode(parent->right, child);
    }
}

void preorder(vector<int> &answer, Node *node) {
    if(node == NULL)
        return;
    answer.push_back(node->idx);
    preorder(answer, node->left);
    preorder(answer, node->right);
}

void postorder(vector<int> &answer, Node *node) {
    if(node == NULL)
        return;
    postorder(answer, node->left);
    postorder(answer, node->right);
    answer.push_back(node->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2, vector<int>());
    
    vector<Node> nodes;
    for(int i = 0; i < nodeinfo.size(); i++) {
        Node tmp;
        tmp.x = nodeinfo[i][0];
        tmp.y = nodeinfo[i][1];
        tmp.idx = i + 1;
        nodes.push_back(tmp);
    }
    sort(nodes.begin(), nodes.end(), comp);
    
    Node *root = &nodes[0];
    for(int i = 1; i < nodes.size(); i++) {
        addNode(root, &nodes[i]);
    }
    preorder(answer[0], root);
    postorder(answer[1], root);
    
    return answer;
}