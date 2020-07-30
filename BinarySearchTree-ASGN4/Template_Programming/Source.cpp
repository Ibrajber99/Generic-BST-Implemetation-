/*
* @file
* @author  <Ibrahim Jaber>
* @version 1.0
*
*
* @section DESCRIPTION
* <Binary Search Tree implementation>
*
*
* @section LICENSE
* <any necessary attributions>
*
* Copyright 2020
* Permission to use, copy, modify, and/or distribute this software for
* any purpose with or without fee is hereby granted, provided that the
* above copyright notice and this permission notice appear in all copies.
*
* THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
* WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
* ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
* WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
* OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
* @section Academic Integrity
*  I certify that this work is solely my own and complies with
*  NBCC Academic Integrity Policy (policy 1111)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <deque>
#include<queue>

template <typename T>//template
struct BstNode {//struct
public:
	T data;//data of Type T
	std::shared_ptr<BstNode>left;//Shared point 
	std::shared_ptr<BstNode>right;//shared Pointer

	template <typename T>
	//fucntion that generates newNode of type BstNode and sets left and right to null preparing it for insertion
	std::shared_ptr<BstNode<T>> generateNewNode(T data_) {
		std::shared_ptr<BstNode<T>> newNode = std::make_shared<BstNode<T>>();
		newNode->data = data_;
		newNode->left = nullptr;
		newNode->right = nullptr;
		return newNode;
	}


	template <typename T>
	//function that inserts data in recurrisve fashion -->it will keep looping till there is an empty spot in either left or right depending on the data size/length
	void insert(std::shared_ptr<BstNode<T>>& root, T data) {
		if (contains(root, data)) {
			std::cout << "cannot insert duplicates\n";
		}
		else {
			if (root == nullptr) {
				root = generateNewNode(data);
			}
			else if (data <= root->data) {
				insert(root->left, data);
			}
			else {
				insert(root->right, data);
			}

		}

	}
	template <typename T>
	//fucntion that recursivley search for data and returns true if it found 
	bool contains(std::shared_ptr<BstNode<T>>& root, T data) {
		if (root == nullptr)return false;
		else if (root->data == data) {std::cout << data << " found\n"; return true;}
		else if (data <= root->data) return contains(root->left, data);
		else return contains(root->right, data);
	}

	template <typename T>
	//fucntion that traverses the tree in Levle order fashion 
	void levelOrdertraversal(std::shared_ptr<BstNode<T>>& root) {
		if (root == nullptr)return;
		std::queue<std::shared_ptr<BstNode<T>>>leafQue;
		leafQue.push(root);
		while (!leafQue.empty()) {
			std::shared_ptr<BstNode<T>>curr = leafQue.front();
			std::cout << curr->data << "   ";
			if (curr->left != nullptr)leafQue.push(curr->left);
			if (curr->right != nullptr)leafQue.push(curr->right);
			leafQue.pop();
		}

	 }
	template <typename T>
	//fucntion that traverses the tree in  Inorder fashion
	void inOrdertraversal(std::shared_ptr<BstNode<T>>& root) {
		if (root == nullptr)return;
		else {
			inOrdertraversal(root->left);
			std::cout << root->data << "   ";
			inOrdertraversal(root->right);
		}

	}

	template <typename T>
	//fucntion that traverses the tree in Postorder fashion
	void postOrdertraversal(std::shared_ptr<BstNode<T>>& root) {
		if (root == nullptr)return;
		else {
			inOrdertraversal(root->left);
			inOrdertraversal(root->right);
			std::cout << root->data << "   ";
		}
	}

	template <typename T>
	//fucntion that traverses the tree in Preorder fashion
	void preOrdertraversal(std::shared_ptr<BstNode<T>>& root) {
		if (root == nullptr)return;
		else {
			std::cout << root->data << "   ";
			inOrdertraversal(root->left);
			inOrdertraversal(root->right);
		}
	}
	//check if tree data is empty
	bool checkIfEmpty(std::shared_ptr<BstNode<T>>& root) {
		return root->data == NULL;
	}


};



int main() {
	std::cout << "Tree That hold chars\n\n";
	std::shared_ptr<BstNode<char>> rootChar = std::make_shared<BstNode<char>>();//pointer to root node
	rootChar = nullptr;//setting tree as Empty
	rootChar->insert(rootChar, 'a');
	rootChar->insert(rootChar, 'b');
	rootChar->insert(rootChar, 'c');
	rootChar->insert(rootChar, 'x');
	rootChar->insert(rootChar, 'j');
	rootChar->insert(rootChar, 'j');//it won't insert it 
	std::cout << rootChar->checkIfEmpty(rootChar) << std::endl; //check if tree is Empty
	std::cout << rootChar->contains(rootChar, 'j') << std::endl; //searching for an element

	std::cout << "In order Traversal\n";
	rootChar->inOrdertraversal(rootChar);//display the tree's data in order Traversal
	std::cout << "\n\n";
	
	std::cout << "Level Order Traversal\n";
	rootChar->levelOrdertraversal(rootChar);//display the tree's data Levle order Traversal
	std::cout << "\n\n";
	
	std::cout << "Post Order Traversal\n";
	rootChar->postOrdertraversal(rootChar);//display the tree's data post orderr Traversal
	std::cout << "\n\n";
	
	std::cout << "pre Order Traversal\n";
	rootChar->preOrdertraversal(rootChar);//display the tree's data pre order Traversal
	std::cout << "\n\n";
	
	
	
	std::cout << "Tree That hold Ints\n\n";
	std::shared_ptr<BstNode<int>> rootInt = std::make_shared<BstNode<int>>();//pointer to root node
	rootInt = nullptr;//setting tree as Empty
	rootInt->insert(rootInt, 1);
	rootInt->insert(rootInt, 6);
	rootInt->insert(rootInt, 9);
	rootInt->insert(rootInt, 8);
	rootInt->insert(rootInt, 10);
	rootInt->insert(rootInt, 10);//it won't insert it 
	
	std::cout << rootInt->contains(rootInt, 10) << std::endl; //searching for an element

	std::cout << "In order Traversal\n";
	rootInt->inOrdertraversal(rootInt);//display the tree's data in order Traversal
	std::cout << "\n\n";
	
	std::cout << "Level Order Traversal\n";
	rootInt->levelOrdertraversal(rootInt);//display the tree's data Levle order Traversal
	std::cout << "\n\n";
	
	std::cout << "Post Order Traversal\n";
	rootInt->postOrdertraversal(rootInt);//display the tree's data post orderr Traversal
	std::cout << "\n\n";
	
	std::cout << "pre Order Traversal\n";
	rootInt->preOrdertraversal(rootInt);//display the tree's data pre order Traversal
	std::cout << "\n\n";







	std::cout << "Tree That hold Strings\n\n";
	std::shared_ptr<BstNode<std::string>> rootString = std::make_shared<BstNode<std::string>>();//pointer to root node
	rootString = nullptr;//setting tree as Empty
	std::string HelloinDiffLanguages = "hello";
	rootString->insert(rootString, HelloinDiffLanguages);

	HelloinDiffLanguages = "Aloha";
	rootString->insert(rootString, HelloinDiffLanguages);

	HelloinDiffLanguages = "Shalom";
	rootString->insert(rootString, HelloinDiffLanguages);

	HelloinDiffLanguages = "Merhaba";
	rootString->insert(rootString, HelloinDiffLanguages);

	HelloinDiffLanguages = "Ciao";
	rootString->insert(rootString, HelloinDiffLanguages);

	HelloinDiffLanguages = "Bom dia";
	rootString->insert(rootString, HelloinDiffLanguages);
	rootString->insert(rootString, HelloinDiffLanguages);//it wont insert duplicates


	std::string searchForEl = "Aloha";
	std::cout << rootString->contains(rootString, searchForEl) << std::endl; //searching for an element

	std::cout << "In order Traversal\n";
	rootString->inOrdertraversal(rootString);//display the tree's data in order Traversal
	std::cout << "\n\n";

	std::cout << "Level Order Traversal\n";
	rootString->levelOrdertraversal(rootString);//display the tree's data Levle order Traversal
	std::cout << "\n\n";

	std::cout << "Post Order Traversal\n";
	rootString->postOrdertraversal(rootString);//display the tree's data post orderr Traversal
	std::cout << "\n\n";

	std::cout << "pre Order Traversal\n";
	rootString->preOrdertraversal(rootString);//display the tree's data pre order Traversal
	std::cout << "\n\n";
}

