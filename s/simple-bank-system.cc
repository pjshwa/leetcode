using ll = long long;

class Bank {
  int N;
  vector<ll> balances;

  bool is_valid_account(int account) {
    return account >= 1 && account <= N;
  }

public:
  Bank(vector<long long>& balance) {
    N = balance.size();
    balances.push_back(0); // 1-indexed
    for (int i = 0; i < N; ++i) {
      balances.push_back(balance[i]);
    }
  }

  bool transfer(int account1, int account2, long long money) {
    if (!is_valid_account(account1) || !is_valid_account(account2)) {
      return false;
    }
    if (balances[account1] < money) {
      return false;
    }
    balances[account1] -= money;
    balances[account2] += money;
    return true;
  }

  bool deposit(int account, long long money) {
    if (is_valid_account(account)) {
      balances[account] += money;
      return true;
    }
    return false;
  }

  bool withdraw(int account, long long money) {
    if (!is_valid_account(account) || balances[account] < money) {
      return false;
    }
    balances[account] -= money;
    return true;
  }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
