#pragma once
#include <algorithm>
#include <iostream>
#include <memory>
#include <optional>
#include <stack>
#include <string>
#include <vector>

template <class T = int> class BinaryTree {
private:
  struct Node {
    Node(T data) : data(data), left(nullptr), right(nullptr) {}
    std::optional<T> data{std::nullopt};
    std::shared_ptr<Node> left{nullptr};
    std::shared_ptr<Node> right{nullptr};
  };
  std::shared_ptr<Node> root{nullptr};

  bool _check_balance(const std::string &str);
  bool _is_operator(char ch);

  static void _rec_pre_order(std::shared_ptr<Node> node);
  static void _rec_in_order(std::shared_ptr<Node> node);
  static void _rec_post_order(std::shared_ptr<Node> node);

  std::shared_ptr<Node> _find(std::shared_ptr<Node> node, T data) {
    if (node == nullptr or node->data == data) {
      return node;
    }

    if (node->data < data) {
      return _find(node->right, data);
    }

    return _find(node->left, data);
  }

  std::shared_ptr<Node> _remove(std::shared_ptr<Node> node, T data) {
    if (node == nullptr)
      return node;

    if (data < node->data.value()) {
      node->left = _remove(node->left, data);
    } else if (data > node->data.value()) {
      node->right = _remove(node->right, data);
    } else {
      if (node->left == nullptr) {
        return node->right;
      } else if (node->right == nullptr) {
        return node->left;
      }

      node->data = _in_order_successor(node->right);
      node->right = _remove(node->right, node->data.value());
    }

    return node;
  }

  T _in_order_successor(std::shared_ptr<Node> node) {
    T min = node->data.value();
    while (node->left not_eq nullptr) {
      min = node->left->data.value();
      node = node->left;
    }
    return min;
  }

public:
  BinaryTree() = default;
  BinaryTree(const std::string &str);

  template <class Cont>
  [[__nodiscard__]] static BinaryTree<T> from_container(Cont cont) {
    BinaryTree<T> res;
    for (auto v : cont) {
      res.add(v);
    }
    return res;
  };

  void add(int data);

  [[__nodiscard__]] std::shared_ptr<Node> find(T data) {
    return _find(this->root, data);
  }

  void remove(T data) {
    auto node = find(data);
    if (node == nullptr) {
      std::cerr << "Cant found element for remove\n";
      return;
    }
    _remove(this->root, data);
  }

  static void rec_pre_order(BinaryTree<T> bt);
  static void rec_in_order(BinaryTree<T> bt);
  static void rec_post_order(BinaryTree<T> bt);

  static void iter_pre_order(BinaryTree<T> bt);
};

template <class T> bool BinaryTree<T>::_check_balance(const std::string &str) {
  std::stack<T> stack{};
  for (const char &ch : str) {
    switch (ch) {
    case '(':
      stack.push(')');
      break;
    case ')':
      if (stack.top() != ch || stack.empty()) {
        std::cerr << "Bad creations\n";
        return false;
      }
      stack.pop();
      break;
    default:
      continue;
    }
  }
  if (not stack.empty()) {
    std::cerr << "Bad creations\n";
    return false;
  }
  return true;
}

template <class T> bool BinaryTree<T>::_is_operator(char ch) {
  std::vector<char> ops = {',', '(', ')'};
  if (std::find(ops.begin(), ops.end(), ch) != ops.end())
    return true;
  return false;
}

template <class T> BinaryTree<T>::BinaryTree(const std::string &str) {
  if (_check_balance(str)) {
    std::string s = str;
    std::string temp_s{};

    while (not s.empty()) {

      if (_is_operator(s.at(0))) {
        s.erase(0, 1);
        continue;
      }

      while (not _is_operator(s.at(0))) {
        temp_s += s.at(0);
        s.erase(0, 1);
      }

      if (not temp_s.empty()) {
        add(std::stoi(temp_s));
        temp_s = "";
      }
      s.erase(0, 1);
    }
  }
}

template <class T> void BinaryTree<T>::add(int data) {
  if (root == nullptr) {
    root = std::make_shared<Node>(data);
    return;
  }
  auto v = root;
  while ((data < v->data and v->left not_eq nullptr) or
         (data > v->data and v->right not_eq nullptr)) {
    if (data < v->data) {
      v = v->left;
    } else {
      v = v->right;
    }
  }
  if (data == v->data) {
    return;
  }
  auto new_node = std::make_shared<Node>(data);
  if (data < v->data) {
    v->left = new_node;
  } else {
    v->right = new_node;
  }
}

template <class T>
void BinaryTree<T>::_rec_pre_order(std::shared_ptr<Node> node) {
  if (node == nullptr)
    return;
  std::cout << node->data.value() << " ";
  _rec_pre_order(node->left);
  _rec_pre_order(node->right);
}

template <class T>
void BinaryTree<T>::_rec_in_order(std::shared_ptr<Node> node) {
  if (node == nullptr)
    return;
  _rec_in_order(node->left);
  std::cout << node->data.value() << " ";
  _rec_in_order(node->right);
}

template <class T>
void BinaryTree<T>::_rec_post_order(std::shared_ptr<Node> node) {
  if (node == nullptr)
    return;
  _rec_post_order(node->left);
  _rec_post_order(node->right);
  std::cout << node->data.value() << " ";
}

template <class T> void BinaryTree<T>::rec_pre_order(BinaryTree<T> bt) {
  _rec_pre_order(bt.root);
}

template <class T> void BinaryTree<T>::rec_in_order(BinaryTree<T> bt) {
  _rec_in_order(bt.root);
}

template <class T> void BinaryTree<T>::rec_post_order(BinaryTree<T> bt) {
  _rec_post_order(bt.root);
}

template <class T> void BinaryTree<T>::iter_pre_order(BinaryTree<T> bt) {
  std::stack<std::shared_ptr<Node>> stack;
  stack.push(nullptr);
  auto temp_pointer_on_root = bt.root;
  while (true) {
    if (temp_pointer_on_root != nullptr) {
      stack.push(temp_pointer_on_root);
      std::cout << temp_pointer_on_root->data.value() << " ";
      temp_pointer_on_root = temp_pointer_on_root->left;
    } else {
      if (stack.top() == nullptr)
        break;
      temp_pointer_on_root = stack.top();
      stack.pop();
      temp_pointer_on_root = temp_pointer_on_root->right;
    }
  }
}
