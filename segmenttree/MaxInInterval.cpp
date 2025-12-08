#include <bits/stdc++.h>
using namespace std;

class MaxInInterval {
public:
    struct Node {
        int data;
        int startInterval;
        int endInterval;
        Node* left;
        Node* right;

        Node(int s, int e) {
            startInterval = s;
            endInterval = e;
            data = 0;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;

    MaxInInterval() {
        root = nullptr;
    }

    void populate(const vector<int>& arr) {
        root = build(arr, 0, arr.size() - 1);
    }

    Node* build(const vector<int>& arr, int s, int e) {
        if (s == e) {
            Node* node = new Node(s, e);
            node->data = arr[s];
            return node;
        }

        Node* node = new Node(s, e);
        int mid = (s + e) / 2;

        node->left = build(arr, s, mid);
        node->right = build(arr, mid + 1, e);

        node->data = max(node->left->data, node->right->data);
        return node;
    }

    void inorder() {
        callInorder(root);
    }

    void callInorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        callInorder(node->left);
        callInorder(node->right);
    }

    int maxQuery(int start, int end) {
        return findMaxQuery(root, start, end);
    }

    int findMaxQuery(Node* node, int start, int end) {
        // complete overlap
        if (node->startInterval >= start && node->endInterval <= end) {
            return node->data;
        }

        // no overlap
        if (node->startInterval > end || node->endInterval < start) {
            return INT_MIN;
        }

        // partial overlap
        return max(findMaxQuery(node->left, start, end),
                   findMaxQuery(node->right, start, end));
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4};

    MaxInInterval seg;
    seg.populate(arr);

    seg.inorder();
    cout << "\n";

    cout << seg.maxQuery(1, 2) << "\n";

    return 0;
}
