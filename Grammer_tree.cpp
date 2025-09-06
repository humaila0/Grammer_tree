#include <string> 

 

#include <iostream> 

 

#include <sstream> 

 

using namespace std; 

 

class GrammerNode { 

  public: string data; 

  GrammerNode * subjectLeft[4]; 

  GrammerNode * ObjectRight[4]; 

  GrammerNode * VerbBtw[1]; 

 

  GrammerNode(string value) { 

    data = value; 

    for (int j = 0; j < 4; j++) { 

      subjectLeft[j] = NULL; 

      ObjectRight[j] = NULL; 

    } 

    for (int j = 0; j < 1; j++) 

      VerbBtw[j] = NULL; 

  } 

}; 

 

int main() { 

  string vrb[9] = { 

    "Accept", 

    "Achieve", 

    "Act", 

    "Adapt", 

    "jumps", 

    "Add", 

    "Boil", 

    "Borrow", 

    "Break" 

  }; 

  string detr[9] = { 

    "a", 

    "theirs", 

    "an", 

    "this", 

    "that", 

    "these", 

    "whose", 

    "ours", 

    "the" 

  }; 

  string adj[9] = { 

    "Happy", 

    "sad", 

    "excited", 

    "quick", 

    "Boring", 

    "brown", 

    "energetic", 

    "lazy", 

    "sweet" 

  }; 

  string noun[9] = { 

    "Movie", 

    "fox", 

    "Beach", 

    "Camera", 

    "phone", 

    "rain", 

    "dog", 

    "Dream", 

    "sky" 

  }; 

  string prep[9] = { 

    "about", 

    "above", 

    "along", 

    "after", 

    "over", 

    "around", 

    "at", 

    "against", 

    "between" 

  }; 

 

  string input; 

  // GrammerNode *root = new GrammerNode("the quick brown fox jumps over the lazy dog"); 

 

  cout << "Enter the sentence in this format from the arrays mentioned in code:\n"; 

  cout << "Determiner Adjective Adjective Noun Verb Preposition Determiner Adjective Noun\n\n"; 

  getline(cin, input); 

  //GrammerNode *root = new GrammerNode("the energetic excited dog Adapt above the sad fox"); 

  GrammerNode * root = new GrammerNode(input); 

 

  // Breaking the string 

  istringstream iss(root -> data); 

  string part1; 

  int nOfWords = 9; 

  string arr[nOfWords] = {}; 

  int c = 0; 

  while (iss >> part1) { 

    arr[c] += part1; 

    c++; 

  } 

  root -> VerbBtw[0] = new GrammerNode(""); 

  // Finding the verb 

  int indexOfVerb = 0; 

  for (int i = 0; i < nOfWords; i++) { 

 

    for (int j = 0; j < nOfWords; j++) { 

      if (vrb[i] == arr[j]) { 

        indexOfVerb = j; 

        root -> VerbBtw[0] -> data += arr[j]; 

      } 

    } 

  } 

 

  // Storing entire subject and object in one node 

  root -> subjectLeft[0] = new GrammerNode(""); 

  for (int i = 0; i < indexOfVerb; i++) { 

    root -> subjectLeft[0] -> data += arr[i]; 

    if (i < indexOfVerb - 1) 

      root -> subjectLeft[0] -> data += " "; 

  } 

 

  root -> ObjectRight[0] = new GrammerNode(""); 

 

  for (int i = indexOfVerb + 1; i < nOfWords; i++) { 

    root -> ObjectRight[0] -> data += arr[i]; 

    if (i < nOfWords - 1) 

      root -> ObjectRight[0] -> data += " "; 

  } 

 

  //again break into array 

  istringstream iss1(root -> subjectLeft[0] -> data); 

  string part2; 

 

  string arr1[indexOfVerb] = {}; 

  int p = 0; 

  while (iss1 >> part2) { 

    arr1[p] = part2; 

    p += 1; 

  } 

 

  root -> subjectLeft[0] -> subjectLeft[0] = new GrammerNode(""); 

 

  for (int i = 0; i < nOfWords; i++) { 

    for (int j = 0; j < indexOfVerb; j++) { 

      if (arr1[j] == detr[i]) { 

 

        root -> subjectLeft[0] -> subjectLeft[0] -> data += detr[i]; 

      } 

    } 

  } 

  int space = 0; 

  root -> subjectLeft[0] -> VerbBtw[0] = new GrammerNode(""); 

 

  for (int i = 0; i < nOfWords; i++) { 

    for (int j = 0; j < indexOfVerb; j++) { 

      if (arr1[j] == adj[i]) { 

        root -> subjectLeft[0] -> VerbBtw[0] -> data += adj[i]; 

 

        space += 1; 

        if (space == 1) { 

          root -> subjectLeft[0] -> VerbBtw[0] -> data += " "; 

        } 

      } 

    } 

 

  } 

 

  root -> subjectLeft[0] -> ObjectRight[0] = new GrammerNode(""); 

 

  for (int i = 0; i < nOfWords; i++) { 

    for (int j = 0; j < indexOfVerb; j++) { 

      if (arr1[j] == noun[i]) { 

 

        root -> subjectLeft[0] -> ObjectRight[0] -> data += noun[i]; 

 

      } 

 

    } 

  } 

 

  root -> subjectLeft[0] -> VerbBtw[0] -> subjectLeft[0] = new GrammerNode(""); 

  root -> subjectLeft[0] -> VerbBtw[0] -> ObjectRight[0] = new GrammerNode(""); 

 

  istringstream iss2(root -> subjectLeft[0] -> VerbBtw[0] -> data); 

  string part3; 

 

  //splitting of adjective 

  string arr2[2] = {}; 

  int s = 0; 

  while (iss2 >> part2) { 

    root -> subjectLeft[0] -> VerbBtw[0] -> ObjectRight[0] -> data = part2; 

    s += 1; 

    if (s == 1) { 

      root -> subjectLeft[0] -> VerbBtw[0] -> subjectLeft[0] -> data = part2; 

    } 

 

  } 

 

  istringstream iss3(root -> ObjectRight[0] -> data); 

  string part4; 

 

  string arr3[indexOfVerb] = {}; 

  int a = 0; 

  while (iss3 >> part4) { 

    arr3[a] = part4; 

    a += 1; 

  } 

 

  root -> ObjectRight[0] -> subjectLeft[0] = new GrammerNode(""); 

  root -> ObjectRight[0] -> VerbBtw[0] = new GrammerNode(""); 

  root -> ObjectRight[0] -> VerbBtw[0] -> subjectLeft[0] = new GrammerNode(""); 

  root -> ObjectRight[0] -> VerbBtw[0] -> ObjectRight[0] = new GrammerNode(""); 

  root -> ObjectRight[0] -> ObjectRight[0] = new GrammerNode(""); 

 

  for (int i = 0; i < indexOfVerb; i++) { 

    for (int j = 0; j < nOfWords; j++) { 

      if (arr3[i] == prep[j]) { 

 

        root -> ObjectRight[0] -> subjectLeft[0] -> data += arr3[i]; 

      } else if (arr3[i] == detr[j]) { 

 

        root -> ObjectRight[0] -> VerbBtw[0] -> subjectLeft[0] -> data += arr3[i]; 

      } else if (arr3[i] == adj[j]) { 

 

        root -> ObjectRight[0] -> VerbBtw[0] -> ObjectRight[0] -> data += arr3[i]; 

      } else if (arr3[i] == noun[j]) { 

        root -> ObjectRight[0] -> ObjectRight[0] -> data += arr3[i]; 

      } 

 

    } 

  } 

 

  cout << endl; 

  cout << "root:(sentence) " << root -> data << endl; 

  cout << "Subject (left): " << root -> subjectLeft[0] -> data << endl; 

  cout << "Verb(Between): " << root -> VerbBtw[0] -> data << endl; 

  cout << "Object (right): " << root -> ObjectRight[0] -> data << endl; 

  cout << "Determiner (left): " << root -> subjectLeft[0] -> subjectLeft[0] -> data << endl; 

  cout << "Adjective 1 & 2 (left): " << root -> subjectLeft[0] -> VerbBtw[0] -> data << endl; 

  cout << "Adjective 1 (left): " << root -> subjectLeft[0] -> VerbBtw[0] -> subjectLeft[0] -> data << endl; 

  cout << "Adjective 2 (left):" << root -> subjectLeft[0] -> VerbBtw[0] -> ObjectRight[0] -> data << endl; 

 

  cout << "Noun (right): " << root -> subjectLeft[0] -> ObjectRight[0] -> data << endl; 

  cout << "preposition (right): " << root -> ObjectRight[0] -> subjectLeft[0] -> data << endl; 

  cout << "Determiner (right): " << root -> ObjectRight[0] -> VerbBtw[0] -> subjectLeft[0] -> data << endl; 

  cout << " Adjective (right): " << root -> ObjectRight[0] -> VerbBtw[0] -> ObjectRight[0] -> data << endl; 

  cout << "Noun(right): " << root -> ObjectRight[0] -> ObjectRight[0] -> data << endl; 

  return 0; 

} 

 