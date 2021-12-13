#include <stdio.h>
#include <iostream>
#include <vector>
#include "User.h"

using namespace std;

class VoteTree{
    private:
        // VoteNode * root = nullptr;
        vector<User*> H;

    public:
       VoteTree(){};
       ~VoteTree(){
           //delete root;
       }
       
       void addVoteNode(User * use);
       void printTree();
       void reheapify(int index);
       //bool UniqueUserSearch(string ui);
       int search(string use);
       void updateVotes(int numvotes, string ui);
       void print();
       void scoreboard(int k);
       void heapSort();
       void heapify(int n, int i);
        string deleteRoot();

        int getSize(){
            return H.size();
        }
};  
