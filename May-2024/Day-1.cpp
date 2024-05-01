// Arrange Consonants and Vowels
// https://www.geeksforgeeks.org/problems/arrange-consonants-and-vowels/1

bool isVowel(char x)
{
    return (x == 'a' || x == 'e' || x == 'i' || x == 'o'
            || x == 'u');
}

struct Node* arrangeCV(Node* head)
{
    // Code here
    vector<char> v;
    Node* head1 = head;

    while (head != NULL) {

        if (isVowel(head->data)) {
            v.push_back(head->data);
        }

        head = head->next;
    }

    head = head1;

    while (head != NULL) {

        if (!isVowel(head->data)) {
            v.push_back(head->data);
        }

        head = head->next;
    }

    Node* newHead1 = new Node('a');
    Node* newHead = new Node('a');
    newHead = newHead1;

    for (int i = 0; i < v.size(); i++) {
        Node* temp = new Node(v[i]);

        newHead1->next = temp;
        newHead1 = newHead1->next;
    }

    return newHead->next;
}