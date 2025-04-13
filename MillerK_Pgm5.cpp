#include <iostream>
#include "BinaryNode.h"
#include "LinkedBTree.h"
#include <string>
#include <fstream>

// Kaj Miller
// CS3350
// 04/04/2025
// Dr. Jadwiga Carlson
// This program is meant to showcase the LinkedBTree class that I've designed.
// Reflection: 
// This program was a bit tough at first, but I think thats just because I didn't know how search trees work.
// Now that I have a better understanding of them though, I feel pretty confident. It was also fun to experiment with exception cases.            
// I also didn't know if we were supposed to format our functions with explicit instantiation, as the project guide lines just said to            
// include our header files. However, said functions declared in the header file don't seem to affect compile time or the speed of the program itself, so I'm happy.           


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