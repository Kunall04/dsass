
class SumOfInterval {
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

    SumOfInterval() {
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

        node->data = node->left->data + node->right->data;
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

    int query(int start, int end) {
        return queryFind(root, start, end);
    }

    int queryFind(Node* node, int start, int end) {
        // complete overlap
        if (node->startInterval >= start && node->endInterval <= end) {
            return node->data;
        }

        // no overlap
        if (node->startInterval > end || node->endInterval < start) {
            return 0;
        }

        // partial overlap
        return queryFind(node->left, start, end) +
               queryFind(node->right, start, end);
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4};

    SumOfInterval seg;
    seg.populate(arr);

    seg.inorder();
    cout << "\n";

    cout << seg.query(1, 3) << "\n";

    return 0;
}
