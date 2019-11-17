#pragma once

// include this library to use NULL, otherwise use nullptr instead
#include <cstddef>
#include <iostream>
#include "node.hpp"

template<class T>
class BST{
public:
    // Constructor for the BST class, creates an empty tree
    BST(void);
    // Destructor for the BST class, destroys the tree
    ~BST(void);
    // Inserts data into the tree
    // param: The data to be inserted into the tree
    void insert(T);
    // Removes data from the tree
    // param: The data to be removed from the tree
    void remove(T);
    // Performs an inorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *inorder(void);
    // Performs an postorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *postorder(void);
    // Performs an preorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *preorder(void);
    // Searches the tree for a given value
    // param: the data to search for
    // returns: a pointer to the node containing the data or NULL if the data
    //          was not found
    Node<T> *search(T);
    // Gets the current number of nodes in the tree
    // returns: the number of nodes in the tree
    int get_size(void);
private:
    // the root node of the tree
    Node<T> *root;
    // the number of nodes in the tree
    int node_count;
    //Helper for the search method.
    Node<T> *searchHelper(Node<T>, T);
    
};

template<class T>
BST<T>::BST()
{
    root = NULL;
    node_count = 0;
}

template<class T>
BST<T>::~BST()
{
    root = NULL;
    while(root != NULL)
    {
        remove(root->get_data());
    }
}

template<class T>
 std::vector<T> * BST<T>::inorder()
{
    std::vector<T> *vec = new std::vector<T>;

    return vec;
}


template<class T>
 std::vector<T> * BST<T>::preorder()
{
    std::vector<T> *vec = new std::vector<T>;
    return vec;
}


template<class T>
 std::vector<T> * BST<T>::postorder()
{
    std::vector<T> *vec = new std::vector<T>;

    return vec;
}

template<class T>
void BST<T>::insert(T new_data)
{
    Node<T> *current = root;
    Node<T> *newNode = new Node<T>(new_data);
    if (root == NULL){
        root = newNode;
    }
    else{
        while (current != NULL){
            if (new_data < current -> get_data()){
                if (current -> get_left() == NULL){
                    current -> set_left(newNode);
                    current = NULL;
                }
                else{
                    current = current -> get_left();
                }
            }
            else{
                if (current -> get_right() == NULL){
                    current -> set_right(newNode);
                    current = NULL;
                }
                else{
                    current = current -> get_right();
                }
            }
        }
    }
}


template<class T>
Node<T> *BST<T>::search(T val)
{
   // Node<T> result = searchHelper(root, val);
    //return result;
    Node<T> *current = root;
    while (current != NULL){
        if (current -> get_data() == val){
            return current;
        }
        else if (current -> get_data() < val){
            current = current -> get_right();
        }
        else{
            current = current -> get_left();
        }
    }
    return NULL;
}

template<class T>
Node<T> *BST<T>::searchHelper(Node<T> current, T searchValue){
    if (current == NULL){
        return NULL;
    }
    if (searchValue == current -> get_data()){
        return current;
    }
    else if (searchValue < current){
        searchHelper(current -> get_left(), searchValue);
    }
    else if (searchValue > current){
        searchHelper(current -> get_right(), searchValue);
    }
}


template<class T>
void BST<T>::remove(T val)
{
    Node<T> *current = root;
    Node<T> *prev;
    while (current != NULL){
        //A value is found.
        if (current -> get_data() == val){
            //Value is a leaf.
            if (current -> get_left() == NULL && current -> get_right() == NULL){
                //Value is root.
                if (prev == NULL){
                    root = NULL;
                }
                else if (prev -> get_left() == current){
                    prev -> set_left(NULL);
                }
                else{
                    prev -> set_right(NULL);
                }
            }
            //Value has a left child.
            else if (current -> get_left() != NULL && current -> get_right() == NULL){
                //Value is root
                if (prev == NULL){
                    root = current -> get_left();
                }
                else if (prev -> get_left() == current){
                    prev -> set_left(current -> get_left());
                }
                else{
                    prev -> set_right(current -> get_left());
                }
            }
            //Value has a right child.
            else if (current -> get_left() == NULL && current -> get_right() != NULL){
                //Value is root
                if (prev == NULL){
                    root = current -> get_right();
                }
                else if (prev -> get_left() == current){
                    prev -> set_left(current -> get_right());
                }
                else{
                    prev -> set_right(current -> get_right());
                }
            }
            //Value has two children. Successor will be leftmost child of right subtree
            else{
                Node<T> *successor = current -> get_right();
                while (successor -> get_left() != NULL){
                    successor = successor -> get_left();
                }
                T successorData = successor -> get_data();
                remove(successor -> get_data());
                current -> set_data(successorData);
            }
            return;
        }
        //Search right.
        else if (current -> get_data() < val){
            prev = current;
            current = current -> get_right();
        }
        //Search left.
        else{
            prev = current;
            current = current -> get_left();
        }
    }
}




template<class T>
int BST<T>::get_size()
{

}