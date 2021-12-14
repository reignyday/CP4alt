#include <stdio.h>
#include <iostream>
#include "UserTree.h"

User* UserTree::addUserNode(string u){
    if(root == nullptr){
        root = new User; //ask if this needs to be deleted later
        // cout << "Before" << root->user_id << endl;
        root->user_id = u;
        // cout <<"After: " << root->user_id << endl;
        
    }
    else{
        //less or more alphabetically
        if(u < root->user_id){
            if(root->left_user == nullptr){
                root->left_user = new User; //delete ?this too
                root->left_user->user_id = u;
                return root->left_user;
            }
            else{
                addToSubTree(root->left_user, u);
            }
        }
        else{
            if(root->right_user == nullptr){
                root->right_user = new User;//delete ?this too
                root->right_user->user_id = u;
                return root->right_user;
            }
            else{
                addToSubTree(root->right_user, u);
            }
        } //comp strimngs as long as cases same
    }
}

/*void UserTree::printTree(User * use){
    cout << "ID: " << use->user_id << "Votes: " << use->vote_count;
    if(use->left_user != nullptr){
        printTree(use->left_user);
    }
    if(use->right_user != nullptr){
        printTree(use->right_user);
    }
}*/

User* UserTree::addToSubTree(User *use, string u){
    if(u < use->user_id){
        if(use->left_user == nullptr){
            use->left_user = new User(u); //delete ?this too
            return use->left_user;
        }
        else{
            addToSubTree(use->left_user, u);
        }
    }
    else{
        if(use->right_user == nullptr){
            use->right_user = new User(u); //delete ?this too
            return use->right_user;
        }
        else{
            addToSubTree(use->right_user, u);
        }
    }
}

bool UserTree::UniqueUserSearch(string ui){
    //false= not in tree, true = in tree
    if (root == nullptr){
        cout << "From UniqueUserSearch: No tree made yet!" << endl;
        return false;
    }
    if(root->user_id == ui){
        cout << "From UniqueUserSearch: root is key" << endl;
        return true;
    }
    // Key is greater than r>left_user, ui);
    if(root->user_id < ui){
        if(root->right_user == nullptr){
            return false;
        }
        else{
            return SearchSubTree(root->right_user, ui);
        }
    }
    // Key is smaller than root's key
    else{
        if(root->left_user == nullptr){
            return false;
        }
        else{
            return SearchSubTree(root->left_user, ui);
        }
    }
}

bool UserTree::SearchSubTree(User *use, string ui){//use is current node, ui is key
    if(use->user_id == ui){
        cout << ui << "= " << use->user_id << endl;
        return true;
    }
    //cehck current node to see if key is a match
    else if(ui < use->user_id){
        cout << ui << "< " << use->user_id << endl;
        if(use->left_user == nullptr){
            return false;
        }
        else{
            return SearchSubTree(use->left_user, ui);
        }
    }
    else{//greater than curent node value
        cout << ui << "> " << use->user_id << endl;
        if(use->right_user == nullptr){
            return false;
        }
        else{
            return SearchSubTree(use->right_user, ui);
        }
    }
}

void UserTree::updateUserVotes(int numvotes, string ui){
    cout << "numvotes: " << numvotes << "  user id: " << ui << endl;
    if (root == nullptr){
        cout << "No tree" << endl;
    }
    if(root->user_id == ui){
        // cout << "root" << endl;
        root->vote_count += numvotes;
        // cout << root->user_id << " vote count is " << root->vote_count << endl;
    }
    // Key is greater than, ui);
    else if(root->user_id < ui){
        if(root->right_user != nullptr){
            cout << "calling right sub" << endl;
            updateSubTreeVotes(root->right_user, ui, numvotes);
        }
    }
    // Key is smaller than root's key
    else{
        if(root->left_user != nullptr){
            cout << "calling left sub" << endl;
            updateSubTreeVotes(root->left_user, ui, numvotes);
        }
    }
}

void UserTree::updateSubTreeVotes(User * use, string ui, int numvotes){
    if(use->user_id == ui){
        use->vote_count += numvotes;
    }
    else if(ui > use->user_id){
        updateSubTreeVotes(use->right_user, ui, numvotes);
    }
    else{
        updateSubTreeVotes(use->left_user, ui, numvotes);
    }
}

// void UserTree::launch(string ui){
//     //if node is root
//     if(root->user_id == ui){
//         if(root->left_user == nullptr && root->right_user == nullptr){
//             delete root;
//             cout << "Launched " << ui << "1" << endl;
//     }
//     //user name is less than roots
//     else if(root->user_id > ui){
//         root->left_user = removeUser(root, ui);
//     }
//     //if id is greater than roots id
//     else{
//         root->right_user = removeUser(root, ui);
//     }
// }
// User* UserTree::removeUser(User *use, string ui){
//     if(use->user_id == ui){
//         //leaf case
//         if(use->left_user == nullptr && use->right_user == nullptr){
//             delete use;
//         }
//         //one child, left child
//         if(use->left_user != nullptr && use->right_user == nullptr){
//             //delete use;
//             use = use->left_user;
//         }
//     }
// }


User* UserTree::deleteNode(User* root, string key)
{
    // base case
    if (root == nullptr){
        return root;
         cout<<"deleted root"<<endl;
    }
    // If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
    if (key < root->user_id)
        root->left_user = deleteNode(root->left_user, key);
 
    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (key > root->user_id)
        root->right_user = deleteNode(root->right_user, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node has no child
        if (root->left_user==nullptr and root->right_user==nullptr)
            return nullptr;
       
        // node with only one child or no child
        else if (root->left_user == nullptr) {
            User* temp = new User;
            temp = root->right_user;
            delete root;
            return temp;
        }
        else if (root->right_user == nullptr) {
            User* temp = new User;
            temp = root->left_user;
            delete root;
            return temp;
        }
 
        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        User* temp = minValueNode(root->right_user);
 
        // Copy the inorder successor's content to this node
        root->user_id = temp->user_id;
 
        // Delete the inorder successor
        root->right_user = deleteNode(root->right_user, temp->user_id);
    }
    cout<<"deleted"<<endl;
    return root;
    
}

User* UserTree::minValueNode(User* node)
{
    User* root = new User;
    root = node;
 
    /* loop down to find the leftmost leaf */
    while (root && root->left_user != nullptr)
        root = root->left_user;
 
    return root;
}

void UserTree::inorder(User* use)
{
    if (use != nullptr) {
        inorder(use->left_user);
        cout << "From Inorder UserTree" << endl;
        cout << "ID: " << use->user_id << " VOTES: " << use->vote_count << endl;
        inorder(use->right_user);
    }
}
