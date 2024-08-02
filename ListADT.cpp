// ques::F :\shoyaib\BUET\Level1 Term2\Course Materials\Sessional\CSE 106\Linked List\assignment 1 - List - V1 .1.docx.pdf
#include <iostream>
using namespace std;
template <class X>
class list
{
    list *head;
    // list *tail;
    list *next;
    X data;
    int current;
    int length;

public:
    list()
    {
        head = nullptr;
        next = nullptr;
        current = 0;
        length = 0;
    }
    list(int data)
    {
        head = nullptr;
        next = nullptr;
        this->data = data;
        current = 0;
        length = 0;
    }
    void init(int k);
    void insert(X item);
    X remove();
    void moveToStart() { current = 0; }
    void moveToEnd();
    void prev()
    {
        if (current)
            current--;
        else
            cout << "Current is at the start\n";
    }
    void Next()
    {
        if (current == length - 1)
            cout << "Current is at the end of the list.\n";
        else
            current++;
    }
    int getlength() { return length; }
    void moveToPos(int pos)
    {
        if (pos < 0 || pos >= length)
        {
            cout << "Out of range!\n";
        }
        else
            current = pos;
    }
    X getValue();
    void showList()
    {
        if (length == 0)
            cout << "\nThe list is empty!\n";
        else
        {
            cout << "\n<\t";
            int tempCurrent = 0;
            list *temp = head;
            while (temp)
            {
                if (tempCurrent == current)
                    cout << "|\t";
                cout << temp->data << "\t";
                tempCurrent++;
                temp = temp->next;
            }
            cout << ">";
        }
    }
    void append(X item);
    void clear();
    int search(X item);
};
template <class X>
void list<X>::insert(X item)
{
    list *node = new list(item);
    if (current == 0)
    {
        node->next = head;
        head = node;
    }
    else
    {
        list *temp = new list;
        temp = head;
        int tempCurrent = current;
        while (--tempCurrent)
        {
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
        temp = nullptr;
        delete temp;
    }
    length++;
}
template <class X>
X list<X>::remove()
{
    list *temp = head;
    if (!current)
    {
        head = head->next;
    }
    else
    {
        int tempCurrent = current;
        while (--current)
        {
            temp = temp->next;
        }
        list *ptr = temp;
        temp = temp->next;
        ptr->next = temp->next;
        ptr = nullptr;
        delete ptr;
    }
    delete temp;
    length--;
}
template <class X>
void list<X>::moveToEnd()
{
    current = length - 1;
}
template <class X>
X list<X>::getValue()
{
    list *temp = head;
    int tempCurrent = current;
    while (tempCurrent--)
    {
        temp = temp->next;
    }
    return temp->data;
}
template <class X>
void list<X>::init(int k)
{
    X item;
    for (int i = 0; i < k; i++)
    {
        cin >> item;
        insert(item);
    }
}
template <class X>
void list<X>::append(X item)
{
    list *node = new list(item);
    if (!head)
        head = node;
    else
    {
        list *temp = new list;
        temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = node;
        temp = nullptr;
        delete temp;
    }
    length++;
}
template <class X>
void list<X>::clear()
{
    if (!head)
        cout << "The list is already empty!\n";
    else
    {
        while (head)
        {
            list *temp = new list;
            temp = head;
            head = head->next;
            delete temp;
        }
        current = 0;
        length = 0;
    }
}
template <class X>
int list<X>::search(X item)
{
    int i = 0;
    list *temp = new list;
    temp = head;
    while (temp)
    {
        if (temp->data == item)
            return i;
        else
        {
            temp = temp->next;
            i++;
        }
    }
    return -1;
}
int main()
{
    int k;
    cin >> k;
    list<int> lst;
    lst.init(k);
    lst.showList();
    lst.Next();
    lst.showList();
    lst.append(-20);
    lst.showList();
    // lst.clear();
    // lst.showList();
    lst.moveToPos(5);
    lst.insert(-1);
    cout << '\n'
         << lst.search(-1);
}