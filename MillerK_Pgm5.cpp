#include <iostream>
#include "BinaryNode.h"
#include "LinkedBTree.h"
#include <string>
#include <fstream>

template <typename T>
void displayNode(T& item)
{
   std::cout << item << " ";
}

int main() {

	LinkedBTree<std::string> wordTree;
	std::string word;
	std::ifstream infile;

    try
    {
        infile.open("words-steve-jobs.txt");
        if (!infile)
        {
            throw std::runtime_error("File not found or could not be opened");
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }

    // Read words from the file and add them to the tree
    std::cout << "Reading words from file and adding to tree...\n";
    while (infile >> word)
    {
        wordTree.add(word);
    }
    infile.close();

    std::cout << "\nInorder Traversal: ";
    wordTree.inorderTraverse(displayNode<std::string>);

    std::cout << "\n\nPreorder Traversal: ";
    wordTree.preorderTraverse(displayNode<std::string>);

    std::cout << "\n\nPostorder Traversal: ";
    wordTree.postorderTraverse(displayNode<std::string>);

    // Get word to replace and its replacement
    std::string wordToReplace, replacementWord;
    std::cout << "\n\nEnter a word to replace: ";
    std::cin >> wordToReplace;
    std::cout << "Enter the replacement word: ";
    std::cin >> replacementWord;

    // Replace the word
    if (wordTree.replace(wordToReplace, replacementWord))
    {
        std::cout << "'" << wordToReplace << "' successfully replaced with '"
            << replacementWord << "'.\n\n";
    }

    // Display tree information
    std::cout << "Number of nodes in the tree: " << BinaryNode<std::string>::getNodeCount() << std::endl;

    // Display the visual tree
    std::cout << "\nVisual Tree:\n";
    wordTree.displayTree();

   return 0;
}