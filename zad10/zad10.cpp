#include <iostream>
using namespace std;

class ComplexNumber {
private:
    float real;
    float imag;

public:
    ComplexNumber(float r = 0, float i = 0) : real(r), imag(i) {}

    float magnitude() const {
        return real * real + imag * imag;
    }

    bool operator<(const ComplexNumber& other) const {
        if (magnitude() == other.magnitude()) {
            if (real == other.real) {
                return imag < other.imag;
            }
            return real < other.real;
        }
        return magnitude() < other.magnitude();
    }

    friend ostream& operator<<(ostream& os, const ComplexNumber& cn) {
        os << cn.real;
        if (cn.imag != 0) {
            os << (cn.imag > 0 ? "+" : "-") << (cn.imag < 0 ? -cn.imag : cn.imag) << 'i';
        }
        return os;
    }

    bool isEqual(const ComplexNumber& other) const {
        return real == other.real && imag == other.imag;
    }
};

class ListNode {
private:
    ComplexNumber data;
    ListNode* next;
    ListNode* prev;

    friend class List;

public:
    ListNode(ComplexNumber d) : data(d), next(nullptr), prev(nullptr) {}

    ComplexNumber getData(){
        return data;
    }

    ListNode* getPrev(){
        return prev;
    }
};

class List {
private:
    ListNode* head;
    ListNode* tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    ~List() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* next = current->next;
            delete current;
            current = next;
        }
    }

    void insert(ComplexNumber data) {
        ListNode* newNode = new ListNode(data);
        if (!head) {
            head = tail = newNode;
        } else {
            ListNode* current = head;
            while (current && current->data < data) {
                current = current->next;
            }
            if (!current) {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            } else {
                newNode->next = current;
                newNode->prev = current->prev;
                if (current->prev) {
                    current->prev->next = newNode;
                } else {
                    head = newNode;
                }
                current->prev = newNode;
            }
        }
    }

    void remove(ComplexNumber data) {
        ListNode* current = head;
        while (current) {
            if (current->data.isEqual(data)) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
                ListNode* toDelete = current;
                current = current->next;
                delete toDelete;
            } else {
                current = current->next;
            }
        }
    }

    friend ostream& operator<<(ostream& os, const List& list) {
        ListNode* current = list.tail;
        while (current != nullptr) {
            os << current->getData() << " ";
            current = current->getPrev();
        }
        return os;
    }
};

int main() {
    List list;
    int M, N;
    float real, imag;

    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> real >> imag;
        list.insert(ComplexNumber(real, imag));
    }

    cout << list;


    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> real >> imag;
        list.remove(ComplexNumber(real, imag));
    }

    cout << list;

    return 0;
}
