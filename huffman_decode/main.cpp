#include "/Users/sailor_mbp/CLionProjects/huffman_decode/stdc++.h"
#define MAX_TREE_HT 256
using namespace std;

// map each character to value in huffman code
map<char, string> codes;
// store the frequencies of input data
map<char, int> freq;

// A Huffman tree node
struct MinHeapNode
{
	char data;			 // One of the input characters
	int freq;			 // Frequency of the character
	MinHeapNode *left, *right; // Left and right child

	MinHeapNode(char data, int freq)
	{
		left = right = nullptr;
		this->data = data;
		this->freq = freq;
	}
};

// priority queue
struct compare
{
	bool operator()(MinHeapNode* l, MinHeapNode* r)
	{
		return (l->freq > r->freq);
	}
};
void printCodes(struct MinHeapNode* root, string str)
{
	if (!root)
		return;
	if (root->data != '$')
		cout << root->data << ": " << str << "\n";
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

// store characters with huffman code values in STL hash table
void storeCodes(struct MinHeapNode* root, string str)
{
	if (root==NULL)
		return;
	if (root->data != '$')
		codes[root->data]=str;
	storeCodes(root->left, str + "0");
	storeCodes(root->right, str + "1");
}

// STL priority queue to store heap tree, with respect
// to their heap root node value
priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

// function to build the Huffman tree and store it in MinHeap
void HuffmanCodes(int size)
{
	struct MinHeapNode *left, *right, *top;
	for (map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++)
		minHeap.push(new MinHeapNode(v->first, v->second));
	while (minHeap.size() != 1)
	{
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		top = new MinHeapNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}
	storeCodes(minHeap.top(), "");
}

// utility function to store map each character with its
// frequency in input string
void calcFreq(string str, int n)
{
	for (int i=0; i<str.size(); i++)
		freq[str[i]]++;
}

// function iterates through the encoded string s
// if s[i]=='1' then move to node->right
// if s[i]=='0' then move to node->left
// if leaf node append the node->data to our output string
string decode_file(struct MinHeapNode* root, string s)
{
	string ans = "";
	struct MinHeapNode* curr = root;
	for (int i=0;i<s.size();i++)
	{
		if (s[i] == '0')
		curr = curr->left;
		else
		curr = curr->right;

		// reached leaf node
		if (curr->left==NULL and curr->right==NULL)
		{
			ans += curr->data;
			curr = root;
		}
	}
	// cout<<ans<<endl;
	return ans+'\0';
}

// Driver program to test above functions
int main()
{
	string str = "zaawansowanealgorytmyistrukturydanych";
	string encodedString, decodedString;
	calcFreq(str, str.length());
	HuffmanCodes(str.length());
	cout << "1) Characters with their frequencies:\n";
	for (auto v=codes.begin(); v!=codes.end(); v++)
		cout << v->first <<' ' << v->second << endl;

	for (auto i: str)
		encodedString+=codes[i];

	cout << "\n2) Encoded Huffman data:\n" << encodedString << endl;

	decodedString = decode_file(minHeap.top(), encodedString);
	cout << "\n3) Decoded Huffman data: " << decodedString << endl;
	return 0;
}
