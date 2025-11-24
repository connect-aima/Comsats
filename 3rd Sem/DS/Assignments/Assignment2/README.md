Perfect. Here are your **Stack Revision Notes** — structured, concise, and lab-exam ready while still technically accurate.
These will help you *write theory*, *analyze questions*, and *code fast during viva or practical*.

---

# 📘 **DSA LAB MID EXAM – STACK COMPLETE NOTES**

---

## 🔹 **1. Definition**

A **Stack** is a **linear data structure** that follows the **LIFO (Last In, First Out)** principle.
→ The element inserted last is removed first.

**Real-life example:** Stack of plates, Undo/Redo operations, function call stack.

---

## 🔹 **2. Basic Operations**

| Operation          | Description                         | Time Complexity |
| ------------------ | ----------------------------------- | --------------- |
| `push(x)`          | Insert an element on top            | O(1)            |
| `pop()`            | Remove the top element              | O(1)            |
| `peek()` / `top()` | Return top element without removing | O(1)            |
| `isEmpty()`        | Check if stack is empty             | O(1)            |
| `isFull()`         | (Only for array-based stack)        | O(1)            |

---

## 🔹 **3. Implementation Methods**

### ✅ **A. Stack using Array**

**Concept:**

* Implemented using a fixed-size array.
* `top` variable stores the index of the top element.

**Code:**

```cpp
#define MAX 100
class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    void push(int val) {
        if (top == MAX - 1)
            cout << "Stack Overflow\n";
        else
            arr[++top] = val;
    }

    void pop() {
        if (top == -1)
            cout << "Stack Underflow\n";
        else
            top--;
    }

    int peek() {
        if (top == -1)
            return -1;
        return arr[top];
    }

    bool isEmpty() { return top == -1; }
};
```

**Advantages:**

* Simple and fast (O(1) operations).
* Better cache performance.

**Disadvantages:**

* Fixed size (may cause overflow).
* Wastes memory if array is large but unused.

**Use When:**

* Stack size is known/fixed.
* Need predictable memory use.

---

### ✅ **B. Stack using Linked List**

**Concept:**

* Dynamic memory allocation.
* Each node has `data` and `next` pointer.
* `top` points to head node.

**Code:**

```cpp
struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top;
public:
    Stack() { top = NULL; }

    void push(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL)
            cout << "Stack Underflow\n";
        else {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    int peek() {
        if (top == NULL)
            return -1;
        return top->data;
    }

    bool isEmpty() { return top == NULL; }
};
```

**Advantages:**

* Dynamic size (no overflow).
* Efficient memory use.

**Disadvantages:**

* Extra memory for pointers.
* Slightly slower due to dynamic allocation.

**Use When:**

* Size unknown or changes frequently.
* Overflow must be avoided.

---

### ✅ **C. Stack using STL (Standard Template Library)**

**Header:** `<stack>`
**Syntax:**

```cpp
#include <stack>
using namespace std;

stack<int> s;
s.push(10);
s.push(20);
cout << s.top();  // 20
s.pop();
```

**Operations:**

* `push(x)`
* `pop()`
* `top()`
* `empty()`
* `size()`

**Advantages:**

* Easiest to use.
* Handles memory automatically.
* Efficient and tested.

**Disadvantages:**

* No direct access to internal elements (no iteration).

**Use When:**

* Need quick, safe implementation.
* Competitive programming or practical exam shortcut.

---

### ✅ **D. Stack using STL List or Deque**

**Using list:**

```cpp
#include <list>
list<int> s;
s.push_back(10);
s.push_back(20);
s.pop_back();
```

**Using deque:**

```cpp
#include <deque>
deque<int> s;
s.push_back(10);
s.push_back(20);
s.pop_back();
```

**Use When:**

* Need iteration or access from both ends.
* Need hybrid stack-queue behavior.

---

## 🔹 **4. Comparison Table**

| Feature       | Array      | Linked List   | STL Stack    | STL List/Deque  |
| ------------- | ---------- | ------------- | ------------ | --------------- |
| Memory Type   | Static     | Dynamic       | Dynamic      | Dynamic         |
| Size Limit    | Fixed      | Unlimited     | Unlimited    | Unlimited       |
| Overflow      | Possible   | No            | No           | No              |
| Speed         | Fast       | Slower        | Fast         | Fast            |
| Memory Use    | Less       | More          | Moderate     | Moderate        |
| Iteration     | Possible   | Possible      | ❌ No         | ✅ Yes           |
| Best Use Case | Fixed-size | Variable size | Quick coding | Custom behavior |

---

## 🔹 **5. Famous Stack Applications**

| Application                    | Description                              |
| ------------------------------ | ---------------------------------------- |
| **Parentheses Matching**       | Check if brackets are balanced           |
| **Expression Conversion**      | Infix → Postfix, Postfix → Evaluation    |
| **Reverse String**             | Using stack to reverse characters        |
| **Undo/Redo System**           | Maintain history using two stacks        |
| **Function Calls (Recursion)** | System uses call stack internally        |
| **Next Greater Element**       | Used in arrays for nearest greater logic |
| **Stack with getMin()**        | Track minimum element in O(1)            |

---

## 🔹 **6. Decision Logic (When to Use Which)**

| Situation                      | Best Implementation |
| ------------------------------ | ------------------- |
| Fixed size known               | Array               |
| Unknown or large size          | Linked List         |
| Quick and safe implementation  | STL Stack           |
| Need iteration/traversal       | STL List / Deque    |
| Low memory, predictable system | Array               |

---

## 🔹 **7. Complexity Summary**

| Operation | Array | Linked List             | STL Stack |
| --------- | ----- | ----------------------- | --------- |
| Push      | O(1)  | O(1)                    | O(1)      |
| Pop       | O(1)  | O(1)                    | O(1)      |
| Peek      | O(1)  | O(1)                    | O(1)      |
| Space     | O(n)  | O(n) + pointer overhead | O(n)      |

---

## 🔹 **8. Important Notes for Viva**

* Stack is **LIFO**, Queue is **FIFO**.
* **Overflow** happens only in **array-based stacks**.
* Linked List stack never overflows unless **heap full**.
* STL `stack` is a **container adaptor**, usually built on **deque**.
* Real recursion internally uses **function call stack**.
* `stack::size()` gives number of elements.
* Never iterate STL stack (it has no iterators).

---

Would you like me to make a **printable PDF version** of these notes (clean layout, for handwritten revision or submission)?
It’ll include formatted sections + side-by-side comparison + one small example per type.
