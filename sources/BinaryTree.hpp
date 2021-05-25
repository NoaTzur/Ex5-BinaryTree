#include <stdlib.h>
#include <queue>
#pragma once
using namespace std;

namespace ariel {
template<typename T>
class BinaryTree {

    public:

        int curr_size;
        // inner class
        struct Node {
            T _value;
            Node* _left_node;
            Node* _right_node;
            // Node(const T& v, Node* r, Node* l): _value(v), _right_node(r) ,_left_node(l) {}
            Node(){
                _right_node = nullptr; // 
                _left_node = nullptr; // 
            }
            // Node(const T& v, Node* n): value(v), m_next(n) {}
        };

        Node* root;
        BinaryTree(): curr_size(0){
            
            root = new Node; 
        }

        ~BinaryTree() {
            delete_tree(root);
        }

        // Recursive function to delete a given binary tree
        void delete_tree(Node* &root)
        {
            // Base case: empty tree
            if (root == nullptr) {
                return;
            }
        
            // delete left and right subtree first (Postorder)
            delete_tree(root->_left_node);
            delete_tree(root->_right_node);
        
            // delete the current node after deleting its left and right subtree
            delete root;
        
            // set root as null before returning
            root = nullptr;
        }

        BinaryTree& add_root(const T& input){

            root->_value = input;
            
            return *this;
            
        }

        BinaryTree& add_left(const T& fatherElement, const T& childElement){
            bool found = false;
            iterator it = iterator{root};
            it.fill_inorder_queue(root);
            std::queue<Node *> it_queue = it.inorder_queue;
            while(!it_queue.empty() && !found){
                if (it_queue.front()->_value == fatherElement)
                {
                    if (it_queue.front()->_left_node == nullptr)
                    {
                        Node* temp = new Node();
                        it_queue.front()->_left_node = temp;

                    }
                    
                    it_queue.front()->_left_node->_value = childElement;
                    found = true;
                }

                it_queue.pop();
                }
                if(!found){
                    throw std::invalid_argument("not in the tree");
                }
                return *this;
            }

        BinaryTree& add_right(const T& fatherElement, const T& childElement){

            bool found = false;
            iterator it = iterator{root};
            it.fill_inorder_queue(root);
            std::queue<Node *> it_queue = it.inorder_queue;

            while(!it_queue.empty() && !found){
    
                if (it_queue.front()->_value == fatherElement)
                {
                    if (it_queue.front()->_right_node == nullptr)
                    {
                        Node* temp = new Node();
                        it_queue.front()->_right_node = temp;

                    }
                    
                    it_queue.front()->_right_node->_value = childElement;
                    found = true;
                }

                it_queue.pop();
            }
            if(!found){
                throw std::invalid_argument("not in the tree");
            }
            return *this;
        }
        
        friend std::ostream& operator << (std::ostream& os, BinaryTree& tree){ // 
            os << "my tree" << endl;
            return os;
        }

        class iterator {
                
            public:
                std::queue<Node *> inorder_queue;

                iterator(Node* root = nullptr){
                    
                }

            
                void fill_inorder_queue(Node* node){
                    
                    if (node == NULL)
                        return;
 
                    /* first recur on left child */
                    fill_inorder_queue(node->_left_node);
                
                    /* then print the data of node */
                    inorder_queue.push(node);
                
                    /* now recur on right child */
                    fill_inorder_queue(node->_right_node);
                }
                void fill_pre_queue(Node* node){
                    
                    if (node == NULL)
                        return;

                    /* then print the data of node */
                    inorder_queue.push(node);
                    /* first recur on left child */
                    fill_pre_queue(node->_left_node);

                    /* now recur on right child */
                    fill_pre_queue(node->_right_node);
                }

                void fill_post_queue(Node* node){
                    
                    if (node == NULL)
                        return;
 
                    /* first recur on left child */
                    fill_post_queue(node->_left_node);
            
                
                    /* now recur on right child */
                    fill_post_queue(node->_right_node);

                    /* then print the data of node */
                    inorder_queue.push(node);
                }

                iterator& operator ++(){

                    inorder_queue.pop();
                    return *this;
                }

                T* operator->() const {
			        return &(inorder_queue.front()->_value);
		        }

                T& operator*() const {
                    return inorder_queue.front()->_value;
		        }

                bool operator!=(const iterator& other) const {
                    if ((other.inorder_queue.empty() && !this->inorder_queue.empty()) ||
                        (!other.inorder_queue.empty() && this->inorder_queue.empty()))
                    {
                        return true;
                    }
                    if (other.inorder_queue.empty() && this->inorder_queue.empty())
                    {
                        return false;
                    }
 
                    return inorder_queue.front() != other.inorder_queue.front();
                }
                bool operator==(const iterator& other) const {
                    
			        return !(inorder_queue.front() != other.inorder_queue.front());
		        }

                
                

        };

        iterator begin() {
            iterator it = iterator{root};
            it.fill_inorder_queue(root);
            
            return it;
	    }
        iterator begin_inorder() {
            return begin();
	    }
        iterator begin_preorder() {
            iterator it = iterator{root};
            it.fill_pre_queue(root);
            return it;
	    }
         iterator begin_postorder() {
            iterator it = iterator{root};
            it.fill_post_queue(root);
            return it;
	    }

        iterator end() {
            // return nullptr; 
            return iterator{nullptr};
        }
        iterator end_preorder() {
            // return nullptr; 
            return iterator{nullptr};
        }
        iterator end_inorder() {
            // return nullptr; 
            return iterator{nullptr};
        }
        iterator end_postorder() {
            // return nullptr; 
            return iterator{nullptr};
        }


};

};
