#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node {
    char data;
    unsigned frequency;
    Node* left, * right;
    Node(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

class Compare {
    public:
    bool operator()(Node* left, Node* right) {
        return left->frequency > right->frequency;
    }
};

void printqueue(priority_queue <Node*, vector<Node*>, Compare> pq){
    cout<<"Priority queue \n";
    while(pq.size()!=0){
        cout<<pq.top()->data<<' '<<pq.top()->frequency<<endl;
        pq.pop();
    }
}

void generateCodes(Node* root, string code, map<char, string>& codes) {
    if (root->left == nullptr && root->right == nullptr) {
        codes[root->data] = code;
        return;
    }

    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

map<char, string> buildHuffmanTree(string text) {
    for(int i=0; i<text.length(); i++){
        text[i] = tolower(text[i]);
    }
    sort(text.begin(), text.end());
    map<char, unsigned> freq;
    for (char c : text) {
        if (isalpha(c)){
            freq[c]++;
        }
    }
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (auto& pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* internalNode = new Node('$', left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;
        pq.push(internalNode);
    }
    map<char, string> codes;
    generateCodes(pq.top(), "", codes);

    return codes;
}

int main() {
    string text;
    cout<<"Enter text : ";
    getline(cin, text);
    map<char, string> codes = buildHuffmanTree(text);
    cout << "Huffman Codes:\n";
    for (auto &pair : codes) {
        cout << pair.first << ": " << pair.second << "\n";
    }
    return 0;
}