/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <queue>
// using namespace std;

// // Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;

//     Node() {}

//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m;
        queue<Node*> nodes;

        Node* result = new Node(node -> val, vector<Node*>());
        m[node] = result;

        nodes.push(node);
        while(!nodes.empty()) {
            Node* origin = nodes.front(); Node* now = m[origin];
            nodes.pop();
            for (auto neighbor : origin -> neighbors) {
                if (!m[neighbor]) {
                    m[neighbor] = new Node(neighbor->val, vector<Node*>());
                    nodes.push(neighbor);
                }
                (now -> neighbors).push_back(m[neighbor]);
            }
        }
        return result;
    }
};

