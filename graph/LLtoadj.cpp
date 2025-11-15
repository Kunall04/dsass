#include<bits/stdc++.h>
using namespace std;

class Node{
    int data;
    int weight;
    Node* next; 

    Node(int u, int w) {
        int u=u;
        int w=w;
        Node* next
    }
}

class graph {
    int n
    vector<int> head(n);

    Graph(int n) {
        this->n=n;
        head.assign(n,nullptr);
    }

    void addElement(int u, int v, int w) {
        Node* node1=new Node(v,w);
        node1->next=head[u];
        head[u]=node1;

        Node* node2=new Node(u,w);
        node2->next=head[v];
        head[v]=node2;
    }
}

int main() {
    Graph(n);

    
}