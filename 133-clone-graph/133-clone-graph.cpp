/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*,Node*> copy_graphs;
public:
    Node* cloneGraph(Node* node) {
        if( !node ) return nullptr;
        if( copy_graphs.find(node) == copy_graphs.end() ){
            copy_graphs[node] = new Node(node->val, {});
            for(Node* neighbor : node -> neighbors){
                copy_graphs[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        } 
        return copy_graphs[node];
    }
    
};