//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:
   
    Node* reverse(Node* head) {

       Node* curr = head ;

       Node* prev = NULL;

        while(curr){

           Node *next = curr->next;

            curr->next = prev;

            prev = curr;

            curr = next;

        }

        return prev;

    }

    Node *reverse(Node *head, int k)

    {

        // code here

        Node *curr = head;

        int n = 0;

        while(curr){

            n++;

            curr = curr->next;

        }

        int m = n-k , i= 0;

        Node * node = reverse(head);

        //4 3 2 1

        // return node ;

        Node *temp = node;

       

      for(i= 0 ; i<m ; i++){

        //   cout<<temp->data;

          if(i<(m-1))temp = temp->next;

           

        }

       

       Node *ans  = temp->next;

       temp->next = NULL;

      Node *temp2 = ans;

      while(temp2->next){

          temp2 = temp2->next;

      }

      temp2->next = node;

      return ans;

    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends