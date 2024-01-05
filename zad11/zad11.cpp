#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    double arr[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == MAX_SIZE - 1;
    }

    void push(double value) {
        if (!isFull()) {
            arr[++top] = value;
        }
    }

    double pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return 0;
    }

    double peek() const {
        if (!isEmpty()) {
            return arr[top];
        }
        return 0;
    }
};

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

double evaluateONP(const char* expression) {
    Stack operands;
    int i = 0;
    while (expression[i] != '\0') {
        if (isDigit(expression[i]) || (expression[i] == '-' && isDigit(expression[i+1]))) {
            double number = 0;
            int sign = 1;
            if (expression[i] == '-') {
                sign = -1;
                ++i;
            }
            while (isDigit(expression[i])) {
                number = number * 10 + (expression[i] - '0');
                ++i;
            }
            operands.push(number * sign);
        } else if (isOperator(expression[i])) {
            double operand2 = operands.pop();
            double operand1 = operands.pop();
            switch (expression[i]) {
                case '+': operands.push(operand1 + operand2); break;
                case '-': operands.push(operand1 - operand2); break;
                case '*': operands.push(operand1 * operand2); break;
                case '/': operands.push(operand1 / operand2); break;
            }
            ++i;
        } else {
            ++i;
        }
    }
    return operands.peek();
}

int main() {
    char expression[MAX_SIZE];

    cin.getline(expression, MAX_SIZE);

    cout << evaluateONP(expression) << endl;

    return 0;
}