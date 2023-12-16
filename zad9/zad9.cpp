#include <iostream>
#include <string>

class Point {
private:
    std::string name;
    double x, y;

public:
    Point(const std::string& n, double xCoord, double yCoord) : name(n), x(xCoord), y(yCoord) {}

    double sumOfCoordinates() const {
        return x + y;
    }

    bool isLessThan(const Point& other) const {
        double sumThis = sumOfCoordinates();
        double sumOther = other.sumOfCoordinates();
        if (sumThis == sumOther) {
            if (x == other.x) {
                return name < other.name; // Sortowanie alfabetyczne
            }
            return x < other.x;
        }
        return sumThis < sumOther;
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << p.name << " " << p.x << " " << p.y;
    return os;
}


class LinkedList {
private:
    class Node {
    public:
        Point data;
        Node* next;
        Node(Point p, Node* n = nullptr) : data(p), next(n) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }

    void insertSorted(const Point& value) {
        Node** curr = &head;
        while (*curr != nullptr && (*curr)->data.isLessThan(value)) {
            curr = &((*curr)->next);
        }
        *curr = new Node(value, *curr);
    }

    void removeIf(double sum) {
        Node** curr = &head;
        while (*curr != nullptr) {
            if ((*curr)->data.sumOfCoordinates() == sum) {
                Node* toDelete = *curr;
                *curr = (*curr)->next;
                delete toDelete;
            } else {
                curr = &((*curr)->next);
            }
        }
    }

    void print() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) {
                std::cout << " ";
            }
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string name;
        double x, y;
        std::cin >> name >> x >> y;
        list.insertSorted(Point(name, x, y));
    }

    double sumToRemove;
    std::cin >> sumToRemove;

    list.removeIf(sumToRemove);

    list.print();
    return 0;
}
