#include <stdio.h>
#include <iostream>
#include "VoteTree.h"


void VoteTree::addVoteNode(User * use){
    cout<<"Size of VoteTree: " << H.size()<<endl;
    User * u = new User();
    u = use;
    H.push_back(u);
    cout <<"Node added to VoteTree with ID: "<< H.back()->user_id << endl;
    cout<<"Size of VoteTree: " <<H.size()<<endl;
}
// void VoteTree::printTree(){
//     cout<<"Print function from Vote Tree"<<endl;
//     cout << "userId = " << root->user_id <<endl; 
//     cout << "vote count = " << root->vote_count << endl;
//     if(root->left != nullptr){
//         cout << "lc --> "; 
//         cout << "Votes:" << root->left->vote_count << " ID:" << root->left->user_id << endl;
//         if(root->left->left != nullptr){
//             cout << "llc --> "; 
//             cout << "Votes:" << root->left->left->vote_count << " ID:" << root->left->left->user_id << endl;
//         }
//         if(root->left->right != nullptr){
//             cout << "lrc --> ";
//             cout<< "Votes:" << root->left->right->vote_count << "ID:" <<root->left->right->user_id<< endl;
//         }
//     }
//     if(root->right != nullptr){
//         cout << "rc --> "; 
//         cout << "Votes:" << root->right->vote_count << " ID:" << root->right->user_id << endl;
//         if(root->right->left != nullptr){
//             cout << "rlc --> "; 
//             cout << "Votes:" << root->right->left->vote_count << " ID:" << root->right->left->user_id << endl;
//         }
//         if(root->right->right != nullptr){
//             cout << "rrc --> "; 
//             cout << "Votes:" << root->right->right->vote_count << " ID:" << root->right->right->user_id << endl;
//         }
//     }
// }

void VoteTree::updateVotes(int numvotes, string ui){
    /*
    if (H.size() == 0){
        cout << "Tree doesn't exist, votes can not be added!" << endl;
    }
    else if(H.at(0)->user_id == ui){
        cout << "Root" << endl;
        H.at(0)->vote_count += numvotes;
        cout << "ID: " << H.at(0)->user_id << "  VOTES: " << H.at(0)->vote_count << endl;
    }
    else{
        heapify(H.size());
    }*/
    heapSort();
}

int VoteTree::search(string use){
    for(int i = 0; i < H.size(); i++){
        if(H.at(i)->user_id == use){
            return i;
        }
    }
    return -1;
}

void VoteTree::reheapify(int index){
    if(H.at(0)->user_id == H.at(index)->user_id){
        cout<< "nothing happens on reheapify" << endl;
    }
    else{ 
        if(H.at(index)->vote_count > H.at((index-1)/2)->vote_count){
            swap( H.at(index), H.at((index-1)/2));
        }

        cout<<" Reheapified" << endl;
        index = (index-1)/2;
        reheapify(index);
    }
    
}

void VoteTree::print(){
    cout << "From Vote Tree" << endl;
    for(int i = 0; i < H.size(); i++){
        
        cout << "i" << i << endl;
        cout<<"ID: " << H.at(i)->user_id<< " VOTES: " << H.at(i)->vote_count <<endl;
    }
}

void VoteTree::heapSort()
{
   // build heap
   for (int i = (H.size()/2) - 1; i >= 0; i--){
       heapify(H.size(), i);
   }  
   // extrac elements from heap one by one
   for (int i = H.size() - 1; i >= 0; i--)
   {
      // Move current root to end
      swap(H.at(0), H.at(i));
  
      // again call max heapify on the reduced heap
      heapify(i, 0);
   }
}

/*void VoteTree::scoreboard(int k){
    vector<User*> temp;

    cout<<"Scoreboard:"<<endl;
    for(int i=0;i<k;i++){
        User* temp2 = H.at(0);


        cout<<temp2->user_id<<" "<<temp2->vote_count<<endl;
        cout<<"1"<<endl;
        temp.push_back(H.at(0));
        cout<<"2"<<endl;
        H.erase(H.begin());
        cout<<"3"<<endl;
        // if(H.at(1)>H.at(2)){
        //     heapify(1);
        // } else {
        //     heapify(2);
        // }
    }

    for(int i=0;i<k;i++){
        
        addVoteNode(temp.at(i)->user_id);
        updateVotes(H.at(i)->vote_count,H.at(i)->user_id);
    }
}*/


void VoteTree::heapify(int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && H.at(l)->vote_count > H.at(largest)->vote_count)
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && H.at(r)->vote_count > H.at(largest)->vote_count)
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(H.at(i), H.at(largest));
 
        // Recursively heapify the affected sub-tree
        heapify(n, largest);
    }
}
 
// Function to delete the root from Heap
string VoteTree::deleteRoot()
{
    // // Get the last element
    // User* lastElement = H.at(H.size()-1);
 
    // // Replace root with last element
    // H.at(0) = lastElement;

    string launchUserId = H.at(0)->user_id;
    
    swap(H.at(0), H.at(H.size()-1));
    // Decrease size of heap by 1
    H.resize(H.size()-1);

 
    // heapify the root node
    //heapify(0);
    heapSort();

    return launchUserId;
}
