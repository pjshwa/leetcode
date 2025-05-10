class Logger {
  unordered_map<string, int> L;

public:
  Logger() {}
  
  bool shouldPrintMessage(int timestamp, string message) {
    if (L.count(message) && L[message] + 10 > timestamp) return false;
    L[message] = timestamp;
    return true;
  }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
